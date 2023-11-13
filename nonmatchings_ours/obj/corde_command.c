#include "obj/corde_command.h"

/* matches, but... */
/* 4FB58 80174358 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/corde_command", DO_CORDE_COMMAND);
#else
/*? DO_CORDE_CASSE(Obj *, u8);
? DO_FUMEE_CORDE(s32, s32);
s32 inter_box(s32, s32, ?, ?, s32, s32, s32, s32);
? set_sub_etat(Obj *, s32);*/

void DO_CORDE_COMMAND(Obj *obj)
{
  s32 pa_id;
  s32 bVar2;
  s16 obj_x_pos;
  s16 obj_y_pos;
  s16 ray_x_pos;
  s16 sVar4;
  s16 ray_y_pos;
  u8 obj_y_offs;
  u8 obj_h;
  s16 inter;
  u8 hp;
  
  pa_id = pierreAcorde_obj_id;
  if (pa_id != -1)
  {
    if (obj->main_etat == 0)
    {
      if (obj->x_pos < level.objects[pa_id].x_pos)
        obj->y_pos = level.objects[pa_id].y_pos + 112;
      else
        obj->y_pos = level.objects[pa_id].y_pos + 120;
    }
    if (ray.main_etat == 2 && ray.sub_etat == 15)
    {
      /* TODO: ... */
      obj_x_pos = obj->x_pos;
      ray_y_pos = obj->y_pos;
      obj_y_pos = obj->y_pos;
      bVar2 = ray.x_pos;
      ray_x_pos = bVar2;
      sVar4 = ray.y_pos;
      ray_y_pos = ray.y_pos;
      bVar2 = TRUE;
      switch(obj->sub_etat) {
      case 16:
        obj_y_offs = 48;
        obj_h = 24;
        break;
      case 17:
        obj_y_offs = 48;
        obj_h = 32;
        break;
      case 18:
      case 19:
        obj_y_offs = 56;
        obj_h = 40;
        break;
      case 20:
        obj_y_offs = 56;
        obj_h = 64;
        break;
      default:
        bVar2 = FALSE;
      }
      if (bVar2 << 0x10) /* TODO: type? */
      {
        inter = inter_box(
            ray_x_pos + 57, ray_y_pos + 26, 46, 4,
            obj_x_pos + 126, obj_y_pos + obj_y_offs, 4, obj_h
        );
        if(inter)
        {
            hp = --obj->hit_points;
            if (hp == 0)
            {
                obj->hit_points = obj->init_hit_points;
                if (obj->sub_etat < 19)
                    set_sub_etat(obj, obj->sub_etat + 1);
                else
                    DO_CORDE_CASSE(obj);
            }
            if (level.objects[pierreAcorde_obj_id].iframes_timer == 0)
                DO_FUMEE_CORDE(obj_x_pos + 128, ray_y_pos + 30);
            
            level.objects[pierreAcorde_obj_id].field23_0x3c = 0;
            return;
        }
      }
    }
    level.objects[pierreAcorde_obj_id].field23_0x3c++;
  }

  __asm__("nop");
}
const u8 rodata_DO_CORDE_COMMAND[4] = {};
#endif