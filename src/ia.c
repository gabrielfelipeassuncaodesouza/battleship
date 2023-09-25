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

void getNeighbours(element_t board[][TAM], chute_t neigh[], chute_t pos) {
  neigh[0] = (chute_t){ pos.x, ((pos.y+1) % TAM) };
  neigh[1] = (chute_t){ ((pos.x+1) % TAM), pos.y };
  neigh[2] = (chute_t){ pos.x, abs(pos.y-1)};
  neigh[3] = (chute_t){ abs(pos.x-1), pos.y};
}