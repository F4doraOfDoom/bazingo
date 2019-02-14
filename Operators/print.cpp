#include <iostream>
#include "../Token/Token.h"
#include "print.h"

bool print(Instruction::ARGS args)
{
    for (auto arg : args)
    {
        std::cout << arg << std::endl;
    }

    return true;
}
