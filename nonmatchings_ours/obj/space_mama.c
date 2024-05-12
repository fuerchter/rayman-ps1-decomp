
#include "obj/space_mama.h"

/* worse than default m2c output? was 1930 */
/*INCLUDE_ASM("asm/nonmatchings/obj/space_mama", allocateMereDenisBombChips);*/

void allocateMereDenisBombChips(Obj *param_1)
{
    Obj *cur_obj;
    s16 i;
    s32 var_s1;
    s32 var_s3;
    u8 var_s5;
    u8 var_s6;
    s32 var_a2;
    u8 nb_objs;

    /*var_s1 = saved_reg_s1;
    var_s3 = saved_reg_s3;*/
    for (var_s6 = 0; var_s6 <= 2; var_s6 += 2)
    {
        cur_obj = level.objects;
        i = 0;
        nb_objs = level.nb_objects;
        while (i < nb_objs)
        {
            var_s5 = 0;
            switch (param_1->sub_etat)
            {
            case 1:
                var_s3 = 0;
                var_s1 = 1;
                break;
            case 3:
            case 5:
                var_s3 = 4;
                if (param_1->flags & 0x4000)
                {
                    var_s1 = 5;
                }
                else
                {
                    var_s3 = 2;
                    var_s1 = 3;
                }
                break;
            case 7:
                var_s3 = 6;
                if (param_1->flags & 0x4000)
                {
                    var_s5 = 1;
                }
                var_s1 = 7;
                break;
            }
            if (
                (cur_obj->type == 0xC2) &&
                (var_a2 = var_s3 & 0xFF, ((cur_obj->flags & 0x800) == 0)) &&
                (((cur_obj->sub_etat == var_a2)) || (cur_obj->sub_etat == (var_s1 & 0xFF)))
            )
            {
                cur_obj->flags = ((cur_obj->flags & ~0x4000) | (param_1->flags & 0x4000) | 0xC00);
                cur_obj->x_pos = param_1->x_pos;
                cur_obj->y_pos = param_1->y_pos;
                if (var_s6 != 0)
                {
                    var_a2 = var_s1 & 0xFF;
                }
                set_main_and_sub_etat(cur_obj, 1, var_a2);
                calc_obj_pos(cur_obj);
                skipToLabel(cur_obj, var_s5 ? var_s6 == 0 : var_s6 != 0, 1U);
            }
            i++;
            cur_obj += 1;
        }
    }
    allocateExplosion(param_1);
    PlaySnd(0xDC, param_1->id);
    param_1->flags &= ~0x800;
    param_1->flags &= ~0x400;
}

/* matches, but __builtin_abs section */
/*INCLUDE_ASM("asm/nonmatchings/obj/space_mama", mereDenisDropBomb);*/

