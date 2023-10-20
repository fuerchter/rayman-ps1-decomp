#include "obj/cymbal.h"

/* matches, but... */
/* 49B74 8016E374 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/cymbal", DO_CYMBAL_COMMAND);*/

/*? GET_SPRITE_POS(void *, ?, ? *, s16 *, ? *, ? *);
? RAY_HIT(?, void *);
s32 on_block_chdir(void *, s32, u8, s16);
? set_main_and_sub_etat(s32 *, ?, ?, u8);
? skipToLabel(void *, ?, ?);*/
extern u16 D_801F61BC;
extern u16 D_801F61BE;
extern s16 D_801F61D6;
extern s16 D_801F61E2;
extern u8 D_801F61F2;
extern u8 D_801F61F3;
extern u8 D_801F61F6;
extern s32 D_801F620C;

s32 on_block_chdir(Obj *obj,short param_2,short param_3);

void DO_CYMBAL_COMMAND(Obj *arg0)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    s16 temp_a2;
    s16 temp_v1_3;
    s16 var_a3;
    s16 var_s2;
    s32 var_v0_2;
    s32 temp_v0_2;
    s32 temp_v1_7;
    s16 var_v0;
    s32 var_v0_3;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s16 var_s1;
    u8 temp_v0;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_4;
    u8 temp_v1_5;
    u32 temp_v1_6;
    int new_var;
    int new_var2;

    var_s1 = arg0->speed_x;
    temp_a2 = ((ray.offset_bx + ray.x_pos) - arg0->x_pos) - arg0->offset_bx;
    var_s2 = temp_a2;
    if (ray.field20_0x36 == arg0->id)
    {
        arg0->gravity_value_2 = 5U;
        if (temp_a2 > 0)
        {
            if (temp_a2 >= 0x63)
            {
                ray.y_pos += 8;
            }
            else
            {
                if (temp_a2 >= 0x47)
                {
                    var_a3 = 4;
                }
                else if (temp_a2 >= 0x3D)
                {
                    var_a3 = 3;
                }
                else if (temp_a2 >= 0x29)
                {
                    var_a3 = 2;
                }
                else
                {
                    var_a3 = (temp_a2 < 0x15) ^ 1;
                }
            }

            if ((s16)var_s1 < var_a3)
            {
                temp_v1 = arg0->gravity_value_1;
                arg0->gravity_value_1 = (u8) (temp_v1 + 0xFF);
                if (temp_v1 == 0)
                {
                    var_s1 += 1;
                    goto block_33;
                }
                goto block_16;
            }
block_16:
            if ((s16)var_s1 > var_a3)
            {
                temp_v1_2 = arg0->gravity_value_1;
                arg0->gravity_value_1 = (u8) (temp_v1_2 + 0xFF);
                if (temp_v1_2 == 0)
                {
                    var_s1 -= 1;
                    goto block_33;
                }
            }
            goto block_40;
        }
        var_s2 = -temp_a2;
        temp_v1_3 = -1;
        temp_v1_3 = temp_a2 * temp_v1_3;
        new_var = 0x1FE; /* this would make u8 overflow */
        new_var2 = 0xFF;
        if (temp_v1_3 >= 0x6A)
        {
            ray.y_pos += 8;
        }
        else
        {
            if (temp_v1_3 >= 0x47)
            {
                var_a3 = -4;
            }
            else if (temp_v1_3 >= 0x3D)
            {
                var_a3 = -3;
            }
            else if (temp_v1_3 >= 0x29)
            {
                var_a3 = -2;
            }
            else
            {
                var_a3 = (temp_v1_3 < 0x15) - 1;
            }
        }
        if (((s16) var_s1) > var_a3)
        {
            temp_v0 = arg0->gravity_value_1;
            temp_v1_4 = temp_v0 + new_var2;
            arg0->gravity_value_1 = temp_v1_4;
            if ((temp_v0 == 0) || (arg0->gravity_value_1 = (temp_v0 + new_var), (temp_v1_4 & 0xFF) == 0))
            {
                var_s1 -= 1;
block_33:
                arg0->gravity_value_1 = 5U;
                goto block_40;
            }
        }
        else
        {
            goto block_40;
        }
    }
    else
    {
        temp_v1_5 = arg0->gravity_value_2;
        arg0->gravity_value_2 = (u8) (temp_v1_5 + 0xFF);
        if (temp_v1_5 == 0)
        {
            arg0->gravity_value_2 = 5U;
            if (var_s1 != 0)
            {
                if (var_s1 > 0)
                {
                    var_s1 -= 1;
                }
                else
                {
                    var_s1 += 1;
                }
            }
        }
    }
