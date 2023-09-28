#ifndef _H_HUMAN
#define _H_HUMAN

#include "board.h"

int isFormatValid(char shoot[3]);
chute_t humanShoot(element_t player[][TAM], element_t ia[][TAM], placar p);
chute_t strToChute(char buf[4]);
char playerDir(void);
chute_t playerPut(int xlimit, int ylimit);

#endif
