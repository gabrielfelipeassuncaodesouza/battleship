#include "board.h"
#include "human.h"
#include "ships.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

/** Verification functions **/

int isEqual(element_t e1, element_t e2) {
  return  e1.type == e2.type && 
          e1.dir == e2.dir;
}

int isValid(element_t board[][TAM], element_t e, chute_t c) {
  //* Refactor this code (it is not eficient)
  for(int i = 0; i < e.tam; i++) { //fix here
    if(e.dir == 'H' && !isEqual(board[c.x][c.y+i], WATER)) { 
      return 0;
    }
    else if(e.dir == 'V' && !isEqual(board[c.x+i][c.y], WATER)) {
      return 0;
    }
  }

  return 1;
}

/** Init functions **/

void assign(element_t* dest, element_t origin) {
  dest->tam = origin.tam;
  dest->type = origin.type;
  dest->dir = origin.dir;
}

void initBoard(element_t board[][TAM], size_t size) {
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      assign(&board[i][j], WATER); 
    }
  }
}

void putShips(element_t board[][TAM], element_t ships[SHIPS]) {
    for (int i = 0; i < SHIPS; i++) {
        int x, y; //coordenadas x e y
        int length = ships[i].tam;

        //int orient = rand() % 2;
        //ships[i].dir = (orient == 0) ? 'H' : 'V';

        int xlimit = TAM, ylimit = TAM;

        if(ships[i].dir == 'H') {
          ylimit = TAM - length + 1;
        }
        else if(ships[i].dir == 'V') {
          xlimit = TAM - length + 1;
        }

        chute_t c;
        do {
            x = rand() % xlimit;
            y = rand() % ylimit;
        } while(!isValid(board, ships[i], (chute_t){x, y}));

        //* Improve and refactor this function (it is not eficient)
        for(int j = 0; j < ships[i].tam; j++) {
            if(ships[i].dir == 'H')
              assign(&board[x][y+j], (element_t){ length--, ships[i].type, ships[i].dir });
            else
              assign(&board[x+j][y], (element_t){ length--, ships[i].type, ships[i].dir});
        }
    }
}