void mereDenisDropBomb(Obj *smama_obj)
{
  s16 ray_x;
  s16 smama_x_1; s16 smama_x_2;
  Obj *cur_obj;
  s16 j; u8 i;
  s16 nb_objs;
  u8 new_sub_etat;
  u8 new_flip_x;
  
  if (currentBombSequence == 0xfe && lastDroppedBombXCenterPos == -32000)
  {
    ray_x = ray.x_pos + ray.offset_bx;
    smama_x_1 = smama_obj->x_pos + smama_obj->offset_bx;
    if ((ray_x >= smama_x_1 - 8) && (ray_x <= smama_x_1 + 8))
    {
      cur_obj = level.objects;
      j = 0;
      nb_objs = level.nb_objects;
      while (j < nb_objs)
      {
        if (cur_obj->type == TYPE_SMA_BOMB && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
          cur_obj->sub_etat = 0;
          cur_obj->flags &= ~FLG(OBJ_FLIP_X);
          cur_obj->x_pos = smama_x_1 - cur_obj->offset_bx;
          cur_obj->y_pos = smama_obj->y_pos + smama_obj->offset_by - cur_obj->offset_by - 33;
          cur_obj->timer = 50;
          cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
          break;
        }
        cur_obj++;
        j++;
      }
      currentBombSequence = 0xff;
      lastDroppedBombXCenterPos = smama_x_1;
    }
  }
  else
  {
    for (i = 0; i < sizeof(lastDroppedBombIdInSequence); i++)
    {
      if (lastDroppedBombIdInSequence[i] == 7)
      {
        currentBombSequence = 0xff;
        lastDroppedBombIdInSequence[i] = 0xff;
        lastDroppedBombXCenterPos = -32000;
      }
      else
      {
        smama_x_2 = smama_obj->x_pos + smama_obj->offset_bx;
        if (i == 0)
        {
          /* tried __builtin_abs. pc also does abs */
          #define OPT_2
          #ifdef OPT_1
          if (__builtin_abs(smama_x_2 - lastDroppedBombXCenterPos) < 0x25) {
            return;
          }
          #endif
          #ifdef OPT_2
          if (smama_x_2 - lastDroppedBombXCenterPos < 0) {
            if (-(smama_x_2 - lastDroppedBombXCenterPos) < 0x25) {
              return;
            }
          }
          else
          {
            if (smama_x_2 - lastDroppedBombXCenterPos < 0x25) {
              do {} while (0);
              return;
            }
          }
          #endif
          #ifdef OPT_3 /* ghidra unmodified */
          iVar2 = smama_x_2 - lastDroppedBombXCenterPos;
          if (iVar2 < 0) {
            iVar2 = lastDroppedBombXCenterPos - smama_x_2;
          }
          if (iVar2 < 0x25) {
            return;
          }
          #endif
        }
        lastDroppedBombIdInSequence[i]++;
        switch(bombSequences[currentBombSequence][i][lastDroppedBombIdInSequence[i]])
        {
        case 0:
        case 4:
          new_sub_etat = 0;
          new_flip_x = 0;
          break;
        case 1:
        case 5:
          new_sub_etat = 2;
          new_flip_x = smama_obj->flags >> OBJ_FLIP_X & 1;
          break;
        case 2:
          new_sub_etat = 6;
          new_flip_x = smama_obj->flags >> OBJ_FLIP_X & 1;
          break;
        case 6:
          new_sub_etat = 6;
          new_flip_x = (smama_obj->flags >> OBJ_FLIP_X ^ 1) & 1;
          break;
        case 3:
        case 7:
          new_sub_etat = 4;
          new_flip_x = (smama_obj->flags >> OBJ_FLIP_X ^ 1) & 1;
          break;
        case 8:
          smama_x_2 = 0;
          droppedBombIds[i][lastDroppedBombIdInSequence[i]] = -1;
          break;
        default:
          break;
        }

        if (smama_x_2 != 0)
        {
          cur_obj = level.objects;
          j = 0;
          nb_objs = level.nb_objects;
          while (j < nb_objs)
          {
            if (cur_obj->type == TYPE_SMA_BOMB && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
            {
              cur_obj->sub_etat = new_sub_etat;
              cur_obj->flags = cur_obj->flags & ~FLG(OBJ_FLIP_X) | (new_flip_x & 1) << OBJ_FLIP_X;
              droppedBombIds[i][lastDroppedBombIdInSequence[i]] = j;
              cur_obj->anim_frame = 0;
              cur_obj->x_pos = smama_x_2 - cur_obj->offset_bx;
              cur_obj->y_pos = (smama_obj->y_pos + smama_obj->offset_by - cur_obj->offset_by) + (i - 6) * 11;
              cur_obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
              break;
            }
            cur_obj++;
            j++;
          }
          if (j >= nb_objs)
            droppedBombIds[i][lastDroppedBombIdInSequence[i]] = -1;
        }
        lastDroppedBombXCenterPos = smama_obj->x_pos + smama_obj->offset_bx;
      }
    }
  }
}