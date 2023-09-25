#include "board.h"
#include "ia.h"
#include "ships.h"
#include "shoot.h"

#include <stdlib.h>

chute_t iaChute(element_t board[][TAM], chute_t* neighbours, int i, int hitted) {
  chute_t chute;
  
  int tries = 0;

  do {
    if(tries >= 4) hitted = 0;

    if(!hitted) {
      chute.x = rand() % TAM;
      chute.y = rand() % TAM;
    }
    else {
      tries++;
      chute = neighbours[i++];
    }
  } while(isPositionShooted(coordinates(board, chute)));

  return chute;
}

chute_t* getNeighbours(element_t board[][TAM], chute_t pos) {
  chute_t* neigh = (chute_t*)malloc(sizeof(chute_t) * 4);

  int i = 0;

  if(pos.x + 1 < TAM) {
    neigh[i++] = (chute_t){ pos.x+1, pos.y};
  }
  if(pos.x - 1 > 0) {
    neigh[i++] = (chute_t){ pos.x-1, pos.y};
  }
  if(pos.y + 1 < TAM) {
    neigh[i++] = (chute_t){ pos.x, pos.y+1};
  }
  if(pos.y - 1 > 0) {
    neigh[i++] = (chute_t){ pos.x, pos.y-1};
  }

  while(i < 3) {
    neigh[i++] = (chute_t){ rand() % TAM, rand() % TAM };
  }

  return neigh;
}