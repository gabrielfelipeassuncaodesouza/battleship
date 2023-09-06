#include "board.h"
#include "render.h"

#include <stdio.h>

char ship_ui[5][15] = {
  {"    _~  _~   "},
  {" __|=| |=|__ "},
  {" \\ o.o.o.oY/ "},
  {"  \\_______/  "},
  {" ~~~~~~~~~~~ "}
};

char wave_ui[5][15] = {
  {" ~~~~~~~~~~~ "},
  {" ~~~~~~~~~~~ "},
  {" ~~~~~~~~~~~ "},
  {" ~~~~~~~~~~~ "},
  {" ~~~~~~~~~~~ "}
};

char assert_ui[5][15] = {
  {"  x       x  "},
  {"    x   x    "},
  {"      x      "},
  {"    x   x    "},
  {"  x       x  "}
};

char miss_ui[5][15] = {
  {"      ,--.!, "},
  {"   __/   -*- "},
  {" ,d08b.  '|` "},
  {" 0088MM      "},
  {" `9MMP       "},
};

void printPart(char draw[5][15], int part) {
	printf("%s", draw[part]);
}

void clearscr()
{
    printf("\x1b[2J");
    printf("\x1b[H");
}

void debugRender(char board[][TAM]) {  
  printf("\n\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  putchar('\n');

  for(int i = 0; i < TAM; i++) {
    printf("%c\t", 'A'+i);
    for(int j = 0; j < TAM; j++) {
      printf("%c ", board[i][j]);
    }
    putchar('\n');
  }
}

void renderBoard(char board[][TAM]) {

    for(int i = 0; i < TAM; i++) {
        //printf("%c\t", 'A' + i);

        for(int part = 0; part < 5; part++) {
            for(int j = 0; j < TAM; j++) {
                char * color = (board[i][j] == ERROR) ? "\x1b[31m" : (board[i][j] == ASSERT ? "\x1b[35m" : (board[i][j] == SHIP ? "\x1b[32m" : "")); 

                printf("%s", color);

                switch (board[i][j])
                {
                    case WATER:
                        printPart(wave_ui, part);
                        break;
                
                    case SHIP:
                        printPart(ship_ui, part);
                        break;
                    case ASSERT:
                        printPart(assert_ui, part);
                        break;
                    case ERROR:
                        printPart(miss_ui, part);
                        break;
                }
                printf("\x1b[m");
            }  
            printf("\n");
        }
        

    //printf("\n\n\t");
    //for(int i = 0; i < TAM; i++) {
    //    printf("%d ", i);
    //}
    //putchar('\n');
    }
}
