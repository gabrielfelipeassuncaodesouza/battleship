#ifndef _H_SHOOT
#define _H_SHOOT

#include "board.h"
#include "ships.h"

#define DIRS 4

enum dirs {
  U = 0,
  R,
  D,
  L
};

int shoot(element_t board[][TAM], element_t ships[], const char* player);
int isEmpty(element_t c);
element_t coordinates(element_t board[][TAM], chute_t c);
int isPositionShooted(element_t c); 

#endif
