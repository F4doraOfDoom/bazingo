#ifndef PARSER_H_
#define PARSER_H_

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <regex>
#include <deque>
#include <map>

#include "Variables.h"
#include "Instruction.h"
#include "Token/Token.h"
#include "Operators/print/print.h"
#include "Operators/set/set.h"
#include "Token/Types/Values/Integer.h"
#include "Token/Types/Values/String.h"
#include "Token/Types/Values/Float.h"
#include "Token/Types/Values/Boolean.h"
#include "Token/Syntax/SyntaxToken.h"

enum class FUNCTION : uint_least8_t
{
    // Uses the print function
    PRINT,
    // Uses the set function
    SET
};

// A map that helps translate head instructions to opcodes
extern std::map<std::string, FUNCTION> opcode_map;

// Name space for different functions regarding parsing arguments for different operators
namespace Parse
{
    /*
        This function passes the strings in th given stream and produces a vector of tokens
        Input:
            std::stringstream& stream - stream of strings (to be parsed as tokens)
        Output:
            Instruction::ARGS - A vector of tokens
    */
    Instruction::ARGS tokenize(std::stringstream& stream);

    /*
        This function is used to get the type of a Token.
        It works by using Regex Evaluation to check what sort of Token the string given belongs to
        Input:
            std::string - a string that needs to be evaulated as a Token
        Output:
            Token* - the inferred type of that string
    */
    Token* infer_type(std::string);
}

// Name space for string trimming functions
namespace Trim
{
    // Removes trailing whitespace from the left of a string
    void trim_left(std::string &s);

    // Removes trailing whitespace from the right of a string
    void trim_right(std::string &s);

    // Removes all trailing whitespace from a string
    void trim_all(std::string &s);
}

Token infer_type(std::string&);

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