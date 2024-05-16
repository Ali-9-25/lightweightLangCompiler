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
std::pair<bool, std::string> SemanticAnalyser::checkType(std::string value, std::string symbolTableType)
{
    std::pair<bool, std::string> result;

    switch (symbolTableType)
    {
    case "int":
        if (checkInt(value))
        {
            result.first = true;
            result.second = value;
        }
        break;
    case "float":
        if (checkFloat(value))
        {
            result.first = true;
            result.second = value;
        }
        break;
    case "bool":
        if (checkBool(value))
        {
            result.first = true;
            result.second = value;
        }
        break;
    case "string":
        if (checkString(value))
        {
            result.first = true;
            result.second = value;
        }
        break;
    case "char":
        if (checkChar(value))
        {
            result.first = true;
            result.second = value;
        }
        break;
    case "void":
        if (checkVoid(value))
        {
            result.first = true;
            result.second = value;
        }
        break;
    default:
        printf("ERROR: Invalid data type, please use a supported data type {int, float, bool, string, char, void}");
        // code to be executed if none of the above cases are true
    }

    if (type1 != type2 && !(type1 == "float" && type2 == "int") && !(type1 == "int" && type2 == "float"))
    {
        result.first = false;
    }

    return result;
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

/*
    @brief Checks if a character is a valid octal digit.*
        @param digit The character to check.
        @ return True if the character is a valid octal digit,
    false otherwise.
*/
bool isOctal(char digit)
{
    return (isdigit(digit) && digit != '8' && digit != '9');
}

/*
@brief Checks if a character is a valid escape character.*
@param escapeChar The character to check.
@return True if the character is a valid escape character, false otherwise.
*/
bool isValidEscapeChar(char escapeChar)
{
    // \\ \’ \” \? \0 \a \b \f \n \r \t \v
    return (escapeChar == '\\' || escapeChar == '\'' || escapeChar == '\"' || escapeChar == '?' || escapeChar == '0' || escapeChar == 'a' || escapeChar == 'b' || escapeChar == 'f' || escapeChar == 'n' || escapeChar == 'r' || escapeChar == 't' || escapeChar == 'v');
}

/*
@brief Checks if a given string represents a valid character.
This function checks if the string is enclosed in single quotes, and if it represents a valid character.
@param value The string to check.
@return True if the string represents a valid character, false otherwise.
*/
bool SemanticAnalyser::checkChar(string value)
{
    // Check if the string is enclosed in single quotes
    if (value.size() == 3 && value.front() == '\'' && value.back() == '\'')
    {
        return true;
    }

    if (value.size() >= 4 && value.front() == '\'' && value.back() == '\'')
    {
        if (value[1] != '\\') // Regular character
        {
            return false;
        }
        else // Escape sequence
        {
            char escapeChar = value[2];

            if (!isValidEscapeChar(escapeChar))
            {
                return false; // Known escape sequences
            }
            else if (escapeChar == 'x' && value.size() == 5) // Hexadecimal escape sequence
            {
                // Check if the next two characters are valid hexadecimal digits
                if (isxdigit(value[3]) && isxdigit(value[4]))
                {
                    return true;
                }
            }
            else if (isOctal(escapeChar)) // Octal escape sequence
            {
                // Check if the next two characters are valid octal digits
                if (value.size() == 5 && isdigit(value[3]) && isdigit(value[4]))
                {
                    return true;
                }
            }
        }
    }

    return false; // Invalid character
}

bool SemanticAnalyser::checkBool(string value)
{
    // Remove leading and trailing whitespaces
    // value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());

    // Check if the string is empty
    if (value.empty())
    {
        return false;
    }

    // Check if the string is either "true" or "false"
    if (value != "true" && value != "false")
    {
        return false;
    }

    return true;
}

bool SemanticAnalyser::checkVoid(string value)
{
    // Check if the string is empty
    if (value.empty())
    {
        return false;
    }

    // Check if the string is "void"
    if (value != "void")
    {
        return false;
    }

    return true;
}
