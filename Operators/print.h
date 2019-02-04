#include <iostream>
#include "../Token/Token.h"

bool print(Token* value, Token* arguments)
{
    std::cout << *value << std::endl;

    return true;
}
