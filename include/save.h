#ifndef SAVE_H
#define SAVE_H

#include "common.h"
#include "collision/collision_block.h"

typedef struct SaveState
{
    u32 triggered_objects[8];
    s16 nb_floc[8];
    s16 vent_x;
    s16 vent_y;
    s16 x_map;
    s16 y_map;
    u8 time;
    u8 field7_0x39;
    s16 ray_x_pos;
    s16 ray_y_pos;
    s16 ray_screen_x;
    s16 ray_screen_y;
    u16 ray_flip_x;
    s16 save_obj_id;
    s16 save_obj_x_pos;
    s16 save_obj_y_pos;
    u8 link_init[256];
    u8 save_obj_detect_zone_flag;
    u8 field18_0x14b;
    BlockType ray_btypes[5];
    u8 ray_anim_index;
    u8 ray_anim_frame;
    u8 ray_main_etat;
    u8 ray_sub_etat;
    u8 poing_sub_etat;
    u8 rayevts_0;
    u8 rayevts_1;
    u8 rayevts_2;
    u8 dead_time;
    u8 has_saved;
    u8 num_wiz;
} SaveState;

extern SaveState save1;

#endif