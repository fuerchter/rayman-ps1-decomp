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

/* 31DEC 801565EC -O2 -msoft-float */
s32 linkListHoldsAGendoor(Obj *obj)
{
    s32 res = false;
    u8 linked = link_init[obj->id];

    while (linked != obj->id)
    {
        if (level.objects[linked].type == TYPE_GENERATING_DOOR)
        {
            res = true;
            break;
        }
        linked = link_init[linked];
    }
    return res;
}

/* 31E6C 8015666C -O2 -msoft-float */
s32 FUN_8015666c(Obj *obj)
{
    ObjType type = obj->type;

    if (
        type == TYPE_BADGUY1 || type == TYPE_BADGUY2 || type == TYPE_BADGUY3 ||
        type == TYPE_ONEUP || type == TYPE_JAUGEUP ||
        type == TYPE_FALLING_OBJ || type == TYPE_FALLING_OBJ2 || type == TYPE_FALLING_OBJ3 ||
        type == TYPE_FALLING_YING || type == TYPE_FALLING_YING_OUYE ||
        type == TYPE_REDUCTEUR || type == TYPE_CAGE || type == TYPE_BULLET || type == TYPE_BLACKTOON1 ||
        type == TYPE_STONEBOMB2 || type == TYPE_STONEBOMB3 ||
        type == TYPE_PI || type == TYPE_AUDIOSTART
    )
        return true;
    return false;
}

INCLUDE_ASM("asm/nonmatchings/gendoor", FUN_80156710);

INCLUDE_ASM("asm/nonmatchings/gendoor", correct_gendoor_link);

INCLUDE_ASM("asm/nonmatchings/gendoor", suppressFromLinkList);

INCLUDE_ASM("asm/nonmatchings/gendoor", correct_link);
