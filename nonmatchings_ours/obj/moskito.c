#include "obj/moskito.h"

/* 6F988 80194188 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/moskito", closeEnoughToSting);*/

s32 closeEnoughToSting(Obj *arg0, u16 arg1, u16 arg2)
{
    s16 sting_x;
    s16 sting_y;
    s32 var_a0;
    s32 var_v1;
    s32 var_v0;
    s16 test;
    u16 new_var2;
    s16 test2;
    int new_var;

    getIdealStingCoords(arg0, &sting_x, &sting_y);
    var_v0 = 0;
    var_v1 = (s16)(sting_x - arg0->x_pos);
    var_a0 = arg1;
    test = arg0->y_pos;
    if (var_v1 < 0)
    {
        var_v1 = -var_v1;
    }
    sting_x = var_v1;
    var_v1 = (s16)var_v1 < var_a0;
    var_a0 = (s16)(sting_y - test);
    if (var_a0 < 0)
    {
        var_a0 = -var_a0;
    }
    sting_y = var_a0;
    if (var_v1)
    {
        var_v0 = (s16)var_a0 < arg2;
    }
    return var_v0;
}