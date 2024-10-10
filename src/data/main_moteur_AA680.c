#include "main_moteur.h"

u8 in_pause = false;
u8 PS1_Ingame = false;
RaymanEvents D_801CEE84 = {};
RaymanEvents D_801CEE88 = { .poing = true };
RaymanEvents D_801CEE8C = { .poing = true, .hang = true };
RaymanEvents D_801CEE90 = { .poing = true, .hang = true, .grap = true };
RaymanEvents D_801CEE94 = { .poing = true, .hang = true, .grap = true, .helico = true };
RaymanEvents PS1_DefaultRayEvts = { .poing = true, .hang = true, .grap = true, .helico = true, .run = true };
s16 D_801CEE9A = 0;
s16 D_801CEE9C = 0;
s16 PS1_CanPlayDeathMusic = true;
s16 D_801CEEA0 = 0;
u8 D_801CEEA2 = 0;