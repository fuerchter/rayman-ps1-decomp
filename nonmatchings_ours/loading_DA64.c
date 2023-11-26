#include "loading_DA64.h"

/*
feels like i need to know the type of D_801F4A40/param_1
perhaps just one or two memcpys? see FUN_80132424
*/
/*INCLUDE_ASM("asm/nonmatchings/loading_DA64", FUN_8013234c);*/

void FUN_8013234c(s32 *param_1)
{
    s32 *var_a3;
    s32 *temp_t0;
    s32 *var_a2;

    var_a3 = &D_801F4A40;
    var_a2 = param_1;
    if (((s32) var_a2 | (s32) &D_801F4A40) & 3)
    {
        __builtin_memcpy(var_a3, var_a2, 928);
    }
    else
    {
        __builtin_memcpy(var_a3, var_a2, 928);
    }
    __builtin_memcpy(var_a3, var_a2, 25);
}