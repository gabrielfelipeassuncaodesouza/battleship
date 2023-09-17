#ifndef _H_SHOOT
#define _H_SHOOT

#include "board.h"
#include "ships.h"
#include "human.h"

int shoot(element_t board[][TAM], const char* player);
int isPositionShooted(element_t c);
element_t coordinates(element_t board[][TAM], chute_t c);

#endif
