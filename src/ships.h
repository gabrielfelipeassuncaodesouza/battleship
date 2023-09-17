#ifndef _H_SHIPS
#define _H_SHIPS

#define SHIPS 5

typedef struct {
  int tam;
  char type;
  char dir;
} element_t;

#define SUBMARIN    (element_t){1, 'S', 'N' }
#define BATTLESHIP  (element_t){2, 'B', 'H' }
#define CRUISE      (element_t){3, 'C', 'H' }

#endif
