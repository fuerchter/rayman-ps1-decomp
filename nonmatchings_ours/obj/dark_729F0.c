#include "obj/dark_729F0.h"

/* matches, but cursed */
/*INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", init_vitraux);*/

void init_vitraux(void)
{
    u8 bVar1;
    s16 sVar2;
    s32 boss_index_2;
    Obj *cur_obj;
    u8 boss_index_1;
    u8 i;
    s16 nb_objs;

    cur_obj = &level.objects[0];
    nb_objs = level.nb_objects;

    boss_index_1 = 0;
    i = 0;

    while (i < nb_objs)
    {
        boss_index_2 = boss_index_1;
        if (boss_index_1 > 4)
            return;
        
        if (cur_obj->type == TYPE_VITRAIL)
        {
            VitrauxInfos[boss_index_2].obj_id = i;
            VitrauxInfos[boss_index_2].x_pos = cur_obj->offset_bx + cur_obj->x_pos;
            bVar1 = cur_obj->offset_by;
            sVar2 = cur_obj->y_pos;
            VitrauxInfos[boss_index_2].index = boss_index_1;
            VitrauxInfos[boss_index_2].y_pos = bVar1;
            VitrauxInfos[boss_index_2].y_pos += sVar2;
            VitrauxInfos[boss_index_1].field4_0x6 = 0;
            VitrauxInfos[boss_index_1].mode = 0;
            VitrauxInfos[boss_index_1].value = 0;
            cur_obj->field23_0x3c = boss_index_1;
            boss_index_1++;
        }
        i++;
        cur_obj++;
    }
}

/* matches, but cursed */
/*INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", poing_face_obj);*/

s32 poing_face_obj(Obj *obj)
{
    Obj *temp_v0;
    s32 temp_a2;
    s32 var_a3;

    temp_v0 = &level.objects[poing_obj_id];
    var_a3 = 0;
    temp_a2 = temp_v0->flags >> 0xE;
    temp_a2 &= 1;
    if (((obj->x_pos + obj->offset_bx) - (temp_v0->x_pos + temp_v0->offset_bx)) > 0)
    {
        if (temp_a2 == 1)
        {
            goto block_4;
        }
    }
    else if (temp_a2 == 0)
    {
block_4:
        var_a3 = 1;
    }
    return var_a3;
}