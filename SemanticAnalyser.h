#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ValidationResult
{
    bool isValid;
    std::string value;
};

class SemanticAnalyser

{
    // bool isConstant(bool isinitialised, bool isconstant);
    ValidationResult checkType(string value, string symbolTableType);
    ValidationResult intNarrowingConversion(string value);
    ValidationResult floatNarrowingConversion(string value);

    bool checkInt(string value);
    bool checkFloat(string value);
    bool checkBool(string value);
    bool checkString(string value);
    bool checkChar(string value);
    bool checkVoid(string value);
};