#include "obj/moving_platform_command.h"

/* 49320 8016DB20 -O2 */
s16 test_allowed(Obj *obj, s16 param_2, s16 param_3);

void DO_MOVING_PLATFORM_COMMAND(Obj *obj)
{
  s16 x_cen;
  s16 y_cen;
  s16 chdir;
  
  x_cen = get_center_x(obj);
  y_cen = get_center_y(obj);
  chdir = on_block_chdir(obj, x_cen, y_cen);
  /* TODO: remove cast once sure of test_allowed() return */
  if (chdir && (s16)test_allowed(obj, x_cen, y_cen))
    skipToLabel(obj, 99, TRUE);

  obj->flags &= ~FLG(OBJ_FLIP_X);
  if (obj->cmd == GO_SPEED)
  {
    obj->speed_x = obj->iframes_timer;
    obj->speed_y = obj->field20_0x36;
  }
}