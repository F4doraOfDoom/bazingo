#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <vector>
#include "Token/Token.h"

enum OPCODE : uint_least8_t
{
    // Set a new const
    NSET_CONST,
    // Set a new variable
    NSET_VAR,
    // Change a new variable
    CSET_VAR,
    // Print
    PRINT,
    // Set varibles or constant
    SET
};

/*
    An instruction contains:
        OPCODE opcode - a code that represents what sort of operation that is
        OPERATOR function - pointer to a function that does the instruction, and takes the tokens
                        As an argument
        Token arg1 - first argument
        Token arg2 - second argument
*/
struct Instruction
{
    using ARGS = std::vector<Token>;
    using OPERATOR = bool (*)(ARGS); 

    Instruction(OPCODE, OPERATOR, ARGS);
    ~Instruction();

    OPCODE opcode;
    OPERATOR function;
    ARGS args;
};

#endif // INSTRUCTION_H_