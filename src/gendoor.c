#include "gendoor.h"

/* 31D3C 8015653C -O2 -msoft-float */
void deactivate_ship_links(void)
{
    Obj *bateau_obj;
    u8 linked;

    if (bateau_obj_id != -1)
    {
        bateau_obj = &level.objects[bateau_obj_id];
        if (bateau_obj->flags & FLG(OBJ_LINKED))
        {
            linked = link_init[bateau_obj->id];
            while (linked != bateau_obj->id)
            {
                level.objects[linked].flags &= ~FLG(OBJ_ALIVE);
                linked = link_init[linked];
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/gendoor", linkListHoldsAGendoor);

INCLUDE_ASM("asm/nonmatchings/gendoor", FUN_8015666c);

INCLUDE_ASM("asm/nonmatchings/gendoor", FUN_80156710);

INCLUDE_ASM("asm/nonmatchings/gendoor", correct_gendoor_link);

INCLUDE_ASM("asm/nonmatchings/gendoor", suppressFromLinkList);

INCLUDE_ASM("asm/nonmatchings/gendoor", correct_link);
