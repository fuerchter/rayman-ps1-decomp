#ifndef DRAW_548CC_H
#define DRAW_548CC_H

#include "common.h"
#include "common/display.h"
#include "psyq_3_0/LIBGTE.H"
#include "psyq_3_0_missing/RAND.H"
#include "main_moteur.h"
#include "luciole.h"

typedef struct RGB {
    u8 r;
    u8 g;
    u8 b;
} RGB;

typedef struct RGBA {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RGBA;

typedef struct Vec2 {
    s16 x;
    s16 y;
} Vec2;

/* .data */
extern RGB D_801C7EAC[4];

/* .data */
extern s16 D_801CF064;
extern s16 D_801CF066;
extern s16 D_801CF068;
extern RGBA D_801CF06C; /* being treated as s32? */
extern RGBA D_801CF070;
extern RGBA D_801CF074;
extern RGBA D_801CF078;
extern RGBA D_801CF07C;
extern RGBA D_801CF080; /* something goes in between D_801CF080 and D_801CF086 */
extern u16 D_801CF086;
extern s16 D_801CF088;
extern s16 D_801CF08A;
extern u16 D_801CF090;
extern u16 D_801CF092; /* is this its own var? part of array or struct? see DISPLAY_FOND_MENU */
extern u16 D_801CF094;
extern s16 D_801CF096;
extern s16 D_801CF098;

/* .data */
extern s16 D_801CF418;
extern s16 D_801CF420;
extern s16 D_801CF428;
extern s16 D_801CF430;

/**/
extern Vec2 D_801E4E60[16];
extern Vec2 D_801E4EA8[16];
extern Vec2 D_801FAA48[2];
extern Vec2 D_801FAA58[2];
extern s32 D_801F8168;
extern s32 D_801F816C;
extern s32 PS1_TPage_x; /* could also go in another file? */
extern s32 PS1_TPage_y;

void FUN_801790cc(Display *display);
void Display_and_free_luciole(void);
void PS1_PerfectBonusDrawBg(void);
void DISPLAY_FOND_MENU(void);
void FUN_8017b260(u16 param_1);

#endif