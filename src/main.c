/** header files of other archives **/

#include "board.h"
#include "header.h"
#include "ships.h"
#include "human.h"
#include "render.h"
#include "shoot.h"

/** clibs **/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

char playerName[100];
element_t playerBoard[TAM][TAM];
element_t iaBoard[TAM][TAM];
element_t ships[] = { AIRCRAFT, TANKER, TANKER, DESTROYER, DESTROYER, SUBMARIN, SUBMARIN, SUBMARIN };
placar p;

void initGame(void) {
  initBoard(playerBoard, sizeof(playerBoard)); //sets all the squares of the board to water
  initBoard(iaBoard, sizeof(iaBoard)); //the same thing from above

  putShips(playerBoard, ships, PLAYER_TURN);
  putShips(iaBoard, ships, IA_TURN);

  p = (placar){ 0, 0 };

  clearscr();
  printf("\n\t\tYour board is here:\n\n");
  boardRender(playerBoard);

  putchar('\n');
  stop();
}

void gameLoop(void) {
  initGame();

  int turn = PLAYER_TURN;
  int ret;

  do {
    ret = 0;
    clearscr();
    if(turn == PLAYER_TURN) {
      printf("\n\tSua vez, %s\n", playerName);
      if((ret = playerShoot(playerBoard, iaBoard, ships, p)) >= 1) {
        if(ret == 2) p.player++;
      }
      else turn = IA_TURN;
    }
    else {
      printf("\n\tVez da IA: ");
      if((ret = iaShoot(playerBoard, ships)) >= 1) {
        if(ret == 2) p.ia++;
      }
      else turn = PLAYER_TURN;
    }
    printBothBoards(playerBoard, iaBoard, p);

    printf("\n\n");
    usleep(1000000);
  } while(p.player < 8 && p.ia < 8);

  if(p.ia == 8)
    printLost();
  else
    printWin();

  char choice;
  printTypeWriter("\n\tDeseja jogar novamente [s/n]? ");
  scanf("%c", &choice);
  while(getchar() != '\n');

  if(tolower(choice) == 's') {
    gameLoop();
  }
} 

int main() {
    srand(time(NULL));

    printHeader();

    printTypeWriter("\tDigite seu nome: ");
    fgets(playerName, 100, stdin);
    playerName[strcspn(playerName, "\n")] = '\0';

    gameLoop();

    clearscr();
    printTypeWriter("\n\tObrigado por jogar!!\n\n");
}
