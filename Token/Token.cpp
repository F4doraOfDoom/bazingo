#include "Token.h"

Token::Token()
{
    _str_val = "Token";
}

Token::~Token()
{
    // pass
}

std::ostream& operator <<(std::ostream& s, const Token& t)
{
    t._print(s);
    return s;
}

void Token::_print(std::ostream& s) const
{
    s << _str_val;
} 