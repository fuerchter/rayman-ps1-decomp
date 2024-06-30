#include "gendoor.h"

/*INCLUDE_ASM("asm/nonmatchings/gendoor", correct_gendoor_link);*/

void correct_gendoor_link(void)
{
    Obj *temp_v0;
    Obj *temp_v1;
    s32 var_a0;
    s16 i;
    s16 var_v0;
    s32 var_a1;
    Obj *cur_obj;
    u8 *temp_v1_2;
    u8 temp_a1;
    s32 var_a2;
    u8 test_1[8];
    s16 new_var;
    s16 nb_objs = level.nb_objects;

    i = 0;
    cur_obj = &level.objects[0];
    if (nb_objs != 0)
    {
        do
        {
            if (cur_obj->type == 0xA4)
            {
                new_var = i;
                var_a2 = link_init[new_var];
                if (var_a2 != new_var)
                {
                    do
                    {
                        if (cur_obj->flags & 0x400)
                        {
                            level.objects[var_a2].flags &= ~0x400;
                        }
                        new_var = var_a2;
                        var_a2 = link_init[new_var];
                    } while ((var_a2 != new_var) && (var_a2 != i));
                }
                
                if (var_a2 == i)
                {
                    link_init[new_var] = link_init[var_a2];
                    temp_a1 = link_init[new_var];
                    if (temp_a1 == new_var)
                    {
                        level.objects[temp_a1].flags &= ~0x1000;
                    }

                    cur_obj->field24_0x3e = link_init[var_a2];
                    link_init[var_a2] = new_var;
                    cur_obj->flags &= ~0x1000;
                }
            }
            i++;
            cur_obj += 1;
        } while (i < nb_objs);
    }
}

/* matches, but unknowns, slight jank */
/*INCLUDE_ASM("asm/nonmatchings/gendoor", suppressFromLinkList);*/

void suppressFromLinkList(Obj *obj)
{
    s16 var_a0;
    s16 var_v0;
    u8 temp_a1;

    var_v0 = obj->id;
    /* why does this not work as do{}while? */
    var_a0 = var_v0;
    var_v0 = link_init[var_a0];
    while (var_v0 != obj->id)
    {
        var_a0 = var_v0;
        var_v0 = link_init[var_a0];
    }
    
    link_init[var_a0] = link_init[obj->id];
    temp_a1 = link_init[var_a0];
    if (temp_a1 == var_a0)
        level.objects[temp_a1].flags &= ~FLG(OBJ_LINKED);
    link_init[obj->id] = obj->id;
    obj->flags &= ~FLG(OBJ_LINKED);
}