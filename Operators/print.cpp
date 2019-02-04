#include <iostream>
#include "../Token/Token.h"

bool print(Token* value, Token* arguments)
{
    if (arguments)
    {
        // Maybe in the future we'll add arguments to the printing function
    }

    if (value)
    {
        std::cout << *value << std::endl;
    }
    else
    {
        std::cout << "NULL" << std::endl;
    }
    

    return true;
}
