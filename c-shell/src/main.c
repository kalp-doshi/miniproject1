#include<stdio.h>
#include<string.h>

#include "prompt.h"
#define BUFFER_SIZE 1024
int main() {
    char command[BUFFER_SIZE];
    prompt_init();
    while(1) {
        print_prompt();
        
        if(fgets(command, BUFFER_SIZE, stdin) == NULL) {
            break;
        }
        command[strcspn(command, "\n")] = 0; 

    }
    return 0;
}