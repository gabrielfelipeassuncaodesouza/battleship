/** header files of other archives **/

#include "board.h"
#include "header.h"
#include "ships.h"
#include "human.h"
#include "render.h"
#include "shoot.h"

/** clibs **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYER_TURN 0
#define IA_TURN     1

int main() {
    srand(time(NULL));

    element_t playerBoard[TAM][TAM];
    element_t iaBoard[TAM][TAM];

    initBoard(playerBoard, sizeof(playerBoard)); //sets all the squares of the board to water
    initBoard(iaBoard, sizeof(iaBoard)); //the same thing from above

    element_t ships[] = { AIRCRAFT, TANKER, TANKER, DESTROYER, DESTROYER, SUBMARIN, SUBMARIN, SUBMARIN };

    printHeader();

    /** Asks for the name of the player **/
    char playerName[100];
    printf("Digite seu nome: ");
    fgets(playerName, 100, stdin);
    playerName[strcspn(playerName, "\n")] = '\0';

    putShips(playerBoard, ships, "player");
    putShips(iaBoard, ships, "ia");

    int playerShips = SHIPS;
    int iaShips = SHIPS;

    clearscr();
    printf("Your board is here:\n\n");
    boardRender(playerBoard);

    putchar('\n');
    pause();

    int turn = PLAYER_TURN;
    int ret;

    do {
        clearscr();
        if(turn == PLAYER_TURN) {
            printf("\nSua vez, %s!\n\n", playerName);

            if((ret = shoot(iaBoard, ships, "player")) >= 1) {
                if(ret == 2) iaShips--;
            }
            else turn = IA_TURN;

            enemyRender(iaBoard);
            printf("\nNavios derrubados: %d\n\n", SHIPS-iaShips);
        }
        else {
            printf("\nVez da IA\n\n");
            if((ret = shoot(playerBoard, ships, "ia")) >= 1) {
                if(ret == 2) playerShips--;
            }
            else turn = PLAYER_TURN;

            boardRender(playerBoard);
            printf("\nNavios derrubados: %d\n\n", SHIPS-playerShips);
        }
        pause();
    } while(iaShips > 0 && playerShips > 0);

    printf("O Ganhador foi %s\n", (playerShips == 0) ? "IA" : playerName);
}
