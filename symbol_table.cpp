#pragma once
#include "symbol_table.h"
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

symbol_table::symbol_table()
{
}

void symbol_table::addsymbol(Symbol *s)
{
    this->c_symbol_table[s->getname()] = s;
}
void symbol_table::addsymbols(std::unordered_map<std::string, Symbol *> *table)
{
    this->c_symbol_table = table;
}
void symbol_table::changesymbolstatus(Symbol *s, std::string value)
{
    if (this->c_symbol_table.find() != this->c_symbol_table.end())
    {
        this->c_symbol_table[s->getname()]->setinitialized(true);
        this->this->c_symbol_table[s->getname()]->setvalue(value);
    }
}
void symbol_table::printline(int line)
{
    cout << "\tname\ttype\tvalue\tconstant\tinitialized\tused\n";
    for (auto s : symbolTable)
    {
        if (s.second->getused() == false)
        {
            s.second->disp();
        }
    }
}
void symbol_table::removesymbol(Symbol *s)
{
    if (this->c_symbol_table.find(s->getname()) != this->c_symbol_table.end())
    {
        return this->c_symbol_table.erase(s->getname());
    }
    else
    {
        return NULL;
    }
}

void symbol_table::displaytable()
{
    cout << "\tname\ttype\tvalue\tconstant\tinitialized\tused\n";
    for (auto s : symbolTable)
    {
        s.second->disp();
    }
}

void symbol_table::printtabletofile(std::ofstream file)
{
    (*file) << endl;
    (*file) << left << "\tname\ttype\tvalue\tconstant\tinitialized\tused\n";
    for (auto x : symbolTable)
    {
        (*file) << left << "\t" << x.second->disp();
    }
    (*file) << endl;
}

const char *symbol_table::getsymbolvalue(std::string name)
{
    if (this->c_symbol_table.find(name) != this->c_symbol_table.end())
    {
        return this->c_symbol_table[name];
    }
    else
    {
        return NULL;
    }
}
const char *symbol_table::getsymboltype(std::string type)
{
    if (this->c_symbol_table.find(name) != this->c_symbol_table.end())
    {
        return this->c_symbol_table[name]->getattributecstr(2);
    }
    else
    {
        return NULL;
    }
}

Symbol *symbol_table::getsymbol(std::string name)
{
    if (this->c_symbol_table.find(name) != this->c_symbol_table.end())
    {
        return this->c_symbol_table[name];
    }
    else
    {
        return NULL;
    }
}

symbol_table::~symbol_table()
{
    foreach (auto *s : this->c_symbol_table)
    {
        delete s;
    }
}
