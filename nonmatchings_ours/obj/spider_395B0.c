#include "obj/spider_395B0.h"

/* matches, but unk_1 */
/*INCLUDE_ASM("asm/nonmatchings/obj/spider_395B0", allocateDard);*/

/* 395B0 8015DDB0 -O2 -msoft-float */
void allocateDard(Obj *spi_obj)
{
    u8 *unk_1;
    s16 spi_x; s16 spi_y; s16 spi_w; s16 spi_h;
    s16 i = 0;
    Obj *cur_obj = &level.objects[i];
    s16 nb_objs = level.nb_objects;
    
    while (i < nb_objs)
    {
        unk_1 = &cur_obj->offset_by; /* TODO: ??? */
        if ((cur_obj->type == TYPE_DARD) && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->flags = cur_obj->flags & ~FLG(OBJ_FLIP_X) | spi_obj->flags & FLG(OBJ_FLIP_X);
            cur_obj->speed_y = 0;
            if (cur_obj->flags & FLG(OBJ_FLIP_X))
                cur_obj->speed_x = -3;
            else
                cur_obj->speed_x = 3;
            
            GET_SPRITE_POS(spi_obj, 3, &spi_x, &spi_y, &spi_w, &spi_h);
            cur_obj->x_pos = spi_x + (spi_w >> 1) - cur_obj->offset_bx;
            cur_obj->y_pos = spi_y + (spi_h >> 1) - *unk_1;
            cur_obj->init_x_pos = cur_obj->x_pos;
            cur_obj->init_y_pos = cur_obj->y_pos;
            cur_obj->display_prio = 4;
            cur_obj->main_etat = 0;
            cur_obj->sub_etat = 9;
            skipToLabel(cur_obj, (u8) (cur_obj->flags >> OBJ_FLIP_X) & 1, true);
            calc_obj_pos(cur_obj);
            cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
            cur_obj->flags &= ~FLG(OBJ_FLAG_9);
            cur_obj->anim_frame = 9;
            break;
        }
        cur_obj++;
        i++;
    }
}