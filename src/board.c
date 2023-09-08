#include "board.h"
#include "globconst.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void assign(element_t* dest, element_t origin) {
  dest->tam = origin.tam;
  dest->type = origin.type;
  dest->dir = origin.dir;
}

int isEqual(element_t e1, element_t e2) {
  return e1.tam == e2.tam &&
          e1.type == e2.type && 
          e1.dir == e2.dir;
}

void initBoard(element_t board[][TAM], size_t size) {
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      assign(&board[i][j], (element_t)WATER); 
    }
  }
}

int isValid(element_t board[][TAM], element_t e, int x, int y) {
  for(int i = 0; i < SHIP.tam; i++) {
    if(SHIP.dir == 'H' && !isEqual(board[x][y+i], WATER)) {
      return 0;
    }
    else if(SHIP.dir == 'V' && !isEqual(board[x+i][y], WATER)) {
      return 0;
    }
    else if(SHIP.dir == 'N' && !isEqual(board[x][y], WATER)) {
      return 0;
    }
  }

  return 1;
}

void putShips(element_t board[][TAM]) {
    for (int i = 0; i < SHIPS; i++) {
        int x, y; //coordenadas x e y
        int length = SHIP.tam;

        int xlimit, ylimit;

        if(SHIP.dir == 'H') {
          xlimit = TAM;
          ylimit = TAM - length + 1;
        }
        else if(SHIP.dir == 'V') {
          xlimit = TAM - length + 1;
          ylimit = TAM;
        }
        else if(SHIP.dir == 'N') {
          xlimit = TAM;
          ylimit = TAM;
        }

        do {
            x = rand() % xlimit;
            y = rand() % ylimit;
        } while(!isValid(board, SHIP, x, y));

        for(int j = 0; j < SHIP.tam; j++) {
            if(SHIP.dir == 'H')
              assign(&board[x][y+j], SHIP);
            else
              assign(&board[x+j][y], SHIP);
        }
    }
}
