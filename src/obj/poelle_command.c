#include "obj/poelle_command.h"

/* 4F818 80174018 -O2 -msoft-float */
void DO_POELLE_COMMAND(Obj *po_obj)
{
    s32 abs_ray_spd_x;
    s16 po_x; s16 po_y; s16 po_w; s16 po_h;
    s32 sub_etat;

    po_obj->flags |= FLG(OBJ_FLIP_X);
    if (ray_on_poelle == true)
    {
        po_obj->flags &= ~FLG(OBJ_FOLLOW_ENABLED);
        if (
            (ray.speed_x > 0 && ray.flags & FLG(OBJ_FLIP_X)) ||
            (ray.speed_x < 0 && !(ray.flags & FLG(OBJ_FLIP_X)))
        )
        {
            abs_ray_spd_x = __builtin_abs(ray.speed_x);
            if (abs_ray_spd_x < 2)
                po_obj->field23_0x3c = ray.speed_x > 0 ? 2 : -2;
            else if (abs_ray_spd_x >= 7)
                po_obj->field23_0x3c = ray.speed_x > 0 ? 7 : -7;
            else
                po_obj->field23_0x3c = ray.speed_x;
        }
        if (po_obj->iframes_timer == 0)
        {
            if (__builtin_abs(ray.speed_y) <= 0) /* ray.speed_y == 0 */
            {
                if (__builtin_abs(ray.speed_x) > 2)
                    po_obj->anim_frame = 1;
            }
            else if (ray.speed_y > 0)
            {
                if (ray.speed_x > 0)
                    po_obj->anim_frame = 0;
                else if (ray.speed_x < 0)
                    po_obj->anim_frame = 2;
                else
                    po_obj->anim_frame = 1;
            }
            else if (ray.speed_y < 0)
            {
                if (ray.speed_x > 0)
                    po_obj->anim_frame = 2;
                else if (ray.speed_x < 0)
                    po_obj->anim_frame = 0;
                else
                    po_obj->anim_frame = 1;
            }

            po_obj->iframes_timer = 8;
        }
        else
            po_obj->iframes_timer--;

        GET_SPRITE_POS(po_obj, 0, &po_x, &po_y, &po_w, &po_h);
        po_y = (po_y + po_obj->offset_hy) - (po_obj->y_pos + po_obj->offset_by);
        po_obj->x_pos = (ray.offset_bx + ray.x_pos) - po_obj->offset_bx;
        po_obj->y_pos = (ray.offset_by + ray.y_pos) - po_obj->offset_by - po_y;
        if (
            (
                ray.main_etat == 3 &&
                ((sub_etat = ray.sub_etat, sub_etat == 23) || sub_etat == 22)
            ) || !RAY_DEAD()
        )
        {
            PS1_RestoreSauveRayEvts();
            ray_on_poelle = false;
        }
    }
    else
    {
        po_obj->flags |= FLG(OBJ_FOLLOW_ENABLED);
        po_obj->iframes_timer = 0;
        po_obj->anim_frame = 1;
        if (ray.main_etat == 3 && ray.sub_etat == 22)
            po_obj->speed_x = po_obj->field23_0x3c;
        else if (
            ray.main_etat == 2 &&
            ((sub_etat = ray.sub_etat, sub_etat == 1) || sub_etat == 2 || sub_etat == 6)
        )
            ray.speed_x = 0;
        else
            po_obj->field23_0x3c = 0;
    }
}
