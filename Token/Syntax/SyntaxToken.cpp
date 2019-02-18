#include "SyntaxToken.h"

SyntaxToken::SyntaxToken(KEYWORD type)
{
    _token_type = type;
}

SyntaxToken::~SyntaxToken()
{
    // pass
}

KEYWORD SyntaxToken::keyword()
{
    return _token_type;
}