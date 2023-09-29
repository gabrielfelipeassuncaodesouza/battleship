#include "board.h"
#include "render.h"
#include "ships.h"
#include "shoot.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void clearscr() {
    printf("\x1b[2J");
    printf("\x1b[H");
}

void stop() {
  printf("\tPress enter to continue... ");
  getchar();
}

void printDelay(const char* text, unsigned int milsecs) {
  printf(text); usleep(milsecs*1000);
}

void printTypeWriter(const char *text) {
  for(int i = 0; text[i] != '\0'; i++) {
    int delay = rand() % 150;
    putchar(text[i]);
    fflush(stdout);
    usleep(delay*1000);
  }
}

void printBothBoards(element_t player[][TAM], element_t ia[][TAM], placar p) {
  printf("\n\x1b[41m\t\t\t\t\tPLACAR: %d x %d\n\x1b[m", p.player, p.ia);

  printf("\n\t\t\tPlayer\t\t\t\t\t\tIA\n\n\t\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  printf("\t\t\t\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  printf("\n\n");

  for(int i = 0; i < TAM; i++) {
    printf("\t%c\t", 'A'+i);
    for(int j = 0; j < TAM; j++) {
      char * color = (isEqual(player[i][j], ERROR)) ? "\x1b[34m" : (isEqual(player[i][j], ASSERT)) ? "\x1b[31m" : "";

      printf("%s%c\x1b[m ", color, player[i][j].type);
    }

    printf("\t\t");

    printf("\t%c\t", 'A'+i);
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
  printf("\n\n");

  for(int i = 0; i < TAM; i++) {
    printf("\t%c\t", 'A'+i);
    for(int j = 0; j < TAM; j++) {

      char * color = (isEqual(board[i][j], ERROR)) ? "\x1b[34m" : (isEqual(board[i][j], ASSERT)) ? "\x1b[31m" : "";

      printf("%s%c\x1b[m ", color, board[i][j].type);
    }
    putchar('\n');
  }
}

/** Unused function
void enemyRender(element_t board[][TAM]) {  
  printf("\n\t\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  printf("\n\n");

  for(int i = 0; i < TAM; i++) {
    printf("\t%c\t", 'A'+i);
    for(int j = 0; j < TAM; j++) {

      char * color = (isEqual(board[i][j], ERROR)) ? "\x1b[34m" : (isEqual(board[i][j], ASSERT)) ? "\x1b[31m" : "";

      printf("%s%c\x1b[m ", color, isPositionShooted(board[i][j]) ? board[i][j].type : WATER.type);
    }
    putchar('\n');
  }
}
**/
