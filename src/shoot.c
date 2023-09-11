#include "shoot.h"
#include "board.h"
#include "ships.h"
#include "human.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isEmpty(element_t c) {
    return !isEqual(c, ERROR) && !isEqual(c, ASSERT);
}

element_t coordinates(element_t board[][TAM], chute_t c) {
  return board[c.x][c.y];
}

chute_t iaChute(element_t board[][TAM]) {
  chute_t chute;

  do {
    chute.x = rand() % TAM;
    chute.y = rand() % TAM;
  } while(!isEmpty(coordinates(board, chute)));

  return chute;
}

int isShipDestroyed(element_t board[][TAM], element_t e, chute_t c) {
  for(int i = 0; i < e.tam; i++) {
    if(e.dir == 'H') {

      if(c.y-i < 0) break;
      if(c.y+i >= TAM) break;

      if(isEqual(board[c.x][c.y+i], e) || isEqual(board[c.x][c.y-i], e)) { //!fix here
        return 0;
      }
    }
    else if(e.dir == 'V') {

      if(c.x-i < 0) break;
      if(c.x+i >= TAM) break;

      if(!isEqual(board[c.x+i][c.y], e)) { //!fix here
        return 0;
      }
    }
  }
  return 1;
}

int shoot(element_t board[][TAM], const char* player) {
    chute_t s;
    if(strcmp(player, "ia") == 0) { 
      s = iaChute(board);
    }
    else {
      s = humanShoot(board);
    }

    element_t result = coordinates(board, s);

    if(isEqual(result, WATER)) {
        printf("\nAGUA!!\n\n");
        assign(&board[s.x][s.y], ASSERT);
    }

    else if(isEqual(result, SUBMARIN)) { //fix here
        printf("\nBOMBA!!\n\n");
        assign(&board[s.x][s.y], ERROR);
        
        if(isShipDestroyed(board, SUBMARIN, s)) {
          return 1;
        }
    }
    else {
      printf("\nError\n\n");
    } 

    return 0;
}