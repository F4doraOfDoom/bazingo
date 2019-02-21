#include "Integer.hpp"

Integer::Integer(long long value)
{
    _val = value;
    _str_val = std::to_string(value);
    _token_type = TOKEN_TYPE::VALUE;
}

std::string Integer::value() const
{
    return _str_val;
}

void Integer::_print(std::ostream& s) const
{
    s << _str_val;
}

bool Integer::operator <(const Value& other) const
{
    return _str_val < other.value();
}

bool Integer::operator >(const Value& other) const
{
    return _str_val > other.value();
}

bool Integer::operator ==(const Value& other) const
{
    return _str_val == other.value();
}