#include "obj/corde_command.h"

/* 4FB58 80174358 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/obj/corde_command", DO_CORDE_COMMAND);

/* 4FDF4 801745F4 -O2 -msoft-float */
/*? set_main_and_sub_etat(Obj *, ?, ?);*/

void DO_PAC_COMMAND(Obj *obj)
{
    if (obj->hit_points == 0)
    {
        if (obj->x_pos < (ray.x_pos + 47) && (obj->x_pos + 186) > ray.x_pos)
        {
            obj->hit_points = 10;
            set_main_and_sub_etat(obj, 2, 4);
        }
    }
    if (obj->hit_points >= 2)
    {
        if (obj->speed_y < 16)
        {
            if (horloge[8] == 0)
                obj->speed_y++;
        }
        else if (horloge[16] == 0)
            obj->y_pos++;
    }
    else
        obj->speed_y = 0;

    if (obj->field23_0x3c >= 2)
        obj->iframes_timer = 0;
    else
        obj->iframes_timer = 1;
    obj->field23_0x3c = 0;
}

/* 4FEF8 801746F8 -O2 -msoft-float */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/obj/corde_command", DO_CFUMEE_COMMAND);
#else
void DO_CFUMEE_COMMAND(Obj *obj)
{
  __asm__("nop");

  obj->y_pos = ray.y_pos + -98;
  if (
    obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1 &&
    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0 &&
    level.objects[pierreAcorde_obj_id].iframes_timer == 0
  )
  {
    obj->flags &= ~OBJ_ALIVE;
    obj->flags &= ~OBJ_ACTIVE;
  }
  return;
}
#endif