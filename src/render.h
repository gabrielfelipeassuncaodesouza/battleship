#ifndef _H_RENDER
#define _H_RENDER

#include "board.h"
#include "ships.h"

void clearscr();
void stop();
void printBothBoards(element_t player[][TAM], element_t ia[][TAM], placar p);
void boardRender(element_t board[][TAM]);
//void enemyRender(element_t board[][TAM]);
void printDelay(const char* text, unsigned int milsecs);
void printTypeWriter(const char *text);

#endif
