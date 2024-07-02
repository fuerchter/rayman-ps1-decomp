#include "obj/hybride_mosams_command.h"

/* 753E8 80199BE8 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu, div_nop_swap */
INCLUDE_ASM("asm/nonmatchings/obj/hybride_mosams_command", doMOSAMScommand);
#else
void doMOSAMScommand(Obj *obj)
{
    scrollLocked = true;
    switch (obj->cmd)
    {
    case GO_LEFT:
    case GO_RIGHT:
        obj->speed_x = 0;
        obj->speed_y = -8;
        scrollLocked = false;
        break;
    case GO_WAIT:
        if (!(obj->main_etat == 0 && obj->sub_etat == 2))
            calc_obj_dir(obj);
        bossXToReach = -32000;
        bossYToReach = -32000;
        obj->speed_y = 0;
        obj->speed_x = 0;
        break;
    case GO_SPEED:
        calc_obj_dir(obj);
        bossXToReach = ray.x_pos + ray.offset_bx - obj->offset_bx;
        bossYToReach = firstFloorBelow(&ray) - obj->offset_by + 16;
        obj->speed_x = obj->iframes_timer;
        obj->speed_y = obj->field20_0x36;
        bossSpeedFactor = __builtin_abs(
            (((bossXToReach - obj->x_pos) << 18) / 55) / obj->eta[obj->main_etat][obj->sub_etat].speed_x_right
        ); /* ??? the shift is multiplication by 262144 ??? */
        bossReachingAccuracyX = -1; /* not sure if best represented as -1 or 0xff */
        bossReachingAccuracyY = 0;
        bossReachingTimer = 1;
        obj->gravity_value_1 = 0;
        obj->gravity_value_2 = 0;
        break;
    case GO_NOP:
        setBossReachingSpeeds(obj, bossReachingTimer, bossReachingAccuracyX, bossReachingAccuracyY);
        break;
    }

    __asm__("nop\nnop");
}
#endif