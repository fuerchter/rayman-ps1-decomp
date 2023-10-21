#include "obj/saxo.h"

/* 51774 80175F74 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_NOTE_REBOND);*/

/*? calc_obj_pos();*/

void DO_NOTE_REBOND(Obj *arg0)
{
  s32 var_v0;
  
  switch (arg0->type)
  {
    case TYPE_NOTE2:
        DO_EXPLOSE_NOTE2(arg0);
        break;
    case TYPE_NOTE0:
    case TYPE_NOTE3:
    case TYPE_BONNE_NOTE:
        var_v0 = arg0->speed_y;
        if (var_v0 < 0)
            var_v0 = -var_v0;
        arg0->speed_y = -var_v0;
        if (-2 <= arg0->speed_y)
            arg0->speed_y = (-var_v0) - 1;

        arg0->gravity_value_1 = 0xA - arg0->gravity_value_1;
        calc_obj_pos();
        break;
  }

}

/* only block_121 and onward isn't matching yet, then could try transferring to standard m2c output */
/* 51E0C 8017660C -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO_COMMAND);*/

/*? GET_SPRITE_POS(?, u16 *, u16 *, u16 *, ? *);
u8 PrepareAtak();
? calc_obj_dir(Obj *);
? set_main_and_sub_etat(Obj *, u8, u8, u32);
? set_sub_etat(Obj *, ?);
? skipToLabel(Obj *, ?, ?);*/

void DO_SAXO_COMMAND(Obj *obj)
{
    s16 sp18;
    s16 sp1A;
    s16 temp_a0;
    s16 temp_v0_2;
    s16 temp_v1_7;
    s16 var_a0;
    s16 var_a0_2;
    s16 var_v0;
    s16 var_v0_2;
    s16 var_v1;
    s16 var_v1_2;
    s16 var_v1_3;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_s0;
    s32 temp_v1_9;
    u16 temp_v0;
    u16 temp_v0_3;
    u16 temp_v1;
    u32 temp_a3;
    u32 temp_v1_8;
    u8 temp_a1;
    s16 temp_s2;
    s16 temp_v1_2;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 temp_v1_5;
    u8 temp_v1_6;
    int new_var;
    s16 *speed_y;

    new_var = 0x20;
    scrollLocked = 1;
    GET_SPRITE_POS(obj, 2, &Sax.sprite2_x, &Sax.sprite2_y, &sp18, &sp1A);
    if (!(obj->flags & 0x4000))
    {
        goto block_2;
    }
    Sax.sprite2_x = Sax.sprite2_x - new_var + sp18;
block_2:
    Sax.sprite2_x += 0xC;
    Sax.sprite2_y += 0xC;
    Sax.x_pos = (s16) (u16) obj->x_pos;
    Sax.y_pos = (u16) obj->y_pos;
    SetSaxoCollNoteBox(obj);
    if (obj->hit_points != 0)
    {
        goto block_6;
    }
    if (Phase == 0x64)
    {
        goto block_6;
    }
    Sax.coup = 0;
    if (!(((u8) block_flags[(u16) *(((s32) ((((s32) (obj->x_pos + obj->offset_bx) >> 4) + (mp.width * ((s32) (obj->y_pos + obj->offset_by) >> 4))) << 0x10) >> 0x10) + mp.map) >> 0xA] >> 1) & 1))
    {
        goto block_6;
    }
    obj->anim_frame = 0xFF;
    set_main_and_sub_etat(obj, 0U, 4U);
    skipToLabel(obj, 0, 1);
    Phase = 0x64;
    Sax.field10_0x10 = 0x01A4;
    obj->speed_x = 0;
    obj->speed_y = 0;
block_6:
    if (Sax.coup != 1)
    {
        goto block_8;
    }
    DO_SAXO_COUP(obj);
    goto block_11;
block_8:
    if (obj->anim_frame != (obj->animations[obj->anim_index].frames_count - 1))
    {
        FinAnim = 0;
        goto block_12;
    }
    if (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] != 0)
    {
        FinAnim = 0;
        goto block_12;
    }
    FinAnim = 1;
    WaitForAnim = 0;
    goto block_12;
block_11:
    FinAnim = 0;
block_12:
    temp_v1 = (u16) obj->x_pos;
    temp_s2 = Phase;
    if (temp_s2 == 2)
    {
        goto block_59;
    }
    if (temp_s2 >= 3)
    {
        goto block_17;
    }
    if (temp_s2 == 0)
    {
        goto block_21;
    }
    if (temp_s2 == 1)
    {
        goto block_30;
    }
    goto block_158;
