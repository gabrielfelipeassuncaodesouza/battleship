#ifndef _H_SHOOT
#define _H_SHOOT

#include "board.h"
#include "human.h"

int shoot(char board[][TAM], const char* player);
int isEmpty(char c);
char coordinates(char board[][TAM], chute_t c);

#endif
