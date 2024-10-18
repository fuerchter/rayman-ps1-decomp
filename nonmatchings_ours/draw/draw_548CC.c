#include "draw/draw_548CC.h"

/* score of ??? */
/*INCLUDE_ASM("asm/nonmatchings/draw/draw_548CC", Display_and_free_luciole);*/

void Display_and_free_luciole(void)
{
    s16 temp_a0_1;
    s16 temp_a2;
    s16 temp_t0;
    s16 temp_t1;
    s16 temp_t1_2;
    s16 temp_t2;
    s16 temp_t3;
    s16 temp_t4;
    s16 temp_t5;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 temp_v0_7;
    s16 temp_v0_8;
    s32 var_a1_1;
    s16 var_a1_2;
    u16 var_s3_1;
    s16 var_s3_2;
    s16 var_s3_3;
    s16 var_s3_4;
    s16 var_s3_5;
    s16 var_s3_6;
    s16 var_s3_7;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_v1;
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_v0_1;
    s32 temp_v1_1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    u16 var_s2;
    s32 var_s2_2;
    s32 var_v0;
    void *temp_a0_2;
    void *temp_a0_3;
    s16 sVar2_1;
    s16 sVar16;
    u16 test_1 = 0x100;

    var_v0 = rand();
    temp_v0_1 = var_v0 - ((var_v0 / 4) * 4);
    temp_a0_1 = temp_v0_1 + 0x97;
    sVar2_1 = temp_a0_1 >> 2;
    sVar16 = temp_a0_1 >> 1;
    if ((u8) dead_time >= 0x40U)
    {
        var_s3_3 = 0;
        if (PS1_CanPlayDeathMusic != 0)
        {
            var_s2 = 0;
            if (*(s32 *)&D_801CF06C[0] != 0)
            {
                do
                {
                    D_801E4E60[var_s3_3].x = (s16) ((s32) (rcos(var_s2) * 0x2D) >> 0xC);
                    D_801E4E60[var_s3_3].y = (s16) ((s32) (rsin(var_s2) * 0x2D) >> 0xC);
                    D_801E4EA8[var_s3_3].x = (s16) ((u32) (rcos(var_s2) * 5) >> 8);
                    D_801E4EA8[var_s3_3].y = (s16) ((u32) (rsin(var_s2) * 5) >> 8);
                    var_s3_3 = var_s3_3 + 1;
                    var_s2 -= test_1;
                } while (var_s3_3 < 0x10);
                D_801CF064 = 0;
                D_801CF068 = 1;
                D_801CF066 = 1;
                *(s32 *)&D_801CF06C[0] = 0;
            }
            D_801CF418 = (u16) x_luc - sVar16; /* TODO: stack? */
            D_801CF428 = temp_v0_1 + (u16) x_luc;
            D_801CF420 = (u16) y_luc - sVar16;
            D_801CF430 = temp_v0_1 + (u16) y_luc;
        }
        else
        {
            goto block_9;
        }
    }
    else
    {
        var_s3_3 = 0;
block_9:
        var_s2 = 0;
        D_801CF066 = 0x2D - (u16) D_801CF064;
        D_801CF068 = 0x50 - (u16) D_801CF064;
        do
        {
            if (D_801CF066 > 0)
            {
                D_801E4E60[var_s3_3].x = (s16) ((s32) (D_801CF066 * rcos(var_s2)) >> 0xC);
                D_801E4E60[var_s3_3].y = (s16) ((s32) (D_801CF066 * rsin(var_s2)) >> 0xC);
            }
            if (D_801CF068 > 0)
            {
                D_801E4EA8[var_s3_3].x = (s16) ((s32) (D_801CF068 * rcos(var_s2)) >> 0xC);
                D_801E4EA8[var_s3_3].y = (s16) ((s32) (D_801CF068 * rsin(var_s2)) >> 0xC);
            }
            var_s3_3 = var_s3_3 + 1;
            var_s2 -= test_1;
        } while (var_s3_3 < 0x10);
        *(s32 *)&D_801CF06C[0] = 1;
        D_801CF064 = (u16) D_801CF064 + 1;
        
    }
    var_s3_3 = 0;
    do
    {
        SetPolyF4(&PS1_CurrentDisplay->unk_poly_f4s[var_s3_3]);
        SetSemiTrans(&PS1_CurrentDisplay->unk_poly_f4s[var_s3_3], 0);
        SetShadeTex(&PS1_CurrentDisplay->unk_poly_f4s[var_s3_3], 1);
        
        (PS1_CurrentDisplay->unk_poly_f4s + var_s3_3)->r0 = 0; /* TODO: bleh */
        PS1_CurrentDisplay->unk_poly_f4s[var_s3_3].g0 = 0;
        PS1_CurrentDisplay->unk_poly_f4s[var_s3_3].b0 = 0;
        SetPolyG4(&PS1_CurrentDisplay->unk_poly_g4s[var_s3_3]);
        SetSemiTrans(&PS1_CurrentDisplay->unk_poly_g4s[var_s3_3], 1);
        SetShadeTex(&PS1_CurrentDisplay->unk_poly_g4s[var_s3_3], 1);
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].r0 = 0x0A;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].g0 = 0x1E;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].b0 = 0x50;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].r1 = 0x0A;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].g1 = 0x1E;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].b1 = 0x50;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].r2 = 0xFF;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].g2 = 0xFF;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].b2 = 0xFF;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].r3 = 0xFF;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].g3 = 0xFF;
        PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].b3 = 0xFF;
        temp_s1_2 = var_s3_3 * 0x1C;
        SetPolyG3(&PS1_CurrentDisplay->unk_poly_g3s[var_s3_3]);
        SetSemiTrans(&PS1_CurrentDisplay->unk_poly_g3s[var_s3_3], 1);
        SetShadeTex(&PS1_CurrentDisplay->unk_poly_g3s[var_s3_3], 1);
        PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].r0 = 0x0A;
        PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].g0 = 0x1E;
        PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].b0 = 0x64;
        PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].r1 = 0x0A;
        PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].g1 = 0x1E;
        PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].b1 = 0x50;
        PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].r2 = 0x0A;
        PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].g2 = 0x1E;
        PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].b2 = 0x50;
        var_s3_3 = var_s3_3 + 1;
        /*(temp_s1_2 + PS1_CurrentDisplay)->unk6B12 = 0x50;*/
    } while (var_s3_3 < 0x10);
    if ((D_801CF066 > 0) || (D_801CF068 > 0))
    {
        var_a1_1 = D_801CF420;
        PS1_CurrentDisplay->field_0x66dc_0x673b[0].x0 = 0;
        PS1_CurrentDisplay->field_0x66dc_0x673b[0].y0 = 0;
        PS1_CurrentDisplay->field_0x66dc_0x673b[0].w = 0x0140;
        if (var_a1_1 < 0)
        {
            var_a1_1 = 0;
        }
        PS1_CurrentDisplay->field_0x66dc_0x673b[0].code &= 0xFD;
        PS1_CurrentDisplay->field_0x66dc_0x673b[0].h = var_a1_1;
        PS1_CurrentDisplay->field_0x66dc_0x673b[1].x0 = 0;
        PS1_CurrentDisplay->field_0x66dc_0x673b[1].y0 = temp_a0_1 + (u16) D_801CF420;
        var_a1_1 = (0xF0 - temp_a0_1) - (s16) (u16) D_801CF420;
        PS1_CurrentDisplay->field_0x66dc_0x673b[1].w = 0x0140;
        if (var_a1_1 < 0)
        {
            var_a1_1 = 0;
        }
        PS1_CurrentDisplay->field_0x66dc_0x673b[1].code &= 0xFD;
        var_a1_1 = D_801CF418;
        PS1_CurrentDisplay->field_0x66dc_0x673b[1].h = var_a1_1;
        PS1_CurrentDisplay->field_0x66dc_0x673b[2].x0 = 0;
        PS1_CurrentDisplay->field_0x66dc_0x673b[2].y0 = (s16) (u16) D_801CF420;
        if (var_a1_1 < 0)
        {
            var_a1_1 = 0;
        }
        PS1_CurrentDisplay->field_0x66dc_0x673b[2].w = var_a1_1;
        PS1_CurrentDisplay->field_0x66dc_0x673b[2].h = temp_a0_1;
        PS1_CurrentDisplay->field_0x66dc_0x673b[2].code &= 0xFD;
        PS1_CurrentDisplay->field_0x66dc_0x673b[3].x0 = temp_a0_1 + (u16) D_801CF418;
        PS1_CurrentDisplay->field_0x66dc_0x673b[3].y0 = D_801CF420;
        PS1_CurrentDisplay->field_0x66dc_0x673b[3].code &= 0xFD;
        var_a1_1 = (0x140 - (s16) temp_a0_1) - D_801CF418;
        if (var_a1_1 < 0)
        {
            var_a1_1 = 0;
        }
        PS1_CurrentDisplay->field_0x66dc_0x673b[3].w = var_a1_1;
        PS1_CurrentDisplay->field_0x66dc_0x673b[3].h = temp_a0_1;
        AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->field_0x66dc_0x673b[0]);
        AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->field_0x66dc_0x673b[1]);
        AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->field_0x66dc_0x673b[2]);
        AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->field_0x66dc_0x673b[3]);
        goto skipped;
