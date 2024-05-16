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
ValidationResult SemanticAnalyser::checkType(std::string value, std::string symbolTableType)
{
    ValidationResult result;

    switch (symbolTableType)
    {
    case "int":
        return intNarrowingConversion(value);
        break;
    case "float":
        return floatNarrowingConversion(value);
        break;
    case "bool":
        return boolNativeConversion(value);
        break;
    case "string":
        if (checkString(value))
        {
            result.isValid = true;
            result.value = value;
        }
        else
        {
            printf("ERROR: Invalid value for string data type");
        }
        break;
    case "char":
        if (checkChar(value))
        {
            result.isValid = true;
            result.value = value;
        }
        else
        {
            printf("ERROR: Invalid value for char data type");
        }
        break;
    case "void":
        if (checkVoid(value))
        {
            result.isValid = true;
            result.value = value;
        }
        // TODO: check if needed
        else
        {
            printf("ERROR: Invalid value for void data type")
        }
        break;
    default:
        printf("ERROR: Invalid data type, please use a supported data type {int, float, bool, string, char, void}");
    }

    return result;
}

ValidationResult SemanticAnalyser::intNarrowingConversion(string value)
{
    ValidationResult result;

    if (checkInt(value))
    {
        result.isValid = true;
        result.value = value;
    }
    else if (checkFloat(value))
    {
        result.isValid = true;
        result.value = value.substr(0, value.find('.')); // truncate the float value
        printf("WARNING: Narrowing conversion from float to int, truncating the value to %s", result.value);
    }
    else if (checkChar(value))
    {
        result.isValid = true;
        result.value = std::to_string(static_cast<int>(value[1])); // convert the char value to int (ASCII value)
        printf("WARNING: Narrowing conversion from char to int, converting the value to %s", result.value);
    }
    else if (checkBool(value))
    {
        result.isValid = true;
        result.value = value == "true" ? "1" : "0"; // convert the bool value to int
        printf("WARNING: Narrowing conversion from bool to int, converting the value to %s", result.value);
    }
    else
    {
        result.isValid = false;
        result.value = value;
        printf("ERROR: Invalid value for int data type");
    }

    return result;
}

ValidationResult SemanticAnalyser::floatNarrowingConversion(string value)
{
    ValidationResult result;

    if (checkFloat(value))
    {
        result.isValid = true;
        result.value = value;
    }
    else if (checkInt(value))
    {
        result.isValid = true;
        result.value = value + ".0"; // convert the int value to float
        printf("WARNING: Narrowing conversion from int to float, converting the value to %s", result.value);
    }
    else
    {
        result.isValid = false;
        result.value = value;
        printf("ERROR: Invalid value for float data type");
    }

    return result;
}

ValidationResult SemanticAnalyser::boolNativeConversion(string value)
{
    ValidationResult result;

    if (checkBool(value))
    {
        result.isValid = true;
        result.value = value;
    }
    else if (checkInt(value))
    {
        result.isValid = true;
        result.value = value == "0" ? "false" : "true"; // convert the int value to bool
        printf("WARNING: Native conversion from int to bool, converting the value to %s", result.value);
    }
    else if (checkFloat(value))
    {
        result.isValid = true;
        result.value = value == "0.0" ? "false" : "true"; // convert the float value to bool
        printf("WARNING: Native conversion from float to bool, converting the value to %s", result.value);
    }
    else if (checkString(value) || checkChar(value))
    {
        result.isValid = true;
        result.value = value == "" ? "false" : value == '' ? "false"
                                                           : "true"; // convert the string or char value to bool
        printf("WARNING: Native conversion from string or char to bool, converting the value to %s", result.value);
    }
    else
    {
        result.isValid = false;
        result.value = value;
        printf("ERROR: Invalid value for bool data type");
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
    // Check if the string is empty "void"
    if (value.empty())
    {
        return true;
    }

    return false;
}
