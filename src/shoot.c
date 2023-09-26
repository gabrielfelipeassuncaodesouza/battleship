#include "board.h"
#include "human.h"
#include "ia.h"
#include "queue.h"

#include "render.h"

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
  chute_t s; //variable that guards the guess

  static queue_t* lastHits = NULL; //queueu that storages the positions hitted to look for around them
  static queue_t* tail = NULL; //auxiliar pointer of the queue

  static chute_t neigh[4]; //neighbours of position shooted
  static int i = 0; //i it's the flag that indicates which position around the hit the ia is guessing
  static int i_lim = 4; //limit of neighbours dependending of the valid positions
  static int hitted = 0; //verify if hitted a position

  if(strcmp(player, "ia") == 0) { 
    if(!i) { //first execution 
      i_lim = getNeighbours(board, neigh, lastHits);
    }

    s = iaChute(board, neigh, i, hitted);
  }
  else {
    s = humanShoot(board);
  }

  element_t result = coordinates(board, s);

  if(isEqual(result, WATER)) {
    printf("\nAGUA!!\n\n");
    assign(&board[s.x][s.y], ERROR);

    if(strcmp(player, "ia") == 0) {
      i++; //increment the pos;
      if(i == i_lim) {
        printf("You have hitted all around the hit\n");
        pause();
      }
    }
  }
    
  else {
    printf("\nBOMBA!!\n\n");
    assign(&board[s.x][s.y], ASSERT); 
  
    if(strcmp(player, "ia") == 0) {
      hitted = 1;
      rem(&lastHits);
      add(&lastHits, &tail, s);
      i_lim = getNeighbours(board, neigh, lastHits);
      i = 0;
    }

    if(isShipDestroyed(board, ships, result, s)) {
      if(strcmp(player, "ia") == 0) {
        hitted = 0;
        lastHits = NULL;
      }
      return 1;
    }
  }
  return 0;
}
