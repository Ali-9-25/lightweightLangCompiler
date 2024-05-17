#pragma once
#include <iostream>
#include <string>
#include "symbol.h"
#include <unordered_map>
#include <fstream>

class symbol_table
{
private:
    std::unordered_map<std::string, Symbol *> c_symbol_table;

public:
    symbol_table();
    void addsymbol(Symbol *s);
    void addsymbols(std::unordered_map<std::string, Symbol *> *table);
    void changesymbolstatus(Symbol *s, std::string value);
    void printline(int line);
    void removesymbol(Symbol *s);
    void displaytable();
    void printtabletofile(std::ofstream file);
    const char *getsymbolvalue(std::string name);
    const char *getsymboltype(std::string type);
    Symbol *getsymbol(std::string name);
    ~symbol_table();
};