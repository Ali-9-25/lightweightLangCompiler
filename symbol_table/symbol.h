#pragma once
#include <iostream>
#include <string>
#include <ordered_map>

class symbol
{
private:
    std::string name;         // name of variable or function
    std::string type;         // data type of variable or return type of function
    std::string value = NULL; // value in identifier
    bool constant = false;    // whether or not it is constant
    bool initialized = false; // if it is initialized
    bool used = false;

public:
    symbol(std::string name, std::string type, std::string value = NULL, bool constant = false, bool initialized = false, bool used = false);
    void setname(std::string name);
    std::string getname();
    void settype(std::string type);
    std::string gettype();
    void setvalue(std::string value);
    std::string getvalue();
    void setconstant(bool constant);
    bool getconstant();
    void setinitialized(bool initialized);
    bool getintialization();
    void setused(bool used);
    bool getused();
    void disp();
    char *getattributecstr(int mode);
};