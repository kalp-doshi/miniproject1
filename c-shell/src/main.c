#include<stdio.h>
#include<string.h>
#define BUFFER_SIZE 1024
int main() {
    while(1) {
        printf("<shell>:");
        fflush(stdout);
        char command[BUFFER_SIZE];
        if(fgets(command, BUFFER_SIZE, stdin) == NULL) {
            break;
        }
        command[strcspn(command, "\n")] = 0; 

    }
}