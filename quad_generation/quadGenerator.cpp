#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "quadGenerator.h"

using namespace std;

int QuadGenerator::quadCount = 0;

QuadGenerator::QuadGenerator() {
    quads = new vector<Quadruple *>();
    scopes.push(quads);
}

void QuadGenerator::startScope() {
    quads = new vector<Quadruple *>();
    scopes.push(quads);
}

void QuadGenerator::endScope(string type) {
    
    if(scopes.empty()){
        cerr << "Error: No scope to end" << endl;
        return;
    }

    vector<Quadruple *> *scope = scopes.top();
    scopes.pop();

    vector<Quadruple *> *parentScope = scopes.top();

    if (type == "if") 
    {
        addQuad("JF",parentScope->back()->getDestination() , "", "L" + to_string(labelCount));
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad("L"+ to_string(labelCount)+ ":", "", "", "");
        labelCount++; 
    } 
    else if (type == "else") 
    {
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
    } 
    else if (type == "for") 
    {
        // addQuad("JMP", "", "", "L" + to_string(labelCount));
        // addQuad("L"+to_string(labelCount)+":", "", "", "");
        // parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad(type, "", "", "");
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad(type, "", "", "");
        labelCount++;
    } 
    else if (type == "while") 
    {   
        string startLabel = "L"+to_string(labelCount);
        labelCount++;
        string endLabel = "L"+to_string(labelCount);
        labelCount++;

        auto it = parentList->rbegin();
        while((*it)->getDestination() != "T0")
        {
            ++it;
        }
        ++it;
        parentScope->insert(it.base(),new Quadruple(startLabel+":","","",""));
        addQuad("JF",parentScope->back()->getDestination(),"",endLabel);
        parentList->insert(parentScope->end(),scope->begin(),scope->end());
        addQuad("JMP","","",startLabel);
        addQuad(endLabel+":","","","");
    } 
    // else if(type == "switch")
    // {   
    //     addQuad(type,"","","");
    //     parentScope->insert(parentScope->end(), scope->begin(), scope->end());
    //     addQuad(type,"","","");
    //     labelCount++;
    // }
    // else if(type == "case"){
    //     addQuad(type,"","","");
    //     parentScope->insert(parentScope->end(), scope->begin(), scope->end());
    //     addQuad(type,"","","");
    //     labelCount++;
    // }
    else if(type == "switch")
    {   
        // Start of switch scope
        addQuad(type,"","","");
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());

        // For each case in the switch
        for(auto& caseQuad : *scope)
        {
            // If it's a case
            if(caseQuad->getOp() == "case")
            {
                string caseLabel = "L"+to_string(labelCount);
                labelCount++;
                string endLabel = "L"+to_string(labelCount);
                labelCount++;

                // Jump to end if not equal
                addQuad("JNE", parentScope->back()->getDestination(), caseQuad->getArg1(), endLabel);

                // Case body
                parentScope->insert(parentScope->end(), caseQuad->getScope()->begin(), caseQuad->getScope()->end());

                // Jump to end of switch after case
                addQuad("JMP", "", "", "L"+to_string(labelCount));

                // End of case
                addQuad(endLabel+":", "", "", "");
            }
        }

        // For each default in the switch
        for(auto& defaultQuad : *scope)
        {
            // If it's a default
            if(defaultQuad->getOp() == "default")
            {
                // Default body
                parentScope->insert(parentScope->end(), defaultQuad->getScope()->begin(), defaultQuad->getScope()->end());
            }
        }

        // End of switch
        addQuad("L"+to_string(labelCount)+":", "", "", "");
        labelCount++;
    }
    // else if(type == "repeat"){
    //     addQuad(type,"","","");
    //     parentScope->insert(parentScope->end(), scope->begin(), scope->end());
    //     addQuad(type,"","","");
    //     labelCount++;
    // }
    // else if(type == "until"){
    //     addQuad(type,"","","");
    //     parentScope->insert(parentScope->end(), scope->begin(), scope->end());
    //     addQuad(type,"","","");
    //     labelCount++;
    // }
    else if(type == "repeat" || type == "until"){
        string startLabel = "L"+to_string(labelCount);
        labelCount++;
        string endLabel = "L"+to_string(labelCount);
        labelCount++;

        if (type == "repeat") {
            addQuad(startLabel+":", "", "", "");
            parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        } else { // type == "until"
            addQuad("JF",parentScope->back()->getDestination(),"",startLabel);
            parentScope->insert(parentScope->end(), scope->begin(), scope->end());
            addQuad(endLabel+":","","","");
        }
    }
    //check it
    else if(type == "do"){
        string startLabel = "L"+to_string(labelCount);
        labelCount++;
        string endLabel = "L"+to_string(labelCount);
        labelCount++;

        addQuad(startLabel+":", "", "", "");
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad("JF",parentScope->back()->getDestination(),"",endLabel);
        addQuad("JMP","","",startLabel);
        addQuad(endLabel+":","","","");
    }
    // check it
    // else if(type == "function"){
    //     addQuad(type+":", "", "", "");
    //     parentScope->insert(parentScope->end(), scope->begin(), scope->end());
    //     addQuad("RET", "T"+
    //     to_string(tempVariables.size(), "", ""));
    //     labelCount++;
    // }
    else if(type == "function"){
        // Get the function name and parameters from somewhere
        string functionName = ...;
        vector<string> parameters = ...;

        // Add a quadruple with the function declaration
        addQuad(type + ":" + functionName, join(parameters, ","), "", "");

        // Insert all the quadruples from the current scope into the parent scope
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());

        // Get the return value from somewhere
        string returnValue = ...;

        // Add a "RET" (return) quadruple with the return value
        addQuad("RET", returnValue, "", "");

        // Increment the label count
        labelCount++;

        // Delete the scope
        delete scope;
    }
    else{
        addQuad(type+":", "", "", "");
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad("RET", "T"+to_string(tempVariables.size(), "", ""));
        labelCount++;
    }
    clearTemp();    
}

