#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include "../symbol_table/symbol_table.h"
#include <fstream>

struct scope {
    std::string name;               /* name of scope */
    std::string type;               /* type of scope */
    symbol_table * table;           /* symbol table of scope */
    scope * parent_scope;           /* the parent scope */
    std::vector<scope *> childern;  /* the internal of scopes */
};

class Stack{
    private:
        scope * globals;
        scope * internal_stack;
    public:
        Stack();
        symbol_table * insert_scope();
        symbol_table * remove_scope(std::string type);
        symbol_tabel * get_globals();
        symbol_table * get_symbol_table(std::string name);
        void display_scope(scope * s, int depth = 0);
        void print_tables_to_file(scope * s, int depth = 0, std::ofstream file); 
}