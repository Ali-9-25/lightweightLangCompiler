#include <iostream>
#include "scope.h"
using namespace std;

Stack::Stack(){
    this->globals = new scope();
    globals->table = new symbol_table();
    globals->parent = NULL;
    globals->name = "L0";
    globals->type = "Globals";
    internal_stack = globals;
}

symbol_table * Stack::insert_scope(){
    scope * s = new scope();
    s->table = new symbol_table();
    s->parent_scope = internal_stack;
    s->name = s->parent_scope->name + "-" + std::to_string(s->parent_scope->childern.size());
    internal_stack->childern.push_back(s);
    internal_stack = s;
    return s->table;  
}

symbol_table * Stack::remove_scope(std::string type){
    internal_stack->type = type;
    internal_stack = internal_stack->parent_scope;
    return internal_stack->table;
}

symbol_table * Stack::get_globals(){
    return this->globals->table;
}

symbol_table * Stack::get_symbol_table(std::string name){
    scope* current = internal_stack;
    while (current != NULL)
    {
        symbol* result = current->table->getsymbol(name);
        if (result != NULL)
        {
            return current->table;
        }
        current = current->parent_scope;
    }
    return NULL; 
}

void Stack::display_scope(scope * s, int depth = 0){
    if (s == NULL)
    {
        s = globals;
    }

    cout << endl;
    cout << right << setfill('=') << setw(2*(depth+1)) << "=>" << left << setfill(' ') << s->name << "(" << s->type << ")" << endl;
    cout << left << setw(2*(depth+1)) << "" << setfill('=') << setw(s->name.size()) << "" << setfill(' ') << endl;

    s->table->printSymbolTable();
    cout << "====================================================================================================" << endl;

    for(int i = 0; i < s->children.size(); ++i)
    {
        display_scope(s->children[i], depth+1);
    }
}

void Stack::print_tables_to_file(scope * s, int depth = 0, std::ofstream file){
    ofstream* output = file;
    if (s == NULL)
    {
        s = globals;
        output = new ofstream("tests/symbole_table");
        if (!output)
        {
            return;
        }
    }

    (*output) << endl;
    (*output) << right << setfill('=') << setw(2*(depth+1)) << "=>" << left << setfill(' ') << s->name << "(" << s->type << ")" << endl;
    (*output) << left << setw(2*(depth+1)) << "" << setfill('=') << setw(s->name.size()) << "" << setfill(' ') << endl;

    s->table->printSymbolTableToFile(output);
    (*output) << "====================================================================================================" << endl;

    for(int i = 0; i < s->children.size(); ++i)
    {
        printSymbolTablesToFile(s->children[i], depth+1, output);
    } 
}