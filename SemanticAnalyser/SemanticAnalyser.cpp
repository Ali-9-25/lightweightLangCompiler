#include <iostream>
#include <string>
#include <algorithm>
#include "SemanticAnalyser.h"

using namespace std;

// "int"               {yylval.str = strdup(yytext); return INT; }
// "float"             {yylval.str = strdup(yytext); return FLOAT; }
// "bool"              {yylval.str = strdup(yytext); return BOOL; }
// "string"            {yylval.str = strdup(yytext); return STRING; }
// "char"              {yylval.str = strdup(yytext); return CHAR; }
// "void"              {yylval.str = strdup(yytext); return VOID; }

// return flase if there is type mismatch and push the error to the errorlist, otherwise return true

// compares data type in symbol table with type of value, returns false on mismatch
bool SemanticAnalyser::checkType(string value, string symbolTableType)
{
    switch (symbolTableType)
    {
    case "int":
        // code to be executed if expression equals value1

        break;
    case "float":
        // code to be executed if expression equals value2
        break;
    // more cases can be added as needed
    case "bool":

        break;
    // more cases can be added as needed
    case "bool":

        break;
    default:
        printf("ERROR: Invalid data type, please use a supported data type {int, float, bool, string, char, void}")
        // code to be executed if none of the above cases are true
    }

    if (type1 != type2 && !(type1 == "float" && type2 == "int") && !(type1 == "int" && type2 == "float"))
    {
        return false;
    }
    return true;
}

bool SemanticAnalyser::checkInt(string value)
{
    // Remove leading and trailing whitespaces
    // value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());

    // Check if the string is empty
    if (value.empty())
    {
        return false;
    }

    // remove the negative sign if exist
    if (value[0] == '-')
    {
        value = value.substr(1);
    }

    // Check if the string contains only digits
    for (char c : value)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    return true;
}

bool SemanticAnalyser::checkFloat(string value)
{
    // Remove leading and trailing whitespaces
    // value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());

    // Check if the string is empty
    if (value.empty())
    {
        return false;
    }

    // remove the negative sign if exist
    if (value[0] == '-')
    {
        value = value.substr(1);
    }

    // Check if the string contains only digits and at most one decimal point
    bool decimalPointFound = false;
    for (char c : value)
    {
        if (!isdigit(c) && c != '.')
        {
            return false;
        }
        if (c == '.')
        {
            decimalPointFound = true;
        }
    }
    if (!decimalPointFound)
    {
        return false;
    }

    return true;
}

bool SemanticAnalyser::checkString(string value)
{
    // Check if the string is enclosed in double quotes
    if (value.size() < 2 || value.front() != '"' || value.back() != '"')
    {
        return false;
    }

    return true;
}

bool SemanticAnalyser::checkChar(string value)
{
    // Check if the string is enclosed in single quotes
    if (value.size() == 3 && value.front() == '\'' && value.back() == '\'')
    {
        return true;
    }
    if (value.size() == 4 && value[1] == '\\' && value.front() == '\'' && value.back() == '\'')
    {
        if (value[2] == 'n' || value[2] == 't' || value[2] == 'r' || value[2] == 'b' || value[2] == 'f' || value[2] == '\\') // check for escape sequences
        {
            return true;
        }
    }
    if (value.size() == 6 && value[1] == '\\' && (value.substr(3, 5) == "ooo" || value.substr(3, 5) == "xhh")) // check for octal and hexadecimal escape sequences
    {
        return true;
    }
    return false;
}

// bool SemanticAnalyser::checkBool(string value)
// {
//     // Remove leading and trailing whitespaces
//     // value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());

//     // Check if the string is empty
//     if (value.empty())
//     {
//         return false;
//     }

//     // Check if the string is either "true" or "false"
//     if (value != "true" && value != "false")
//     {
//         return false;
//     }

//     return true;
// }