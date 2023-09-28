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
    printf("\tDigite seu nome: ");
    fgets(playerName, 100, stdin);
    playerName[strcspn(playerName, "\n")] = '\0';

    putShips(playerBoard, ships, PLAYER_TURN);
    putShips(iaBoard, ships, IA_TURN);

    placar placar = { 0, 0 };

    clearscr();
    printf("\n\t\tYour board is here:\n\n");
    boardRender(playerBoard);

    putchar('\n');
    pause();

    int turn = PLAYER_TURN;
    int ret;

    do {
        ret = 0;
        clearscr();
        if(turn == PLAYER_TURN) {
            printf("\n\tSua vez, %s\n", playerName);
            if((ret = playerShoot(playerBoard, iaBoard, ships, placar)) >= 1) {
                if(ret == 2) placar.player++;
            }
            else turn = IA_TURN;
        }
        else {
            printf("\n\tVex da IA: ");
            if((ret = iaShoot(playerBoard, ships)) >= 1) {
                if(ret == 2) placar.ia++;
            }
            else turn = PLAYER_TURN;
        }
        printBothBoards(playerBoard, iaBoard, placar);

        printf("\n\n");
        pause();
    } while(placar.player < 8 && placar.ia < 8);

    printf("O Ganhador foi %s\n", (placar.ia == 8) ? "IA" : playerName);
}