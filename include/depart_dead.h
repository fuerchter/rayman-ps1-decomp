#ifndef DEPART_DEAD_H
#define DEPART_DEAD_H

#include "common.h"
#include "main.h"
#include "loading_794DC.h"
#include "main_moteur.h"
#include "victoire.h"
#include "sound.h"

/* TODO: data conflict */
/* .data */
extern u8 D_801CEDFC;
extern u8 D_801CF0DC;

void DEPART_WORLD(void);
void DEPART_LEVEL(void);
void DEPART_DEAD_LOOP(void);
void FIN_DEAD_LOOP(void);

#endif