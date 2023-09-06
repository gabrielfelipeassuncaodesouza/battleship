#include "shoot.h"
#include <stdio.h>
#include <stdlib.h>

int isValid(char c) {
    return c != ERROR && c != ASSERT;
}

int shoot(char board[][TAM]) {
    int x, y;

    do {
        x = rand() % TAM;
        y = rand() % TAM;
    } while(!isValid(board[x][y]));

    if(board[x][y] == WATER) {
        printf("\nAGUA!!\n\n");
        board[x][y] = ASSERT;
    }

    else if(board[x][y] == SHIP) {
        printf("\nBOMBA!!\n\n");
        board[x][y] = ERROR;
        return 1;
    }

    return 0;
}
