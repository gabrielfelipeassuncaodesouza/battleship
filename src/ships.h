#ifndef _H_SHIPS
#define _H_SHIPS

#define SHIPS 8

typedef struct {
  int tam;
  char type;
  char dir;
} element_t;

typedef struct {
  int x;
  int y;
} chute_t;

typedef struct {
  int player;
  int ia;
} placar;

#define SUBMARIN    (element_t){2, 'S', 'N' }
#define DESTROYER   (element_t){3, 'D', 'H' }
#define TANKER      (element_t){4, 'T', 'H' }
#define AIRCRAFT    (element_t){5, 'A', 'H' }

#define PASS        (element_t){1, 'P', 'N' }

#endif
