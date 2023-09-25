#ifndef _H_IA
#define _H_IA

#include "ships.h"
#include "board.h"

chute_t iaChute(element_t board[][TAM], chute_t* neighbours, int i, int hitted);
void getNeighbours(element_t board[][TAM], chute_t neigh[], chute_t pos);

#endif