block_40:
    if ((s16)on_block_chdir(arg0, arg0->offset_bx + (var_s1 * 2), arg0->offset_by))
    {
        var_s1 = 0;
    }
    arg0->speed_x = var_s1;
    if (arg0->main_etat == 0)
    {
        temp_v1_6 = arg0->sub_etat;
        if(temp_v1_6 == 0)
        {
            if ((arg0->field24_0x3e == 0) && (ray.field20_0x36 == arg0->id))
            {
                if ((u8) arg0->timer >= 0x65U)
                {
                    arg0->field24_0x3e = 1;
                    arg0->timer = 0U;
                    skipToLabel(arg0, 2, 1);
                    return;
                }
                arg0->timer = (u8) (arg0->timer + 1);
                return;
            }
        }
        else if(temp_v1_6 == 1)
        {
            arg0->field24_0x3e = 0;
            if ((ray.main_etat == 2) && (ray.iframes_timer == -1) && ((u32) (arg0->anim_frame - 0x14) < 3U))
            {
                GET_SPRITE_POS(arg0, 1, &sp18, &sp1A, &sp1C, &sp1E);
                var_v0_2 = var_s2;
                if (var_v0_2 < 0)
                {
                    var_v0_2 = -var_v0_2;
                }
                if (var_v0_2 < 0x64)
                {
                    temp_v1_7 = (((s16) ray.y_pos + ray.offset_by) - sp1A) - arg0->offset_hy;
                    temp_v0_2 = temp_v1_7 - 0x1C;
                    if (temp_v0_2 >= 0)
                    {
                        if ((temp_v0_2) < 0x14)
                        {
                            goto block_61;
                        }
                    }
                    else if ((0x1C - temp_v1_7) < 0x14)
                    {
block_61:
                        if (var_s2 < 0)
                        {
                            ray.flags |= 0x4000;
                        }
                        else
                        {
                            ray.flags &= ~0x4000;
                        }
                        RAY_HIT(1, arg0);

                    }
                }
            }
        }
        else if(temp_v1_6 == 3)
        {
            if (!(ray.flags & 0x800) && (arg0->anim_frame == 0) && (ray.field20_0x36 == arg0->id))
            {
                ray.flags |= 0x800;
                ray.iframes_timer = -1;
                ray.x_pos -= 4;
                GET_SPRITE_POS(arg0, 1, &sp18, &sp1A, &sp1C, &sp1E);
                ray.y_pos = (arg0->offset_hy + (u16) sp1A) - ray.offset_by;
                set_main_and_sub_etat(&ray, 0, 8);
            }
        }
    }
}

/* 4A078 8016E878 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/cymbal", DO_2_PARTS_CYMBAL);*/

/*? GET_SPRITE_POS(Obj *, ?, u16 *, u16 *, s16 *, s16 *);
u16 on_block_chdir(Obj *, u8, u8);
? set_main_and_sub_etat(Obj *, ?, ?, u8);
? skipToLabel(Obj *, ?, ?);*/
s16 test_allowed(Obj *, u8, u8);
s32 on_block_chdir(Obj *obj,short param_2,short param_3);
extern u16 D_801F61BC;
extern u16 D_801F61BE;
extern s16 D_801F61D6;
extern s16 D_801F61E2;
extern u8 D_801F61F2;
extern u8 D_801F61F3;
extern s32 D_801F620C;

