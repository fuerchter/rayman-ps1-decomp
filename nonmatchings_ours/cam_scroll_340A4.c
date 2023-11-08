#include "cam_scroll_340A4.h"

/*
matches, but do {} while (0);
m2c increments i in multiple places for some reason
*/
/*INCLUDE_ASM("asm/nonmatchings/cam_scroll_340A4", DO_AUTO_SCROLL);*/

/* 340A4 801588A4 -O2 -msoft-float */
void DO_AUTO_SCROLL(void)
{
  s16 x_pos;
  s16 y_pos;
  s16 i;
  s32 eau_id;
  Obj *scr_obj;
  s16 scr_x;
  
  x_pos = ray.x_pos;
  y_pos = ray.y_pos;
  scroll_x = 0;
  scroll_y = -1;
  i = 0;
  if (NumScrollObj > 0) {
    eau_id = eau_obj_id;
    do {
      scr_obj = &level.objects[scroll_obj_id[i]];
      if (scr_obj->type != TYPE_SCROLL) break;
      switch(scr_obj->hit_points)
      {
      case 0:
        if (scr_obj->x_pos <= x_pos) {
          scroll_x++;
          scr_obj->x_pos = scr_obj->init_x_pos + -200;
        }
        break;
      case 1:
        if (scr_obj->x_pos <= x_pos) {
          scroll_x--;
          scr_obj->x_pos = scr_obj->init_x_pos + -200;
        }
        break;
      case 2:
        if (y_pos >= scr_obj->y_pos)
          scroll_y = -scroll_y;
        else
          scr_obj->y_pos = 10000;
        break;
      case 3:
        if (
            eau_id == -1 ||
            (level.objects[eau_id].hit_points == 0 && level.objects[eau_id].field23_0x3c == 0)
        )
        {
            if (y_pos >= scr_obj->y_pos)
            {
                if (__builtin_abs(scroll_y) == 1)
                    scroll_y = 2;
                else
                    scroll_y = -scroll_y;
            }
            else
                scr_obj->y_pos = 10000;
            
            if (eau_id != -1 && scroll_y != 2)
                level.objects[eau_id].iframes_timer = 2;
            do {} while (0);
        }
        break;
      }
      i++;
    } while (i < NumScrollObj);
  }

  if (scroll_x < 1)
    scroll_x--;
  scr_x = scroll_x;
  if (scr_x >= 1)
    h_scroll_speed = scr_x;
  else if (scr_x < -1)
    h_scroll_speed = scr_x + 1;

  if (scroll_y == 1)
    v_scroll_speed = -1;
  else
  {
    if (scroll_y == 2)
    {
      if (horloge[2] != 0)
        v_scroll_speed = -1;
      else
        v_scroll_speed = 0;
    }
    if (scroll_y == -2)
      scroll_y = -1;
  }
}