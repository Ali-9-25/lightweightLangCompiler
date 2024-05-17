#include <iostream>
#include <string>

#include "function.h"

using namespace std;

Function::Function(string name, string variableType) {
    this->name = name;
    this->variableType = variableType;
}

void Function::setIsDefined(bool isDefined) {
    this->isDefined = isDefined;
}

void Function::addParameter(Symbol* symbol) {
    parameters[count] = symbol;
    count++;
}

void Function::setVariableType(string variableType) {
    this->variableType = variableType;
}

void Function::setName(string name) {
    this->name = name;
}

void Function::print() {
    cout << "Function: " << name << " " << variableType << endl;
    for (int i = 0; i < count; i++) {
        cout << "Parameter " << i << ": ";
        parameters[i].second->disp();
    }
}

string Function::getName() {
    return this->name;
}

Symbol* Function::getParameter(int index) {
    if (parameters.find(index) == parameters.end()) {
        return nullptr;
    }
    return parameters[index];
}

string Function::getVariableType() {
    return this->variableType;
}

int Function::getCount() {
    return count;
}

bool Function::checkDefined() {
    return this->isDefined;
}



