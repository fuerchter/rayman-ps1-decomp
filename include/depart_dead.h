#ifndef DEPART_DEAD_H
#define DEPART_DEAD_H

#include "common.h"
#include "world_map_95CC.h"
#include "first_init.h"

/* .data */
extern u8 PS1_ShouldFadeOutWorldIntro;

void DEPART_WORLD(void);
void DEPART_LEVEL(void);
void DEPART_DEAD_LOOP(void);
void FIN_DEAD_LOOP(void);

#endif