#ifndef SAXO_H
#define SAXO_H

#include "common.h"
#include "obj_update.h"
#include "timers.h"
#include "obj/poing.h"
#include "collision/collision_block.h"
#include "num_level_36260.h"
#include "cam_scroll.h"
#include "moteur_init_end.h"
#include "ray/ray_32398.h"
#include "world_map_677C0.h"

typedef struct SaxAttackEntry
{
    u8 next_note;
    u8 time;
    s16 field2_0x2;
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

extern SaxData Sax;

#endif