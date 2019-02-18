#ifndef SYNTAX_TOKEN_H_
#define SYNTAX_TOKEN_H_

#include "../Token.h"

/*
    This enum shall define all the types of the syntaxic tokens in the language
*/
enum class KEYWORD : uint_least8_t
{
    CONST
};

/*
    This class is for tokens that represent syntax, such as keywords. For example:
    When one wants to set a constant, he will do:
        set const [var_name] [value]
    The set represents a function, while "const" represents a keyword - a standard 
    syntaxic token of the language
*/
class SyntaxToken : public Token
{
public:
    /*
        Constructor.
        Input:
            KEYWORD _ - the type of the syntaxic token
        Output:
            None
    */
    SyntaxToken(KEYWORD);
    ~SyntaxToken();

    /*
        This is a getter function for _token_type
        Input:
            None
        Output:
            SYNTAX_TOKENS - the type of the token, as listed in the SYNTAX_TOKENS enum
    */
    KEYWORD keyword();

private:
    KEYWORD _token_type;
};

#endif // SYNTAX_TOKEN_H_