#ifndef _H_STACK
#define _H_STACK

#include "ships.h"

typedef struct stack_t {
    chute_t hit;
    struct stack_t* next;
} stack_t;

void add(stack_t** head, chute_t s);
void rem(stack_t** head);

#endif
