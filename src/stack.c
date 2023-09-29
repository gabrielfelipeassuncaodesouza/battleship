#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "ships.h"

void add(stack_t** head, chute_t s) {
    stack_t* new = (stack_t*)malloc(sizeof(stack_t));

    new->hit = s;
    new->next = *head;
    *head = new;
}
void rem(stack_t** head) {
    if(*head == NULL) return;

    *head = (*head)->next;
}