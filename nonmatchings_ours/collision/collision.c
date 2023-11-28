#include "collision/collision.h"

/* reg swaps
BOX_IN_COLL_ZONES seems to need s16 return */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", in_coll_sprite_list);*/

s16 in_coll_sprite_list(Obj *obj, s16 param_2)
{
    u8 sp[16];
    s16 var_a2;
    u8 var_v0;
    s16 temp_a0;
    
    switch(obj->type)
    {
    case 0x14:
        sp[0] = 0;
        sp[1] = 1;
        sp[2] = 2;
        sp[3] = 0xFF;
        break;
    case 0xA5:
        var_v0 = 2;
        if (obj->main_etat == 0)
        {
            var_v0 = 4; /* insists on setting this here */
            if (obj->sub_etat == 0xF || obj->sub_etat == 0x10)
            {}
            else if (obj->sub_etat == 0x11)
                var_v0 = 4;
            else
                var_v0 = 2;
        }
        sp[0] = var_v0;
        sp[1] = 0xFF;
        break;
    case 0xD9:
    case 0x64:
        sp[0] = 1;
        if (obj->sub_etat == 0x0B)
        {
            var_v0 = 3;
            if (obj->main_etat != 2 && obj->anim_frame >= 0x10U)
            {
                var_v0 = 2;
            }
            else if(obj->main_etat != 2 && obj->anim_frame < 0x10U)
            {
                var_v0 = 0xFF;
            }
            sp[1] = var_v0;
            sp[2] = 0xFF;
        }
        else
        {
            sp[1] = 0xFF;
        }
        break;
    default:
        sp[0] = 0;
        sp[1] = 0xff;
        break;
    }
    var_a2 = 0;
    do
    {
        temp_a0 = param_2 == sp[var_a2];
        var_a2 = var_a2 + 1;
        if(sp[var_a2] == 0xFF) break;
    } while (temp_a0 != 1);

    return temp_a0;
}

/* matches, but cleanup */
/* 1B600 8013FE00 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", GET_OBJ_ZDC);*/

/*void GET_ANIM_POS(Obj *param_1,short *x,short *y,ushort *w,ushort *h);
void GET_RAY_ZDC(Obj *ray,short *x,short *y,short *w,short *h);
void get_cou_zdc(Obj *param_1,short *param_2,short *param_3,short *param_4,short *param_5);
void get_spi_zdc(int param_1,short *param_2,short *param_3,s16 *param_4,s16 *param_5);*/

