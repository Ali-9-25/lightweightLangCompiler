#pragma once 
#include <iostream>
#include <string>
#include "symbol.h"
#include <unordered_map>
#include <ofstream>

class symbol_table{
    private:
        std::unordered_map<std::string, symbol *> c_symbol_table;
    public:
        symbol_table();
        void addsymbol(symbol * s);
        void addsymbols(std::unordered_map<std::string, symbol *> *table);
        void changesymbolstatus(symbol * s, std::value value);
        void printline(int line);
        void removesymbol(symbol * s);
        void displaytable();
        void printtabletofile(std::ofstream file);
        const char * getsymbolvalue(std::string name);
        const char * getsymboltype(std::string type);
        symbol * getsymbol(std::string name);
        ~symbol_table();
}