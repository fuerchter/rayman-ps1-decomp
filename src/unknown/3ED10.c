#include "unknown/3ED10.h"

/* 3ED10 80163510 -O2 -msoft-float */
s16 GetY(s16 x)
{
    s16 unk_1;
    s32 unk_2;
    s16 unk_obj_id;
    s16 unk_3;
    Obj *unk_obj;

    if (eau_obj_id == -1)
        return 0;

    unk_1 = (x + 50) / 101;
    unk_2 = unk_1 * 101;
    unk_obj_id = eau_obj_id + unk_1 % 5;
    unk_3 = 51 - ABS(x - unk_2);
    unk_obj = &level.objects[unk_obj_id];

    return unk_obj->y_pos -
           unk_3 * EauDy[(unk_obj->anim_frame + DecEau[unk_obj->anim_index]) % 14] / 50;
}