void GET_OBJ_ZDC(Obj *obj, s16 *x, s16 *y, s16 *w, s16 *h)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    s32 temp_v1;
    s16 temp_v1_2;
    s16 var_v0;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_v0_4;
    s16 var_v0_5;
    s16 var_v0_6;
    s16 temp_v0_2;
    u32 temp_s0;
    u8 temp_a0;
    u8 temp_v0;
    u8 temp_v1_3;
    u8 temp_v1_4;
    int new_var;

    temp_v0 = obj->type;
    switch (temp_v0)
    {
    case 0x39:
        GET_SPRITE_POS(obj, 1, x, y, w, h);
        temp_v1 = 3;
        if ((s32) *w > *h)
        {
            *x = *x + 4;
            *w = *w - 8;
            *y = *y + 8;
            *h = *h - 0xC;
        }
        else
        {
            *x = *x - temp_v1 + (*w >> 1);
            *w = 6;
            *y = *y + 0x10;
            *h = *h - 0x20;
        }

        return;
    case 0xCC:
        GET_RAY_ZDC(obj, x, y, w, h);
        return;
    case 0x4F:
        GET_ANIM_POS(obj, &sp18, &sp1A, &sp1C, &sp1E);
        *x = sp18 + 0xD;
        *y = sp1A + 0xD;
        *w = 4;
        *h = 4;
        return;
    case 0x2:
    case 0x8:
    case 0x86:
    case 0xA7:
        GET_ANIM_POS(obj, &sp18, &sp1A, &sp1C, &sp1E);
        *x = sp18 + 0xA;
        *y = sp1A + 0xA;
        *w = sp1C - 0x14;
        *h = sp1E - 0x14;
        return;
    case 0x92:
        GET_ANIM_POS(obj, x, y, w, h);
        new_var = 2;
        *x = *x - new_var + (*w >> 1);
        *y = *y - new_var + (*h >> 1);
        *w = 4;
        *h = 4;
        return;
    case 0x79:
    case 0x87:
        GET_ANIM_POS(obj, &sp18, &sp1A, &sp1C, &sp1E);
        *x = sp18 + 0xA;
        *y = sp1A + 4;
        *w = sp1C - 0x1E;
        *h = sp1E - 8;
        return;
    case 0x2C:
    case 0x47:
        GET_ANIM_POS(obj, &sp18, &sp1A, &sp1C, &sp1E);
        *x = sp18 + 2;
        *y = sp1A - 4;
        *w = sp1C - 4;
        *h = sp1E + 3;
        return;
    case 0x61:
        temp_v0_2 = ((obj->flags >> 0xE) & 1) << 0xE;
        obj->flags &= ~0x4000;
        GET_ANIM_POS(obj, &sp18, &sp1A, &sp1C, &sp1E);
        obj->flags = (obj->flags & ~0x4000) | temp_v0_2;
        if (obj->field23_0x3c != 2)
        {
            *x = sp18 + 3;
            *y = sp1A + 0x14;
            *w = 0x0032;
            *h = 0x0028;
            return;
        }
        *x = sp18 + 0x14;
        *y = sp1A + 0x23;
        *w = 1;
        *h = 1;
        return;
    case 0x69:
    case 0x6A:
        GET_SPRITE_POS(obj, 2, &sp18, &sp1A, &sp1C, &sp1E);
        *x = sp18;
        *y = sp1A;
        *w = 0x0010;
        *h = 0x0020;
        return;
    case 0x28:
    case 0x7A:
        GET_ANIM_POS(obj, &sp18, &sp1A, &sp1C, &sp1E);
        *x = sp18 + 4;
        *y = sp1A + 2;
        *w = sp1C - 8;
        *h = sp1E - 6;
        return;
    case 0x3A:
        GET_ANIM_POS(obj, &sp18, &sp1A, &sp1C, &sp1E);
        *x = sp18 + 8;
        *y = sp1A + 8;
        *w = sp1C - 0x10;
        *h = sp1E - 0x10;
        return;
    case 0x23:
    case 0x2B:
    case 0x38:
    case 0xAC:
        if ((obj->main_etat == 0) && ((u32) (obj->sub_etat - 3) < 2U))
        {
        case 0x3B:
            *x = obj->x_pos;
            *y = obj->y_pos;
            *w = 0;
            *h = 0;
            return;
        }
        *x = (obj->offset_bx + obj->x_pos) - 0xA;
        *y = (obj->offset_by + obj->y_pos) - 0x3C;
        *w = 0x0014;
        *h = 0x0032;
        return;
    case 0x5:
        *x = obj->x_pos;
        *y = obj->y_pos;
        *w = 0x0032;
        *h = 0x006E;
        return;
    case 0x3C:
        if (obj->main_etat == 0 && (obj->sub_etat == 2) && ((u8) obj->anim_frame >= 0x10U))
        {
            temp_v1 = obj->x_pos;
            if (obj->flags & 0x4000)
            {
                *x = temp_v1 + 0x50;
            }
            else
            {
                *x = temp_v1 + 0x10;
            }
            *y = obj->y_pos + 0x28;
            *w = 0x0044;
        }
        else if ((obj->main_etat == 0) && (obj->sub_etat == 2))
        {
            temp_v1 = obj->x_pos;
            if (obj->flags & 0x4000)
            {
                var_v0_4 = temp_v1 + 0x50;
            }
            else
            {
                var_v0_4 = temp_v1 + 0x30;
            }
            *x = var_v0_4;
            *y = obj->y_pos + 0x26;
            *w = 0x0020;
        }
        else
        {
            var_v0_4 = obj->x_pos + 0x40;
            *x = var_v0_4;
            *y = obj->y_pos + 0x26;
            *w = 0x0020;
        }
        *h = 0x0030;
        return;
    case 0x3E:
        GET_SPRITE_POS(obj, 0, &sp18, &sp1A, &sp1C, &sp1E);
        if (obj->main_etat == 2)
        {
            if (obj->sub_etat == 2)
            {
                *x = sp18 + 5;
                *y = sp1A + 0x1C;
                *w = 6;
                *h = 0x0016;
            }
            else if(obj->sub_etat == 1)
            {
                *x = sp18 + 6;
                *y = sp1A + 0x12;
                *w = 0x000D;
                *h = 0x000B;
            }
            else if(obj->sub_etat == 0)
            {
                *x = sp18 + 7;
                *y = sp1A + 8;
                *w = 0x0013;
                *h = 0x000B;
            }
        }
        else
        {
            return;
        }
        break;
    case 0x46:
        GET_ANIM_POS(obj, &sp18, &sp1A, &sp1C, &sp1E);
        *x = sp18 + 0x18;
        *y = sp1A + 0xE;
        *w = sp1C - 0x30;
        *h = sp1E - 0x1B;
        return;
    case 0x77:
        *x = obj->x_pos + 0x4C;
        *y = obj->y_pos + 0x55;
        *w = 8;
        *h = 8;
        return;
    case 0x53:
        *x = obj->x_pos;
        *y = obj->y_pos;
        if (obj->sub_etat == 0)
        {
            *w = 0x0016;
            *h = 0x0016;
            *x = *x + 0x44;
            *y = *y + 0x41;
            return;
        }
        *w = 0;
        *h = 0;
        return;
    case 0xBE:
        get_cou_zdc(obj, x, y, w, h);
        return;
    case 0xC3:
        get_spi_zdc((s32) obj, x, y, w, h);
        return;
    case 0x84:
        if (
            (obj->main_etat == 2) &&
            (
                (temp_v1_4 = obj->sub_etat, (temp_v1_4 == 0x0F)) ||
                (temp_v1_4 == 0x0C) ||
                (obj->sub_etat == 0x0D)
            )
        )
        {
            *x = obj->x_pos + 0x36;
            var_v0_6 = obj->y_pos + 0x37;
        }
        else
        {
            *x = obj->x_pos + 0x4A;
            var_v0_6 = obj->y_pos + 0x2D;
        }
        *y = var_v0_6;
        *w = 0x000E;
        *h = 0x0015;
        return;
    case 0x81:
        if (obj->hit_points == 1)
        {
            *x = obj->x_pos + 0x8A;
            *y = obj->y_pos + 0x8A;
            *w = 0x002B;
            *h = 0x000F;
        }
        if (obj->hit_points == 2)
        {
            *x = obj->x_pos + 0x83;
            *y = obj->y_pos + 0x58;
            *w = 0x0011;
            *h = 0x0031;
        }
        if (obj->hit_points == 3)
        {
            *x = obj->x_pos + 0x3E;
            *y = obj->y_pos + 0x8A;
            *w = 0x002B;
            *h = 0x0010;
        }
        if (obj->hit_points == 4)
        {
            *x = obj->x_pos + 0x60;
            *y = obj->y_pos + 0x57;
            var_v0_3 = 0x0011;
            *w = var_v0_3;
            *h = 0x0030;
        }
        break;
    default:
        GET_ANIM_POS(obj, x, y, w, h);
        break;
    }
}

