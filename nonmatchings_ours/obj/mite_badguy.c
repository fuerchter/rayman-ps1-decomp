#include "obj/mite_badguy.h"

/* matches, but clean that last part (diff_y)? */
/*INCLUDE_ASM("asm/nonmatchings/obj/mite_badguy", calc_esquive_poing);*/

void calc_esquive_poing(Obj *mit_obj, s16 *out_diff_x, s16 *out_diff_y, s16 *out_unk)
{
    s16 unk_x; s16 unk_y;
    s16 mit_y;
    Obj *poing_obj = &level.objects[poing_obj_id];
    
    if (!(poing_obj->flags & FLG(OBJ_ACTIVE)))
    {
        unk_x = ray.x_pos + ray.offset_bx;
        unk_y = ray.y_pos + ((ray.offset_by + ray.offset_hy) >> 1) - 10;
        poing_obj->speed_x = 0;
    }
    else
    {
        unk_x = poing_obj->x_pos + poing_obj->offset_bx;
        unk_y = poing_obj->y_pos + poing_obj->offset_by;
    }

    *out_diff_x = unk_x - mit_obj->x_pos - mit_obj->offset_bx;
    mit_y = mit_obj->y_pos;
    if ((mit_y + mit_obj->offset_hy) - unk_y >= 0)
        *out_diff_y = (mit_obj->offset_hy + mit_y) - unk_y;
    else
        *out_diff_y = -((mit_obj->offset_hy + mit_y) - unk_y);
    *out_unk = mit_obj->detect_zone * 4;
}