#ifndef _H_QUEUE
#define _H_QUEUE

typedef struct queue_t {
    int num;
    struct queue_t* next;
} queue_t;

void add(queue_t** head, queue_t** tail, int num);
void rem(queue_t** head);

#endif