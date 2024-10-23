#include "obj/ufo_idc.h"

/* 74954 80199154 -O2 -msoft-float */
s16 test_block_chdir(Obj *obj, s16 *out_unk, s16 off_x, s16 off_y)
{
    u8 res = false;
    s16 obj_x = (obj->x_pos + off_x) >> 4;
    s16 obj_y = (obj->y_pos + off_y) >> 4;
    
    *out_unk = obj_x + obj_y * mp.width;
    if (*out_unk != obj->test_block_index)
    {
        obj->test_block_index = *out_unk;
        if (
            obj_x >= 0 && (mp.width - 1 >= obj_x) &&
            obj_y >= 0 && (mp.height - 1 >= obj_y)
        )
            res = (mp.map[*out_unk] & 0xFC00) == 0x400;
    }
    return res;
}

INCLUDE_ASM("asm/nonmatchings/obj/ufo_idc", DO_MOVING_WITH_INDICATOR_COMMAND);

/* 74E40 80199640 -O2 -msoft-float */
void DO_IDC_COMMAND(Obj *idc_obj)
{
    switch (idc_obj->sub_etat)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        idc_obj->display_prio = 4;
        idc_obj->flags &= ~FLG(OBJ_FLIP_X);
        break;
    default:
        idc_obj->display_prio = 0;
        break;
    }
}

/* 74E80 80199680 -O2 -msoft-float */
void DO_LEV_POING_COLLISION(Obj *lev_obj)
{
    Obj *idc_obj;

    if (lev_obj->main_etat == 5 && lev_obj->sub_etat == 53)
    {
        PlaySnd(235, lev_obj->id);
        set_main_and_sub_etat(lev_obj, 5, 54);
        idc_obj = &level.objects[link_init[lev_obj->id]];
        if (idc_obj->type == TYPE_INDICATOR)
        {
            switch (idc_obj->sub_etat)
            {
            case 0:
                set_sub_etat(idc_obj, 1);
                return;
            case 1:
                set_sub_etat(idc_obj, 2);
                return;
            case 2:
                set_sub_etat(idc_obj, 3);
                return;
            case 3:
                set_sub_etat(idc_obj, 0);
                break;
            }
        }
    }
}

/* 74F98 80199798 -O2 -msoft-float */
void START_UFO(Obj *ufo_idc_obj)
{
    if (ufo_idc_obj->main_etat == 0 && ufo_idc_obj->sub_etat == 13)
    {
        set_main_and_sub_etat(ufo_idc_obj, 0, 14);
        ufo_idc_obj->speed_x = 2;
        ufo_idc_obj->speed_y = 0;
    }
}
