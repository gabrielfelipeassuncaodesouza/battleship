#include "board.h"
#include "human.h"
#include "ia.h"
#include "ships.h"
#include "shoot.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPositionShooted(element_t c) {
    if(isEqual(c, PASS)) return 1;
    
    return isEqual(c, ERROR) || isEqual(c, ASSERT);
}

element_t coordinates(element_t board[][TAM], chute_t c) {
  if(c.x == -1 && c.y == -1) return PASS;

  return board[c.x][c.y];
}

int isShipDestroyed(element_t board[][TAM], element_t ships[], element_t e, chute_t c) {
  int tam = e.tam;
  chute_t shipStart = {
    c.x,
    c.y
  }; //coordenada onde começa o navio;
  
  for(int i = 0; i < SHIPS; i++) {
    if(ships[i].type == e.type) {
      if(e.dir == 'H') {
        shipStart.y = c.y - (ships[i].tam - tam);
      }
      else {
        shipStart.x = c.x - (ships[i].tam - tam);
      }
      tam = ships[i].tam;
      break;
    }
  }

  for(int i = 0; i < tam; i++) {
    if(e.dir == 'H') {
      if(isEqual(board[shipStart.x][shipStart.y+i], e)) {
        return 0;
      }
    }
    else {
      if(isEqual(board[shipStart.x+i][shipStart.y], e)) {
        return 0;
      }
    }
  }
  return 1;
}

int iaShoot(element_t player[][TAM], element_t ships[]) {
  chute_t s;
  static queue_t* lastHits = NULL; 
  static queue_t* tail = NULL;

  s = iaChute(player, &lastHits);  
  element_t result = coordinates(player, s);

  if(isEqual(result, WATER)) {
    printf("\n\tAGUA!!\n\n");
    assign(&player[s.x][s.y], ERROR);
  }
  else {
    printf("\n\tBOMBA!!\n\n");
    assign(&player[s.x][s.y], ASSERT); 
  
    getNeighbours(player, &lastHits, &tail, s);
  
    if(isShipDestroyed(player, ships, result, s)) {
      while(lastHits != NULL)
        rem(&lastHits);

      return 2;
    }
    return 1;
  }
  return 0;
}

int playerShoot(element_t player[][TAM], element_t ia[][TAM], element_t ships[]) {
  chute_t s;

  s = humanShoot(player, ia);
  element_t result = coordinates(player, s);

  if(isEqual(result, WATER)) {
    printf("\n\tAGUA!!\n\n");
    assign(&ia[s.x][s.y], ERROR);
  }
  else {
    printf("\n\tBOMBA!!\n\n");
    assign(&ia[s.x][s.y], ASSERT); 
  
    if(isShipDestroyed(ia, ships, result, s)) return 2;
         
    return 1;
  }
  return 0;
}