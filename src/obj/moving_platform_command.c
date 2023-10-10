#include "obj/moving_platform_command.h"

/*INCLUDE_ASM("asm/nonmatchings/obj/moving_platform_command", DO_MOVING_PLATFORM_COMMAND);*/

/* 49320 8016DB20 -O2 */
void DO_MOVING_PLATFORM_COMMAND(Obj *obj)
{
  s16 x_cen;
  s16 y_cen;
  s16 chdir;
  
  x_cen = get_center_x(obj);
  y_cen = get_center_y(obj);
  chdir = on_block_chdir(obj, x_cen, y_cen);
  if (chdir && (x_cen = test_allowed(obj, x_cen, y_cen), x_cen != 0))
    skipToLabel(obj, 99, TRUE);

  obj->flags &= ~OBJ_FLIP_X;
  if (obj->cmd == GO_SPEED)
  {
    obj->speed_x = obj->iframes_timer;
    obj->speed_y = obj->field20_0x36;
  }
}