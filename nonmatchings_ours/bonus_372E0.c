#include "bonus_372E0.h"

/* TEST_WIZARD-10 output improved score */
/* 375BC 8015BDBC -O2 */
/*INCLUDE_ASM("asm/nonmatchings/bonus_372E0", TEST_WIZARD);*/

/*? GET_ANIM_POS(Obj *, ? *, s16 *, u16 *, s16 *);
? set_sub_etat(Obj *, ?, s32 *);*/

/* 470 */
void TEST_WIZARD(Obj *obj)

{
  u8 bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  s16 x;
  short y;
  s16 w;
  short h;
  u8 new_var2;
  
  if (!RayEvts.demi ||
     (((ray.flags & FLG(OBJ_FLAG_0)) == FLG_OBJ_NONE &&
      (((ray.main_etat != 0 && (ray.main_etat != 3)) || (nb_wiz_collected != 0)))))) {
    obj->detect_zone_flag = 0;
  }
  bVar1 = obj->sub_etat;
  if (bVar1 == 0) {
    if ((ray.flags & FLG(OBJ_FLAG_0))) {
        if (status_bar.num_wiz + nb_wiz_collected >= 10) {
            set_sub_etat(obj,0xb);
            obj->timer = 200;
        }
        else
        {
            ray.flags = ray.flags & ~FLG(OBJ_FLAG_0);
        }
    }
    else
    {
      if (obj->detect_zone_flag != 0) {
        if (obj->anim_frame < 0x14) {
            if (status_bar.num_wiz >= 10) {
                obj->anim_frame = 0x14;
            }
            else {
                set_sub_etat(obj,10);
                obj->flags = obj->flags & ~FLG(OBJ_FLIP_X);
            }
        }
      }
      else
      {
        if ((obj->anim_frame == 0x13) && (obj->anim_frame = 0, obj->detect_zone_flag == 0)) {
          ray.flags = ray.flags & ~FLG(OBJ_FLAG_0);
        }
      }
    }
  }
  else if (obj->detect_zone_flag != 0) {
    if(((ray.flags & FLG(OBJ_FLAG_0))) && (bVar1 == 0xb))
    {
        obj->timer--;
        if (obj->timer == 0) {
        ray.flags = ray.flags & ~FLG(OBJ_FLAG_0);
        set_sub_etat(obj,1);
        }
    }
    else
    {
        if (obj->sub_etat == 1) {
            if (((ray.main_etat == 0) && ((ray.sub_etat < 2) || ((new_var2 = ray.sub_etat) == 2))) || (ray.main_etat == 1))
            {
                GET_ANIM_POS(obj,&x,&y,&w,&h);
                iVar2 = ((obj->offset_bx + (ushort)obj->x_pos) - (ushort)ray.x_pos) - ray.offset_bx;
                iVar3 = (w >> 1);
                iVar5 = iVar2 - iVar3;
                iVar2 = iVar2 + iVar3;
                iVar3 = ray.y_pos; /* ??? */
                iVar4 = (ray.y_pos + ray.offset_by) - y;
                if (iVar4 - h >= 0)
                {
                    if(iVar4 - h < 9)
                        goto block_1;
                    return;
                }
                if (h - iVar4 < 9) {
block_1:
                    if ((0x10 < __builtin_abs((s16) iVar5)) || ((ray.flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE)) {
                        if (0x10 < __builtin_abs((s16) iVar2)) {
                            return;
                        }
                        if ((ray.flags & FLG(OBJ_FLIP_X)) != FLG_OBJ_NONE) {
                            return;
                        }
                    }
                    if ((__builtin_abs((s16) iVar5) < 0x11) && ((ray.flags & FLG(OBJ_FLIP_X)) != FLG_OBJ_NONE)) {
                        obj->flags = obj->flags & ~FLG(OBJ_FLIP_X);
                        ray.x_pos = ((((ushort)obj->offset_bx + obj->x_pos) - (ushort)ray.offset_bx) -
                                    ((short)w >> 1)) + -0xc;
                    }
                    else if ((__builtin_abs((s16) iVar2) < 0x11) && ((ray.flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE)) {
                        obj->flags = obj->flags | FLG(OBJ_FLIP_X);
                        ray.x_pos = (((ushort)obj->offset_bx + obj->x_pos) - (ushort)ray.offset_bx) +
                                    ((short)w >> 1) + 0xc;
                    }
                    ray.y_pos = ((ray.y_pos + ray.offset_by) >> 4) * 0x10 - ray.offset_by;
                    ray.speed_x = 0;
                    decalage_en_cours = 0;
                    ray.speed_y = 0;
                    ray.field24_0x3e = 0;
                    DO_WIZARD(obj);
                }
            }
        }
        else {
            DO_WIZARD(obj);
        }
    }
  }
  else if (((bVar1 != 10) && (ray.main_etat != 3)) && (bVar1 != 1)) {
    set_sub_etat(obj,1);
  }
  return;
}

/* 1095 */
void TEST_WIZARD(Obj *arg0)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    s16 temp_a2;
    s16 temp_a3;
    s16 temp_v0;
    s32 temp_v0_2;
    s16 temp_v1;
    s32 temp_v1_2;
    s16 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s16 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s16 var_v0_7;
    s32 var_v0_9;
    u16 var_v0_8;
    u8 temp_a0;
    u8 temp_a1;
    s32 new_var;
    u8 new_var2;
    s16 new_var3;
    s32 new_var4;

    if ((RayEvts.demi) || (!(ray.flags & 0x100) && (((ray.main_etat != 0) && (ray.main_etat != 3)) || (nb_wiz_collected != 0))))
    {
        arg0->detect_zone_flag = 0;
    }
    temp_a0 = arg0->sub_etat;
    if (temp_a0 == 0)
    {
        if (ray.flags & 0x100)
        {
            if ((status_bar.num_wiz + nb_wiz_collected) >= 0xA)
            {
                set_sub_etat(arg0, 0xB);
                arg0->timer = 0xC8;
                return;
            }
            ray.flags &= ~0x100;
            return;
        }
        if (arg0->detect_zone_flag != 0)
        {
            if ((u8) arg0->anim_frame < 0x14U)
            {
                if ((u8) status_bar.num_wiz >= 0xAU)
                {
                    arg0->anim_frame = 0x14;
                    return;
                }
                set_sub_etat(arg0, 0xA);
                arg0->flags &= ~0x4000;
            }
        }
        else if (arg0->anim_frame == 0x13)
        {
            arg0->anim_frame = 0;
            if (arg0->detect_zone_flag == 0)
            {
                ray.flags &= ~0x100;
            }
        }
    }
    else if (arg0->detect_zone_flag != 0)
    {
        if ((ray.flags & 0x100) && (temp_a0 == 0x0B))
        {
            arg0->timer -= 1;
            if (arg0->timer == 0)
            {
                ray.flags &= ~0x100;
                set_sub_etat(arg0, 1, &ray.flags);
            }
        }
        else
        {
            temp_a1 = arg0->sub_etat;
            if (temp_a1 == 1)
            {
                /* 4ec */
                if (((ray.main_etat == 0) && ((ray.sub_etat < 2) || ((new_var2 = ray.sub_etat) == 2))) || (ray.main_etat == temp_a1))
                {
                    GET_ANIM_POS(arg0, &sp18, &sp1A, &sp1C, &sp1E);
                    temp_v0 = ((arg0->offset_bx + (u16) arg0->x_pos) - ray.x_pos) - ray.offset_bx;
                    temp_v1 = (sp1C >> 1);
                    temp_a2 = temp_v0 - temp_v1;
                    temp_a3 = temp_v0 + temp_v1;
                    temp_v1_2 = (ray.y_pos + ray.offset_by) - sp1A;
                    temp_v0_2 = temp_v1_2 - sp1E;
                    if (temp_v0_2 >= 0)
                    {
                        var_v0 = temp_a2;
                        if (temp_v0_2 < 9)
                        {
                            goto block_33;
                            
                        }
                        return;
                    }
                    var_v0 = temp_a2;
                    if ((sp1E - temp_v1_2) < 9)
                    {
block_33:
                        var_v0_2 = temp_a2;
                        new_var = temp_a3;
                        if (var_v0_2 < 0)
                        {
                            var_v0_2 = -var_v0_2;
                        }
                        var_v0_3 = temp_a3;
                        var_v0_4 = temp_a2;
                        new_var3 = temp_a3;
                        if (var_v0_2 < 0x11)
                        {
                            
                            if (!(ray.flags & 0x4000))
                            {
                                var_v0_3 = new_var3;
                                goto block_38;
                            }
                            goto block_42;
                        }
block_38:
                        var_v0_5 = var_v0_3;
                        if (var_v0_5 < 0)
                        {
                            var_v0_5 = -var_v0_5;
                        }
                        if (var_v0_5 < 0x11)
                        {
                            var_v0_4 = temp_a2;
                            if (!(ray.flags & 0x4000))
                            {
block_42:
                                var_v0_6 = var_v0_4;
                                if (var_v0_6 < 0)
                                {
                                    var_v0_6 = -var_v0_6;
                                }
                                var_v0_7 = new_var;
                                if (var_v0_6 < 0x11)
                                {
                                    if (ray.flags & 0x4000)
                                    {
                                        arg0->flags &= ~0x4000;
                                        var_v0_8 = (((arg0->offset_bx + (u16) arg0->x_pos) - ray.offset_bx) - ((s32) (sp1C >> 1))) - 0xC;
                                        goto block_53;
                                    }
                                    var_v0_7 = new_var3;
                                    goto block_48;
                                }
block_48:
                                /* 698 */
                                var_v0_9 = var_v0_7;
                                if (var_v0_9 < 0)
                                {
                                    var_v0_9 = -var_v0_9;
                                }
                                if ((var_v0_9 < 0x11) && !(ray.flags & 0x4000))
                                {
                                    arg0->flags |= 0x4000;
                                    var_v0_8 = ((arg0->offset_bx + (u16) arg0->x_pos) - ray.offset_bx) + (sp1C >> 1) + 0xC;
block_53:
                                    ray.x_pos = var_v0_8;
                                }
                                var_v0_4 = (((s32) (ray.y_pos + ray.offset_by)) >> 4) * 0x10;
                                ray.speed_x = 0;
                                decalage_en_cours = 0;
                                ray.speed_y = 0;
                                ray.field24_0x3e = 0;
                                ray.y_pos = var_v0_4 - ray.offset_by;
                                DO_WIZARD(arg0);
                            }
                        }
                    }
                }
            }
            else
            {
                DO_WIZARD(arg0);
            }
        }
    }
    else if ((temp_a0 != 0x0A) && (ray.main_etat != 3) && (temp_a0 != 1))
    {
        set_sub_etat(arg0, 1);
    }
}