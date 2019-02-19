#include "Token.h"

Token::Token()
{
    _str_val = "Token";
    _token_type = TOKEN_TYPE::TOKEN;
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

TOKEN_TYPE Token::type()
{
    return _token_type;
}

void Token::_print(std::ostream& s) const
{
    s << _str_val;
} 