#include "shoot.h"
#include "human.h"
#include <stdio.h>
#include <stdlib.h>

//TODO: change the type of the value of the struct to all int

int isValid(char c) {
    return c != ERROR && c != ASSERT;
}

char coordinates(char board[][TAM], chute_t c) {
  int x = (int)(c.x - 'a'), y = c.y;

  return board[x][y];
}

chute_t iaChute(char board[][TAM]) {
  chute_t chute;

  do {
    chute.x = 'A'+ rand() % (TAM-1);
    chute.y = rand() % TAM;
  } while(!isValid(coordinates(board, chute)));

  return chute;
}

int shoot(char board[][TAM]) {
    chute_t s = iaChute(board);
    char result = coordinates(board, s);

    if(result == WATER) {
        printf("\nAGUA!!\n\n");
        board[(int)(s.x - 'a')][s.y] = ASSERT;
    }

    else if(result == SHIP) {
        printf("\nBOMBA!!\n\n");
        board[(int)(s.x - 'a')][s.y] = ERROR;
        return 1;
    }
    else {
      printf("\nError\n\n");
    } 

    return 0;
}
