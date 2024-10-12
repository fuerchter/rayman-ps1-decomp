#ifndef DARK_PHASE2_H
#define DARK_PHASE2_H

#include "common.h"
#include "common/obj.h"
#include "collision/etat.h"
#include "obj/fire.h"
#include "obj/dark2_pink_fly.h"

/* .rodata */
extern const u8 s_youre_doomed_rayman__8012c1e4[27];

/**/
extern Obj *dark_obj;
extern s16 phase_dark2;
extern u8 TextDark2_Affiche;
extern s16 XText;
extern s16 YText;
extern s16 temps_text;
extern u8 txt_dark2[104];
extern s16 dark2_rayon_dx_1;
extern s16 dark2_rayon_dx_2;
extern s16 dark2_rayon_dy_1;
extern s16 dark2_rayon_dy_2;
extern s16 PosXSin1;
extern s16 PosYSin1;
extern s16 PosXSin2;
extern s16 PosYSin2;
extern s16 VitesseYText;
extern u8 num_dark2_phrase;
extern u8 sens_sinus_1;
extern u8 sens_sinus_2;
extern u8 sinus_actif;

void AllocateDarkPhase2(Obj *mr_drk_obj);
void DO_DARK2_AFFICHE_TEXT(void);
void DO_DARK_PHASE2_COMMAND(Obj *dp2_obj);
void DO_DARK2_SORT_COMMAND(Obj *ds2_obj);
void allocate_DARK2_SORT(s32 param_1, s16 param_2, s16 param_3, s16 param_4);

#endif