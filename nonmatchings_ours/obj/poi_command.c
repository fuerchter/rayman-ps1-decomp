#include "obj/poi_command.h"

/*
matches, but gotos

!flip_x
(!chdir(,-0x14,) || !test(,-0x14,))
!flip_x
line 19

!flip_x
chdir(,-0x14,) && test(,-0x14,)
line 35 and on

flip_x
(!chdir(,+0x14,) || !test(,+0x14,))
line 31

flip_x
chdir(,+0x14,) && test(,+0x14,)
line 35 and on
*/

/* 4EFB0 801737B0 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/poi_command", DO_POISSON_VERT_CMD);*/

/*s16 test_allowed(Obj *obj, s16 param_2, s16 param_3);*/

void DO_POISSON_VERT_CMD(Obj *obj)
{
  short sVar1;
  u8 label;
  
  DO_ONE_CMD(obj);
  if (!(obj->flags & FLG(OBJ_FLIP_X))) {
    sVar1 = on_block_chdir(obj,obj->offset_bx - 0x14,obj->offset_by - 3);
    if ((sVar1 == 0) || (sVar1 = test_allowed(obj,obj->offset_bx - 0x14,obj->offset_by - 3), sVar1 == 0)) {
      if (!(obj->flags & FLG(OBJ_FLIP_X)))
      {
        DO_OBJ_COLLISIONS(obj,4); /* line 19 */
        return;
      }
    }
    else
    {
        goto test_1;
    }
  }
  sVar1 = on_block_chdir(obj,obj->offset_bx + 0x14,obj->offset_by - 3);
  if ((sVar1 == 0) || (sVar1 = test_allowed(obj,obj->offset_bx + 0x14,obj->offset_by - 3), sVar1 == 0))
  {
      DO_OBJ_COLLISIONS(obj,4); /* line 31 */
      return;
  }

test_1: /* line 35 and on */
  if (obj->flags & FLG(OBJ_FLIP_X)) {
    obj->flags &= ~FLG(OBJ_FLIP_X);
    skipToLabel(obj,7,true);
  }
  else {
    obj->flags |= FLG(OBJ_FLIP_X);
    skipToLabel(obj,8,true);
  }

  DO_OBJ_COLLISIONS(obj,4);
  return;
}

/* matching, but... gotos */
/* 4F0CC 801738CC -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/poi_command", DO_POISSON_BLEU_CMD);*/

s16 test_allowed(Obj *obj, s16 param_2, s16 param_3);

void DO_POISSON_BLEU_CMD(Obj *obj)
{
  s16 chdir;
  u8 uVar3;
  
  DO_ONE_CMD(obj);
  if (!(obj->flags & FLG(OBJ_FLIP_X)))
  {
    chdir = on_block_chdir(obj, obj->offset_bx - 0x14, obj->offset_by - 3);
    if (!chdir || (chdir = test_allowed(obj, obj->offset_bx - 0x14, obj->offset_by - 3), !chdir))
    {
      if (!(obj->flags & FLG(OBJ_FLIP_X))) goto LAB_801739d8;
      goto LAB_80173948;
    }
  }
  else {
LAB_80173948:
    chdir = on_block_chdir(obj,obj->offset_bx + 0x14,obj->offset_by - 3);
    if (!chdir || (chdir = test_allowed(obj,obj->offset_bx + 0x14,obj->offset_by - 3), !chdir))
        goto LAB_801739d8;
  }


  if (obj->flags & FLG(OBJ_FLIP_X)) {
    obj->flags &= ~FLG(OBJ_FLIP_X);
    skipToLabel(obj,0xd,true);
  }
  else {
    obj->flags |= FLG(OBJ_FLIP_X);
    skipToLabel(obj,0xe,true);
  }
  obj->y_pos = obj->init_y_pos;
LAB_801739d8:
  if (obj->main_etat == 2) {
    if ((obj->sub_etat == 0x11) && (obj->init_y_pos <= obj->y_pos)) {
      if ((obj->flags & FLG(OBJ_FLIP_X)))
        skipToLabel(obj,10,true);
      else
        skipToLabel(obj,9,true);
      obj->y_pos = obj->init_y_pos;
    }
    if ((obj->main_etat == 2) && (obj->sub_etat == 0x12)) {
      if ((obj->eta[2][0x12].flags & 0x10)) {
        if (obj->anim_frame != 0)
            return;
      }
      else if (obj->anim_frame != obj->animations[obj->anim_index].frames_count - 1)
          return;

      if (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0) {
        if (obj->speed_y == 5) {
          obj->display_prio = 0;
          obj->flags = obj->flags & ~FLG(OBJ_ACTIVE);
        }
        else {
          obj->speed_x = 0;
          obj->speed_y = 5;
          skipToLabel(obj,0xc,true);
        }
      }
    }
  }
  return;
}

void DO_POISSON_BLEU_CMD(Obj *obj)
{
    s32 var_a1;
    s32 var_a1_2;
    u32 temp_v1;

    DO_ONE_CMD();
    if (!(obj->flags & 0x4000))
    {
        if (((on_block_chdir(obj, obj->offset_bx - 0x14, obj->offset_by - 3) << 0x10) != 0) && ((test_allowed(obj, obj->offset_bx - 0x14, obj->offset_by - 3) << 0x10) != 0))
        {
            goto block_6;
        }
        else
        {
            if (obj->flags & 0x4000)
            {
                goto block_4;
            }
        }
    }
    else
    {
block_4:
        if (((on_block_chdir(obj, obj->offset_bx + 0x14, obj->offset_by - 3) << 0x10) != 0) && ((test_allowed(obj, obj->offset_bx + 0x14, obj->offset_by - 3) << 0x10) != 0))
        {
block_6:
            temp_v1 = obj->flags;
            if (temp_v1 & 0x4000)
            {
                obj->flags = temp_v1 & ~0x4000;
                skipToLabel(obj, 0xd, 1);
            }
            else
            {
                obj->flags = temp_v1 | 0x4000;
                skipToLabel(obj, 0xe, 1);
            }
            obj->y_pos = obj->init_y_pos;
        }
    }
    if (obj->main_etat == 2)
    {
        if ((obj->sub_etat == 0x11) && (obj->init_y_pos <= obj->y_pos))
        {
            if (obj->flags & 0x4000)
            {
                skipToLabel(obj, 0xa, 1);
            }
            else
            {
                skipToLabel(obj, 9, 1);
            }

            obj->y_pos = obj->init_y_pos;
        }
        if ((obj->main_etat == 2) && (obj->sub_etat == 0x12))
        {
            if ((obj->eta[2][0x12].flags & 0x10))
            {
                if (obj->anim_frame != 0)
                {
                    return;
                }
                goto block_23;
            }
            if (obj->anim_frame == (obj->animations[obj->anim_index].frames_count - 1))
            {
block_23:
                if (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0)
                {
                    if (obj->speed_y == 5)
                    {
                        obj->display_prio = 0;
                        obj->flags &= ~0x800;
                        return;
                    }
                    obj->speed_x = 0;
                    obj->speed_y = 5;
                    skipToLabel(obj, 0xC, 1);
                }
            }
        }
    }
}