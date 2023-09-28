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

int iaShoot(element_t player[][TAM], element_t ships[]);
int playerShoot(element_t player[][TAM], element_t ia[][TAM], element_t ships[]);
int isEmpty(element_t c);
element_t coordinates(element_t board[][TAM], chute_t c);
int isPositionShooted(element_t c); 

#endif
