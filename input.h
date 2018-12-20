/**
 * @file input.h
 * @brief This is the header files for all of the functions
 * concerning input
 * 
 * 
 * 
 * version log
 * ------------
 * version 1.0 by F4dora_0f_D00m, 20.12.2018
 * 
*/

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <string.h>

#define BUF_SIZE 16384

/**
 * This function takes the user's input and seperates it by spaces, and then
 * stores the tokens inside token_buf
 * 
 * @param char** token_buf - an array of strings (a string for each token)
 * @param size_t* token_buf_len - pointer to a variable holding the number of
 * tokens returned
 * @param max_tokens - max number of tokens to be processed
 * @param char* preline - a string to print before taking the user's input
 * 
 * @return int - returns 0 if the operation was successful
 */
int take_input(char** token_buf, size_t* token_buf_len, size_t max_tokens, char* preline);

#endif  // INPUT_H_