#ifndef _H_IA
#define _H_IA

#include "ships.h"
#include "board.h"

chute_t iaChute(element_t board[][TAM], chute_t lastHit, int lastDir, int hitted); 
chute_t huntAndTarget(element_t board[][TAM], chute_t lastHit, int lastDir); 

#endif