block_17:
    if (temp_s2 == 4)
    {
        goto block_101;
    }
    if ((s32) temp_s2 < 4)
    {
        goto block_77;
    }
    if (temp_s2 == 0x64)
    {
        goto block_156;
    }
    goto block_158;
block_21:
    if (obj->main_etat != 0)
    {
        goto block_23;
    }
    if (obj->sub_etat == 0)
    {
        goto block_158;
    }
block_23:
    if (ray.x_pos >= ((s16) temp_v1 + 0xDC))
    {
        goto block_26;
    }
    if ((s16) temp_v1 >= (ray.x_pos + 0x6E))
    {
        goto block_26;
    }
    WaitForAnim = 1;
    goto block_27;
block_26:
    set_main_and_sub_etat(obj, 0U, 2U);
block_27:
    if (WaitForAnim == 0)
    {
        goto block_158;
    }
    if (FinAnim == 0)
    {
        goto block_158;
    }
    Phase = 1;
    NiveauDansPhase = 1;
    IndexAtak = 0;
    IndexSerie = 0;
    NextNote = PrepareAtak();
    set_main_and_sub_etat(obj, 0U, 1U);
    goto block_158;
block_30:
    temp_s0 = ((u32) obj->flags >> 0xE) & 1;
    calc_obj_dir(obj);
    if ((((u32) obj->flags >> 0xE) & 1) == temp_s0)
    {
        goto block_32;
    }
    set_main_and_sub_etat(obj, 0U, 0U);
    obj->speed_x = 0;
    FinAnim = 0;
block_32:
    temp_v1_2 = obj->sub_etat;
    if (temp_v1_2 == temp_s2)
    {
        goto block_39;
    }
    if (temp_v1_2 >= 2)
    {
        goto block_36;
    }
    if (temp_v1_2 == 0)
    {
        goto block_57;
    }
    goto block_158;
block_36:
    if (temp_v1_2 == 2)
    {
        goto block_48;
    }
    if (temp_v1_2 == 3)
    {
        goto block_46;
    }
    goto block_158;
block_39:
    if (horloge[obj->eta[obj->main_etat][1].anim_speed & 0xF] != 0)
    {
        goto block_158;
    }
    temp_v1_3 = obj->anim_frame;
    if (temp_v1_3 == 0x18)
    {
        goto block_45;
    }
    if (temp_v1_3 != 0x1C)
    {
        goto block_43;
    }
    if (WaitForFinAtan == 0)
    {
        goto block_45;
    }
block_43:
    if (temp_v1_3 != 0x20)
    {
        goto block_158;
    }
    if (WaitForFinAtan != 0)
    {
        goto block_158;
    }
block_45:
    SAXO_TIRE(obj);
    goto block_158;
block_46:
    if (FinAnim == 0)
    {
        goto block_158;
    }
    Sax.coup = 0;
    goto block_158;
block_48:
    if (FinAnim == 0)
    {
        goto block_158;
    }
    if ((u8) WaitForFinAtan >= 2U)
    {
        goto block_56;
    }
    switch (attaque.next_note)
    {
case 0:
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
    set_sub_etat(obj, 1);
    goto block_158;
case 7:
    set_main_and_sub_etat(obj, 0U, 0x0AU);
    Phase = 2;
    Sax.field10_0x10 = 3;
    goto block_158;
case 8:
    set_main_and_sub_etat(obj, 0U, 0x0AU);
    Phase = 3;
    Sax.field10_0x10 = 2;
    goto block_158;
case 9:
    set_main_and_sub_etat(obj, 0U, 0x0AU);
    Phase = 4;
    goto block_158;
default:
    goto block_158;
}
block_56:
    WaitForFinAtan--;
    goto block_158;
block_57:
    if (FinAnim == 0)
    {
        goto block_158;
    }
    set_sub_etat(obj, 1);
    NextNote = PrepareAtak();
    goto block_158;
block_59:
    if (FinAnim == 0)
    {
        goto block_63;
    }
    if (obj->main_etat != 0)
    {
        goto block_74;
    }
    if (obj->sub_etat != 3)
    {
        goto block_63;
    }
    set_main_and_sub_etat(obj, Sax.field8_0xe, Sax.field9_0xf);
    Sax.coup = 0;
    FinAnim = 0;
block_63:
    if (obj->main_etat != 0)
    {
        goto block_74;
    }
    if (obj->flags & 0x4000)
    {
        goto block_67;
    }
    if ((obj->x_pos + obj->offset_bx) < 0)
    {
        goto block_68;
    }
    goto block_69;
