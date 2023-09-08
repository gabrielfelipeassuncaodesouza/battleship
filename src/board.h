#ifndef _H_BOARD
#define _H_BOARD

#include "globconst.h"
#include <stddef.h>

#define TAM 5

#define WATER {'~', 'N'}
#define ERROR {'E', 'N'}
#define ASSERT {'A', 'N'}

void assign(element_t* dest, element_t origin); 
int isEqual(element_t e1, element_t e2);
void initBoard(element_t board[][TAM], size_t size);
void putShips(element_t board[][TAM]);

#endif
