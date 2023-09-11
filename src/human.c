#include "board.h"
#include "ships.h"
#include "human.h"
#include "shoot.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

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

chute_t humanShoot(element_t board[][TAM]) {
  char buf[4];
  chute_t chute;

  while(1) {
    printf("Digite as coordenadas do chute: ");
    scanf("%s", buf);
    while(getchar() != '\n');

    if(!isFormatValid(buf)) {
      printf("Coordenada inválida!\n");
      continue;
    }
    chute = strToChute(buf);

    printf("\nYou choose %d %d\n", chute.x, chute.y);

    if(isEmpty(coordinates(board, chute))) break;
  }
  return chute;
}