block_67:
    if ((obj->x_pos + obj->offset_bx) <= (xmapmax + 0x140))
    {
        goto block_69;
    }
block_68:
    obj->speed_x = 0;
block_69:
    if (FinAnim == 0)
    {
        goto block_158;
    }
    temp_v1_4 = obj->sub_etat;
    if (temp_v1_4 == 0x0A)
    {
        goto block_91;
    }
    if (temp_v1_4 != 0x0B)
    {
        goto block_158;
    }
    temp_v0 = Sax.field10_0x10 - 1;
    Sax.field10_0x10 = temp_v0;
    if ((temp_v0 << 0x10) > 0)
    {
        goto block_100;
    }
    goto block_147;
block_74:
    if (obj->main_etat != 1)
    {
        goto block_158;
    }
block_75:
    if (!(obj->flags & 0x4000))
    {
        goto block_152;
    }
    goto block_154;
block_77:
    if (FinAnim == 0)
    {
        goto block_81;
    }
    if (obj->main_etat != 0)
    {
        goto block_97;
    }
    if (obj->sub_etat != 3)
    {
        goto block_81;
    }
    set_main_and_sub_etat(obj, Sax.field8_0xe, Sax.field9_0xf);
    Sax.coup = 0;
    FinAnim = 0;
block_81:
    if (obj->main_etat != 0)
    {
        goto block_97;
    }
    if (obj->flags & 0x4000)
    {
        goto block_85;
    }
    if ((obj->x_pos + obj->offset_bx) < 0)
    {
        goto block_86;
    }
    goto block_87;
block_85:
    if ((obj->x_pos + obj->offset_bx) <= (xmapmax + 0x140))
    {
        goto block_87;
    }
block_86:
    obj->speed_x = 0;
block_87:
    if (FinAnim == 0)
    {
        goto block_158;
    }
    temp_v1_5 = obj->sub_etat;
    if (temp_v1_5 == 0x0A)
    {
        goto block_91;
    }
    if (temp_v1_5 == 0x0B)
    {
        goto block_94;
    }
    goto block_158;
block_91:
    obj->gravity_value_2 = 5;
    obj->gravity_value_1 = 0;
    obj->speed_y = -6;
    var_a0 = -1;
    obj->y_pos = (u16) obj->y_pos - 6;
    if (!(obj->flags & 0x4000))
    {
        goto block_93;
    }
    var_a0 = 1;
block_93:
    obj->speed_x = var_a0;
    goto block_158;
block_94:
    Sax.field10_0x10 -= 1;
    set_main_and_sub_etat(obj, 1U, 0U);
    var_v1 = -2;
    if (!(obj->flags & 0x4000))
    {
        goto block_96;
    }
    var_v1 = 2;
block_96:
    obj->speed_x = var_v1;
    obj->iframes_timer = 0x001E;
    goto block_158;
block_97:
    temp_v1_6 = obj->main_etat;
    if (temp_v1_6 != 1)
    {
        goto block_158;
    }
    if ((s16) Sax.field10_0x10 != temp_v1_6)
    {
        goto block_75;
    }
    temp_v0_2 = obj->iframes_timer - 1;
    obj->iframes_timer = temp_v0_2;
    if ((temp_v0_2) > 0)
    {
        goto block_158;
    }
block_100:
    set_main_and_sub_etat(obj, 0U, 0x0AU);
    obj->speed_x = 0;
    goto block_158;
block_101:
    if (FinAnim == 0)
    {
        goto block_105;
    }
    if (obj->main_etat != 0)
    {
        goto block_150;
    }
    if (obj->sub_etat != 3)
    {
        goto block_105;
    }
    set_main_and_sub_etat(obj, Sax.field8_0xe, Sax.field9_0xf);
    Sax.coup = 0;
    FinAnim = 0;
block_105:
    if (obj->main_etat != 0)
    {
        goto block_150;
    }
    if (obj->flags & 0x4000)
    {
        goto block_109;
    }
    if ((obj->x_pos + obj->offset_bx) < 0)
    {
        goto block_110;
    }
    goto block_111;
block_109:
    if ((obj->x_pos + obj->offset_bx) <= (xmapmax + 0x140))
    {
        goto block_111;
    }
block_110:
    obj->speed_x = 0;
