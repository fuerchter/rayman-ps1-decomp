#include "collision/etat.h"

/* 22A98 80147298 -O2 -msoft-float */
s32 vblToEOA(Obj *obj, u8 factor)
{
    ObjState *eta = &obj->eta[obj->main_etat][obj->sub_etat];
    s32 anim_speed = eta->anim_speed & 15;
    s32 res = 
        (s16) (obj->animations[eta->anim_index].frames_count *
        anim_speed * factor - horloge[anim_speed] + 1);
    MAX_2(res, 1);
    
    return res;
}

/* 22B30 80147330 -O2 -msoft-float */
void GET_ANIM_POS(Obj *obj, s16 *x, s16 *y, s16 *w, s16 *h)
{
    AnimationFrame *frame = &obj->animations[obj->anim_index].frames[obj->anim_frame];
    
    *w = frame->width;
    *h = frame->height;
    if (!(obj->flags & FLG(OBJ_FLIP_X)))
        *x = obj->x_pos + frame->x;
    else
        *x = obj->x_pos + obj->offset_bx * 2 - frame->x - *w;
    *y = obj->y_pos + frame->y;
}

INCLUDE_ASM("asm/nonmatchings/collision/etat", FUN_801473d4);

INCLUDE_ASM("asm/nonmatchings/collision/etat", FUN_801473dc);

INCLUDE_ASM("asm/nonmatchings/collision/etat", add_actobj);

INCLUDE_ASM("asm/nonmatchings/collision/etat", PS1_BTYPAbsPos);

INCLUDE_ASM("asm/nonmatchings/collision/etat", set_sub_etat);

INCLUDE_ASM("asm/nonmatchings/collision/etat", set_main_etat);

INCLUDE_ASM("asm/nonmatchings/collision/etat", set_main_and_sub_etat);
