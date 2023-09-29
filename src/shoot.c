#include "board.h"
#include "human.h"
#include "ia.h"
#include "render.h"
#include "ships.h"
#include "shoot.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPositionShooted(element_t c) {
  return (isEqual(c, ERROR) || isEqual(c, ASSERT));   
}

element_t coordinates(element_t board[][TAM], chute_t c) {
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
  static stack_t* lastHits = NULL; 

  s = iaChute(player, &lastHits);  
  element_t result = coordinates(player, s);

  if(isEqual(result, WATER)) {
    printError(" ERROU :(\n");
    assign(&player[s.x][s.y], ERROR);
  }
  else {
    printSucess(" ACERTOU :D\n");
    assign(&player[s.x][s.y], ASSERT); 
  
    getNeighbours(player, &lastHits, s);
  
    if(isShipDestroyed(player, ships, result, s)) {
      while(lastHits != NULL)
        rem(&lastHits);

      return 2;
    }
    return 1;
  }
  return 0;
}

int playerShoot(element_t player[][TAM], element_t ia[][TAM], element_t ships[], placar p) {
  chute_t s;

  s = humanShoot(player, ia, p);
  element_t result = coordinates(ia, s);

  if(isEqual(result, WATER)) {
    printError("\n\tERROU :(\n");
    assign(&ia[s.x][s.y], ERROR);
  }
  else {
    printSucess("\n\tACERTOU :D\n");
    assign(&ia[s.x][s.y], ASSERT); 
  
    if(isShipDestroyed(ia, ships, result, s)) {
      return 2;
    }   
    return 1;
  }
  return 0;
}