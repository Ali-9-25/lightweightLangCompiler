#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SemanticAnalyser

{

    bool isConstant(bool isinitialised, bool isconstant);
    bool checkType(string type1, string type2);
}