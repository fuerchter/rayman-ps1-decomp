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

INCLUDE_ASM("asm/nonmatchings/collision/collision", get_nb_zdc);

INCLUDE_ASM("asm/nonmatchings/collision/collision", get_zdc_index);

INCLUDE_ASM("asm/nonmatchings/collision/collision", get_zdc);

INCLUDE_ASM("asm/nonmatchings/collision/collision", get_ZDCPTR);

INCLUDE_ASM("asm/nonmatchings/collision/collision", in_coll_sprite_list);

INCLUDE_ASM("asm/nonmatchings/collision/collision", box_inter_v_line);

INCLUDE_ASM("asm/nonmatchings/collision/collision", box_inter_h_line);

INCLUDE_ASM("asm/nonmatchings/collision/collision", inter_box);

INCLUDE_ASM("asm/nonmatchings/collision/collision", GET_OBJ_ZDC); /**/

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
