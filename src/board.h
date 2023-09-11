#ifndef _H_BOARD
#define _H_BOARD

#include "ships.h"
#include <stddef.h>

#define TAM 10

#define WATER (element_t){1, '~', 'N'}
#define ERROR (element_t){1, 'E', 'N'}
#define ASSERT (element_t){1, 'A', 'N'}

void assign(element_t* dest, element_t origin); 
int isEqual(element_t e1, element_t e2);
void initBoard(element_t board[][TAM], size_t size);
void putShips(element_t board[][TAM], element_t ships[SHIPS]);

#endif