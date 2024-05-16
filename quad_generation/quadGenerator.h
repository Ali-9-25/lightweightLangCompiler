#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <vector>

#include "../symbol_table/symbol.h"
#include "quad.h"

class QuadGenerator
{
private:
    std::stack<Quadruple *> quads;
    std::stack<std::vector<Quadruple *>> scopes;
    std::unordered_map<symbol *, std::string> assignments;
    std::unordered_map<std::string, std::string> tempVariables;
    std::stack<std::vector<Quadruple*>> repeatLabels;

public:
    static int labelCount;
    QuadGenerator();
    void startScope();
    void endScope(std::string type);
    const char *addAssignment(symbol *sym);
    const char *getAssignment(symbol *sym);
    const char *addTemp(std::string expr1, std::string op, std::string expr2);
    const char *getTemp(std::string name);
    void clearTemp();
    void addQuad(std::string op, std::string arg1, std::string arg2, std::string dist);
    void printQuads();
    void printQuadsToFile(); 
}