void QuadGenerator::clearTemp() {
    tempVariables.clear();
}

const char *QuadGenerator::addAssignment(Symbol *sym) {
    assignments[sym] = "R" + to_string(assignments[sym]);
    std::string str_value = assignments[sym];
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;    
}

const char *QuadGenerator::getAssignment(Symbol *sym) {
    std::string str_value = assignments[sym];
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;
}

const char *QuadGenerator::addTemp(string expr1, string op, string expr2) {
    temps["T"+to_string(temps.size())] = expr1 + op + expr2;
    std::string str_value = "T"+to_string(temps.size()-1);
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;
}

const char *QuadGenerator::getTemp(string name) {
    std::string str_value = temps[name];
    char *cstr_value = new char[str_value.length() + 1];
    str_value.copy(cstr_value, str_value.length());
    cstr_value[str_value.length()] = '\0';
    return cstr_value;
}

void QuadGenerator::addQuad(string op, string arg1, string arg2, string dist) {
    scopes.top()->push_back(new Quadruple(op, arg1, arg2, dist));
}

void QuadGenerator::printQuads() {
    cout << left << setw(10) << "Op" << setw(10) << "Arg1" << setw(10) << "Arg2" << setw(10) << "Dist" << endl;
    for (int i =0; i < quadCount; i++) {
        cout << left << setw(10) << quads[i]->getOp() << setw(10) << quads[i]->getArg1() << setw(10) << quads[i]->getArg2() << setw(10) << quads[i]->getDist() << endl;
    }
}

void QuadGenerator::printQuadsToFile() {
    ofstream file;
    file.open("results/quadruples.txt");
    if (!file) {
        cout << "Unable to open file";
        return;
    }

    file << "--------------------------------" << endl;
    file << "Quadruples" << endl;
    file << left << setw(10) << "Op" << setw(10) << "Arg1" << setw(10) << "Arg2" << setw(10) << "Dist" << endl;
    for (int i =0; i < quadCount; i++) {
        file << left << setw(10) << quads[i]->getOp() << setw(10) << quads[i]->getArg1() << setw(10) << quads[i]->getArg2() << setw(10) << quads[i]->getDist() << endl;
    }
    file.close();
}