#include "SyntaxToken.h"

SyntaxToken::SyntaxToken(SYNTAX_TOKENS type)
{
    _token_type = type;
}

SyntaxToken::~SyntaxToken()
{
    // pass
}

SYNTAX_TOKENS SyntaxToken::type()
{
    return _token_type;
}