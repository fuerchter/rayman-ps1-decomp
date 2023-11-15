#include "ray/ray_5D190.h"

/* didn't try hard on reg swaps yet, first "type" check (switch?) has been difficult so far */
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", rayMayLandOnAnObject);*/

int GET_SPRITE_POS(Obj *obj,int spriteIndex,short *x,short *y,ushort *w,ushort *h);
s16 ashr16(ushort param_1,uint param_2);
extern s16 helico_time;

void rayMayLandOnAnObject(u8 *param_1, s16 param_2)
{
    s16 sp18;
    s16 sp1A;
    u16 sp1C;
    u16 sp1E;
    u8 var_a1_2;
    Obj *var_s1;
    s16 temp_v0;
    s16 var_a0_2;
    s16 var_a0_3;
    s16 var_a1;
    s16 var_s0;
    s16 var_s0_2;
    s16 var_s2;
    s16 var_v0;
    s16 var_v1;
    s32 var_v1_2;
    s32 temp_v1_4;
    s32 var_v0_2;
    s16 var_a0;
    u8 temp_v0_2;
    u8 temp_v1;
    s32 temp_v1_2;
    u8 temp_v1_3;
    ActiveObjects *new_var;
    RaymanEvents *test_1;
    s32 test_2;

    var_s2 = 4;
    if (!(RayEvts.flags1 & 2))
    {
        goto block_2;
    }
    var_s2 = 8;

block_2:
    ray.field20_0x36 = -1;
    var_s0 = 0;
    
    var_s1 = &level.objects[actobj.objects[0]];
    if (actobj.num_active_objects <= 0)
    {
        goto block_122;
    }
    new_var = &actobj;
    test_1 = &RayEvts;
loop_4:
    if (!(var_s1->flags & 0x10000))
    {
        goto block_120;
    }
    var_a1 = var_s0 + 1;
    if (var_s1->id == param_2)
    {
        goto block_121;
    }
    if (!(((u8) flags[var_s1->type].flags1 >> 5) & 1))
    {
        goto block_8;
    }
    var_a0 = instantSpeed(var_s1->speed_y);
    goto block_9;
block_8:
    var_a0 = var_s1->speed_y;
block_9:
    var_v0 = __builtin_abs((s16)(var_a0 + (var_s1->follow_y - ray.speed_y)));
block_11:
    temp_v0 = var_v0 + 2;
    var_a0_2 = temp_v0;
    if (temp_v0 >= var_s2)
    {
        goto block_13;
    }
    var_a0_2 = var_s2;
block_13:
    temp_v1 = var_s1->type;
    if (temp_v1 == 0x6D)
    {
        goto block_16;
    }
    if (temp_v1 == 0xF1)
    {
        goto block_16;
    }
    if (temp_v1 != 0xB3)
    {
        goto block_17;
    }
block_16:
    var_a0_2 += 8;
block_17:
block_19:
    var_a1 = var_s0 + 1;
    if (__builtin_abs(var_s1->ray_dist) >= var_a0_2)
    {
        goto block_121;
    }
    if (((u8) block_flags[calc_typ_trav(&ray, 2) & 0xFF] >> 4) & 1)
    {
        goto block_120;
    }
    ray.field20_0x36 = new_var->objects[var_s0];
    if (left_time != -2)
    {
        goto block_24;
    }
    if (!(map_time & 1))
    {
        goto block_24;
    }
    map_time += 1;
block_24:
    ray.field23_0x3c = -1;
    ray_last_ground_btyp = 1;
    if (ray.main_etat != 2)
    {
        goto block_62;
    }
    temp_v1_2 = var_s1->type;
    if (temp_v1_2 == 0x54)
    {
        goto block_62;
    }
    if (temp_v1_2 >= 0x55)
    {
        goto block_38;
    }
    if (temp_v1_2 == 0x16)
    {
        goto block_57;
    }
    if ((s32) temp_v1_2 >= 0x17)
    {
        goto block_34;
    }
    if (temp_v1_2 == 1)
    {
        goto block_52;
    }
    if (temp_v1_2 == 0)
    {
        goto block_60;
    }
    if ((s32) temp_v1_2 >= 0x12)
    {
        goto block_60;
    }
    var_a0_3 = 0x0013;
    if ((s32) temp_v1_2 < 0x10)
    {
        goto block_61;
    }
    goto block_55;
block_34:
    var_a0_3 = 0x0013;
    if ((s32) temp_v1_2 < 0x1A)
    {
        goto block_61;
    }
    if ((s32) temp_v1_2 < 0x1D)
    {
        goto block_57;
    }
    if (temp_v1_2 == 0x3F)
    {
        goto block_57;
    }
    goto block_60;
block_38:
    if (temp_v1_2 == 0xA0)
    {
        goto block_51;
    }
    if ((s32) temp_v1_2 >= 0xA1)
    {
        goto block_44;
    }
    var_a0_3 = 0x0013;
    if ((s32) temp_v1_2 < 0x56)
    {
        goto block_61;
    }
    if ((s32) temp_v1_2 < 0x59)
    {
        goto block_62;
    }
    if (temp_v1_2 == 0x9F)
    {
        goto block_62;
    }
    goto block_60;
block_44:
    if (temp_v1_2 == 0xED)
    {
        goto block_59;
    }
    if ((s32) temp_v1_2 >= 0xEE)
    {
        goto block_49;
    }
    if ((s32) temp_v1_2 >= 0xB4)
    {
        goto block_60;
    }
    var_a0_3 = 0x0013;
    if ((s32) temp_v1_2 < 0xB2)
    {
        goto block_61;
    }
    goto block_62;
block_49:
    var_a0_3 = 0x0034;
    if (temp_v1_2 == 0xF3)
    {
        goto block_61;
    }
    var_a0_3 = 0x0013;
    goto block_61;
block_51:
    PlaySnd(0x006E, var_s1->id);
    goto block_62;
block_52:
    if (num_world == temp_v1_2)
    {
        goto block_60;
    }
    var_a0_3 = 0x00F2;
    if (num_world == 4)
    {
        goto block_60;
    }
    goto block_61;
block_55:
    var_a0_3 = 0x0013;
    if ((u32) ((u16) num_world - 4) < 2U)
    {
        goto block_61;
    }
    var_a0_3 = 0x00F2;
    goto block_61;
block_57:
    var_a0_3 = 0x00F2;
    if (num_world == 4)
    {
        goto block_60;
    }
    goto block_61;
block_59:
    var_a0_3 = 0x00F8;
    goto block_61;
block_60:
    var_a0_3 = 0x0013;
block_61:
    PlaySnd(var_a0_3, -1);
block_62:
    temp_v0_2 = var_s1->type;
    /*if ((temp_v0_2 - 8) > 0xC7U)
    {
        goto block_111;
    }*/
    switch (temp_v0_2)
    {
    case 0x51:
        var_s1->field24_0x3e = 0;
        goto block_111;
    case 0x8:
    case 0x86:
    case 0xA7:
        if (var_s1->main_etat != 0)
        {
            goto block_111;
        }
        if (var_s1->sub_etat != 0x0D)
        {
            goto block_111;
        }
        set_main_and_sub_etat(var_s1, 0, 0xF);
        goto block_111;
    case 0x83:
        if (var_s1->sub_etat != 3)
        {
            goto block_111;
        }
        var_a1_2 = 0;
        skipToLabel(var_s1, var_a1_2, 1);
        goto block_111;
    case 0x56:
        if (var_s1->sub_etat != 4)
        {
            goto block_111;
        }
        if (var_s1->hit_points != 0)
        {
            goto block_73;
        }
        set_sub_etat(var_s1, 5);
        goto block_111;
    block_73:
        MARACAS_GO(var_s1);
        goto block_111;
    case 0x57:
        var_s1->field56_0x69 = 0x10;
        if (var_s1->main_etat != 0)
        {
            goto block_111;
        }
        temp_v1_3 = var_s1->sub_etat;
        if (temp_v1_3 != 7)
        {
            goto block_77;
        }
        set_main_and_sub_etat(var_s1, 2, 0);
        PlaySnd(0x006E, var_s1->id);
        goto block_111;
    block_77:
        if (temp_v1_3 != 9)
        {
            goto block_111;
        }
        set_main_and_sub_etat(var_s1, 2, 2);
        PlaySnd(0x0070, var_s1->id);
        goto block_111;
    case 0x58:
        var_s1->field56_0x69 = 0x10;
        set_main_and_sub_etat(var_s1, 2, 1);
        PlaySnd(0x006F, var_s1->id);
        goto block_111;
    case 0xA9:
        if (var_s1->main_etat != 0)
        {
            goto block_111;
        }
        if (var_s1->sub_etat != 0x0D)
        {
            goto block_111;
        }
        START_2_PARTS_CYMBAL_ACTION(var_s1);
        goto block_111;
    case 0x8A:
        if (var_s1->main_etat != 0)
        {
            goto block_111;
        }
        if (var_s1->sub_etat != 0x0A)
        {
            goto block_111;
        }
        var_a1_2 = 1;
        skipToLabel(var_s1, var_a1_2, 1);
        goto block_111;
    case 0x9A:
        if (var_s1->main_etat != 0)
        {
            goto block_111;
        }
        if (var_s1->sub_etat != 0x0D)
        {
            goto block_111;
        }
        var_a1_2 = 1;
        skipToLabel(var_s1, var_a1_2, 1);
        goto block_111;
    case 0x9B:
        if (var_s1->main_etat != 0)
        {
            goto block_111;
        }
        if (var_s1->sub_etat != 0x0F)
        {
            goto block_111;
        }
        var_a1_2 = 1;
        skipToLabel(var_s1, var_a1_2, 1);
        goto block_111;
    case 0x31:
        if (var_s1->main_etat != 0)
        {
            goto block_111;
        }
        if (var_s1->sub_etat != 0)
        {
            goto block_111;
        }
        var_a1_2 = 0;
        skipToLabel(var_s1, var_a1_2, 1);
        goto block_111;
    case 0x3F:
        if (var_s1->main_etat != 0)
        {
            var_a1_2 = 0;
            skipToLabel(var_s1, var_a1_2, 1);
            goto block_111;
        }
        if (var_s1->sub_etat == 0x0A)
        {
            goto block_111;
        }
    case 0x10:
    case 0x11:
        var_a1_2 = 0;
        skipToLabel(var_s1, var_a1_2, 1);
        goto block_111;
    case 0xA2:
        if (!(finBosslevel[1] & 4))
        {
            goto block_111;
        }
        START_UFO(var_s1);
        goto block_111;
    case 0xCF:
        if (var_s1->main_etat != 0 || var_s1->sub_etat != 1)
        {
            set_main_and_sub_etat(var_s1, 0, 1);
            test_2 = 1;
            var_s1->flags &= 0xFFFEFFFF;
            ray_on_poelle = test_2;
            ray.field20_0x36 = -1;
            ray.speed_x = 1;
            PS1_SetSauveRayEvts();
            test_1->flags0 = 1; /* TODO: var? */
            test_1->flags1 = 0U;
        }
        goto block_111;
    case 0x43:
        if (var_s1->main_etat != 0)
        {
            goto block_111;
        }
        if (var_s1->sub_etat != 2)
        {
            goto block_111;
        }
        set_sub_etat(var_s1, 9);
        goto block_111;
    case 0x1B:
    case 0x44:
        var_v1_2 = ray.speed_y;
        if (var_v1_2 < 2)
        {
            var_v1_2 = 2;
        }
        var_s1->field20_0x36 = var_v1_2;
    }
block_111:
    if (ray.main_etat != 2)
    {
        goto block_119;
    }

block_114:
    if (__builtin_abs(ray.speed_x) < ashr16((s8) ray.eta[1][3].speed_x_right, 4))
    {
        goto block_117;
    }
    if (!(RayEvts.flags1 & 1))
    {
        goto block_117;
    }
    set_main_and_sub_etat((Obj *) (&ray.main_etat - 0x56), 1, 3);
    goto block_119;
block_117:
    set_main_etat(&ray, 0);
    set_sub_etat(&ray, 8);
    if (ray.field24_0x3e < 0xC9)
    {
        goto block_119;
    }
    allocateRayLandingSmoke();
block_119:
    GET_SPRITE_POS(var_s1, (s32) var_s1->follow_sprite, &sp18, &sp1A, &sp1C, &sp1E);
    ray.speed_y = ((var_s1->offset_hy + (u16) sp1A) - ray.offset_by) - ray.y_pos;
    *param_1 = 0;
    ray.field24_0x3e = -1;
    helico_time = -1;
    var_v0_2 = param_2 << 0x10;
    goto block_123;
block_120:
    var_a1 = var_s0 + 1;
block_121:
    var_s0 = var_a1;
    var_s1 = &level.objects[new_var->objects[var_a1]];
    if (var_a1 < new_var->num_active_objects)
    {
        goto loop_4;
    }
block_122:
    var_v0_2 = param_2 << 0x10;
block_123:
    temp_v1_4 = var_v0_2 >> 0x10;
    if (temp_v1_4 == -1)
    {
        goto block_126;
    }
    if ((s16) ray.field20_0x36 != (s16) -1)
    {
        goto block_127;
    }
    ray.field20_0x36 = (u16) param_2;
    return;
block_126:
    if ((s16) ray.field20_0x36 == temp_v1_4)
    {
        goto block_128;
    }
block_127:
    level.objects[(s16) ray.field20_0x36].ray_dist = 0;
block_128:
    return;
}