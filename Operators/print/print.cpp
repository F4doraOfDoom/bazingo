#include "print.h"

bool print(Instruction::ARGS args)
{
    for (auto arg : args)
    {
        std::cout << arg << " ";
    }

    std::cout << std::endl;

    return true;
}
