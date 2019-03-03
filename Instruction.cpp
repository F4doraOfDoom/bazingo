#include "Instruction.hpp"

Instruction::Instruction(OPCODE opcode, OPERATOR function, ARGS args)
{
    this->opcode = opcode;
    this->function = function;
    this->args = args;
}

Instruction::~Instruction()
{
    // Pass
}