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
  printf("Press any key to continue... ");
  getchar();
}

void boardRender(element_t board[][TAM]) {  
  printf("\n\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  putchar('\n');

  for(int i = 0; i < TAM; i++) {
    printf("%c\t", 'A'+i);
    for(int j = 0; j < TAM; j++) {

      char * color = (isEqual(board[i][j], ERROR)) ? "\x1b[34m" : (isEqual(board[i][j], ASSERT)) ? "\x1b[31m" : "";

      printf("%s%c\x1b[m ", color, board[i][j].type);
    }
    putchar('\n');
  }
}

void enemyRender(element_t board[][TAM]) {  
  printf("\n\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  putchar('\n');

  for(int i = 0; i < TAM; i++) {
    printf("%c\t", 'A'+i);
    for(int j = 0; j < TAM; j++) {

      char * color = (isEqual(board[i][j], ERROR)) ? "\x1b[34m" : (isEqual(board[i][j], ASSERT)) ? "\x1b[31m" : "";

      printf("%s%c\x1b[m ", color, isPositionShooted(board[i][j]) ? board[i][j].type : WATER.type);
    }
    putchar('\n');
  }
}
