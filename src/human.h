#ifndef _H_HUMAN
#define _H_HUMAN

#include "board.h"

typedef struct {
  int x;
  int y;
} chute_t;

int isShootValid(char shoot[3]);
void humanShoot(char board[][TAM]);

#endif
