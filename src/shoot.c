#include "shoot.h"
#include "human.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isEmpty(char c) {
    return c != ERROR && c != ASSERT;
}

char coordinates(char board[][TAM], chute_t c) {
  return board[c.x][c.y];
}

chute_t iaChute(char board[][TAM]) {
  chute_t chute;

  do {
    chute.x = rand() % TAM;
    chute.y = rand() % TAM;
  } while(!isEmpty(coordinates(board, chute)));

  return chute;
}

int shoot(char board[][TAM], const char* player) {

    chute_t s;
    if(strcmp(player, "ia") == 0) { 
      s = iaChute(board);
    }
    else {
      s = humanShoot(board);
    }

    char result = coordinates(board, s);

    if(result == WATER) {
        printf("\nAGUA!!\n\n");
        board[s.x][s.y] = ASSERT;
    }

    else if(result == SHIP) {
        printf("\nBOMBA!!\n\n");
        board[s.x][s.y] = ERROR;
        return 1;
    }
    else {
      printf("\nError\n\n");
    } 

    return 0;
}