/* matches, but cleanup
return is either s32 with cast or s16 */
/* 1C034 80140834 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", GET_SPRITE_ZDC);*/

s32 GET_SPRITE_ZDC(Obj *obj, s16 index, s16 *param_3, s16 *param_4, s16 *param_5, s16 *param_6)
{
    s16 sp18;
    s16 sp1A;
    u16 sp1C;
    u16 sp1E;
    s16 *sp20;
    s32 temp_v1;
    s32 var_a1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s6;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    u16 var_v0_3;
    s16 temp_s5;
    u8 temp_v1_2;

    var_s7 = 0;
    var_s6 = 0;
    var_s2 = 0;
    temp_s5 = obj->type;
    var_s3 = 0;
    var_a1 = GET_SPRITE_POS(obj, index, &sp18, &sp1A, &sp1C, &sp1E);
    if ((s16) var_a1 != 0)
    {
        switch (temp_s5)
        {
        case 0x51:
            switch (index)
            {
            case 3:
                var_s3 = 4;
                var_s2 = 2;
                var_s6 = -4;
                var_s7 = -0xA;
                break;
            case 4:
                var_s3 = 0;
                var_s2 = 2;
                var_s6 = 0;
                var_s7 = -0xA;
                break;
            case 5:
                var_s3 = 0;
                var_s2 = 2;
                var_s6 = -4;
                var_s7 = -0xA;
                break;
            }
            break;
        case 0x14:
            temp_v1_2 = obj->main_etat;
            if (((temp_v1_2 == 0) && (obj->sub_etat == 0)) || ((temp_v1_2 == 1) && (obj->sub_etat == 0)))
            {
                switch (index)
                {
                case 0:
                    var_s3 = 0xA;
                    var_s2 = 0;
                    sp1C = 0x0022;
                    var_v0_3 = 0x0020;
                    sp1E = var_v0_3;
                    break;
                case 1:
                    var_s3 = 4;
                    var_s2 = 0;
                    sp1C = 0x001A;
                    break;
                case 2:
                    var_s3 = 4;
                    var_s2 = 0;
                    sp1C = 0x0030;
                    var_v0_3 = 0x0018;
                    sp1E = var_v0_3;
                    break;
                }
            }
            else if ((obj->main_etat == 0) && (obj->sub_etat == 1))
            {
                sp1C = 0x0020;
                sp1E = 0x0010;
                sp18 = (u16) obj->x_pos + 0x70;
                sp1A = (u16) obj->y_pos + 0xB8;
            }
            else
            {
                sp1C = 0;
                sp1E = 0;
                var_a1 = 0;
            }
            break;
        case 0xA5:
            if (index != 2)
            {
                if (index == 4)
                {
                    var_s3 = -3;
                    var_s2 = 0;
                    sp1C = 0x0015;
                    var_v0_3 = 0x000A;
                    sp1E = var_v0_3;
                    break;
                }
            }
            else
            {
                var_s3 = 1;
                var_s2 = -4;
                var_s6 = -2;
                var_s7 = 6;
            }
            break;
        case 0x64:
        case 0xD9:
            switch (index)
            {
            case 1:
                var_s3 = 1;
                if (obj->main_etat == 0)
                {
                    var_s3 = -8;
                    if (obj->sub_etat == 9 || obj->sub_etat == 0x0A || (obj->sub_etat == 0x0B))
                    {
                        var_s2 = 5;
                        sp1C = 0x001A;
                        var_v0_3 = 8;
                    }
                    else
                    {
                        var_s3 = 1; /* duplicate? */
                        var_s2 = -5;
                        sp1C = 0x0010;
                        var_v0_3 = 0x001E;
                    }
                }
                else
                {
                    var_s2 = -5;
                    sp1C = 0x0010;
                    var_v0_3 = 0x001E;
                }
                sp1E = var_v0_3;
                break;
            case 2:
                var_s3 = 0;
                var_s2 = 7;
                var_v0_3 = 0x0010;
                sp1C = 0x0010;
                sp1E = var_v0_3;
                break;
            case 3:
                var_s3 = 0;
                var_s2 = 2;
                sp1C = 0x000D;
                var_v0_3 = 9;
                sp1E = var_v0_3;
                break;
            }
            break;
        }
        *param_3 = var_s3 + (u16) sp18;
        *param_4 = var_s2 + (u16) sp1A;
        *param_5 = var_s6 + sp1C;
        *param_6 = var_s7 + sp1E;
    }
    return (s16)var_a1;
}

