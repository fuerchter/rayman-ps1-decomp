#include "obj/pirate_poelle.h"

/* 72384 80196B84 -O2 -msoft-float */
void DO_PIRATE_POELLE(Obj *pirp_obj)
{
    s16 i;
    Obj *cur_obj;
    s16 nb_objs;
    s16 pirp_x; s16 pirp_y; s16 pirp_w; s16 pirp_h;
    s16 cen_x = get_center_x(pirp_obj);
    s16 cen_y = get_center_y(pirp_obj);
    
    if (on_block_chdir(pirp_obj, cen_x, cen_y))
    {
        if (
            !(pirp_obj->sub_etat == 13 || pirp_obj->sub_etat == 28 ||
            pirp_obj->sub_etat == 14 || pirp_obj->sub_etat == 29)
        )
        {
            if (pirp_obj->speed_y > 0)
            {
                pirp_obj->speed_y--;
                if (pirp_obj->type == TYPE_PIRATE_POELLE || pirp_obj->type == TYPE_PIRATE_P_45)
                    pirp_obj->speed_x = -36;
                else
                    pirp_obj->speed_x = 36;
                
                test_allowed(pirp_obj, cen_x, cen_y);
            }
            else if (test_allowed(pirp_obj, cen_x, cen_y))
            {
                pirp_obj->speed_y = -1;
                if (pirp_obj->type == TYPE_PIRATE_POELLE || pirp_obj->type == TYPE_PIRATE_P_45)
                    pirp_obj->speed_x = -16;
                else
                    pirp_obj->speed_x = 16;

                if (pirp_obj->sub_etat == 6)
                    set_main_and_sub_etat(pirp_obj, 1, 7);
                else if (pirp_obj->sub_etat == 21)
                    set_main_and_sub_etat(pirp_obj, 1, 22);
            }
        }
    }

    if (
        (pirp_obj->sub_etat == 13 || pirp_obj->sub_etat == 28) &&
        pirp_obj->anim_frame == 6 && horloge[2] != 0
    )
    {
        i = 0;
        cur_obj = &level.objects[i];
        nb_objs = level.nb_objects;
        while (i < nb_objs)
        {
            if (cur_obj->type == TYPE_POELLE_ALWAYS && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
            {
                GET_SPRITE_POS(pirp_obj, 0, &pirp_x, &pirp_y, &pirp_w, &pirp_h);
                if (pirp_obj->flags & FLG(OBJ_FLIP_X))
                {
                    cur_obj->speed_x = 13;
                    cur_obj->init_x_pos = 
                    cur_obj->x_pos =
                        pirp_x - cur_obj->offset_bx + (pirp_w >> 1) + cur_obj->speed_x;
                    cur_obj->flags |= FLG(OBJ_FLIP_X);
                }
                else
                {
                    cur_obj->speed_x = -13;
                    cur_obj->init_x_pos =
                    cur_obj->x_pos =
                        pirp_x - cur_obj->offset_bx + (pirp_w >> 1) + cur_obj->speed_x;
                }
                cur_obj->speed_y = 2;
                cur_obj->init_y_pos =
                cur_obj->y_pos =
                    (pirp_y - cur_obj->offset_by) + pirp_h + 2;
                cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
                cur_obj->flags &= ~FLG(OBJ_READ_CMDS);
                break;
            }
            i++;
            cur_obj++;
        }
    }
    else
    {
        if (pirp_obj->sub_etat == 14 || pirp_obj->sub_etat == 29)
        {
            pirp_obj->speed_y = -8;
            pirp_obj->speed_x = 0;
            pirp_obj->flags &= ~FLG(OBJ_READ_CMDS);
        }
        else
        {
            if (pirp_obj->speed_y == -1)
            {
                if (pirp_obj->sub_etat == 6)
                    set_main_and_sub_etat(pirp_obj, 1, 7);
                else if (pirp_obj->sub_etat == 21)
                    set_main_and_sub_etat(pirp_obj, 1, 22);
                else if (pirp_obj->sub_etat == 11 && pirp_obj->anim_frame == 54)
                    set_main_and_sub_etat(pirp_obj, 1, 2);
                else if (pirp_obj->sub_etat == 26 && pirp_obj->anim_frame == 54)
                    set_main_and_sub_etat(pirp_obj, 1, 19);
            }
        }
    }
}

/* 7276C 80196F6C -O2 -msoft-float */
void DO_PIRATE_POELLE_POING_COLLISION(Obj *obj)
{
    if (obj->sub_etat == 0 || obj->sub_etat == 1)
    {
        if (--obj->hit_points == 0)
            set_main_and_sub_etat(obj, 0, 13);
        else
            set_main_and_sub_etat(obj, 0, 10);
    }
    else if (obj->sub_etat == 7 || obj->sub_etat == 2 || obj->sub_etat == 3 || obj->sub_etat == 4)
    {
        if (--obj->hit_points == 0)
            set_main_and_sub_etat(obj, 0, 13);
        else
            set_main_and_sub_etat(obj, 0, 12);
    }
    else if (obj->sub_etat == 5 || obj->sub_etat == 6)
    {
        if (--obj->hit_points == 0)
            set_main_and_sub_etat(obj, 0, 13);
        else
            set_main_and_sub_etat(obj, 0, 11);
    }
    else if (obj->sub_etat == 15 || obj->sub_etat == 16)
    {
        if (--obj->hit_points == 0)
            set_main_and_sub_etat(obj, 0, 28);
        else
            set_main_and_sub_etat(obj, 0, 25);
    }
    else if (obj->sub_etat == 22 || obj->sub_etat == 17 || obj->sub_etat == 18 || obj->sub_etat == 19)
    {
        if (--obj->hit_points == 0)
            set_main_and_sub_etat(obj, 0, 28);
        else
            set_main_and_sub_etat(obj, 0, 27);
    }
    else if (obj->sub_etat == 20 || obj->sub_etat == 21)
    {
        if (--obj->hit_points == 0)
            set_main_and_sub_etat(obj, 0, 28);
        else
            set_main_and_sub_etat(obj, 0, 26);
    }
}

/* 72924 80197124 -O2 -msoft-float */
void PIRATE_POELLE_REACT(Obj *obj)
{
    u8 sub_etat;

    if (obj->main_etat == 0)
    {
        sub_etat = obj->sub_etat;
        if (sub_etat == 0 || sub_etat == 1 || sub_etat == 15 || sub_etat == 16)
        {
            if (sub_etat == 0 || sub_etat == 1)
                set_main_and_sub_etat(obj, 1, 5);
            else
                set_main_and_sub_etat(obj, 1, 20);
            
            switch (obj->type)
            {
            case TYPE_PIRATE_POELLE:
            case TYPE_PIRATE_POELLE_D:
                obj->speed_y = 3;
                if (obj->type == TYPE_PIRATE_POELLE)
                    obj->speed_x = -24;
                else
                    obj->speed_x = 24;
                break;
            default:
                obj->speed_y = 2;
                if (obj->type == TYPE_PIRATE_P_45)
                    obj->speed_x = -36;
                else /* TYPE_PIRATE_P_D_45 */
                    obj->speed_x = 36;
                break;
            }
        }
    }
}
