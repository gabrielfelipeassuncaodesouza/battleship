#include "shoot.h"
#include "board.h"
#include "globconst.h"
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

    else if(isEqual(result, SHIP)) {
        printf("\nBOMBA!!\n\n");
        assign(&board[s.x][s.y], ERROR);
        return 1;
    }
    else {
      printf("\nError\n\n");
    } 

    return 0;
}
