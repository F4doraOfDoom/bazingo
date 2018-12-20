#include <stdio.h>
#include "input.h"

int main(void)
{
        char* strings[10] = { 0 };
        size_t len;

        take_input(strings, &len, 10, ">>> ");

        printf("number of tokens: %ld\n", len);

        int i = 0;
        for(i = 0; i < len; i++)
        {
                printf("%s\n", strings[i]);
        }

        return 0;
}
