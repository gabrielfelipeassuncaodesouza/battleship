#include "board.h"
#include "ia.h"
#include "ships.h"
#include "shoot.h"

#include <stdlib.h>

chute_t iaChute(element_t board[][TAM], chute_t neighbours[], int i, int hitted) {
  chute_t chute;
  
  int tries = 0;

  do {
    if(tries >= 8) hitted = 0;

    if(!hitted) {
      chute.x = rand() % TAM;
      chute.y = rand() % TAM;
    }
    else {
      tries++;
      chute = neighbours[i];
      i = (i+1) % 4;
    }
  } while(isPositionShooted(coordinates(board, chute)));

  return chute;
}

int getNeighbours(element_t board[][TAM], chute_t neigh[], queue_t* head) {
  chute_t pos;
  int qtde = 4;

  if(head == NULL) {
    pos = (chute_t){0, 0};
    return 1;
  }
  else {
    pos = head->hit;
  }

  neigh[0] = (chute_t){ pos.x, pos.y+1 };
  neigh[1] = (chute_t){ pos.x+1, pos.y };
  neigh[2] = (chute_t){ pos.x, pos.y-1 };
  neigh[3] = (chute_t){ pos.x-1, pos.y };

  if(pos.y == TAM - 1) { //se estiver na parede direita
    neigh[0] = neigh[1];
    neigh[1] = (chute_t){ -1, -1 };
    qtde--;
  }

  if(pos.x == TAM - 1) { // se estiver em baixo
    neigh[1] = neigh[2];
    neigh[2] = (chute_t){ -1, -1 };
    qtde--;
  }

  if(pos.y == 0) { //se estiver na parede esquerda
    neigh[2] = neigh[3];
    neigh[3] = (chute_t){ -1, -1 };
    qtde--;
  }

  if(pos.x == 0) { // se estiver em cima
    neigh[3] = (chute_t){ -1, -1 };
    qtde--;
  }

  return qtde;
}