/* lots still wrong (stack, control flow, types?) */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", BOX_HIT_SPECIAL_ZDC);*/

void GET_BB1_ZDCs(Obj *obj,short *param_2,short *param_3,short *param_4,short *param_5,
                 short *param_6,short *param_7,short *param_8,short *param_9);

int BOX_HIT_SPECIAL_ZDC(short x,short y,short w,short h,Obj *obj)
{
  ObjType OVar1;
  u8 bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short local_48;
  short local_46;
  short local_44;
  short local_42;
  short local_40;
  short local_3e;
  ushort local_3c;
  short local_3a;
  s32 local_38;
  short local_30;
  
  iVar8 = -1;
  local_38 = y;
  local_30 = w;
  switch(obj->type)
  {
  case 0x71:
    bVar2 = obj->anim_frame;
    if (bagD[bVar2] != -1)
    {
        iVar5 = y;
        iVar4 = (obj->x_pos + (uint)obj->offset_bx) - ((s16) bagW[bVar2] >> 0x1);
        iVar8 = (obj->y_pos + (uint)obj->offset_by + bagD[bVar2]) - bagH[bVar2];
        iVar6 = w;
        sVar3 = inter_box(x,iVar5,iVar6,h,iVar4,iVar8,bagW[bVar2],bagH[bVar2]);
        /*iVar4 = -0x10000;*/
        if (sVar3 != 0)
            iVar8 = 1;
    }
    break;
  case 0xC8:
  case 0xC9:
    iVar8 = -1;
  case 0x2E:
  case 0xC6:  
    iVar9 = h;
    if (iVar9 == ray_zdc_h) {
      GET_BB1_ZDCs(obj,&local_48,&local_46,&local_44,&local_42,&local_40,&local_3e,&local_3c,
                   &local_3a);
      iVar5 = local_38;
      iVar6 = local_30;
      sVar3 = inter_box(x,iVar5,iVar6,iVar9,local_48,local_46,local_44,
                        local_42);
      if (sVar3 == 0) {
        iVar4 = local_40;
        iVar8 = local_3e;
        sVar3 = inter_box(x,iVar5,iVar6,h,iVar4,iVar8,(short)local_3c,local_3a);
        /*iVar4 = -0x10000;*/
        if (sVar3 != 0)
            iVar8 = 1;
      }
      else
        iVar8 = 1;
    }
    else {
      GET_BB1_ZDCs(obj,&local_48,&local_46,&local_44,&local_42,&local_40,&local_3e,&local_3c,
                   &local_3a);
      iVar7 = x;
      iVar6 = local_38;
      iVar5 = local_30;
      sVar3 = inter_box(iVar7,iVar6,iVar5,iVar9,local_48,local_46,local_44,
                        local_42);
      if (sVar3 != 0) {
        iVar8 = 6;
      }
      sVar3 = inter_box(iVar7,iVar6,iVar5,iVar9,local_40,local_3e,(short)local_3c,
                        local_3a);
      if (sVar3 != 0) {
        iVar8 = 1;
      }
      if ((obj->main_etat == 0) && (obj->sub_etat == 10))
      {
        GET_SPRITE_POS(obj,9,&local_48,&local_46,&local_42,&local_44);
        sVar3 = inter_box(iVar7,iVar6,iVar5,iVar9,local_48,local_46,local_44,
                            local_42);
        if (sVar3 != 0)
            iVar8 = 9;
      }
    }
    break;
  }
LAB_80140fac:
  /*iVar4 = iVar8 << 0x10;*/
LAB_80140fb0:
  return (s16) iVar8; /*iVar4 >> 0x10;*/
}

