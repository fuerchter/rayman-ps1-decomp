#ifndef SAXO_H
#define SAXO_H

#include "common.h"
#include "timers.h"
#include "obj/poing.h"
#include "collision/collision_block.h"
#include "num_level_36260.h"
#include "cam_scroll_29B5C.h"
#include "moteur_init_end.h"
#include "ray/ray_32398.h"
#include "world_map_677C0.h"
#include "boss.h"

typedef struct SaxAttackEntry
{
    u8 next_note;
    u8 time;
    s16 end;
} SaxAttackEntry;

typedef struct SaxNoteEntry
{
    u8 type;
    s16 speed_x;
    s16 speed_y;
    s16 initial_iframes;
    s16 field4_0x8; /* unused */
} SaxNoteEntry;

typedef struct SaxData
{
    s16 x_pos;
    s16 y_pos;
    s16 note_box_coll_x;
    s16 note_box_coll_y;
    s16 sprite2_x;
    s16 sprite2_y;
    u8 coup;
    u8 saved_hp;
    u8 field8_0xe;
    u8 field9_0xf;
    s16 field10_0x10;
} SaxData;

/* .data */
extern SaxNoteEntry atak[7];
extern SaxAttackEntry SerieDatak[4][11];

/**/
extern SaxData Sax;
extern s16 IndexSerie;
extern s16 D_801F7FA0;
extern u8 NextNote;
extern s16 IndexAtak;
extern SaxAttackEntry attaque;
extern u8 NiveauDansPhase;

void INIT_SAXO(Obj *sax_obj);
void allocateNote2(Obj *note_obj, s16 param_2);
void DO_EXPLOSE_NOTE2(Obj *obj);
void DO_NOTE_CMD(Obj *obj);
void Cree_Eclat_Note(Obj *bnote, Obj *note1, s16 index);
void DO_EXPLOSE_NOTE1(Obj *obj);
void BonneNote(Obj *orig_obj);
void DO_NOTE_TOUCHEE(Obj *obj);
void DO_NOTE_REBOND(Obj *param_1);
void allocateNote(Obj *obj);
u8 PrepareAtak(void);
void SAXO_TIRE(Obj *obj);
void DO_SAXO_COUP(Obj *obj);
void DO_SAXO2_COUP(Obj *obj);
void SetSaxoCollNoteBox(Obj *obj);
void DO_SAXO_COMMAND(Obj *obj);
void DO_SAXO_ATTER(Obj *obj);
void DO_SAXO2_COMMAND(Obj *obj);
void DO_SAXO2_ATTER(Obj *obj);
void DO_SAXO_MARCHE(s16 hp);
void DO_SAXO3_COMMAND(Obj *obj);
void DO_SAXO3_DEBUT(Obj *obj);
s32 saxo2_get_eject_sens(void);

#endif