#ifndef _H_RENDER
#define _H_RENDER

#include "board.h"
#include "ships.h"

void clearscr();
void debugRender(element_t board[][TAM]);
void renderBoard(element_t board[][TAM]);
void printPart(char draw[5][15], int part);

#endif
