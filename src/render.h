#ifndef _H_RENDER
#define _H_RENDER

#include "board.h"
#include "ships.h"

void clearscr();
void printBothBoards(element_t player[][TAM], element_t ia[][TAM], placar p);
void boardRender(element_t board[][TAM]);
void enemyRender(element_t board[][TAM]);
void pause();

#endif
