#ifndef _H_RENDER
#define _H_RENDER

#include "board.h"
#include "ships.h"

void clearscr();
void stop();
void printBothBoards(element_t player[][TAM], element_t ia[][TAM], placar p);
void boardRender(element_t board[][TAM]);

void printDelay(const char* text, unsigned int milsecs);
void printTypeWriter(const char *text);
void printError(const char* text);
void printSucess(const char* text);

#endif