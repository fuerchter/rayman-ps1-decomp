#ifndef DISPLAY_UI_H
#define DISPLAY_UI_H

#include "common.h"
#include "psyq_3_0/LIBGPU.H"
#include "obj_update.h"
#include "world_map_677C0.h"
#include "obj/poing.h"
#include "obj/fee_4DFD0.h"
#include "card.h"
#include "menu/menu_6A3BC.h"

typedef struct GrpStar
{
    u8 timer;
    u8 length;
    u8 dist;
    u8 sprite_table_index;
} GrpStar;

extern u8 s__801cef84[2];
extern u8 PS1_TingsToGet_Col;
extern u8 PS1_TingsToGet_ColAdd;
extern u8 s_time_801cef88[5];
extern u8 s__801cef90[2];
extern u8 s_go__801cef94[7];
extern u8 s_the_end_801cef9c[8];

extern GrpStar grp_stars[30];
extern s16 current_star;
extern u8 PS1_star_spr[8];
extern Obj div_obj;

void CLRSCR(void);
void display_etoile(s32 in_x, s32 in_y);
void display_grp_stars(void);
void DISPLAY_TEXT_FEE(void);
void DisplayJumellesNormal(void);
void PS1_DisplayWorldMapBg1(s16 x1, s16 y1, s16 x2, s16 y2);
void DISPLAY_SAVE_SPRITES(s16 param_1, s16 param_2);
void DISPLAY_SAVE_POING(void);
void display_time(s16 param_1);
void PS1_LoadPts(void);
void DISPLAY_CONTINUE_SPR(void);
void PS1_PromptCardDisplayPoing(void);
void DISPLAY_OPTIONS_POING(void);

#endif