block_111:
    if (FinAnim == 0)
    {
        goto block_158;
    }
    temp_a1 = obj->sub_etat;
    if (temp_a1 == 0x0A)
    {
        goto block_115;
    }
    if (temp_a1 == 0x0B)
    {
        goto block_137;
    }
    goto block_158;
block_115:
    obj->gravity_value_2 = 5;
    obj->gravity_value_1 = 0;
    temp_v1_7 = (ray.x_pos - 0x30);
    temp_v1_7 = obj->x_pos - temp_v1_7;
    var_a0_2 = temp_v1_7;
    if (temp_v1_7 >= 0)
    {
        goto block_117;
    }
    var_a0_2 = -temp_v1_7;
block_117:
    if (var_a0_2 < 0x65)
    {
        goto block_127;
    }

block_121:
    obj->speed_y = (s16) var_a0_2 / 20;
    if (obj->speed_y < 0xA)
    {
        goto block_123;
    }
    var_v0 = 9;
    goto block_124;
block_123:
    var_v0 = 4;
    if (obj->speed_y >= 4)
    {
        goto block_125;
    }
block_124:
    obj->speed_y = var_v0;
block_125:
    var_v1_2 = -2;
    if (!(obj->flags & 0x4000))
    {
        goto block_136;
    }
    var_v1_2 = 2;
    goto block_136;
block_127:
block_130:
    obj->speed_y = var_a0_2 / (s32) temp_a1;
    if (obj->speed_y < 0xA)
    {
        goto block_132;
    }
    var_v0_2 = 9;
    goto block_133;
block_132:
    var_v0_2 = 4;
    if (obj->speed_y >= 4)
    {
        goto block_134;
    }
block_133:
    obj->speed_y = var_v0_2;
block_134:
    var_v1_2 = -1;
    if (!(obj->flags & 0x4000))
    {
        goto block_136;
    }
    var_v1_2 = 1;
block_136:
    obj->speed_x = var_v1_2;
    obj->y_pos = obj->y_pos - obj->speed_y;
    obj->speed_y = -obj->speed_y;
    goto block_158;
block_137:
    if (!(obj->flags & 0x4000))
    {
        goto block_140;
    }
    if ((obj->x_pos + 0x30) < ray.x_pos)
    {
        goto block_142;
    }
    goto block_145;
block_140:
    temp_a0 = obj->x_pos;
    if (ray.x_pos >= (temp_a0 + 0x30))
    {
        goto block_143;
    }
block_142:
    set_main_and_sub_etat(obj, 0U, 0x0AU);
    goto block_158;
block_143:
    if ((temp_a0 + 0x40) < 0)
    {
        goto block_155;
    }
    goto block_147;
block_145:
    if ((obj->x_pos + 0xC0) > (xmapmax + 0x140))
    {
        goto block_155;
    }
block_147:
    set_main_and_sub_etat(obj, 1U, 0U);
    var_v1_3 = -2;
    if (!(obj->flags & 0x4000))
    {
        goto block_149;
    }
    var_v1_3 = 2;
block_149:
    obj->speed_x = var_v1_3;
    goto block_158;
block_150:
    if (obj->main_etat != 1)
    {
        goto block_158;
    }
    if (obj->flags & 0x4000)
    {
        goto block_154;
    }
block_152:
    if ((obj->x_pos + 0x40) < 0)
    {
        goto block_155;
    }
    goto block_158;
block_154:
    if ((obj->x_pos + 0xC0) <= (xmapmax + 0x140))
    {
        goto block_158;
    }
block_155:
    temp_v1_8 = obj->flags;
    temp_a3 = (temp_v1_8 & ~0x4000) | (((1 - ((temp_v1_8 >> 0xE) & 1)) & 1) << 0xE);
    obj->flags = temp_a3;
    set_main_and_sub_etat(obj, 0U, 0U, temp_a3);
    obj->speed_x = 0;
    Phase = 1;
    goto block_158;
block_156:
    temp_v0_3 = Sax.field10_0x10 - 1;
    Sax.field10_0x10 = temp_v0_3;
    if ((temp_v0_3 << 0x10) > 0)
    {
        goto block_158;
    }
    Sax.field10_0x10 = 0x03E7;
    fin_boss = 1;
    *finBosslevel |= 4;
block_158:
    temp_v1_9 = obj->x_pos + obj->offset_bx + obj->speed_x;
    if (temp_v1_9 < 0)
    {
        goto block_160;
    }
    if ((xmapmax + 0x13F) >= temp_v1_9)
    {
        goto block_161;
    }
block_160:
    obj->speed_x = 0;
block_161:
    return;
}