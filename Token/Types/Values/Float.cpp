#include "Float.hpp"

Float::Float(double value)
{
    _val = value;
    _str_val = std::to_string(value);
    _token_type = TOKEN_TYPE::VALUE;
}

std::string Float::value() const
{
    return _str_val;
}

void Float::_print(std::ostream& s) const
{
    s << _str_val;
}

bool Float::operator <(const Value& other) const
{
    return _str_val < other.value();
}

bool Float::operator >(const Value& other) const
{
    return _str_val > other.value();
}

bool Float::operator ==(const Value& other) const
{
    return _str_val == other.value();
}