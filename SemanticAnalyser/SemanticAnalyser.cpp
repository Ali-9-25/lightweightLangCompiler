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