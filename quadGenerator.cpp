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
    if (scopes.empty()) {
        cerr << "Error: No scope to end" << endl;
        return;
    }

    vector<Quadruple *> *scope = scopes.top();
    scopes.pop();

    if (scopes.empty()) {
        cerr << "Error: No parent scope to end into" << endl;
        delete scope;
        return;
    }

    vector<Quadruple *> *parentScope = scopes.top();

    if (type == "if") {
        addQuad("JF", parentScope->back()->getDestination(), "", "L" + to_string(labelCount));
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad("L" + to_string(labelCount) + ":", "", "", "");
        labelCount++;
    } else if (type == "else") {
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
    } else if (type == "for") {
        addQuad(type, "", "", "");
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad(type, "", "", "");
        labelCount++;
    } else if (type == "while") {
        string startLabel = "L" + to_string(labelCount);
        labelCount++;
        string endLabel = "L" + to_string(labelCount);
        labelCount++;

        auto it = parentScope->rbegin();
        while ((*it)->getDestination() != "T0") {
            ++it;
        }
        ++it;
        parentScope->insert(it.base(), new Quadruple(startLabel + ":", "", "", ""));
        addQuad("JF", parentScope->back()->getDestination(), "", endLabel);
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad("JMP", "", "", startLabel);
        addQuad(endLabel + ":", "", "", "");
    } else if (type == "repeat") {
        string startLabel = "L" + to_string(labelCount);
        labelCount++;

        addQuad(startLabel + ":", "", "", "");
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        repeatLabels.push(startLabel);
    } else if (type == "until") {
        if (repeatLabels.empty()) {
            cerr << "Error: No matching repeat for until" << endl;
            delete scope;
            return;
        }

        string startLabel = repeatLabels.top();
        repeatLabels.pop();

        string endLabel = "L" + to_string(labelCount);
        labelCount++;

        addQuad("JF", parentScope->back()->getDestination(), "", startLabel);
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad(endLabel + ":", "", "", "");
    } else if (type == "function") {
        string startLabel = "L" + to_string(labelCount);
        labelCount++;
        string endLabel = "L" + to_string(labelCount);
        labelCount++;
        addQuad("JMP", "", "", startLabel);
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad("RET", "", "", endLabel);
    } else {
        addQuad(type + ":", "", "", "");
        parentScope->insert(parentScope->end(), scope->begin(), scope->end());
        addQuad("RET", "T" + to_string(tempVariables.size()), "", "");
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