/** header files of other archives **/

#include "board.h"
#include "ships.h"
#include "human.h"
#include "render.h"
#include "shoot.h"

/** clibs **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//TODO: Improve IA

int main() {
    srand(time(NULL));

    element_t playerBoard[TAM][TAM];
    element_t iaBoard[TAM][TAM];
    initBoard(playerBoard, sizeof(playerBoard));
    initBoard(iaBoard, sizeof(iaBoard));

    element_t ships[] = { AIRCRAFT, TANKER, TANKER, DESTROYER, DESTROYER, SUBMARIN, SUBMARIN, SUBMARIN };

    putShips(playerBoard, ships, "player");
    putShips(iaBoard, ships, "ia");

    int playerShips = SHIPS;
    int iaShips = SHIPS;

    clearscr();
    printf("Your board is here:\n\n");
    boardRender(playerBoard);

    putchar('\n');
    pause();

    int i = 0;
    do {
        clearscr();
        if(i % 2 == 0) {
            printf("\nVez do player\n\n");
            if(shoot(iaBoard, ships, "player") == 1) {
                iaShips--;
            }
            enemyRender(iaBoard);
            printf("\nNavios derrubados: %d\n\n", SHIPS-iaShips);
        }
        else {
            printf("\nVez da IA\n\n");
            if(shoot(playerBoard, ships, "ia") == 1) {
                playerShips--;
            }
            boardRender(playerBoard);
            printf("\nNavios derrubados: %d\n\n", SHIPS-playerShips);
        }

        i++;
        getchar();
    } while(iaShips > 0 && playerShips > 0);

    printf("O Ganhador foi %s\n", (playerShips == 0) ? "IA" : "Player");
}
