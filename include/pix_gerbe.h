#ifndef PIX_GERBE_H
#define PIX_GERBE_H

#include "common.h"
#include "collision/block_22C84.h"

typedef struct PixGerbeItem {
    s16 x_pos;
    s16 y_pos;
    u16 speed_x;
    s16 speed_y;
    u8 y_accel;
    u8 unk_1;
} PixGerbeItem;

typedef struct PixGerbe {
    PixGerbeItem items[64];
    s16 is_active;
} PixGerbe;

/**/
extern PixGerbe pix_gerbe[8];

s32 allocate_gerbe(void);
void start_pix_gerbe(s32 x_pos, s32 y_pos);
void do_pix_gerbes(void);

#endif