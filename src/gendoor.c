#include "gendoor.h"

#ifdef BSS_DEFS
u8 *link_init;
#endif

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
s16 FUN_80156710(Obj *obj)
{
    s16 type = obj->type;

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

#ifndef NONMATCHINGS
INCLUDE_ASM("asm/nonmatchings/gendoor", correct_gendoor_link);
#else
/* score of 1150 */
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
#endif

/* 321C0 801569C0 -O2 -msoft-float */
void suppressFromLinkList(Obj *obj)
{
    s16 unk_1;
    s16 unk_2;
    s16 unk_3;

    unk_2 = obj->id;
    
    unk_1 = unk_2;
    unk_2 = link_init[unk_1];
    while (unk_2 != obj->id)
    {
        unk_1 = unk_2;
        unk_2 = link_init[unk_1];
    }
    
    link_init[unk_1] = link_init[obj->id];
    unk_3 = link_init[unk_1];
    if (unk_3 == unk_1)
        level.objects[unk_3].flags &= ~FLG(OBJ_LINKED);
    link_init[obj->id] = obj->id;
    obj->flags &= ~FLG(OBJ_LINKED);
}

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
