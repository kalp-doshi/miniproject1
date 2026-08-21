#ifndef LEXER_H
#define LEXER_H

#include<stdbool.h>
#include<stddef.h>

typedef enum {
    TOK_WORD,
    TOK_PIPE,
    TOK_AMP,
    TOK_SEMI,
    TOK_LT,
    TOK_GT,
    TOK_GTGT
}token_kind;

typedef struct {
    token_kind kind;
    char* value;
}token;

typedef struct {
    token* tokens;
    size_t capacity;
    size_t count;
}token_list;

bool tokenize(const char *line, token_list *list);
void free_token_list(token_list *list);
const char *token_kind_name(token_kind kind);
#endif