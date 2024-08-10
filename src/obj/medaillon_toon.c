#include "obj/medaillon_toon.h"

/* 3CFA0 801617A0 -O2 -msoft-float */
void DO_MEDAILLON_TOON(Obj *obj)
{
    if (
        obj->sub_etat == 32 || obj->sub_etat == 33 || obj->sub_etat == 34 ||
        obj->sub_etat == 35 || obj->sub_etat == 36 || obj->sub_etat == 37
    )
    {
        if (obj->anim_frame == 41)
            PlaySnd(192, obj->id);
        else if (obj->anim_frame == 64)
            PlaySnd(193, obj->id);
    }
    else if (obj->sub_etat == 38)
    {
        obj->flags &= ~FLG(OBJ_ALIVE);
        obj->flags &= ~FLG(OBJ_ACTIVE);
    }
}

/* 3D050 80161850 -O2 -msoft-float */
void DO_MEDAILLON_TOON_GELE(void)
{
    s16 i = 0;
    Obj *obj = &level.objects[actobj.objects[i]];

    while (i < actobj.num_active_objects)
    {
        if (obj->type == TYPE_MEDAILLON_TOON)
        {
            if (!snd_flag_medaillon)
            {
                FUN_80169194();
                snd_flag_medaillon = true;
            }
            DO_ANIM(obj);
            if (
                obj->sub_etat == 32 || obj->sub_etat == 33 || obj->sub_etat == 34 ||
                obj->sub_etat == 35 || obj->sub_etat == 36 || obj->sub_etat == 37
            )
            {
                if (obj->anim_frame == 41)
                    PlaySnd(192, obj->id);
                else if (obj->anim_frame == 64)
                    PlaySnd(193, obj->id);
            }
            else if (obj->sub_etat == 38)
            {
                gele = 0;
                snd_flag_medaillon = false;
                obj->flags &= ~FLG(OBJ_ALIVE);
                obj->flags &= ~FLG(OBJ_ACTIVE);
                PlaySnd(61, -1);
            }
        }
        i++;
        obj = &level.objects[actobj.objects[i]];
    }
}

/* 3D1E8 801619E8 -O2 -msoft-float */
void ALLOCATE_MEDAILLON_TOON(void)
{
    s16 nb_objs = level.nb_objects;
    s16 i = 0;
    Obj *cur_obj = level.objects;
  
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_MEDAILLON_TOON && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->init_x_pos = cur_obj->x_pos = xmap - (cur_obj->offset_bx - 160);
            cur_obj->init_y_pos = cur_obj->y_pos = ymap - cur_obj->offset_by;
            cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
            cur_obj->flags &= ~FLG(OBJ_READ_CMDS);
            set_sub_etat(cur_obj, t_world_info[world_index].nb_cages + 32);
            if (t_world_info[world_index].nb_cages == 6)
                t_world_info[world_index].nb_cages = 5;
            t_world_info[world_index].nb_cages++;
            gele = 1;
            h_scroll_speed = 0;
            v_scroll_speed = 0;
            break;
        }
        cur_obj++;
        i++;
    }
}