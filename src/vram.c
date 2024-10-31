#include "vram.h"

s32 PS1_LoadToVRAM(s16 w, s16 h, s16 x, s16 y, u8 *data)
{
  RECT rect;

  rect.x = x; rect.y = y;
  rect.w = w; rect.h = h;
  LoadImage(&rect, (u32 *)data);
  DrawSync(0);
  return w * h * 2;
}

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/vram", PS1_LoadVRAMBlock);
#else
/*
matches, but clean up
try shifts vs mult (what did i mean by this???)
*/
/*INCLUDE_ASM("asm/nonmatchings/vram", PS1_LoadVRAMBlock);*/

void PS1_LoadVRAMBlock(s16 start_page, s16 start_pos, s16 end_page, s16 end_pos, s16 unused, u8 *data)
{
    u8 *temp_s0_1;
    s16 temp_t0 = start_page >> 1;
    s16 temp_s2 = start_pos >> 1;
    s16 temp_s3 = end_pos + ((start_pos & 1) << 8);
    s16 temp_a2 = end_page + ((start_page & 1) << 8);
    
    if (start_page < 0xA && start_pos >= 0xA)
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
            temp_s0_1 = &temp_s0_1[PS1_LoadToVRAM(
                (
                    ((temp_s2 - 1) > 0 ? (((temp_s2 - 2) << 7) + 0x40) : 0) +
                    ((temp_t0 + 1) > 0 ? (-(temp_t0 << 7) - 0x40) : 0)
                ),
                0x0200,
                (temp_t0 + 1) > 0 ? (temp_t0 << 7) + 0x180 : 0x140,
                0,
                temp_s0_1
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
            (
                (temp_s2 > 0 ? (((temp_s2 - 1) << 7) + 0x40) : 0) +
                (temp_t0 > 0 ? (-((temp_t0 - 1) << 7) - 0x40) : 0)
            ),
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
            (
                (temp_s2 > 0 ? (((temp_s2 - 1) << 7) + 0x40) : 0) +
                ((temp_t0 + 1) > 0 ? (-(temp_t0 << 7) - 0x40) : 0)
            ),
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
#endif
