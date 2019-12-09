// C code to demonstrate
// strtok by white space example
// revised by str_tok c++ code

#include <string.h>
#include <stdio.h>
 
// Driver function
int main()
{
 // Declaration of string
    char *gfg;
    size_t size;
    printf("Write a sentence: ");
    getline(&gfg, &size, stdin);
    gfg[strlen(gfg)-1] = '\0';
 
    // Declaration of delimiter, here 
    char* tok;
 
    // Use of strtok
    // get first token
    tok = strtok(gfg, " ");
 
    // Checks for delimeter
    while (tok != 0) {
        printf(" %s\n", tok);
 
        // Use of strtok
        // go through other tokens
        tok = strtok(0, " ");
    }
 
    return (0);
}