#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <map>

#include "Token/Token.h"
#include "Operators/print.h"
#include "Token/Types/Values/Integer.h"

enum OPCODE
{
    // Set a new const
    NSET_CONST,
    // Set a new variable
    NSET_VAR,
    // Change a new variable
    CSET_VAR,
    // Print
    PRINT
};

// A map that helps translate head instructions to opcodes
extern std::map<std::string, OPCODE> opcode_map;

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
    using OPERATOR = bool (*)(Token*, Token*); 
    
    OPCODE opcode;
    OPERATOR function;
    Token* arg1;
    Token* arg2;
};

/*
    The point of the parser is to take a string of data, and turn that into an instruction.
    After we parse the whole file, we get a list of instructions, that we can then execute
    What I think:
        The parser takes a line of code, and returns an instruction, that the main loop then executes.
        If we want to include complex lines of code in our language, we should use a vector of instructions,
        beacause one line evaluates to multiple instructions (i.e. print 6 + 8 * 2 / 3) 
    Input:
        std::string line - a line of code
    Output:
        Instruction* - pointer to an extraction
*/
std::vector<Instruction*> parse(std::string line);

// main --> Sent each line to Parser
// Parser --> Gets a line of code:
//     If int, bool or string print.
//     If user sets var or const add it to the variables unordered map
//     If print
//     else: report syntax error

#endif // PARSER_H_