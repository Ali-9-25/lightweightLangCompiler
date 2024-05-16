#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SemanticAnalyser

{

    bool isConstant(bool isinitialised, bool isconstant);
    bool checkType(string type1, string type2);

    bool check_int(string value);
    bool check_float(string value);
    bool check_bool(string value);
    bool check_string(string value);
    bool check_char(string value);
}