addprim:
        PS1_CurrentDisplay->field_0x66dc_0x673b[0].x0 = 0;
        PS1_CurrentDisplay->field_0x66dc_0x673b[0].y0 = 0;
        PS1_CurrentDisplay->field_0x66dc_0x673b[0].w = 0x0140;
        PS1_CurrentDisplay->field_0x66dc_0x673b[0].h = 0x00F0;
        AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->field_0x66dc_0x673b[0]);
        return;
skipped:
        PS1_CurrentDisplay->unk_poly_f4s[0].x0 = (u16) D_801E4EA8[0].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0].y0 = D_801E4EA8[0].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0].x1 = D_801E4EA8[1].x + (u16) D_801CF428;
        temp_t0 = temp_a0_1 + (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[0].x2 = temp_t0;
        PS1_CurrentDisplay->unk_poly_f4s[0].x3 = temp_t0;
        temp_t5 = sVar16 + (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[0].y2 = temp_t5;
        PS1_CurrentDisplay->unk_poly_f4s[0].y1 = D_801E4EA8[1].y + (u16) D_801CF430;
        temp_t1 = sVar2_1 + (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[0].y3 = temp_t1;
        PS1_CurrentDisplay->unk_poly_f4s[1].x0 = D_801E4EA8[1].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[1].y0 = D_801E4EA8[1].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[1].x1 = D_801E4EA8[2].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[1].x2 = temp_t0;
        PS1_CurrentDisplay->unk_poly_f4s[1].y2 = temp_t1;
        PS1_CurrentDisplay->unk_poly_f4s[1].x3 = temp_t0;
        PS1_CurrentDisplay->unk_poly_f4s[1].y3 = (s16) (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[1].y1 = D_801E4EA8[2].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[2].x0 = D_801E4EA8[2].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[2].y0 = D_801E4EA8[2].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[2].x1 = D_801E4EA8[3].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[2].x2 = temp_t0;
        PS1_CurrentDisplay->unk_poly_f4s[2].y2 = (s16) (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[2].y3 = (s16) (u16) D_801CF420;
        temp_t4 = sVar2_1 + sVar16 + (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[2].x3 = temp_t4;
        PS1_CurrentDisplay->unk_poly_f4s[2].y1 = D_801E4EA8[3].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[3].x0 = D_801E4EA8[3].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[3].y0 = D_801E4EA8[3].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[3].x1 = D_801E4EA8[4].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[3].x2 = temp_t4;
        PS1_CurrentDisplay->unk_poly_f4s[3].y2 = (s16) (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[3].y3 = (s16) (u16) D_801CF420;
        temp_t3 = sVar16 + (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[3].x3 = temp_t3;
        PS1_CurrentDisplay->unk_poly_f4s[3].y1 = D_801E4EA8[4].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[4].x0 = D_801E4EA8[4].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[4].y0 = D_801E4EA8[4].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[4].x1 = D_801E4EA8[5].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[4].x2 = temp_t3;
        PS1_CurrentDisplay->unk_poly_f4s[4].y2 = (s16) (u16) D_801CF420;
        temp_t2 = sVar2_1 + (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[4].x3 = temp_t2;
        PS1_CurrentDisplay->unk_poly_f4s[4].y3 = (s16) (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[4].y1 = D_801E4EA8[5].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[5].x0 = D_801E4EA8[5].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[5].y0 = D_801E4EA8[5].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[5].x1 = D_801E4EA8[6].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[5].x2 = temp_t2;
        PS1_CurrentDisplay->unk_poly_f4s[5].y2 = (s16) (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[5].x3 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[5].y3 = (s16) (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[5].y1 = D_801E4EA8[6].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[6].x0 = D_801E4EA8[6].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[6].y0 = D_801E4EA8[6].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[6].x1 = D_801E4EA8[7].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[6].x2 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[6].y2 = (s16) (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[6].x3 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[6].y3 = temp_t1;
        PS1_CurrentDisplay->unk_poly_f4s[6].y1 = D_801E4EA8[7].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[7].x0 = D_801E4EA8[7].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[7].y0 = D_801E4EA8[7].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[7].x1 = D_801E4EA8[8].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[7].x2 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[7].y2 = temp_t1;
        PS1_CurrentDisplay->unk_poly_f4s[7].x3 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[7].y3 = temp_t5;
        PS1_CurrentDisplay->unk_poly_f4s[7].y1 = D_801E4EA8[8].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[8].x0 = D_801E4EA8[8].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[8].y0 = D_801E4EA8[8].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[8].x1 = D_801E4EA8[9].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[8].x2 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[8].y2 = temp_t5;
        PS1_CurrentDisplay->unk_poly_f4s[8].x3 = (s16) (u16) D_801CF418;
        temp_t1_2 = sVar2_1 + sVar16 + (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[8].y3 = temp_t1_2;
        PS1_CurrentDisplay->unk_poly_f4s[8].y1 = D_801E4EA8[9].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[9].x0 = D_801E4EA8[9].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[9].y0 = D_801E4EA8[9].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[9].x1 = D_801E4EA8[10].x + (u16) D_801CF428;
        temp_a2 = temp_a0_1 + (u16) D_801CF420;
        PS1_CurrentDisplay->unk_poly_f4s[9].x2 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[9].y2 = temp_t1_2;
        PS1_CurrentDisplay->unk_poly_f4s[9].x3 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[9].y3 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[9].y1 = D_801E4EA8[10].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[9].x0 = D_801E4EA8[9].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[9].y0 = D_801E4EA8[9].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[9].x1 = D_801E4EA8[10].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[9].x2 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[9].y2 = temp_t1_2;
        PS1_CurrentDisplay->unk_poly_f4s[9].x3 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[9].y1 = D_801E4EA8[10].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[9].y3 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[0xA].x0 = D_801E4EA8[10].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xA].y0 = D_801E4EA8[10].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xA].x1 = D_801E4EA8[11].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xA].x2 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->unk_poly_f4s[0xA].y2 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[0xA].x3 = temp_t2;
        PS1_CurrentDisplay->unk_poly_f4s[0xA].y3 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[0xA].y1 = D_801E4EA8[11].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xB].x0 = D_801E4EA8[11].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xB].y0 = D_801E4EA8[11].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xB].x1 = D_801E4EA8[12].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xB].x2 = temp_t2;
        PS1_CurrentDisplay->unk_poly_f4s[0xB].y2 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[0xB].x3 = temp_t3;
        PS1_CurrentDisplay->unk_poly_f4s[0xB].y3 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[0xB].y1 = D_801E4EA8[12].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xC].x0 = D_801E4EA8[12].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xC].y0 = D_801E4EA8[12].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xC].x1 = D_801E4EA8[13].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xC].x2 = temp_t3;
        PS1_CurrentDisplay->unk_poly_f4s[0xC].y1 = D_801E4EA8[13].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xC].y2 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[0xC].x3 = temp_t4;
        PS1_CurrentDisplay->unk_poly_f4s[0xC].y3 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[0xD].x0 = D_801E4EA8[13].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xD].y0 = D_801E4EA8[13].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xD].x1 = D_801E4EA8[14].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xD].x2 = temp_t4;
        PS1_CurrentDisplay->unk_poly_f4s[0xD].y2 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[0xD].x3 = temp_t0;
        PS1_CurrentDisplay->unk_poly_f4s[0xD].y3 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[0xD].y1 = D_801E4EA8[14].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xE].x0 = D_801E4EA8[14].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xE].y0 = D_801E4EA8[14].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xE].x1 = D_801E4EA8[15].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xE].x2 = temp_t0;
        PS1_CurrentDisplay->unk_poly_f4s[0xE].y2 = temp_a2;
        PS1_CurrentDisplay->unk_poly_f4s[0xE].x3 = temp_t0;
        PS1_CurrentDisplay->unk_poly_f4s[0xE].y3 = temp_t1_2;
        PS1_CurrentDisplay->unk_poly_f4s[0xE].y1 = D_801E4EA8[15].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xF].x0 = D_801E4EA8[15].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xF].y0 = D_801E4EA8[15].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xF].x1 = (u16) D_801E4EA8[0].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_f4s[0xF].y1 = D_801E4EA8[0].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_f4s[0xF].x2 = temp_t0;
        PS1_CurrentDisplay->unk_poly_f4s[0xF].y2 = temp_t1_2;
        PS1_CurrentDisplay->unk_poly_f4s[0xF].x3 = temp_t0;
        PS1_CurrentDisplay->unk_poly_f4s[0xF].y3 = temp_t5;
        var_s3_3 = 0;
        do
        {
            AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->unk_poly_f4s[var_s3_3]);
            var_s3_3 = var_s3_3 + 1;
        } while (var_s3_3 < 0x10);
        var_s3_3 = 0;
        do
        {
            PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].x0 = (u16) D_801E4E60[var_s3_3].x + (u16) D_801CF428;
            /* TODO: ??? */
            temp_v1_2 = var_s3_3 + 1;
            temp_v1_3 = temp_v1_2 * 4;
            PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].y0 = D_801E4E60[var_s3_3].y + (u16) D_801CF430;
            PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].x1 = (u16) D_801E4E60[temp_v1_2].x + (u16) D_801CF428;
            PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].y1 = D_801E4E60[temp_v1_3].y + (u16) D_801CF430;
            PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].x2 = (u16) D_801E4EA8[var_s3_3].x + (u16) D_801CF428;
            PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].y2 = D_801E4EA8[var_s3_3].y + (u16) D_801CF430;
            PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].x3 = (u16) D_801E4EA8[temp_v1_2].x + (u16) D_801CF428;
            PS1_CurrentDisplay->unk_poly_g4s[var_s3_3].y3 = (s16) ((D_801E4EA8[temp_v1_3].y) + (u16) D_801CF430);
            var_s3_3 = var_s3_3 + 1;
        } while (var_s3_3 < 0xF);
        PS1_CurrentDisplay->unk_poly_g4s[0xF].x0 = D_801E4E60[15].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_g4s[0xF].y0 = D_801E4E60[15].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_g4s[0xF].x1 = (u16) D_801E4E60[0].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_g4s[0xF].y1 = D_801E4E60[0].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_g4s[0xF].x2 = D_801E4EA8[15].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_g4s[0xF].y2 = D_801E4EA8[15].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_g4s[0xF].x3 = (u16) D_801E4EA8[0].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_g4s[0xF].y3 = D_801E4EA8[0].y + (u16) D_801CF430;

        var_s3_3 = 0;
        do
        {
            AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->unk_poly_g4s[var_s3_3]);
            var_s3_3 = var_s3_3 + 1;
        } while (var_s3_3 < 0x10);
        PS1_CurrentDisplay->drawing_environment.tpage = GetTPage(1, 2, 0x00000100, 0);
        SetDrawEnv(&PS1_CurrentDisplay->map_drawing_environment_primitives[D_801E4BE0], &PS1_CurrentDisplay->drawing_environment);
        AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->map_drawing_environment_primitives[D_801E4BE0]);
        var_s3_3 = 0;
        D_801E4BE0 = (u16) D_801E4BE0 + 1;
        do
        {
            (PS1_CurrentDisplay->unk_poly_g3s + var_s3_3)->x0 = (s16) (u16) D_801CF428;
            PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].y0 = (s16) (u16) D_801CF430;
            PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].x1 = (u16) D_801E4E60[var_s3_3].x + (u16) D_801CF428;
            PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].y1 = (D_801E4E60[var_s3_3].y) + (u16) D_801CF430;
            PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].x2 = (u16) D_801E4E60[var_s3_3 + 1].x + (u16) D_801CF428;
            PS1_CurrentDisplay->unk_poly_g3s[var_s3_3].y2 = (s16) ((D_801E4E60[var_s3_3 + 1].y) + (u16) D_801CF430);
            var_s3_3 = var_s3_3 + 1;
        } while (var_s3_3 < 0xF);
        PS1_CurrentDisplay->unk_poly_g3s[0xF].x0 = (s16) (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_g3s[0xF].y0 = (s16) (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_g3s[0xF].x1 = D_801E4E60[15].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_g3s[0xF].y1 = D_801E4E60[15].y + (u16) D_801CF430;
        PS1_CurrentDisplay->unk_poly_g3s[0xF].x2 = (u16) D_801E4E60[0].x + (u16) D_801CF428;
        PS1_CurrentDisplay->unk_poly_g3s[0xF].y2 = D_801E4E60[0].y + (u16) D_801CF430;

        var_s3_3 = 0;
        do
        {
            AddPrim(&PS1_CurrentDisplay->ordering_table[5], &PS1_CurrentDisplay->unk_poly_g3s[var_s3_3]);
            var_s3_3 = var_s3_3 + 1;
        } while (var_s3_3 < 0x10);
        PS1_CurrentDisplay->drawing_environment.tpage = GetTPage(1, 2, 0x00000100, 0);
        SetDrawEnv(&PS1_CurrentDisplay->map_drawing_environment_primitives[D_801E4BE0], &PS1_CurrentDisplay->drawing_environment);
        AddPrim(&PS1_CurrentDisplay->ordering_table[5], &PS1_CurrentDisplay->map_drawing_environment_primitives[D_801E4BE0]);
        D_801E4BE0 = (u16) D_801E4BE0 + 1;
        PS1_CurrentDisplay->field_0x66dc_0x673b[4].code |= 2;
        PS1_CurrentDisplay->field_0x66dc_0x673b[4].h = temp_a0_1;
        PS1_CurrentDisplay->field_0x66dc_0x673b[4].x0 = (s16) (u16) D_801CF418;
        PS1_CurrentDisplay->field_0x66dc_0x673b[4].y0 = (s16) (u16) D_801CF420;
        PS1_CurrentDisplay->field_0x66dc_0x673b[4].w = (s16) temp_a0_1;
        PS1_CurrentDisplay->field_0x66dc_0x673b[4].r0 = 0x78;
        PS1_CurrentDisplay->field_0x66dc_0x673b[4].g0 = 0x78;
        PS1_CurrentDisplay->field_0x66dc_0x673b[4].b0 = 0x50;
        AddPrim(&PS1_CurrentDisplay->ordering_table[5], &PS1_CurrentDisplay->field_0x66dc_0x673b[4]);
        PS1_CurrentDisplay->drawing_environment.tpage = GetTPage(1, 1, 0x00000100, 0);
        SetDrawEnv(&PS1_CurrentDisplay->map_drawing_environment_primitives[D_801E4BE0], &PS1_CurrentDisplay->drawing_environment);
        AddPrim(&PS1_CurrentDisplay->ordering_table[5], &PS1_CurrentDisplay->map_drawing_environment_primitives[D_801E4BE0]);
        D_801E4BE0 = (u16) D_801E4BE0 + 1;
        return;
    }
    goto addprim;
}

