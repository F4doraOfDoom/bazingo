#include "Boolean.h"

Boolean::Boolean(bool value)
{
    _val = value;
    _str_val = _val ? "True" : "False";
}

std::string Boolean::value() const
{
    return _str_val;
}

void Boolean::_print(std::ostream& s) const
{
    s << _str_val;
}

bool Boolean::operator <(const Value& other) const
{
    return _str_val < other.value();
}

bool Boolean::operator >(const Value& other) const
{
    return _str_val > other.value();
}

bool Boolean::operator ==(const Value& other) const
{
    return _str_val == other.value();
}