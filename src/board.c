#include "board.h"
#include "human.h"
#include "ia.h"
#include "render.h"
#include "ships.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/** Verification functions **/

int isEqual(element_t e1, element_t e2) {
  return  e1.type == e2.type && 
          e1.dir == e2.dir;
}

int isValid(element_t board[][TAM], element_t e, chute_t c) {
  int i;
  int zero = 0;
        
  int* incr1;
  int* incr2;

  if(e.dir == 'H') {
    incr1 = &zero;
    incr2 = &i;
  }
  else {
    incr1 = &i;
    incr2 = &zero;
  }

  for(i = 0; i < e.tam; i++) {
    if(!isEqual(board[c.x + *incr1][c.y + *incr2], WATER)) {
      printf("\n\tCoordenada inválida\n"); 
      return 0;
    }
  }
  return 1;
}

/** Init functions **/

void assign(element_t* dest, element_t origin) {
  dest->tam = origin.tam;
  dest->type = origin.type;
  dest->dir = origin.dir;
}

void initBoard(element_t board[][TAM], size_t size) {
  for(int i = 0; i < TAM; i++) {
    for(int j = 0; j < TAM; j++) {
      assign(&board[i][j], WATER); 
    }
  }
}

void printNameOfShip(element_t ship) {
  if(isEqual(ship, AIRCRAFT)) {
    printf("\n\tPosicione seu porta-aviões\n");
  }
  else if(isEqual(ship, TANKER)) {
    printf("\n\tPosicione seus dois navios-tanque\n");
  }
  else if(isEqual(ship, DESTROYER)) {
    printf("\n\tPosicione seus dois contratorpedeiros\n");
  }
  else if(isEqual(ship, SUBMARIN)) {
    printf("\n\tPosicione seus três submarinos\n");
  }
}

void putShips(element_t board[][TAM], element_t ships[SHIPS], int who) {
    for (int i = 0; i < SHIPS; i++) {
        int length = ships[i].tam;
        char orient = 'N';

        if(who == PLAYER_TURN) {
          clearscr();
          printf("\n\t\tTabuleiro atual:\n\n");
          boardRender(board);

          printNameOfShip(ships[i]);
        }

        chute_t c;
        int xlimit = TAM, ylimit = TAM;

        do {
          if(length > 1) {
            if(who == IA_TURN)
              orient = iaDir();
            else {
              orient = playerDir();

              if(orient == 'R') {
                orient = iaDir();
                who = IA_TURN;
              }
            }
          }

          ships[i].dir = orient;
          
          if(ships[i].dir == 'H') {
            ylimit = TAM - length + 1;
          }
          else if(ships[i].dir == 'V') {
            xlimit = TAM - length + 1;
          }

          if(who == IA_TURN) {
            c = iaPut(xlimit, ylimit);
          } else {
            c = playerPut(xlimit, ylimit);
          }
        } while(!isValid(board, ships[i], c));

        int zero = 0;
        int j;
        int* incr1;
        int* incr2;

        if(ships[i].dir == 'H') {
          incr1 = &zero;
          incr2 = &j;
        }
        else {
          incr1 = &j;
          incr2 = &zero;
        }

        for(j = 0; j < ships[i].tam; j++) {
          assign(&board[c.x + *incr1][c.y + *incr2], (element_t){ length--, ships[i].type, ships[i].dir });
        }
    }
}