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
        addQuad("type", "", "", "");
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
    } 
    // else if (type == "while") 
    // {
    //     addQuad("JMP", "", "", "L" + to_string(labelCount));
    //     addQuad("L"+to_string(labelCount)+":", "", "", "");
    //     parentScope->insert(parentScope->end(), scope->begin(), scope->end());
    // } 
    // else 
    // {
    //     parentScope->insert(parentScope->end(), scope->begin(), scope->end());
    // }
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