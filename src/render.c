#include "board.h"
#include "render.h"
#include "ships.h"
#include "shoot.h"

#include <stdio.h>

void clearscr() {
    printf("\x1b[2J");
    printf("\x1b[H");
}

void pause() {
  printf("\tPress enter to continue... ");
  getchar();
}

void printBothBoards(element_t player[][TAM], element_t ia[][TAM]) {
  printf("\n\t\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  printf("\t\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  putchar('\n');

  for(int i = 0; i < TAM; i++) {
    printf("\t%c\t", 'A'+i);
    for(int j = 0; j < TAM; j++) {

      char * color = (isEqual(player[i][j], ERROR)) ? "\x1b[34m" : (isEqual(player[i][j], ASSERT)) ? "\x1b[31m" : "";

      printf("%s%c\x1b[m ", color, player[i][j].type);
    }

    printf("\t\t");

    for(int j = 0; j < TAM; j++) {

      char * color = (isEqual(ia[i][j], ERROR)) ? "\x1b[34m" : (isEqual(ia[i][j], ASSERT)) ? "\x1b[31m" : "";

      printf("%s%c\x1b[m ", color, isPositionShooted(ia[i][j]) ? ia[i][j].type : WATER.type);
    }
    putchar('\n');
  }
}

void boardRender(element_t board[][TAM]) {  
  printf("\n\t\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  putchar('\n');

  for(int i = 0; i < TAM; i++) {
    printf("\t%c\t", 'A'+i);
    for(int j = 0; j < TAM; j++) {

      char * color = (isEqual(board[i][j], ERROR)) ? "\x1b[34m" : (isEqual(board[i][j], ASSERT)) ? "\x1b[31m" : "";

      printf("%s%c\x1b[m ", color, board[i][j].type);
    }
    putchar('\n');
  }
}

void enemyRender(element_t board[][TAM]) {  
  printf("\n\t\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  putchar('\n');

  for(int i = 0; i < TAM; i++) {
    printf("\t%c\t", 'A'+i);
    for(int j = 0; j < TAM; j++) {

      char * color = (isEqual(board[i][j], ERROR)) ? "\x1b[34m" : (isEqual(board[i][j], ASSERT)) ? "\x1b[31m" : "";

      printf("%s%c\x1b[m ", color, isPositionShooted(board[i][j]) ? board[i][j].type : WATER.type);
    }
    putchar('\n');
  }
}