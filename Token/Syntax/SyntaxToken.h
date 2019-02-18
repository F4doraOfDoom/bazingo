#ifndef SYNTAX_TOKEN_H_
#define SYNTAX_TOKEN_H_

#include "../Token.h"

enum SYNTAX_TOKENS : uint_least8_t
{
        CONST
};

class SyntaxToken : public Token
{
public:
    SyntaxToken(SYNTAX_TOKENS);
    ~SyntaxToken();

    SYNTAX_TOKENS type();

private:
    SYNTAX_TOKENS _token_type;
};

#endif // SYNTAX_TOKEN_H_