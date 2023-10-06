#include "command_494FC.h"

/* 494FC 8016DCFC -O2 */
void DO_ONE_CMD_WAIT(Obj *obj)
{
    if (obj->main_etat == 1)
    {
        obj->speed_y = 0;
        obj->speed_x = 0;
        set_main_and_sub_etat(obj, 0, 0);
    }
    else if (obj->type == TYPE_FISH && obj->main_etat == 0 && obj->sub_etat == 0)
        obj->speed_y = 0;
}

INCLUDE_ASM("asm/nonmatchings/command_494FC", DO_ONE_CMD_LR_ATTENTE);

INCLUDE_ASM("asm/nonmatchings/command_494FC", DO_ONE_CMD_UPDOWN);

/* 497FC 8016DFFC -O2 */
void special_pour_liv(Obj *obj)
{
    if (obj->type == TYPE_BADGUY1 && obj->main_etat == 1 && obj->sub_etat == 0xb)
        obj->flags &= ~OBJ_READ_CMDS;
}

/* 49844 8016E044 -O2 */
INCLUDE_ASM("asm/nonmatchings/command_494FC", DO_ONE_CMD);