/* ??? tried gotos-only, both m2c and ghidra */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", BOX_IN_COLL_ZONES);*/

s32 BOX_IN_COLL_ZONES(s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, Obj *obj)
{
    s16 sp20;
    s16 sp22;
    s16 sp24;
    s16 sp26;
    s16 sp28;
    s16 sp30;
    Animation *temp_v1_3;
    ZDC *temp_v0;
    s16 temp_a1_3;
    s16 temp_v1_4;
    s16 var_s2;
    s16 var_s2_2;
    s16 var_v0_3;
    s32 temp_v0_2;
    s32 temp_v1_6;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_a1;
    u16 var_s3;
    u8 temp_a0;
    u8 temp_a1_2;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_5;
    s32 test_1;

    sp26 = 0;
    sp24 = 0;
    sp22 = 0;
    sp20 = 0;
    var_s5 = -1;
    temp_a1 = obj->zdc;
    if (temp_a1 != 0)
    {
        var_s3 = get_nb_zdc(obj);
        if (num_world == 1)
        {
            temp_v1 = obj->type;
            if ((temp_v1 == 0x32) || (temp_v1 == 0xE3))
            {
                if (obj->eta[obj->main_etat][obj->sub_etat].flags & 0x40)
                {
                    goto block_6;
                }
                goto block_8;
            }
block_6:
            if (obj->type == 0xA5)
            {
        
                if (obj->eta[obj->main_etat][obj->sub_etat].flags & 0x40)
                {
block_8:
                    var_s3 -= 1;
                }
            }
        }
        var_s2 = 0;
        if ((s16) var_s3 > 0)
        {
            /* load param_1 into test_1 here instead? */
loop_11:
            temp_v0 = get_zdc(obj, var_s2);
            temp_v1_2 = temp_v0->flags;
            if (!(temp_v1_2 & 4) || (param_1 == 0x005E))
            {
                if (temp_v1_2 & 2)
                {
                    temp_v1_3 = &obj->animations[obj->anim_index];
                    temp_a1_2 = temp_v0->sprite;
                    if (temp_v1_3->layers[(temp_v1_3->layers_count & 0x3FFF) * obj->anim_frame + temp_a1_2].sprite != 0)
                    {
                        GET_SPRITE_POS(obj, (s32) temp_a1_2, &sp20, &sp22, &sp24, &sp26);
                        if (obj->flags & 0x4000)
                        {
                            sp20 = (u16) sp20 + ((sp24 - temp_v0->width) - (u16) temp_v0->x_pos);
                        }
                        else
                        {
                            sp20 = (u16) sp20 + (u16) temp_v0->x_pos;
                        }
                        sp22 = (u16) sp22 + (u16) temp_v0->y_pos;
                        sp24 = (u16) temp_v0->width;
                        sp26 = (u16) temp_v0->height;
                    }
                }
                else
                {
                    temp_a1_3 = (u16) obj->x_pos + (u16) temp_v0->x_pos;
                    sp20 = temp_a1_3;
                    sp22 = (u16) obj->y_pos + (u16) temp_v0->y_pos;
                    temp_a0 = temp_v0->width;
                    sp24 = (u16) temp_a0;
                    sp26 = (u16) temp_v0->height;
                    if (obj->flags & 0x4000)
                    {
                        sp20 = ((obj->offset_bx + (u16) obj->x_pos)) + ((obj->offset_bx + (u16) obj->x_pos)) - (temp_a1_3 + temp_a0);
                    }
                }
                if ((s16) inter_box(param_2, param_3, param_4, param_5, sp20, sp22, sp24, sp26) == 0)
                {
                    goto block_22;
                }
                else
                    var_v0 = temp_v0->sprite << 0x10;
            }
            else
            {
block_22:
                temp_v1_4 = var_s2 + 1;
                var_s2 = temp_v1_4;
                if (temp_v1_4 >= (s16) var_s3)
                {
                    var_v0 = var_s5 << 0x10;
                }
                else
                {
                    goto loop_11;
                }
            }
        }
        else
        {
            goto block_38;
        }
    }
    else
    {
        temp_v1_5 = obj->hit_sprite;
        if (temp_v1_5 == 0xFE)
        {
            GET_OBJ_ZDC(obj, &sp20, &sp22, (s16 *) &sp24, (s16 *) &sp26);
            if (obj->flags & 0x4000)
            {
                sp20 = ((obj->offset_bx + (u16) obj->x_pos)) + ((obj->offset_bx + (u16) obj->x_pos)) - ((u16) sp20 + sp24);
            }
            temp_v0_2 = inter_box((s32) param_2, (s32) param_3, (s32) param_4, (s32) (s16) (s32) param_5, (s16) (s32) sp20, (s16) (s32) sp22, (s32) (s16) sp24, (s32) (s16) sp26);
            
            if ((temp_v0_2 << 0x10) == 0)
            {
                var_s5 = -1;
            }
            else
                var_s5 = temp_v0_2;
            goto block_38;
        }
        var_v0 = -1 << 0x10;
        if (temp_v1_5 == 0xFF)
        {
            temp_v1_6 = obj->animations[obj->anim_index].layers_count & 0x3FFF;
            var_s2_2 = 0;
            if ((s32) temp_a1 < temp_v1_6)
            {
loop_34:
                var_v0_3 = var_s2_2 + 1;
                if (((in_coll_sprite_list(obj, var_s2_2) << 0x10) == 0) || (var_v0_3 = var_s2_2 + 1, ((GET_SPRITE_ZDC(obj, var_s2_2, &sp20, &sp22, (s16 *) &sp24, (s16 *) &sp26) << 0x10) == 0)) || (var_v0_3 = var_s2_2 + 1, ((inter_box((s32) (s16) (u16) param_2, (s32) param_3, (s32) param_4, (s32) (s16) (s32) param_5, (s16) (s32) sp20, (s16) (s32) sp22, (s32) (s16) sp24, (s32) (s16) sp26) << 0x10) == 0)))
                {
                    var_s2_2 = var_v0_3;
                    if (var_v0_3 < temp_v1_6)
                    {
                        goto loop_34;
                    }
                }
                else
                {
                    var_s5 = (s32) var_s2_2;
                }
            }
block_38:
            var_v0 = var_s5 << 0x10;
        }
    }
    return var_v0 >> 0x10;
}