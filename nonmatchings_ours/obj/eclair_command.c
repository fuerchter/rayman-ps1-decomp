#include "obj/eclair_command.h"

/* matches, but ... that */
/*INCLUDE_ASM("asm/nonmatchings/obj/eclair_command", DO_ECLAIR_COMMAND);*/

void DO_ECLAIR_COMMAND(Obj *obj)
{
    Obj *var_s0;
    s16 temp_v0;
    s16 var_a1;
    Obj *var_a0;
    u32 temp_v1_2;
    u8 temp_v1;
    s16 nb_objs;


    temp_v1 = obj->cmd;
    switch (temp_v1)
    {
    default:
        goto block_1;
    block_2:
        var_s0->flags = temp_v1_2 & ~0x4000;
        var_s0->speed_y = 0;
        var_s0->speed_x = 0;
        var_s0->x_pos = (u16) obj->x_pos - 0x20;
        var_s0->y_pos = (u16) obj->y_pos - 0x30;
        var_s0->init_x_pos = (s16) (u16) var_s0->x_pos;
        var_s0->init_y_pos = (s16) (u16) var_s0->y_pos;
        calc_obj_pos(var_s0);
        var_s0->iframes_timer = 0x00FF;
        var_s0->field23_0x3c = 0x001E;
        var_s0->field24_0x3e = 0x001E;
        var_s0->main_etat = 0;
        var_s0->sub_etat = 4;
        var_s0->anim_frame = 0;
        var_s0->cmd_offset = -1;
        var_s0->nb_cmd = 0;
        var_s0->flags |= 0xC00;
        goto block_3;
    block_1:
        break;
    case 0:
        obj->flags &= ~0x4000;
        
    case 1:
        if (obj->cmd == 1)
        {
            obj->flags |= 0x4000;
        }
        SET_X_SPEED(obj);
        obj->speed_y = 0;
        if (
            block_flags[
                mp.map[
                    (s16) (((obj->x_pos + obj->offset_bx) >> 4) + mp.width * ((obj->y_pos + obj->offset_by) >> 4))
                ] >> 10
            ] >> BLOCK_CH_DIR & 1)
        {
            var_s0 = level.objects;
            var_a1 = 0;
            nb_objs = level.nb_objects;
            while (var_a1 < nb_objs)
            {
                if ((var_s0->type != 0x73) || (temp_v1_2 = var_s0->flags, ((temp_v1_2 & 0x800) != 0)))
                {
                    var_s0 += 1;
                    var_a1 = var_a1 + 1;
                }
                else
                {
                    goto block_2;
                }
            }
block_3:
            obj->flags &= ~0x800;
            obj->flags &= ~0x400;
        }
        return;
    }
}