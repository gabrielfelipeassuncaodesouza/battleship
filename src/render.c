#include "board.h"
#include "ships.h"
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

void clearscr() {
    printf("\x1b[2J");
    printf("\x1b[H");
}

void pause() {
  printf("Press any key to continue... ");
  getchar();
}

void debugRender(element_t board[][TAM]) {  
  printf("\n\t");
  for(int i = 1; i <= TAM; i++) printf("%d ", i);
  putchar('\n');

  for(int i = 0; i < TAM; i++) {
    printf("%c\t", 'A'+i);
    for(int j = 0; j < TAM; j++) {
      printf("%c ", board[i][j].type);
    }
    putchar('\n');
  }
}

void renderBoard(element_t board[][TAM]) {
    for(int i = 0; i < TAM; i++) {
        //printf("%c\t", 'A' + i);

        for(int part = 0; part < 5; part++) {
            for(int j = 0; j < TAM; j++) {
                char * color = (isEqual(board[i][j], ERROR)) ? "\x1b[31m" : 
                               (isEqual(board[i][j], ASSERT)) ? "\x1b[35m" : 
                               (isEqual(board[i][j], SUBMARIN)) ? "\x1b[32m" : ""; //fix here

                printf("%s", color);

                if(isEqual(board[i][j], WATER)) {
                    printPart(wave_ui, part);
                } else if(isEqual(board[i][j], SUBMARIN)) { //fix here
                    printPart(ship_ui, part);
                } else if(isEqual(board[i][j], ASSERT)) {
                    printPart(assert_ui, part);
                } else if(isEqual(board[i][j], ERROR)) {
                    printPart(miss_ui, part);
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