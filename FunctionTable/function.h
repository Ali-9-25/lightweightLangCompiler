#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "../SymbolTable/symbol.h"

class Function {
    private:
        std::string name;
        std::string variableType;
        std::unordered_map<int, Symbol*> parameters;
        int count = 0;
        bool isDefined = false;
    
    public:
        Function(std::string name, std::string variableType);
        void setIsDefined(bool isDefined);
        void addParameter(Symbol* symbol);
        void setVariableType(std::string variableType);
        void setName(std::string name);
        void print();

        std::string getName();
        Symbol* getParameter(int index);
        std::string getVariableType();
        int getCount();
        bool checkDefined();
