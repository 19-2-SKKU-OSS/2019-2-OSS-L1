// C code to demonstrate
// strtok by white space example
// revised by str_tok c++ code

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
// Driver function
int main(int argc, char* argv[])
{
 // Declaration of string
    char *gfg;
    size_t size;

    //set file discriptor
    int fd = open (argv[1], O_RDONLY);
    int nbytes;
    char buf[1024];
    char* tok;
 
    while((nbytes = read(fd, buf, sizeof(buf))==0)){
        // Use of strtok
        // get first token
        tok = strtok(buf, " ");

        while (tok != 0) {

            printf(" %s\n", tok);
 
            // Use of strtok
            // go through other tokens
            tok = strtok(0, " ");
        }
    }
 
    return (0);
}