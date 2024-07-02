#ifndef DARK_729F0_H
#define DARK_729F0_H

#include "common.h"
#include "common/obj.h"
#include "common/level.h"
#include "moteur_init_end.h"
#include "collision/etat.h"
#include "obj/poing.h"
#include "boss.h"
#include "obj/black_ray_command.h"

typedef struct VitrauxInfo
{
    s16 x_pos;
    s16 y_pos;
    u8 obj_id;
    u8 index; /* 0-4 */
    u8 field4_0x6;
    u8 mode; /* 0 is inactive, 1 is getting less bright and 2 is getting brighter */
    u16 value; /* goes from 100 to 0 */
} VitrauxInfo;

/* .data */
extern s16 oscille[30];
extern u8 vitrail_clignotement[4][5];

/* .data */
extern u8 dark_sequence[3];
extern u8 dark_attaque;
extern u8 type_dark_attaque;

/**/
extern u8 dark_phase;
extern VitrauxInfo VitrauxInfos[5];
extern s16 corde_dark_obj_id;
extern s16 corde_x;
extern s16 corde_y_bas;
extern s16 corde_y_haut;
extern s16 moskitomama_droite_obj_id;
extern s16 moskitomama_gauche_obj_id;
extern s16 moskitosaxo_obj_id;
extern s16 stosko_obj_id;
extern u8 D_801E5518;
extern s16 dark_rayon_dx;
extern s16 dark_rayon_dy;

void PlaceDarkPhase1et2(Obj *obj);
void dark_attaque_suivante(void);
void init_vitraux(void);
s32 poing_face_obj(Obj *obj);
void DARK_phase1(Obj *dark_obj);
void DARK_phase3(Obj *dark_obj);
void DO_DARK_COMMAND(Obj *dark_obj);
void DO_DARK_POING_COLLISION(Obj *obj);
void DO_DARK_REACT(Obj *obj);
void DO_DARK_SORT_COMMAND(Obj *param_1);
void DO_DARK_SORT_COLLISION(Obj *obj);
void allocate_DARK_SORT(s16 x, s16 y, s16 sub_etat, s16 iframes);
void corde_en_bas(void);
void corde_en_haut(u8 param_1);
void init_corde(Obj *obj);
void goto_phase1(Obj *dark_obj);
void goto_phase2(Obj *dark_obj);
void goto_phase3(Obj *dark_obj);
void goto_phase5(Obj *dark_obj);

#endif