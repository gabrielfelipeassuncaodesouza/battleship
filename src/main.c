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
//Render UI

int main() {
    srand(time(NULL));

    element_t playerBoard[TAM][TAM];
    element_t iaBoard[TAM][TAM];
    initBoard(playerBoard, sizeof(playerBoard));
    initBoard(iaBoard, sizeof(iaBoard));

    element_t ships[] = { SUBMARIN, BATTLESHIP, BATTLESHIP, CRUISE, CRUISE };

    putShips(playerBoard, ships, "player");
    putShips(iaBoard, ships, "ia");

    int playerShips = SHIPS;
    int iaShips = SHIPS;

    clearscr();
    printf("Board of Player:\n\n");
    debugRender(playerBoard);
    printf("\nBoard of IA:\n\n");
    debugRender(iaBoard);

    printf("\nPress any key to start ... ");
    getchar();

    int i = 0;
    do {
        clearscr();
        if(i % 2 == 0) {
            printf("\nVez do player\n\n");
            if(shoot(iaBoard, "player") == 1) {
                iaShips--;
            }
            debugRender(iaBoard);
            printf("\nTotal de acertos: %d\n\n", SHIPS-iaShips);
        }
        else {
            printf("\nVez da IA\n\n");
            if(shoot(playerBoard, "ia") == 1) {
                playerShips--;
            }
            debugRender(playerBoard);
            printf("\nTotal de acertos: %d\n\n", SHIPS-playerShips);
        }

        i++;
        getchar();
    } while(iaShips > 0 && playerShips > 0);

    printf("O Ganhador foi %s\n", (playerShips == 0) ? "IA" : "Player");
}