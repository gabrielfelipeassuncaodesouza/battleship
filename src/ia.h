#ifndef _H_IA
#define _H_IA

#include "board.h"
#include "stack.h"
#include "ships.h"

char iaDir();
chute_t iaPut(int xlimit, int ylimit);
chute_t iaChute(element_t board[][TAM], stack_t** hits);
void getNeighbours(element_t board[][TAM], stack_t** hits, chute_t pos);

#endif
