#include <isotream>
#include <string>
#include "symbol.h"
using namespace std;

//
symbol::symbol(std::string name, std::string type, std::string value = NULL, bool constant = false, bool initialized = false, bool used = false)
{
    this->name = name;
    this->type = type;
    this->value = value;
    this->constant = constant;
    this->initialized = initialized;
    this->used = used;
}

void symbol::setname(std::string name)
{
    this->name = name;
}

std::string symbol::getname()
{
    return this->name;
}
void symbol::settype(std::string type)
{
    this->type = type;
}
std::string symbol::gettype()
{
    return this->type;
}
void symbol::setvalue(std::string value)
{
    this->value = value;
}
std::string symbol::getvalue()
{
    return this->value;
}
void symbol::setconstant(bool constant)
{
    this->constant = constant;
}
bool symbol::getconstant()
{
    return this->constant;
}
void symbol::setinitialized(bool initialized)
{
    this->initialized = initialized;
}
bool symbol::getintialization()
{
    return this->initialized;
}
void symbol::setused(bool used)
{
    this->used = used;
}
bool symbol::getused()
{
    return this->used;
}
void symbol::disp()
{
    cout << this->name << "\t" << this->type << "\t" << this->value << "\t" << this->costant << "\t" << this->initialized << "\t" << this->used << endl;
}

char *symbol::getattributecstr(int i)
{
    if (i == 0)
    {
        std::string str_value = this->name;
        char *cstr_value = new char[str_value.length() + 1];
        str_value.copy(cstr_value, str_value.length());
        cstr_value[str_value.length()] = '\0';
        return cstr_value;
    }
    else if (i == 1)
    {
        std::string str_value = this->type;
        char *cstr_value = new char[str_value.length() + 1];
        str_value.copy(cstr_value, str_value.length());
        cstr_value[str_value.length()] = '\0';
        return cstr_value;
    }
    else
    {
        std::string str_value = this->value;
        char *cstr_value = new char[str_value.length() + 1];
        str_value.copy(cstr_value, str_value.length());
        cstr_value[str_value.length()] = '\0';
        return cstr_value;
    }
}