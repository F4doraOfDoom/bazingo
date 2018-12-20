/*
 * BAZINGO - input.c
 *
 * This file implements the functions specified in input.h
 *
 * By @F4doraOfDoom and @Mr-M33533K5
 * 20-12-18
 */

#include "input.h"

int take_input(char** token_buf, size_t* token_buf_len, size_t max_tokens, char* preline)
{
        size_t i = 0; 
        char buffer[BUF_SIZE] = { 0 };
        char* found = NULL;

        printf("%s", preline);

        fgets(buffer, BUF_SIZE, stdin);

        found = strtok(buffer, " ");
        while(found != NULL && i < max_tokens) {
                token_buf[i] = found;
                found = strtok(NULL, " ");
                i++;
        }

        if (token_buf_len != NULL) {
                *token_buf_len = i; 
        }

        return 0;
}