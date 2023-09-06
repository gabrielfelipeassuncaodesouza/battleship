#include "board.h"
#include "human.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int isShootValid(char shoot[3]) {
  if(!isalpha(shoot[0]) || !isdigit(shoot[1])) {
    printf("Coordenada inválida!\n");
    return 0;
  }

  if(tolower(shoot[0]) < 'a' || tolower(shoot[0]) > 'a' + (TAM-1)) {
    printf("Coordenada inválida!\n");
    return 0;
  }

  int y;
  sscanf(&shoot[1], "%d", &y);

  if(y < 1 || y > TAM) {
    printf("Coordenada inválida!\n");
    return 0;
  }

  return 1;
}

void humanShoot(char board[][TAM]) {
  chute_t chute;

  char buf[4];
  do {
    printf("Digite as coordenadas do chute: ");
    scanf("%s", buf);

    while(getchar() != '\n');

  } while(!isShootValid(buf));

  chute.x = (int)(tolower(buf[0])) - 97;
  printf("the x coordinate is %d\n", chute.x);

  int y;
  sscanf(&buf[1], "%d", &y);
  chute.y = y;

  printf("You choose %d%d\n", chute.x, chute.y);
}
