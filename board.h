#ifndef _H_BOARD
#define _H_BOARD

#include <stddef.h>

#define TAM 5

#define WATER '~'
#define SHIP 'N'
#define ERROR 'E'
#define ASSERT 'A'

void initBoard(char board[][TAM], size_t size);
void putShips(char board[][TAM]);

#endif