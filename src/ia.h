#ifndef _H_IA
#define _H_IA

#include "board.h"
#include "queue.h"
#include "ships.h"

chute_t iaChute(element_t board[][TAM], queue_t** hits);
void getNeighbours(element_t board[][TAM], queue_t** hits, queue_t** tail, chute_t pos);

#endif