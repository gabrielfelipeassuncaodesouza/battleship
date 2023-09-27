#ifndef _H_QUEUE
#define _H_QUEUE

#include "ships.h"

typedef struct queue_t {
    chute_t hit;
    struct queue_t* next;
} queue_t;

void add(queue_t** head, queue_t** tail, chute_t s);
void rem(queue_t** head);

#endif