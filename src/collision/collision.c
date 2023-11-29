#include "collision/collision.h"

s16 GET_SPRITE_POS(Obj *obj,s32 spriteIndex,s16 *x,s16 *y,u16 *w,u16 *h);

extern s16 ZDCPTR;
extern ZDC zdc_tab[512];
extern u16 type_zdc[256];
extern s16 bagD[20];
extern s16 bagW[20];
extern s16 bagH[20];

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
s32 inter_box(s32 x_1, s32 y_1, s32 w_1, s32 h_1, s16 x_2, s16 y_2, s32 w_2, s32 h_2)
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

INCLUDE_ASM("asm/nonmatchings/collision/collision", GET_SPRITE_ZDC);

INCLUDE_ASM("asm/nonmatchings/collision/collision", BOX_HIT_SPECIAL_ZDC);

INCLUDE_ASM("asm/nonmatchings/collision/collision", BOX_IN_COLL_ZONES);

/* 1CD38 80141538 -O2 -msoft-float */
s32 COLL_BOX_SPRITE(s16 in_x, s16 in_y, s16 in_w, s16 in_h, Obj *obj)
{
  s16 unk_1;
  s16 spr_x;
  s16 spr_y;
  s16 spr_w;
  s16 spr_h;
  s32 spr;
  
  unk_1 = GET_SPRITE_POS(obj, obj->hit_sprite, &spr_x, &spr_y, &spr_w, &spr_h);
  if (unk_1 != 0)
    unk_1 = inter_box(in_x, in_y, in_w, in_h, spr_x, spr_y, spr_w, spr_h);
  if (unk_1 != 0)
    spr = obj->hit_sprite;
  else
    spr = -1;
  return spr;
}

/* 1CE18 80141618 -O2 -msoft-float */
s16 CHECK_BOX_COLLISION(s16 obj_type, s16 x, s16 y, s16 w, s16 h, Obj *obj)
{
    s32 h_spr;
    s16 res;

    if (obj->hit_sprite == 0xFD)
        res = BOX_HIT_SPECIAL_ZDC(x, y, w, h, obj);
    else if (((h_spr = obj->hit_sprite) >= 0xFD) && h_spr < 0x100)
        res = BOX_IN_COLL_ZONES(obj_type, x, y, w, h, obj);
    else
        res = COLL_BOX_SPRITE(x, y, w, h, obj);
    return res;
}

/* 1CF08 80141708 -O2 -msoft-float */
s32 possible_sprite(Obj *obj, s16 index)
{
    s16 spr[12];
    
    switch(obj->type)
    {
    case TYPE_BON3:
        spr[0] = 0;
        spr[1] = 1;
        spr[2] = 2;
        spr[3] = 3;
        spr[4] = 4;
        spr[5] = 0x00FF;
        break;
    case TYPE_CYMBALE:
    case TYPE_CYMBAL2:
        spr[0] = 0;
        spr[1] = 1;
        spr[2] = 2;
        spr[3] = 0x00FF;
        break;
    case TYPE_ROULETTE:
        spr[0] = 5;
        spr[1] = 6;
        spr[2] = 7;
        spr[3] = 8;
        spr[4] = 0x00FF;
        break;
    case TYPE_ROULETTE2:
        spr[0] = 1;
        spr[1] = 2;
        spr[2] = 3;
        spr[3] = 4;
        spr[4] = 0x00FF;
        break;
    case TYPE_ROULETTE3:
        spr[0] = 1;
        spr[1] = 2;
        spr[2] = 3;
        spr[3] = 0x00FF;
        break;
    case TYPE_FALLPLAT:
    case TYPE_LIFTPLAT:
    case TYPE_INTERACTPLT:
        spr[0] = 0;
        spr[1] = 1;
        spr[2] = 0x00FF;
        break;
    case TYPE_TIBETAIN_6:
        if (ray.flags & FLG(OBJ_FLIP_X))
        {
            spr[0] = 4;
            spr[1] = 5;
            spr[2] = 6;
            spr[3] = 7;
            spr[4] = 8;
            spr[5] = 9;
        }
        else
        {
            spr[0] = 9;
            spr[1] = 8;
            spr[2] = 7;
            spr[3] = 6;
            spr[4] = 5;
            spr[5] = 4;
        }
        spr[6] = 0x00FF;
        break;
    case TYPE_TIBETAIN_2:
        spr[0] = 4;
        spr[1] = 5;
        spr[2] = 0x00FF;
        break;
    }
    return spr[index];
}

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
