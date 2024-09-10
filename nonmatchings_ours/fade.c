#include "fade.h"

/* matches, but cleanup and label stuff */
/*INCLUDE_ASM("asm/nonmatchings/fade", FUN_801695ec);*/

void FUN_801695ec(s16 param_1)
{
    RGBAArray **temp_v0_1;
    s16 temp_v0_3;
    s16 i;
    s32 temp_v1;
    s32 var_a1;
    s32 var_s0;
    s32 var_t0;
    u8 *temp_a0;
    u8 temp_v0_2;
    RGBAArray *new_var;

    var_s0 = 0;
    if (D_801CEFF6 == 1)
    {
        temp_v0_1 = &D_801C7D78[D_801CEFF4];
        D_801CF008.data[0] = (*temp_v0_1)->data[0];
        D_801CF008.data[1] = (*temp_v0_1)->data[1];
        D_801CF008.data[2] = (*temp_v0_1)->data[2];
        D_801CF410 = param_1;
        D_801CEFF6 = 2;
    }
    
    switch (D_801CF014)
    {
    case 0:
        for (i = 0; i < (s16) LEN(D_801CF008.data) - 1; i++)
        {
            temp_v1 = D_801CF008.data[i] - D_801CF00E;
            temp_v0_2 = -((s16) temp_v1 > 0) & temp_v1;
            D_801CF008.data[i] = temp_v0_2;
            var_a1 = false;
            if (temp_v0_2 || (s16) var_s0)
                var_a1 = true;
            var_s0 = var_a1;
        }

        if ((s16) var_s0 && D_801CEFF4 != 0)
            ((void (*)())D_801C7D68[D_801CEFF4 - 1])(&D_801CF008, D_801CF410);
        else
            D_801CF014 = 1;
        break;
    case 1:
        if (D_801CF010 == 250)
            D_801CF00C = -50;
        else if (D_801CF010 == 0)
            D_801CF00C = 50;

        D_801CF010 += D_801CF00C;
        if (D_801CF010 == 0)
            D_801CF014 = 2;

        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.r0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.g0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.b0 = D_801CF010;
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[D_801CF410],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile
        );
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[D_801CF410],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[5]
        );
        break;
    case 2:
        if (D_801CF010 == 100)
            D_801CF00C = -10;
        else if (D_801CF010 == 0)
            D_801CF00C = 10;
        
        D_801CF010 += D_801CF00C;
        if (D_801CF010 == 0)
            D_801CF014 = 3;
        
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.r0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.g0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.b0 = D_801CF010;
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[D_801CF410],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile
        );
        AddPrim(
            &PS1_CurrentDisplay->ordering_table[D_801CF410],
            &PS1_CurrentDisplay->field_0x60bc_0x660b[5]
        );
        break;
    case 3:
        for (i = 0; i < (s16) LEN(D_801CF008.data) - 1; i++)
        {
            temp_v0_3 = D_801CF008.data[i] + D_801CF00E;
            new_var = D_801C7D78[D_801CEFF4];
            temp_a0 = &new_var->data[i];
            var_t0 = false;
            MIN_2(temp_v0_3, *temp_a0);
            D_801CF008.data[i] = temp_v0_3;
            if (((u8) temp_v0_3 != D_801C7D78[D_801CEFF4]->data[i]) || (s16) var_s0)
                var_t0 = true;
            var_s0 = var_t0;
        }

        if (D_801CEFF4 != 0)
            ((void (*)())D_801C7D68[D_801CEFF4 - 1])(&D_801CF008, D_801CF410);
        
        if (!((s16) var_s0))
        {
            D_801CF012 = 0;
            D_801CF014 = 0;
            D_801CEFF6 = 0;
        }
        break;
    default:
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.r0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.g0 = D_801CF010;
        PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile.b0 = D_801CF010;
        AddPrim(&PS1_CurrentDisplay->ordering_table[D_801CF410], &PS1_CurrentDisplay->field_0x60bc_0x660b[5].tile);
        AddPrim(&PS1_CurrentDisplay->ordering_table[D_801CF410], &PS1_CurrentDisplay->field_0x60bc_0x660b[5]);
        break;    
    }
}