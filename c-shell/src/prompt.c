#include<stdio.h>
#include<string.h>
#include<pwd.h>
#include "prompt.h"
#include<limits.h>
#include<sys/types.h>
#include<unistd.h>


static char username[256];
static char hostname[256];
static char home_path[PATH_MAX];


void prompt_init(void) {
    struct passwd *user = getpwuid(getuid());

    if(user != NULL) {
        strncpy(username, user->pw_name, sizeof(username) - 1);
        username[sizeof(username) - 1] = '\0';
    }
    if(gethostname(hostname, sizeof(hostname)) == 0) {
        hostname[sizeof(hostname) - 1] = '\0';
        char *dot = strchr(hostname, '.');
        if (dot != NULL) *dot = '\0';
    }
    if(getcwd(home_path, sizeof(home_path) )== 0) {
        home_path[0] = '\0';
    }
    // fprintf(stderr, "DEBUG home=[%s]\n", home_path);
}

void print_prompt(void) {
    char current_dir[PATH_MAX];
    size_t home_path_len = strlen(home_path);
    if(getcwd(current_dir, sizeof(current_dir)) == NULL) {
        printf("<%s@%s:?> ",username, hostname);
        fflush(stdout);
        return;
    }
    else if(strcmp(current_dir, home_path) == 0) {
        printf("<%s@%s:~> ", username, hostname);
    }
    else if(strncmp(current_dir, home_path, home_path_len) == 0 && current_dir[home_path_len] == '/') {     //to eliminate cases such like "kalpdoshi/documents" and "kalpdoshi/documents1"
        printf("<%s@%s:~%s> ", username, hostname, current_dir + home_path_len);
    }
    else {
        printf("<%s@%s:%s> ", username, hostname, current_dir);
    }
    fflush(stdout);
}