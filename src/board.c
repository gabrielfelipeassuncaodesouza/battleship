#include "board.h"
#include "globconst.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void assign(element_t* dest, element_t origin) {
  dest->type = origin.type;
  dest->dir = origin.dir;
}

int isEqual(element_t e1, element_t e2) {
  return e1.type == e2.type && e1.dir == e2.dir;
}

void initBoard(element_t board[][TAM], size_t size) {
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      assign(&board[i][j], (element_t)WATER); 
    }
  }
}

void putShips(element_t board[][TAM]) {
    for (int i = 0; i < SHIPS; i++)
    {
        int x, y;
        do
        {
            x = rand() % TAM;
            y = rand() % TAM;
        } while(isEqual(board[x][y], (element_t)SHIP));

        assign(&board[x][y], (element_t)SHIP);
    }
}
