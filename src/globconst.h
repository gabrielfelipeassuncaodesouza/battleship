#ifndef _H_CONSTS
#define _H_CONSTS

#define SHIPS 5

typedef struct {
  int tam;
  char type;
  char dir;
} element_t;

#define SHIP (element_t){2, 'N', 'H' }

#endif
