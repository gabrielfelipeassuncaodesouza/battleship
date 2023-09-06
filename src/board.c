#include "board.h"
#include "globconst.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void initBoard(char board[][TAM], size_t size) {
    memset(board, WATER, size);
}

void putShips(char board[][TAM]) {
    for (int i = 0; i < SHIPS; i++)
    {
        int x, y;
        do
        {
            x = rand() % TAM;
            y = rand() % TAM;
        } while (board[x][y] == SHIP);

        board[x][y] = SHIP;
    }
}
