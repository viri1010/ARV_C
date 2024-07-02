// Move a robot arm by tokeing commands from the user input
// use strtok to split the input into tokens
// save input into tokens and therefore control the arm

#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "readLine.h"

#define MAX_BUFFER 24
#define MAX_TOKENS (MAX_BUFFER/2)
#define MAX_DELIMS 3


int main(void) {    

    init_serial();
    char input[MAX_BUFFER + 1] = {};
    char delims[MAX_DELIMS + 1] = {" "}; // space used as delimiter

    puts("Move xArm using tokenization");
    printf("Enter cmd, distance, direction, and joint : ");
    printf("Possible delimitors are (w/ ASCII code): ");
    for (uint8_t delim=0; delim < MAX_DELIMS; delim++)
    {
        printf("' ' 0x%x ", delims[delim], delims[delim]); // shows the user what is the delimeter
    }
    printf("\n");
    uint8_t num_char = readLine(input, MAX_BUFFER);

    printf("You entered %i characters\n", num_char);

    for (uint8_t out_char=0; out_char<num_char; out_char++)
    {
        printf("%c", input[out_char]);
    }
    printf("\n");

    // break input line into tokens
    char *tokens[MAX_TOKENS];
    uint8_t index = 0;
    tokens[index] = strtok(input, delims);
    while ( (tokens[index] != NULL) && (index < MAX_TOKENS - 1) ) {
        index++;
        tokens[index] = strtok(NULL, delims);
    }
    uint8_t tokens_found = index;

    printf("The %i tokens parsed are:\n", tokens_found);
    printf("index token\n");
    for (index=0; index<tokens_found; index++)
    {
        printf("%5i %s\n", index, tokens[index]);

    }
}
