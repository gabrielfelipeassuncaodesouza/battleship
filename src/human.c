#include "board.h"
#include "render.h"
#include "ships.h"
#include "human.h"
#include "shoot.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int isFormatValid(char shoot[3]) { //check if the move typed by the user is valid
  if(!isalpha(shoot[0]) || !isdigit(shoot[1])) {
    return 0;
  }

  if(tolower(shoot[0]) < 'a' || tolower(shoot[0]) > 'a' + (TAM-1)) {
    return 0;
  }

  int y;
  sscanf(&shoot[1], "%d", &y);

  if(y < 1 || y > TAM) {
    return 0;
  }

  return 1;
}

chute_t strToChute(char buf[4]) { //convert the move to a valid move struct
  chute_t c;
  c.x = (int)(tolower(buf[0])) - 97;
  c.y = atoi(&buf[1]) - 1;

  return c;
}

char playerDir(void) {
  char dir;

  while(1) {
    printf("\n\tDigite a direção do navio (H = Horizontal V = Vertical): \n");
    printf("\tOu digite r para posicionar todos os navios randomicamente: ");
    scanf("%c", &dir);
    while(getchar() != '\n');

    if(toupper(dir) != 'H' && toupper(dir) != 'V' && toupper(dir) != 'R') {
      printf("\x1b[3A");
      printf("\x1b[3M");

      printError("\tOpção inválida\n");
      usleep(500000);
      printf("\x1b[1A");
      printf("\x1b[1M");

      continue;
    }
    else break;
  }
  return toupper(dir);
}

chute_t playerPut(int xlimit, int ylimit) {
  char buf[4];
  chute_t c;

  while(1) {
    printf("\n\tDigite as coordenadas do navio: ");
    scanf("%s", buf);
    while(getchar() != '\n');

    c = strToChute(buf);

    if(!isFormatValid(buf) || (c.x >= xlimit || c.y >= ylimit)) {
      printf("\x1b[2A");
      printf("\x1b[2M");

      printError("\tCoordenada inválida\n");
      usleep(500000);
      printf("\x1b[1A");
      printf("\x1b[1M");

      continue;
    }
    else break;
  }

  return c;
}

chute_t humanShoot(element_t player[][TAM], element_t ia[][TAM], placar p) {
  char buf[4];
  chute_t chute;

  while(1) {
    printBothBoards(player, ia, p);
    printf("\n\tDigite as coordenadas do tiro: ");
    scanf("%s", buf);
    while(getchar() != '\n');

    if(!isFormatValid(buf)) {
      clearscr();
      printError("\n\tCoordenada inválida!\n"); 
      continue;
    }

    chute = strToChute(buf);

    if(!isPositionShooted(coordinates(ia, chute))) break;
    else {
      clearscr();
      printError("\n\tCoordenada inválida\n");
    }
  }

  clearscr();
  return chute;
}