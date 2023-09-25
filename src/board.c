#include "board.h"
#include "human.h"
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
  //* Refactor this code (it is not eficient)
  for(int i = 0; i < e.tam; i++) {
    if(e.dir == 'H' && !isEqual(board[c.x][c.y+i], WATER)) {
      printf("\nInvalid coordinate\n"); 
      return 0;
    }
    else if(e.dir == 'V' && !isEqual(board[c.x+i][c.y], WATER)) {
      printf("\nInvalid coordinate\n");
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

chute_t playerPut(int xlimit, int ylimit) {
  char buf[4];
  chute_t c;

  while(1) {
    printf("\nDigite as coordenadas do navio: ");
    scanf("%s", buf);
    while(getchar() != '\n');

    if(!isFormatValid(buf)) {
      printf("\nCoordenada inválida!\n");
      continue;
    }

    c = strToChute(buf);
    if(c.x >= xlimit || c.y >= ylimit) {
      printf("\nInvalid\n");
    }
    else break;
  }

  return c;
}

char playerDir() {
  char dir;

  while(1) {
    printf("\nType the direction of the ship (H = Horizontal V = Vertical): ");
    scanf("%c", &dir);
    while(getchar() != '\n');

    if(toupper(dir) != 'H' && toupper(dir) != 'V') {
      printf("\nInvalid orient\n");
      continue;
    }
    else break;
  }
  return toupper(dir);
}

chute_t iaPut(int xlimit, int ylimit) {
  chute_t c;
  c.x = rand() % xlimit;
  c.y = rand() % ylimit;
  
  return c;
}

char iaDir() {
  return ((rand() % 2 == 0) ? 'H' : 'V');
}

void putShips(element_t board[][TAM], element_t ships[SHIPS], const char* who) {
    for (int i = 0; i < SHIPS; i++) {
        int length = ships[i].tam;
        char orient = 'N';

        if(strcmp(who, "player") == 0) {
          clearscr();
          printf("\nCurrent board:\n\n");
          boardRender(board);
        }

        chute_t c;
        int xlimit = TAM, ylimit = TAM;

        do {
          if(length > 1) {
            if(strcmp(who, "ia") == 0)
              orient = iaDir();
            else {
              orient = playerDir();
            }
          }

          ships[i].dir = orient;
          
          if(ships[i].dir == 'H') {
            ylimit = TAM - length + 1;
          }
          else if(ships[i].dir == 'V') {
            xlimit = TAM - length + 1;
          }

          if(strcmp(who, "ia") == 0) {
            c = iaPut(xlimit, ylimit);
          } else {
            c = playerPut(xlimit, ylimit);
          }
        } while(!isValid(board, ships[i], c));

        //* Improve and refactor this function (it is not eficient)
        for(int j = 0; j < ships[i].tam; j++) {
            if(ships[i].dir == 'H') {
              assign(&board[c.x][c.y+j], (element_t){ length, ships[i].type, ships[i].dir });
            } else {
              assign(&board[c.x+j][c.y], (element_t){ length, ships[i].type, ships[i].dir });
            }

            length--;
        }

        if(strcmp(who, "player") == 0) {
          printf("\nShip putted succesfully\n\n");
          pause();
        }
    }
}