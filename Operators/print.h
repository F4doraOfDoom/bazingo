#ifndef PRINT_H_
#define PRINT_H_

#include "../Instruction.h"

/*
    This function represents the print operator
    It iterates over the tokens, and outputs each one to std::cout
    Input:
        Instruction::ARGS - A vector of Tokens
    Output:
        bool - whether or not the operation was successful 

*/
bool print(Instruction::ARGS);

#endif // PRINT_H_