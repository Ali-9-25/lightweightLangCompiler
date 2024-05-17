#include <isotream>
#include <string>
#include "symbol.h"
using namespace std;

//
Symbol::Symbol(std::string name, std::string type, std::string value = NULL, bool constant = false, bool initialized = false, bool used = false)
{
    this->name = name;
    this->type = type;
    this->value = value;
    this->constant = constant;
    this->initialized = initialized;
    this->used = used;
}

void Symbol::setname(std::string name)
{
    this->name = name;
}

std::string Symbol::getname()
{
    return this->name;
}
void Symbol::settype(std::string type)
{
    this->type = type;
}
std::string Symbol::gettype()
{
    return this->type;
}
void Symbol::setvalue(std::string value)
{
    this->value = value;
}
std::string Symbol::getvalue()
{
    return this->value;
}
void Symbol::setconstant(bool constant)
{
    this->constant = constant;
}
bool Symbol::getconstant()
{
    return this->constant;
}
void Symbol::setinitialized(bool initialized)
{
    this->initialized = initialized;
}
bool Symbol::getintialization()
{
    return this->initialized;
}
void Symbol::setused(bool used)
{
    this->used = used;
}
bool Symbol::getused()
{
    return this->used;
}
void Symbol::disp()
{
    cout << this->name << "\t" << this->type << "\t" << this->value << "\t" << this->costant << "\t" << this->initialized << "\t" << this->used << endl;
}

char *Symbol::getattributecstr(int i)
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