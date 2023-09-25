#include "board.h"
#include "ia.h"
#include "ships.h"
#include "shoot.h"

#include <stdlib.h>

chute_t iaChute(element_t board[][TAM], chute_t lastHit, int lastDir, int hitted) {
  chute_t chute;
  static int tries = -1;

  if(tries > 0) {
    lastDir = (lastDir + 1) % DIRS;
  }

  if(tries == 4) {
    hitted = 0;
  }

  do {
    if(!hitted) {
      chute.x = rand() % TAM;
      chute.y = rand() % TAM;
    }
    else {
      tries++;
      chute = huntAndTarget(board, lastHit, lastDir);
    }
  } while(isPositionShooted(coordinates(board, chute)));
  //TODO: this verification may need outside the function

  tries = -1;
  return chute;
}

chute_t huntAndTarget(element_t board[][TAM], chute_t lastHit, int lastDir) {
  chute_t chute = lastHit;

  if(lastDir == U) {
    chute.x = (chute.x - 1) % TAM;
  }
  else if(lastDir == R) {
    chute.y = (chute.y + 1) % TAM;
  }
  else if(lastDir == D) {
    chute.x = (chute.x + 1) % TAM;
  }
  else if(lastDir == L) {
    chute.y = (chute.y - 1) % TAM;
  }

  return chute;
}
