#ifndef _H_HUMAN
#define _H_HUMAN

#include "board.h"

int isFormatValid(char shoot[3]);
chute_t humanShoot(element_t board[][TAM]);
chute_t strToChute(char buf[4]);

#endif