/* matches, but cleanup */
/*INCLUDE_ASM("asm/nonmatchings/draw/draw_548CC", DISPLAY_FOND_MENU);*/

void DISPLAY_FOND_MENU(void)
{
  Display *pDVar1;
  u_short uVar2;
  uint uVar3;
  s16 iVar4;
  u16 uVar5;
  u16 uVar6;
  u16 *new_var;
  s32 test_4;
  u16 test_1 = 0x100;
  u16 test_2 = 0xa0;
  u16 test_3 = 0x78;
  
  uVar6 = 0;
  do {
    
    SetPolyG4(PS1_CurrentDisplay->unk_poly_g4s + uVar6);
    SetSemiTrans(PS1_CurrentDisplay->unk_poly_g4s + uVar6,0);
    SetShadeTex(PS1_CurrentDisplay->unk_poly_g4s + uVar6,1);
    SetPolyG3(PS1_CurrentDisplay->unk_poly_g3s + uVar6);
    SetSemiTrans(PS1_CurrentDisplay->unk_poly_g3s + uVar6,0);
    SetShadeTex(PS1_CurrentDisplay->unk_poly_g3s + uVar6,1);
    test_4 = uVar6;
    uVar5 = test_4 & 3; /* ??? */
    if (uVar5 != 3) {
      iVar4 = uVar5 + 1;
      
    }
    else {
      iVar4 = 0;
    }
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->r0 = D_801C7EAC[uVar5].r;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->g0 = D_801C7EAC[uVar5].g;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->b0 = D_801C7EAC[uVar5].b;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->r1 = D_801C7EAC[iVar4].r;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->g1 = D_801C7EAC[iVar4].g;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->b1 = D_801C7EAC[iVar4].b;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->r1 = D_801C7EAC[uVar5].r;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->g1 = D_801C7EAC[uVar5].g;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->b1 = D_801C7EAC[uVar5].b;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->r2 = D_801C7EAC[iVar4].r;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->g2 = D_801C7EAC[iVar4].g;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->b2 = D_801C7EAC[iVar4].b;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->r2 = '\0';
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->g2 = '\0';
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->b2 = '\0';
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->r3 = '\0';
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->g3 = '\0';
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->b3 = '\0';
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->r0 = '\0';
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->g0 = '\0';
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->b0 = '\0';
    
    D_801FAA48[0].x = (short)(D_801CF096 * rcos((uint)D_801CF090) >> 0xc) + test_2;
    D_801FAA48[0].y = (short)(D_801CF096 * rsin((uint)D_801CF090) >> 0xc) + test_3;
    D_801FAA58[0].x = (short)(D_801CF098 * rcos((uint)D_801CF090) >> 0xc) + test_2;
    D_801FAA58[0].y = (short)(D_801CF098 * rsin((uint)D_801CF090) >> 0xc) + test_3;
    uVar5 = (uint)(ushort)(D_801CF090 + test_1);
    D_801FAA48[1].x = (short)(D_801CF096 * rcos(uVar5) >> 0xc) + test_2;
    D_801FAA48[1].y = (short)(D_801CF096 * rsin(uVar5) >> 0xc) + test_3;
    D_801FAA58[1].x = (short)(D_801CF098 * rcos(uVar5) >> 0xc) + test_2;
    D_801FAA58[1].y = (short)(D_801CF098 * rsin(uVar5) >> 0xc) + test_3;
    pDVar1 = PS1_CurrentDisplay;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->x0 = D_801FAA48[0].x;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->y0 = D_801FAA48[0].y;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->x1 = D_801FAA48[1].x;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->y1 = D_801FAA48[1].y;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->x2 = D_801FAA58[0].x;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->y2 = D_801FAA58[0].y;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->x3 = D_801FAA58[1].x;
    (PS1_CurrentDisplay->unk_poly_g4s + uVar6)->y3 = D_801FAA58[1].y;
    AddPrim(PS1_CurrentDisplay->ordering_table,PS1_CurrentDisplay->unk_poly_g4s + uVar6);
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->x0 = test_2;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->y0 = test_3;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->x1 = D_801FAA48[0].x;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->y1 = D_801FAA48[0].y;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->x2 = D_801FAA48[1].x;
    (PS1_CurrentDisplay->unk_poly_g3s + uVar6)->y2 = D_801FAA48[1].y;
    AddPrim(PS1_CurrentDisplay->ordering_table,PS1_CurrentDisplay->unk_poly_g3s + uVar6);
    D_801CF090 = D_801CF090 + test_1;
    uVar6 = uVar6 + 1;
  } while ((uVar6) < 0x10);
  D_801CF096 = (short)(rsin((uint)D_801CF094) * 0x4b >> 0xc) + 0x69;
  uVar2 = GetTPage(1,0,0x100,0);
  (PS1_CurrentDisplay->drawing_environment).tpage = uVar2;
  SetDrawEnv(PS1_CurrentDisplay->map_drawing_environment_primitives + D_801E4BE0,&PS1_CurrentDisplay->drawing_environment);
  AddPrim(PS1_CurrentDisplay->ordering_table + 10,
          PS1_CurrentDisplay->map_drawing_environment_primitives + D_801E4BE0);
  D_801E4BE0 = D_801E4BE0 + 1;
  
  D_801CF090 = D_801CF092;
  D_801CF094 += 10;
  D_801CF092 += 10;
  return;
}