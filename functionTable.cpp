#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

#include "functionTable.h"

using namespace std;

void FunctionTable::addFunctionInTable(Function* function) {
    if (checkExists(function->getName())) {
        cout << "Function " << function->getName() << " already exists in the table" << endl;
        functions[function->getName()] = function;
        return;
    }
}

void FunctionTable::setFunctionByNameInTable(string name, bool defined) {
    if (functions.find(name) == functions.end()) {
        cout << "Function " << name << " not found in the table" << endl;
        return;
    }
    functions[name]->setIsDefined(defined);
}

Function* FunctionTable::getFunctionByName(string name) {
    if (functions.find(name) == functions.end()) {
        cout << "Function " << name << " not found in the table" << endl;
        return nullptr;
    }
    return functions[name];
}

void FunctionTable::removeFunctionFromTable(Function *function) {
    if (functions.find(function->getName()) == functions.end()) {
        cout << "Function " << function->getName() << " not found in the table" << endl;
        return;
    }
    functions.erase(function->getName());
}

bool FunctionTable::checkFunctionExist(string name) {
    
    for (auto it : functions) {
        if (it.first == name) {
            cout << "Function " << name << " exists in the table" << endl;
            return false;
        }
    }
    return true;
}

void FunctionTable::printFunctionTable() {
    cout << "--------------------------------" << endl;
    cout << "Function Table" << endl;
    cout << left << setw(20) << "Function Name" << setw(20) << "Function Type" << setw(20) << "Is Defined" << "Parameters"<< endl;
    for (auto it : functions) {
        cout << left << setw(20) << it.second << setw(20) << it.second->getVariableType() << setw(20) << it.second->checkDefined();
        
        int count = it.second->getCount();
        for (int i = 0; i < count; i++) {
            Symbol* symbol = it.second->getParameter(i);
            cout << i << ": " << symbol->getType() << " " << symbol->getName() << " ";
            if ( i < count - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    cout << "--------------------------------" << endl;
}

void FunctionTable::printFunctionTableToFile() {
    ofstream file;
    file.open("results/functionTable.txt");
    if (!file) {
        cout << "Unable to open file";
        return;
    }
    file << "--------------------------------" << endl;
    file << "Function Table" << endl;
    file << left << setw(20) << "Function Name" << setw(20) << "Function Type" << setw(20) << "Is Defined" << "Parameters"<< endl;
    for (auto it : functions) {
        file << left << setw(20) << it.second << setw(20) << it.second->getVariableType() << setw(20) << it.second->checkDefined();
        
        int count = it.second->getCount();
        for (int i = 0; i < count; i++) {
            Symbol* symbol = it.second->getParameter(i);
            file << i << ": " << symbol->getType() << " " << symbol->getName() << " ";
            if ( i < count - 1) {
                file << ", ";
            }
        }
        file << endl;
    }
    file << "--------------------------------" << endl;
    file.close();
}