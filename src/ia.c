#include "board.h"
#include "ia.h"
#include "queue.h"
#include "ships.h"
#include "shoot.h"

#include <stdlib.h>

chute_t iaChute(element_t board[][TAM], queue_t** hits) {
  chute_t chute;

  do {
    if(*hits == NULL) {
      chute.x = rand() % TAM;
      chute.y = rand() % TAM;
    }
    else {
      chute = (*hits)->hit;
      rem(hits);
    }
  } while(isPositionShooted(coordinates(board, chute)));

  return chute;
}

void getNeighbours(element_t board[][TAM], queue_t** hits, queue_t** tail, chute_t pos) {

  if(pos.y < TAM - 1)
    add(hits, tail, (chute_t){ pos.x, pos.y+1 });
  
  if(pos.x < TAM - 1)
    add(hits, tail, (chute_t){ pos.x+1, pos.y });
  
  if(pos.y > 0)
    add(hits, tail, (chute_t){ pos.x, pos.y-1 });
  
  if(pos.x > 0)
    add(hits, tail, (chute_t){ pos.x-1, pos.y }); 
}
