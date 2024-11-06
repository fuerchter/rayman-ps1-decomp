#include "unknown/3ED10.h"

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/unknown/3ED10", GetY);
#else
/* matches, but clean up further? */
/*INCLUDE_ASM("asm/nonmatchings/unknown/3ED10", GetY);*/

s16 GetY(s16 x)
{
    s16 unk_1;
    s32 unk_2;
    s16 obj_id;
    s16 unk_3;
    Obj *obj;

    if (eau_obj_id == -1)
        return 0;

    unk_1 = (x + 50) / 101;
    unk_2 = unk_1 * 101;
    obj_id = eau_obj_id + unk_1 % 5;
    if (x - unk_2 >= 0)
    {
        unk_3 = x - unk_2;
        unk_3 = 51 - unk_3;
    }
    else
    {
        unk_3 = unk_2 - x;
        unk_3 = 51 - unk_3;
    }
    obj = &level.objects[obj_id];

    return
        obj->y_pos -
        unk_3 * EauDy[
            (obj->anim_frame + DecEau[obj->anim_index]) % 14
        ] / 50;
}
#endif
