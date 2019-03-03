#include "SyntaxToken.hpp"

SyntaxToken::SyntaxToken(KEYWORD type)
{
    _token_type = TOKEN_TYPE::KEYWORD;
    _keyword_type = type;
    _str_val = "Keyword";
}

SyntaxToken::~SyntaxToken()
{
    // pass
}

KEYWORD SyntaxToken::keyword()
{
    return _keyword_type;
}
