#ifndef _H_IA
#define _H_IA

#include "board.h"
#include "queue.h"
#include "ships.h"

chute_t iaChute(element_t board[][TAM], chute_t neighbours[], int i, int hitted);

int getNeighbours(element_t board[][TAM], chute_t neigh[], queue_t* head);

#endif
