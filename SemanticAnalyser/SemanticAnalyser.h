#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SemanticAnalyser

{

    bool isConstant(bool isinitialised, bool isconstant);
    bool checkType(string type1, string type2);

    bool checkInt(string value);
    bool checkFloat(string value);
    bool checkBool(string value);
    bool checkString(string value);
    bool checkChar(string value);
    bool checkVoid(string value);
}