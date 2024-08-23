#ifndef DISPLAY_H
#define DISPLAY_H

#include "common.h"
#include "psyq_3_0/LIBGPU.H"

typedef struct DRENVAndTile {
    DR_ENV drawing_environment;
    TILE tile;
} DRENVAndTile;

typedef struct Display {
    DISPENV field0_0x0;
    DRAWENV drawing_environment;
    DR_ENV map_drawing_environment_primitives[6];
    DR_ENV field3_0x1f0;
    DR_ENV field4_0x230;
    DR_ENV field5_0x270;
    DR_ENV field6_0x2b0[16];
    u8 field_0x6b0_0x7d7[296];
    u8 map_ordering_tables;
    u8 field_0x7d9_0x7ef[23];
    u8 * ordering_table[11]; /* TODO: not sure this is correct, see compiler warnings for synchro_loop.c and main_moteur.c */
    SPRT_8 tiles[360];
    SPRT_8 field_0x1e9c_0x321b[312]; /* size? see D_801F4A28? could also either be SPRT_8 or SPRT_16, structs are the same */
    TILE_1 tile1s[240];
    SPRT sprites[50];
    POLY_FT4 polygons[200];
    TILE field5324_0x6084;
    POLY_G4 field5325_0x6094;
    u8 field_0x60b8_0x60bb[4];
    DRENVAndTile field5330_0x60bc[17];
    u8 field_0x660c_0x668b[128];
    TILE fond_box_tiles[4];
    TILE fond_box_tile;
    TILE field5461_0x66dc[6];
    u8 field_0x673c_0x6cbb[1408];
} Display;

/* .data */
extern Display *PS1_CurrentDisplay;

/**/
extern Display PS1_Display1;
extern Display PS1_Display2;
extern s16 D_801E4BE0; /* used as index for map_drawing_environment_primitives (0x70) */

#endif