#include "Name.hpp"

Name::Name(std::string var_name)
{
    _token_type = TOKEN_TYPE::NAME;
    _var_name = var_name;
    _str_val = "Name";
}

Name::~Name()
{
    // Pass
}

std::string Name::name()
{
    return _var_name;
}