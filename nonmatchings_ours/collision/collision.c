#include "collision/collision.h"

/* reg swaps */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", in_coll_sprite_list);*/

s8 in_coll_sprite_list(Obj *obj, s16 param_2)
{
    u8 sp[16];
    s16 var_a2;
    u8 var_v0;
    s8 temp_a0;
    
    switch(obj->type)
    {
    case 0x14:
        sp[0] = 0;
        sp[1] = 1;
        sp[2] = 2;
        sp[3] = 0xFF;
        break;
    case 0xA5:
        var_v0 = 2;
        if (obj->main_etat == 0)
        {
            var_v0 = 4; /* insists on setting this here */
            if (obj->sub_etat == 0xF || obj->sub_etat == 0x10)
            {}
            else if (obj->sub_etat == 0x11)
                var_v0 = 4;
            else
                var_v0 = 2;
        }
        sp[0] = var_v0;
        sp[1] = 0xFF;
        break;
    case 0xD9:
    case 0x64:
        sp[0] = 1;
        if (obj->sub_etat == 0x0B)
        {
            var_v0 = 3;
            if (obj->main_etat != 2 && obj->anim_frame >= 0x10U)
            {
                var_v0 = 2;
            }
            else if(obj->main_etat != 2 && obj->anim_frame < 0x10U)
            {
                var_v0 = 0xFF;
            }
            sp[1] = var_v0;
            sp[2] = 0xFF;
        }
        else
        {
            sp[1] = 0xFF;
        }
        break;
    default:
        sp[0] = 0;
        sp[1] = 0xff;
        break;
    }
    var_a2 = 0;
    do
    {
        temp_a0 = param_2 == sp[var_a2];
        var_a2 = var_a2 + 1;
        if(sp[var_a2] == 0xFF) break;
    } while (temp_a0 != 1);

    return temp_a0;
}