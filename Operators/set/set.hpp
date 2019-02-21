#ifndef SET_H_
#define SET_H_

#include <iostream>
#include "../../Token/Token.hpp"
#include "../../Instruction.hpp"
#include "../../Variables.hpp"
#include "../../Token/Syntax/SyntaxToken.hpp"
#include "../../Token/Name/Name.hpp"

/*
    This function sets variables and constants
    Input:
        Instruction::ARGS - A vector of Tokens
    Output:
        bool - whether or not the operation was successful 
*/
bool set(Instruction::ARGS);

#endif // SET_H_