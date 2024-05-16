#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

#include "function.h"

#define cNull 0

class FunctionTable {
    private:
        std::unordered_map<std::string, Function*> functions;
    
    public:
        void addFunctionInTable(Function* function);
        void setFunctionByNameInTable(std::string name, bool defined);  
        Function* getFunctionByName(std::string name);
        void removeFunctionFromTable(Function *function);
        bool checkFunctionExist(std::string name);
        void printFunctionTable();
        void printFunctionTableToFile();
};