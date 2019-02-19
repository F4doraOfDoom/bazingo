#include "set.h"

bool set(Instruction::ARGS args)
{
    bool set_const = false;

    if (args[0].type() == TOKEN_TYPE::KEYWORD)
    {
        // We already checked that args[0] is indeed a SyntaxToken, so a downward cast is safe
        SyntaxToken* syntax_token = (SyntaxToken*)&args[0];
        set_const = (syntax_token->keyword() == KEYWORD::CONST);
    }

    std::cout << "Is const: " << set_const << std::endl;

    return false;
}