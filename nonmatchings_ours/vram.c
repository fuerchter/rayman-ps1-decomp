#include "vram.h"

/*
matches, but clean up
try shifts vs mult
*/
/*INCLUDE_ASM("asm/nonmatchings/vram", PS1_LoadVRAMBlock);*/

void PS1_LoadVRAMBlock(s16 start_page, s16 start_pos, s16 end_page, s16 end_pos, s16 unused, u8 *data)
{
    s16 temp_a2;
    s16 temp_s3;
    s32 var_a0_1;
    s32 var_a0_5;
    s32 var_a2_1;
    s32 var_a2_5;
    s16 temp_s2;
    s16 temp_t0;
    s32 var_v0;
    s32 var_v0_2;
    u8 *temp_s0_1;
    u8 *temp_s0_2;
    u8 *temp_s0_3;
    u8 *temp_s0_4;
    u8 *var_s0;
    u8 *new_var;

    temp_t0 = (start_page) >> 1;
    temp_s2 = (start_pos) >> 1;
    
    temp_s3 = end_pos + ((start_pos & 1) << 8);
    temp_a2 = end_page + ((start_page & 1) << 8);
    if ((start_page < 0xA) && (start_pos >= 0xA))
    {
        if (start_page >= 8)
        {
            data = &data[PS1_LoadToVRAM(
                temp_t0 != 0 ? 0x80 : 0x40,
                0x1E0 - temp_a2,
                temp_t0 > 0 ? ((temp_t0 << 7) + 0x100) : 0x0140,
                temp_a2,
                data
            )];
            PS1_LoadToVRAM(
                temp_s2 != 0 ? 0x80 : 0x40,
                temp_s3,
                temp_s2 > 0 ? ((temp_s2 << 7) + 0x100) : 0x0140,
                0,
                data
            );
        }
        else if (start_page >= 6)
        {
            temp_s0_1 = &data[PS1_LoadToVRAM(
                temp_t0 != 0 ? 0x80 : 0x40,
                0x200 - temp_a2,
                temp_t0 > 0 ? ((temp_t0 << 7) + 0x100) : 0x0140,
                temp_a2,
                data
            )];
            data = &temp_s0_1[PS1_LoadToVRAM(
                temp_s2 != 1 ? 0x80 : 0x40,
                0x01E0,
                (temp_s2 - 1) > 0 ? ((temp_s2 << 7) + 0x80) : 0x140,
                0,
                temp_s0_1
            )];
            PS1_LoadToVRAM(
                temp_s2 != 0 ? 0x80 : 0x40,
                temp_s3,
                temp_s2 > 0 ? ((temp_s2 << 7) + 0x100) : 0x0140,
                0,
                data
            );
        }
        else
        {
            temp_s0_1 = &data[PS1_LoadToVRAM(
                temp_t0 != 0 ? 0x80 : 0x40,
                0x200 - temp_a2,
                temp_t0 > 0 ? ((temp_t0 << 7) + 0x100) : 0x0140,
                temp_a2,
                data
            )];
            /*if ((temp_s2 - 1) > 0)
            {
                var_a0_5 = ((temp_s2 - 2) << 7) + 0x40;
            }
            else
            {
                var_a0_5 = 0;
            }
            if ((temp_t0 + 1) > 0)
            {
                var_a0_5 = (var_a0_5 - 0x40) - (temp_t0 << 7);
            }*/
            temp_s0_3 = &temp_s0_1[PS1_LoadToVRAM(
                ((temp_s2 - 1) > 0 ? (((temp_s2 - 2) << 7) + 0x40) : 0) + ((temp_t0 + 1) > 0 ? (- 0x40 - ((temp_t0 << 7))) : 0),
                0x0200,
                (temp_t0 + 1) > 0 ? (temp_t0 << 7) + 0x180 : 0x140,
                0,
                temp_s0_1
            )];
            data = &temp_s0_3[PS1_LoadToVRAM(
                temp_s2 != 1 ? 0x80 : 0x40,
                0x01E0,
                (temp_s2 - 1) > 0 ? ((temp_s2 << 7) + 0x80) : 0x140,
                0,
                temp_s0_3
            )];
            PS1_LoadToVRAM(
                temp_s2 != 0 ? 0x80 : 0x40,
                temp_s3,
                temp_s2 > 0 ? ((temp_s2 << 7) + 0x100) : 0x0140,
                0,
                data
            );
        }

    }
    else if (temp_t0 == temp_s2)
    {
        PS1_LoadToVRAM(
            temp_t0 != 0 ? 0x80 : 0x40,
            temp_s3 - temp_a2,
            temp_t0 > 0 ? ((temp_t0 << 7) + 0x100) : 0x0140,
            temp_a2,
            data
        );
    }
    else if (temp_a2 == 0)
    {
        data = &data[PS1_LoadToVRAM(
            ((temp_s2) > 0 ? (((temp_s2 - 1) << 7) + 0x40) : 0) + ((temp_t0) > 0 ? (- 0x40 - (((temp_t0 - 1) << 7))) : 0),
            0x0200,
            temp_t0 > 0 ? ((temp_t0 << 7) + 0x100) : 0x140,
            0,
            data
        )];
        PS1_LoadToVRAM(
            temp_s2 != 0 ? 0x80 : 0x40,
            temp_s3,
            temp_s2 > 0 ? ((temp_s2 << 7) + 0x100) : 0x0140,
            0,
            data
        );
    }
    else if ((temp_s2 - temp_t0) >= 2)
    {
        temp_s0_1 = &data[PS1_LoadToVRAM(
            temp_t0 != 0 ? 0x80 : 0x40,
            0x200 - temp_a2,
            temp_t0 > 0 ? ((temp_t0 << 7) + 0x100) : 0x0140,
            temp_a2,
            data
        )];

        data = &temp_s0_1[PS1_LoadToVRAM(
            ((temp_s2) > 0 ? (((temp_s2 - 1) << 7) + 0x40) : 0) + ((temp_t0 + 1) > 0 ? (- 0x40 - (((temp_t0) << 7))) : 0),
            0x0200,
            (temp_t0 + 1) > 0 ? (temp_t0 << 7) + 0x180 : 0x0140,
            0,
            temp_s0_1
        )];
        PS1_LoadToVRAM(
            temp_s2 != 0 ? 0x80 : 0x40,
            temp_s3,
            temp_s2 > 0 ? ((temp_s2 << 7) + 0x100) : 0x0140,
            0,
            data
        );
    }
    else
    {
        data = &data[PS1_LoadToVRAM(
            temp_t0 != 0 ? 0x80 : 0x40,
            0x200 - temp_a2,
            temp_t0 > 0 ? ((temp_t0 << 7) + 0x100) : 0x140,
            temp_a2,
            data
        )];
        PS1_LoadToVRAM(
            temp_s2 != 0 ? 0x80 : 0x40,
            temp_s3,
            temp_s2 > 0 ? ((temp_s2 << 7) + 0x100) : 0x0140,
            0,
            data
        );
    }
}