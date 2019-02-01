#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>

enum OPCODE
{
    SET_CONST,
    SET_VAR,
    PRINT
};

struct Instruction
{
    OPCODE operation;
    
};

Instruction* parse(std::string line);

class Token -->

main --> Sent each line to Parser
Parser --> Gets a line of code:
    If int, bool or string print.
    If user sets var or const add it to the variables unordered map
    If print
    else: report syntax error
#endif // PARSER_H_