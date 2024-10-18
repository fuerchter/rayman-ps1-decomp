#include "moteur_init_end.h"

/*
score of ???
idk what it wants from me in the save1.link_init loop
*/
/*INCLUDE_ASM("asm/nonmatchings/moteur_init_end", restore_gendoor_link);*/

void restore_gendoor_link(void)
{
    Obj *temp_v1;
    Obj *var_v0_2;
    Obj *var_a2;
    s16 var_t0;
    s16 var_v0_1;
    s32 temp_a0_3;
    s32 var_a0;
    s16 temp_a0_1;
    u16 temp_a0_2;
    s16 var_a1;
    u32 var_v1;
    u8 temp_a1;
    s16 test_1;

    var_t0 = 0;
    var_a2 = &level.objects[0];
    test_1 = level.nb_objects;
    while (var_t0 < test_1)
    {
        if (var_a2->type == 0xA4)
        {
            if (var_a2->flags & 0x400)
            {
                var_a1 = var_a2->field24_0x3e;
                do
                {
                    temp_a0_1 = var_a1;
                    var_a1 = link_init[var_a1];
                } while (var_a1 != var_a2->field24_0x3e);
                link_init[var_a2->id] = var_a1;
                link_init[temp_a0_1] = var_a2->id;
                var_a2->flags = (var_a2->flags | 0x1000);
                level.objects[temp_a0_1].flags |= 0x1000;
                goto block_12;
            }
            temp_a0_2 = (u16) var_a2->id;
            var_a0 = temp_a0_2 << 0x10;
            if ((s16) temp_a0_2 != save1.link_init[temp_a0_2])
            {
                do
                {
                    temp_a0_3 = var_a0 >> 0x10;
                    temp_a1 = save1.link_init[temp_a0_3];
                    link_init[temp_a0_3] = temp_a1;
                    if (temp_a0_3 != temp_a1)
                    {
                        level.objects[temp_a0_3].flags |= 0x1000;
                    }
                    else
                    {
                        level.objects[temp_a0_3].flags &= ~0x1000;
                    }
                    var_a0 = temp_a1 << 0x10;
                } while (var_a2->id != (s16) temp_a1);
            }
        }
block_12:
        var_t0 = var_t0 + 1;
        var_a2 += 1;
    }
}

/* lower score, but not sure if busted */
void restore_gendoor_link(void)
{
    Obj *temp_v1;
    Obj *var_v0_2;
    Obj *var_a2;
    s16 var_t0;
    s16 var_v0_1;
    s32 temp_a0_3;
    s32 var_a0;
    s16 temp_a0_1;
    s32 temp_a0_2;
    s16 var_a1;
    u32 var_v1;
    s16 temp_a1;
    s16 test_1;

    var_t0 = 0;
    var_a2 = &level.objects[0];
    test_1 = level.nb_objects;
    while (var_t0 < test_1)
    {
        if (var_a2->type == 0xA4)
        {
            if (var_a2->flags & 0x400)
            {
                var_a1 = var_a2->field24_0x3e;
                do
                {
                    temp_a0_1 = var_a1;
                    var_a1 = link_init[var_a1];
                } while (var_a1 != var_a2->field24_0x3e);
                link_init[var_a2->id] = var_a1;
                link_init[temp_a0_1] = var_a2->id;
                var_a2->flags = (var_a2->flags | 0x1000);
                level.objects[temp_a0_1].flags |= 0x1000;
                goto block_12;
            }
            
            temp_a1 = save1.link_init[var_a2->id];
            while (temp_a1 != var_a2->id)
            {
                temp_a0_3 = temp_a1;
                temp_a1 = save1.link_init[temp_a0_3];
                link_init[temp_a0_3] = temp_a1;
                if (temp_a0_3 != temp_a1)
                {
                    level.objects[temp_a0_3].flags |= 0x1000;
                }
                else
                {
                    level.objects[temp_a0_3].flags &= ~0x1000;
                }
            }
        }
block_12:
        var_t0 = var_t0 + 1;
        var_a2 += 1;
    }
}