void DO_2_PARTS_CYMBAL(Obj *param_1)
{
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  short sVar4;
  s32 iVar5;
  s16 iVar5_2;
  u8 sub_etat;
  Obj *obj;
  u8 sub_etat_00;
  u8 bVar6;
  short local_30;
  short local_2e;
  s16 local_2c;
  s16 local_2a;
  int new_var2; /* s16? */
  s32 test; /* s16? */

  bVar6 = param_1->offset_bx;
  bVar1 = param_1->offset_by;
  if (param_1->field24_0x3e == 0)
  {
    param_1->speed_x = 0;
    param_1->speed_y = 0;
  }
  else
    if (param_1->field24_0x3e == 1)
  {
    if (ray.field20_0x36 == param_1->id)
    {
      iVar5 = (s16)(ray.offset_bx + ray.x_pos - param_1->x_pos - bVar6);
      iVar5_2 = iVar5; /* assignment from larger to smaller type */
      if (0x60 < iVar5 || (iVar5_2 < -0x6b))
      {
        ray.y_pos = ray.y_pos + 8;
      }
    }
    sVar4 = on_block_chdir(param_1, (u16) bVar6, (u16) bVar1);
    new_var2 = (u16) bVar1;
    if ((sVar4 != 0) && ((sVar4 = test_allowed(param_1, (u16) bVar6, new_var2), sVar4 != 0)))
    {
      skipToLabel(param_1, 99, 1);
    }
    param_1->flags = param_1->flags & ~0x4000;
    if (param_1->cmd == 20)
    {
      param_1->speed_x = param_1->iframes_timer;
      param_1->speed_y = param_1->field20_0x36;
    }
  }
  if (0 < param_1->field24_0x3e)
  {
    obj = level.objects + link_init[param_1->id];
    if ((obj->flags & 0x800) == 0)
    {
      obj->flags = obj->flags | 0x800;
    }

    iVar5_2 = param_1->speed_y;
    test = -1;
    if (*(s32 *)&param_1->speed_x == 0)
    {
      sVar4 = param_1->field24_0x3e;
      if (sVar4 == 1)
      {
        param_1->field24_0x3e = 2;
        skipToLabel(obj, 99, 1);
      }
      if (param_1->field24_0x3e == 2)
      {
        obj->field24_0x3e = 3;
        iVar5_2 = obj->x_pos - param_1->x_pos;
        new_var2 = (u16) obj->y_pos - (u16) param_1->y_pos;
        if (6 < iVar5_2)
        {
          obj->speed_x = -4;
          return;
        }
        if (iVar5_2 < -6)
        {
          obj->speed_x = 4;
          return;
        }
        if (0 < iVar5_2)
        {
          obj->speed_x = -1;
          return;
        }
        if (iVar5_2 < 0)
        {
          obj->speed_x = 1;
          return;
        }
        iVar5_2 = new_var2;
        obj->speed_x = 0;
        if (iVar5_2 < -8)
        {
          sVar4 = 4;
        }
        else
        {
          sVar4 = -4;
          if (iVar5_2 < 9 && (sVar4 = -1, iVar5_2 < 1))
          {
            if (-1 < iVar5_2)
            {
              obj->speed_y = 0;
              param_1->field24_0x3e = 4;
              sub_etat_00 = 5;
              obj->field24_0x3e = 4;
              if (obj->type == 168)
              {
                sub_etat_00 = 9;
                sub_etat = 5;
              }
              else
              {
                sub_etat = 9;
              }
              set_main_and_sub_etat(obj, 0, sub_etat);
              sVar4 = 1;
              set_main_and_sub_etat(param_1, 0, sub_etat_00);
              return;
            }

          }
        }
      }
      else
      {
        if (param_1->field24_0x3e == 4)
        {
          bVar6 = 0xb;
          if (param_1->type == 168)
          {
            bVar6 = 7;
          }
          if (param_1->main_etat != 0)
          {
            return;
          }
          if (param_1->sub_etat != bVar6)
          {
            return;
          }
          if (param_1->anim_frame != 0)
          {
            return;
          }
          param_1->field24_0x3e = 5;
          if ((ray.flags & 0x800) != 0)
          {
            return;
          }
          if (ray.field20_0x36 != param_1->id)
          {
            return;
          }
          if (ray.iframes_timer != test)
          {
            return;
          }
          if (param_1->type != 169)
          {
            return;
          }
          ray.x_pos = ray.x_pos + -4;
          ray.flags = ray.flags | 0x800;
          GET_SPRITE_POS(param_1, 1, &local_30, &local_2e, &local_2c, &local_2a);
          ray.y_pos = param_1->offset_hy + local_2e - ray.offset_by;
          set_main_and_sub_etat(&ray, 0, 8);
          return;
        }
        if (param_1->field24_0x3e != 5)
        {
          return;
        }
        bVar2 = obj->offset_bx;
        bVar3 = obj->offset_by;
        local_30 = on_block_chdir(param_1, (u16) bVar6, (u16) bVar1);
        local_2e = on_block_chdir(obj, (u16) bVar2, (u16) bVar3);
        local_2c = test_allowed(param_1, (u16) bVar6, (u16) bVar1);
        local_2a = test_allowed(obj, (u16) bVar2, (u16) bVar3);
        sVar4 = on_block_chdir(param_1, (u16) bVar6, (u16) bVar1);
        if ((sVar4 != 0) && ((sVar4 = on_block_chdir(obj, (u16) bVar2, (u16) bVar3), sVar4 != 0)))
        {
          param_1->field24_0x3e = 1;
          obj->field24_0x3e = 1;
          test_allowed(param_1, (u16) bVar6, (u16) bVar1);
          test_allowed(obj, (u16) bVar2, (u16) bVar3);
          skipToLabel(param_1, 99, 1);
          skipToLabel(obj, 99, 1);
          return;
        }
        sVar4 = on_block_chdir(obj, (u16) bVar2, (u16) bVar3);
        if (sVar4 != 0)
        {
          return;
        }
        
        sVar4 = 1;
        if (obj->type == 168)
        {
          sVar4 = -1;
        }
      }
      obj->speed_y = sVar4;
    }
  }
  return;
}