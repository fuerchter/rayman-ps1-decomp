#include "world_map_677C0.h"

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", FUN_8018d9e0);*/

/* matching but unable to fill in other global uses */
/* 691E0 8018D9E0 -O2 */
extern u16 D_801E4F88;
extern s16 D_801E4F90;
extern u16 D_801E4FCA;
extern s16 D_801E4FD2;
extern u16 D_801E5008;
extern s16 D_801E5010;
extern u16 D_801E504A;
extern s16 D_801E5052;

void FUN_8018d9e0(void) {
    if (text_to_display[0].x_pos >= 161) {
        text_to_display[0].x_pos -= 6;
        text_to_display[0].centered_x_pos -= 6;
    }
    if (D_801E5010 >= 161) {
        D_801E5010 -= 6;
        text_to_display[2].centered_x_pos -= 6;
    }
    if (D_801E4FD2 < 320) {
        D_801E4FD2 += 2;
        text_to_display[1].centered_y_pos += 2;
    }
    if (D_801E5052 >= -59) {
        D_801E5052 -= 2;
        text_to_display[3].centered_y_pos -= 2;
    }
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", RESPOND_TO_UP);*/
/* https://decomp.me/scratch/6ivxi PSYQ3.3 (gcc 2.6.0 + aspsx 2.21) -O1 */
/* 698B4 8018E0B4 */
extern s16 num_world_choice;
extern WorldInfo t_world_info[24];

void RESPOND_TO_UP(void) {
    num_world_choice = t_world_info[num_world_choice].index_up;
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", INIT_PASTILLES_SAUVE);*/
/* https://decomp.me/scratch/Y1VKk PSYQ3.3 (gcc 2.6.0 + aspsx 2.21) -O1 */
/* 6A0C8 8018E8C8 */
extern s32 D_801C34D4;
extern s32 D_801C34E8;
extern s32 D_801C34FC;
extern s32 D_801C3510;
extern s32 D_801C3524;
extern s32 D_801C3538;
extern s32 D_801C353C;
extern s32 D_801C3544;
extern u8 NBRE_SAVE;

void INIT_PASTILLES_SAUVE(void) {
    s32 var_v0;

    if (NBRE_SAVE != 0) {
        var_v0 = D_801C353C;
    } else {
        var_v0 = D_801C3544;
    }
    D_801C34D4 = var_v0;
    t_world_info[19].level_name = var_v0;
    D_801C34FC = var_v0;
    D_801C3510 = var_v0;
    D_801C3524 = var_v0;
    D_801C3538 = var_v0;
}

/* 6A180 8018E980 */
void INIT_PASTILLES_SAUVE();
extern s8 PROC_EXIT;
extern s8 dir_on_wldmap;
extern u16 xmapinit;
extern u16 xwldmapsave;
extern u16 ymapinit;
extern u16 ywldmapsave;

extern u8 D_801F6200;
extern u32 D_801F620C;

void FIN_WORLD_CHOICE(void) {
    xwldmapsave = xmap;
    ywldmapsave = ymap;
    xmap = xmapinit;
    ymap = ymapinit;
    /*
    tried ray.flags & OBJ_FLIP_X,
    tried ray.flags & OBJ_FLIP_X != 0
    and bitfield
    */
    dir_on_wldmap = ray.flags >> 0xE & 1;
    RESTORE_RAY();
    INIT_PASTILLES_SAUVE();
    PROC_EXIT = FALSE;
    if (ray.hit_points == 0xFF) {
        D_801F6200 = 0; /* this is also ray.hit_points */
    }
}

/*INCLUDE_ASM("asm/nonmatchings/world_map_677C0", DoScrollInWorldMap);*/

/* 677F4 8018BFF4 -O2 */
extern s16 dhspeed;
extern s16 dvspeed;
extern s16 scroll_end_x;
extern s16 scroll_end_y;
extern s16 scroll_start_x;
extern s16 scroll_start_y;

void DoScrollInWorldMap(s32 arg0, s32 arg1) {
    /* ??? */
    u8 test[16];
    s16 temp_v1;
    s16 var_a0;
    s16 var_v1;

    ymap = (u16) ymap + arg1;
    temp_v1 = (u16) xmap + arg0;
    xmap = temp_v1;
    if ((temp_v1 < scroll_start_x) || (var_a0 = scroll_end_x, ((scroll_end_x < temp_v1) != 0))) {
        xmap = var_a0;
        dhspeed = 0;
    }
    if ((scroll_start_y > ymap) || (var_v1 = scroll_end_y, ((scroll_end_y < ymap) != 0))) {
        ymap = var_v1;
        dvspeed = 0;
    }
    CalcObjPosInWorldMap(&ray);
}