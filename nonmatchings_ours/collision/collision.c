#include "collision/collision.h"

/* reg swaps */
/*INCLUDE_ASM("asm/nonmatchings/collision/collision", in_coll_sprite_list);*/

s8 in_coll_sprite_list(Obj *obj, s16 param_2)
{
    u8 sp[16];
    s16 var_a2;
    u8 var_v0;
    s8 temp_a0;
    
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
int GET_SPRITE_POS(Obj *obj,int spriteIndex,short *x,short *y,ushort *w,ushort *h);
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

/*int GET_SPRITE_POS(Obj *obj,int spriteIndex,short *x,short *y,ushort *w,ushort *h);*/

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