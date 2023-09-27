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

int shoot(element_t board[][TAM], element_t ships[], const char* player) {
  chute_t s;
  static queue_t* lastHits = NULL; 
  static queue_t* tail = NULL;

  if(strcmp(player, "ia") == 0) {
    s = iaChute(board, &lastHits);
  }
  else {
    s = humanShoot(board);
  }

  element_t result = coordinates(board, s);

  if(isEqual(result, WATER)) {
    printf("\nAGUA!!\n\n");
    assign(&board[s.x][s.y], ERROR);
  }
  else {
    printf("\nBOMBA!!\n\n");
    assign(&board[s.x][s.y], ASSERT); 
  
    if(strcmp(player, "ia") == 0) {
      getNeighbours(board, &lastHits, &tail, s);
    }
  
    if(isShipDestroyed(board, ships, result, s)) {
      
      while(lastHits != NULL)
        rem(&lastHits);

      return 2;
    }
    return 1;
  }
  return 0;
}
