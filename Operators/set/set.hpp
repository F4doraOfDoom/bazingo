#ifndef SET_H_
#define SET_H_

#include <iostream>
#include "../../Token/Token.h"
#include "../../Instruction.h"
#include "../../Variables.h"
#include "../../Token/Syntax/SyntaxToken.h"

/*
    This function sets variables and constants
    Input:
        Instruction::ARGS - A vector of Tokens
    Output:
        bool - whether or not the operation was successful 
*/
bool set(Instruction::ARGS);

#endif // SET_H_