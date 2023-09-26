#include "queue.h"
#include "ships.h"

#include <stdio.h>
#include <stdlib.h>

void add(queue_t** head, queue_t** tail, chute_t s) {
    queue_t* new = (queue_t*)malloc(sizeof(queue_t));

    new->hit = s;
    new->next = NULL;

    if(*head == NULL) {
        *head = new;
        *tail = new;
    }
    else {
        (*tail)->next = new;
        *tail = new;
    }
}
void rem(queue_t** head) {
    if(*head == NULL) return;

    queue_t* aux = *head;
    *head = (*head)->next;
    free(aux);
}