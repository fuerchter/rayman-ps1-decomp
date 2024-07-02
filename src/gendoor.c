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
s16 linkListHoldsAGendoor(Obj *obj)
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
s16 FUN_8015666c(Obj *obj)
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

/* 31F10 80156710 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/gendoor", FUN_80156710);
#else
s16 FUN_80156710(Obj *obj)
{
    s16 type = obj->type;

    __asm__("nop");
    if (
        flags[type].flags0 & FLG(OBJ0_ALWAYS) ||
        type == TYPE_POWERUP ||
        type == TYPE_TAMBOUR1 || type == TYPE_TAMBOUR2 ||
        type == TYPE_NEIGE || type == TYPE_PALETTE_SWAPPER || type == TYPE_GRAP_BONUS ||
        type == TYPE_POING || type == TYPE_POING_POWERUP ||
        type == TYPE_LIDOLPINK2 || type == TYPE_NEUTRAL || type == TYPE_PLANCHES ||
        type == TYPE_RIDEAU ||
        type == TYPE_VAGUE_DEVANT || type == TYPE_VAGUE_DERRIERE ||
        type == TYPE_LIDOLPINK || type == TYPE_WIZ || type == TYPE_RAYON ||
        type == TYPE_LAVE || type == TYPE_SCROLL || type == TYPE_SCROLL_SAX ||
        type == TYPE_PANCARTE || type == TYPE_RAY_POS || type == TYPE_UFO_IDC ||
        type == TYPE_HYB_BBF2_D || type == TYPE_HYB_BBF2_G || type == TYPE_CORDE_DARK ||
        type == TYPE_BOUEE_JOE
    )
        return true;
    return false;
}
#endif

INCLUDE_ASM("asm/nonmatchings/gendoor", correct_gendoor_link);

INCLUDE_ASM("asm/nonmatchings/gendoor", suppressFromLinkList);

/* 32298 80156A98 -O2 -msoft-float */
void correct_link(void)
{
    Obj *cur_obj = level.objects;
    s16 i = 0;
    s16 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {
        if (link_init[i] != i)
        {
            if (FUN_80156710(cur_obj) || (FUN_8015666c(cur_obj) && !linkListHoldsAGendoor(cur_obj)))
                suppressFromLinkList(cur_obj);
            else
                cur_obj->flags |= FLG(OBJ_LINKED);
        }
        else
            cur_obj->flags &= ~FLG(OBJ_LINKED);
        cur_obj++;
        i++;
    }
}