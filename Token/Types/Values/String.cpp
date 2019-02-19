#include "String.h"

String::String(std::string value)
{
    _val = value;
    _str_val = value;
    _token_type = TOKEN_TYPE::VALUE;
}

std::string String::value() const
{
    return _str_val;
}

void String::_print(std::ostream& s) const
{
    s << _str_val;
}

bool String::operator <(const Value& other) const
{
    return _str_val < other.value();
}

bool String::operator >(const Value& other) const
{
    return _str_val > other.value();
}

bool String::operator ==(const Value& other) const
{
    return _str_val == other.value();
}