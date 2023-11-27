#include "collision/collision.h"

extern s16 ZDCPTR;
extern ZDC zdc_tab[512];
extern u16 type_zdc[256];

/* 1B1F0 8013F9F0 -O2 -msoft-float */
void PS1_SetZDC(s16 x, s16 y, u8 w, u8 h, u8 flags, u8 sprite)
{
    ZDC *zdc = &zdc_tab[ZDCPTR];

    zdc->x_pos = x;
    zdc->y_pos = y;
    zdc->width = w;
    zdc->height = h;
    zdc->flags = flags;
    zdc->sprite = sprite + 0xFF; /* ??? */
    ZDCPTR++;
}

/* 1B248 8013FA48 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/collision/collision", PS1_SetTypeZDC);
#else
void PS1_SetTypeZDC(ObjType type, u16 param_2, s32 param_3)
{
    type_zdc[type] = param_2 | (param_3 << 11);
    
    __asm__("nop");
}
#endif

/* 1B270 8013FA70 -O2 -msoft-float */
u16 get_nb_zdc(Obj *obj)
{
    return obj->zdc >> 11;
}

/*
first 11 bits, see
https://github.com/BinarySerializer/BinarySerializer.Ray1/blob/0323431715346d65200f898664351932b86deb8b/src/BinarySerializer.Ray1/DataTypes/Collision/ZDCReference.cs#L6
*/
/* 1B27C 8013FA7C -O2 -msoft-float */
u16 get_zdc_index(Obj *obj)
{
    return obj->zdc & 0x7ff;
}

/* 1B288 8013FA88 -O2 -msoft-float */
ZDC *get_zdc(Obj *obj, s16 param_2)
{
    return &zdc_tab[(s16) get_zdc_index(obj) + param_2];
}

/*INCLUDE_ASM("asm/nonmatchings/collision/collision", get_ZDCPTR);*/

s16 get_ZDCPTR(void)
{
    return ZDCPTR;
}

INCLUDE_ASM("asm/nonmatchings/collision/collision", in_coll_sprite_list);

INCLUDE_ASM("asm/nonmatchings/collision/collision", box_inter_v_line);
/* ??? think param_6 and 7 might be s32 ??? */

INCLUDE_ASM("asm/nonmatchings/collision/collision", box_inter_h_line);

/* 1B57C 8013FD7C -O2 -msoft-float */
u8 inter_box(s32 x_1, s32 y_1, s32 w_1, s32 h_1, s16 x_2, s16 y_2, s32 w_2, s32 h_2)
{
    s16 unk_1 = x_1 - w_2;
    s16 unk_2 = y_1 - h_2;
    s16 unk_3 = w_1 + w_2;
    s16 unk_4 = h_1 + h_2;
    u8 res = false;

    if (x_2 >= unk_1 && y_2 >= unk_2 && (unk_1 + unk_3 >= x_2))
        res = (unk_2 + unk_4 < y_2) ^ 1;
    return res;
}

INCLUDE_ASM("asm/nonmatchings/collision/collision", GET_OBJ_ZDC);

INCLUDE_ASM("asm/nonmatchings/collision/collision", GET_SPRITE_ZDC); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", BOX_HIT_SPECIAL_ZDC); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", BOX_IN_COLL_ZONES); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", COLL_BOX_SPRITE);

INCLUDE_ASM("asm/nonmatchings/collision/collision", CHECK_BOX_COLLISION);

INCLUDE_ASM("asm/nonmatchings/collision/collision", possible_sprite);

INCLUDE_ASM("asm/nonmatchings/collision/collision", setToleranceDist);

INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_RAY_DIST_MULTISPR_CANTCHANGE);

INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_RAY_DIST_PI);

INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_RAY_DIST_BAG);

INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_RAY_DIST);

INCLUDE_ASM("asm/nonmatchings/collision/collision", do_boum);

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_PNG_COLL_STONEMAN);

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_PNG_COLL_STONEWOMAN);

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_POING_COLLISION); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", COLL_BOX_ALL_SPRITES);

INCLUDE_ASM("asm/nonmatchings/collision/collision", COLL_RAY_PIC);

INCLUDE_ASM("asm/nonmatchings/collision/collision", COLL_RAY_BLK_MORTEL);

INCLUDE_ASM("asm/nonmatchings/collision/collision", RAY_KO);

INCLUDE_ASM("asm/nonmatchings/collision/collision", RAY_HIT); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", standard_frontZone);

INCLUDE_ASM("asm/nonmatchings/collision/collision", SET_DETECT_ZONE_FLAG); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", goToRay);

INCLUDE_ASM("asm/nonmatchings/collision/collision", unleashMonsterHost);

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_COLL_RAY_CYMBALE); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", DoAudioStartRaymanCollision);

INCLUDE_ASM("asm/nonmatchings/collision/collision", PS1_DoRaymanCollision); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_COLLISIONS); /**/

INCLUDE_ASM("asm/nonmatchings/collision/collision", DO_OBJ_COLLISIONS); /**/
