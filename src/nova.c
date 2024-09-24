#include "nova.h"

INCLUDE_ASM("asm/nonmatchings/nova", allocateNOVA);

INCLUDE_ASM("asm/nonmatchings/nova", DO_NOVA);

/* 3B034 8015F834 -O2 -msoft-float */
void DO_NOVA2(Obj *in_obj)
{
    s16 i;
    Obj *nova_obj;
    s16 nova_x; s16 nova_y; s16 nova_w; s16 nova_h;
    s16 in_x; s16 in_y; s16 in_w; s16 in_h;
    s16 new_x; s16 new_y;
    
    for (i = 0; i < 5; i++)
    {
        nova_obj = allocateNOVA();
        if (nova_obj != 0)
        {
            nova_obj->x_pos = in_obj->x_pos;
            nova_obj->y_pos = in_obj->y_pos;
            GET_ANIM_POS(nova_obj, &nova_x, &nova_y, &nova_w, &nova_h);
            GET_ANIM_POS(in_obj, &in_x, &in_y, &in_w, &in_h);
            new_x = in_x - (nova_x + (nova_w >> 1));
            new_y = in_y - (nova_y + (nova_h >> 1));
            nova_obj->flags |= FLG(OBJ_ACTIVE);
            switch (i)
            {
            case 0:
                break;
            case 1:
                new_x += in_w;
                break;
            case 2:
                new_x += in_w;
                new_y += in_h;
                break;
            case 3:
                new_y += in_h;
                break;
            case 4:
                new_x += in_w >> 1;
                new_y += in_h >> 1;
                break;
            }
            nova_obj->display_prio = 0;
            nova_obj->field23_0x3c = i * 5;
            nova_obj->x_pos += new_x;
            nova_obj->y_pos += new_y;
            calc_obj_pos(nova_obj);
        }
    }
}
const u8 rodata_DO_NOVA2[4] = {};

INCLUDE_ASM("asm/nonmatchings/nova", NOVA_STATUS_BAR);
