#ifndef COMMAND_H
#define COMMAND_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    char *filename;
    bool append;
} redirect;


typedef struct {
    char **argv;
    size_t argc;
    size_t argv_capacity;

    char **inputs;
    size_t input_count;
    size_t input_capacity;

    redirect *outputs;
    size_t output_count;
    size_t output_capacity;
} stage;

typedef struct {
    stage *stages;
    size_t stage_count;
    size_t stage_capacity;

    bool is_background;
} command_group;


typedef struct {
    command_group *groups;
    size_t group_count;
    size_t group_capacity;
} command_line;


void free_command_line(command_line *line);
void print_command_line(command_line *line);

#endif