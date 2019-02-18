/**
 * This file is the header file for everything that concerns variables.
 * Since not all functions need access to the variables, to avoid linking hell,
 * I put the definition for the program_variables map here
 * 
 * Variables.h by f4dora_0f_d00m 
 */

#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <iostream>
#include <unordered_map>
#include <string>

#include "Token/Types/Value.h"

// This global variable shall hold the variables present in the languange's user space
extern std::unordered_map<std::string, Value*> program_variables;

#endif // VARIABLES_H_