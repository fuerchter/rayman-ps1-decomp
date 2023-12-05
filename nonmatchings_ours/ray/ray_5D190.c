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

/* matches, but too many unknown locals */
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", ray_inertia_speed);*/

/*s16 ashr16(s16 param_1, u32 param_2);
s32 ashl16(s16 param_1, u32 param_2);*/

void ray_inertia_speed(u8 param_1, s16 param_2, s16 prev_speed_x, s16 param_4)
{

    s16 temp_s3_2;
    s16 temp_v1;
    s16 var_a1;
    s32 var_s0;
    s16 var_s2;
    s16 var_s6;
    s16 var_v1;
    s16 temp_s0_2;
    s32 temp_s1;
    s32 temp_s1_2;
    s16 temp_s3_1;
    s32 temp_v0;
    s32 new_var2;

    if (param_1 == 0)
    {
        decalage_en_cours = prev_speed_x;
        var_s2 = 0;
    }
    else
    {
        new_var2 = 6;
        temp_s3_1 = ashr32(prev_speed_x * param_1, 8);
        var_s2 = ashr16(param_1, 3);
        var_v1 = var_s2;
        if (var_v1 == 0)
            var_v1 = 1;
        var_s2 = var_v1;
        temp_s0_2 = ashl16(param_2, 2);
        temp_s3_2 = ashl16(param_4, 3) + (temp_s3_1 + temp_s0_2);
        temp_v1 = num_world - 1;
        switch (temp_v1)
        {
        case 0:
        case 1:
        case 3:
        case 5:
            var_s6 = new_var2;
            break;
        case 2:
            var_s6 = 3;
            break;
        }
        if (temp_s3_2 > 0)
        {
            if (temp_s3_1 > 0)
                var_s0 = prev_speed_x;
            else
                var_s0 = 0;
            temp_s1 = ashl16(param_4, 8);
            if (temp_s0_2 > 0)
            {
                temp_v0 = ashl16(param_2 + var_s6, 8);
                temp_v0 = var_s0 + temp_v0 / var_s2 + temp_s1;
            }
            else
                temp_v0 = var_s0 + temp_s1;
            var_a1 = temp_v0;
            MAX_3(var_a1, decalage_en_cours);

        }
        else if (temp_s3_2 < 0)
        {
            if (temp_s3_1 < 0)
                var_s0 = prev_speed_x;
            else
                var_s0 = 0;
            temp_s1_2 = ashl16(param_4, 8);
            if (temp_s0_2 < 0)
            {
                temp_v0 = ashl16(param_2 - var_s6, 8);
                temp_v0 = var_s0 + temp_v0 / var_s2 + temp_s1_2;
            }
            else
                temp_v0 = var_s0 + temp_s1_2;
            var_a1 = temp_v0;
            MIN_3(var_a1, decalage_en_cours);
        }
        else
            var_a1 = decalage_en_cours;
        if (temp_s3_2 != 0)
        {
            if (var_a1 > 0)
            {
                if (decalage_en_cours < var_a1)
                    decalage_en_cours += temp_s3_2;
                MIN_3(decalage_en_cours, var_a1);
            }
            else
            {
                if (var_a1 < decalage_en_cours)
                    decalage_en_cours += temp_s3_2;
                MAX_3(decalage_en_cours, var_a1);
            }
        }
    }
    if (decalage_en_cours != 0)
    {
        ray.speed_x = instantSpeed(ashr16(decalage_en_cours, 4));
        if (block_flags[(u8) calc_typ_travd(&ray, 0)] >> BLOCK_FLAG_4 & 1 && ray.main_etat != 2)
        {
            ray.speed_x = 0;
            decalage_en_cours = 0;
            ray.nb_cmd = 0;
        }
    }
    else
        ray.speed_x = 0;

    if ((ray.main_etat == 0 || ray.main_etat == 1 || ray.main_etat == 3) && ray.field20_0x36 == -1)
        CALC_MOV_ON_BLOC(&ray);
    
    if (ray.main_etat == 2 && ray.sub_etat == 15)
        var_s2 += 2;
    if (decalage_en_cours >= var_s2)
        decalage_en_cours -= var_s2;
    else if (decalage_en_cours <= -var_s2)
        decalage_en_cours += var_s2;
    else
        decalage_en_cours = 0;
}

/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_SWIP);*/

void RAY_SWIP(void)
{
    u8 sp10;
    Obj *temp_s1;
    s16 temp_a2;
    s16 temp_v0;
    s16 temp_v1;
    s16 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_a1;
    u8 var_s0;
    s32 var_s4;
    s32 var_v1;
    u8 temp_s1_2;
    u8 temp_v1_2;

    /*var_s0 = saved_reg_s0;*/
    var_s2 = 0;
    var_s4 = 0x10;
    if (num_world == 3)
    {
        var_s4 = 0x20;
    }
    if (ray.field20_0x36 != -1)
    {
        temp_s1 = &level.objects[ray.field20_0x36];
        if (!(temp_s1->flags & 0x10000))
        {
            ray.field20_0x36 = -1;
        }
        temp_v1 = temp_s1->ray_dist;
        var_v0 = __builtin_abs(temp_v1); /* abs? */
        if ((var_v0 >= 9) || (temp_v1 < 0) || (ray.field20_0x36 == -1))
        {
            rayMayLandOnAnObject(&sp10, ray.field20_0x36);
            if (ray.field20_0x36 != -1)
            {
                if (__builtin_abs(temp_s1->ray_dist) >= 9)
                {
                    ray.field20_0x36 = -1;
                    temp_s1_2 = ray.main_etat;
                    set_main_etat(&ray, 2);
                    
                    if (ray_on_poelle != 0)
                    {
                        if ((temp_s1_2 == 0) && (ray.sub_etat == 0x28))
                        {
                            set_sub_etat((Obj *) (&ray), 0x1A);
                        }
                        else
                        {
                            set_sub_etat(&ray, 0x1C);
                        }
                    }
                    else if ((temp_s1_2 & 0xFF) == 1)
                    {
                        if ((ray.sub_etat == 9) || ((ray.sub_etat == 0x0B)))
                        {
                            ray.flags = (ray.flags & ~0x4000) | (((((u32) ray.flags >> 0xE) ^ 1) & 1) << 0xE);
                        }
                        if (temp_s1_2 == 1)
                        {
                            if (ray.sub_etat == 3)
                            {
                                set_sub_etat((Obj *) (&ray.sub_etat - 0x58), 0x20);
                            }
                            else
                            {
                                set_sub_etat((Obj *) (&ray.sub_etat - 0x58), 0x18);
                            }
                        }
                        else
                        {
                            goto block_27;
                        }
                    }
                    else
                    {
block_27:
                        set_sub_etat(&ray, 1);
                    }
                    ray.field24_0x3e = 0;
                    jump_time = 0;
                }
            }
        }
    }
    if (ray_in_fee_zone == 0)
    {
        SET_X_SPEED(&ray);
    }
    if ((ray.main_etat == 1) && ((ray.sub_etat == 9) || (ray.sub_etat == 0x30) || (ray.sub_etat == 0x0B)))
    {
        ray.speed_x = (u16) -(s32) ray.speed_x;
    }
    temp_v0 = ashl16((s16) ray.speed_x, 4);
    temp_a2 = temp_v0;
    if ((s16) ray.speed_x != 0)
    {
        var_a1 = -(__builtin_abs(temp_v0) < 0x101);
        if (ray_wind_force > 0)
        {
            ray.speed_x = (s16) ray.speed_x + 0xA;
        }
        else if (ray_wind_force < 0)
        {
            ray.speed_x = (s16) ray.speed_x - 0xA;
        }
    }
    else
    {
        var_a1 = 0;
    }
    /* could try gotos-only for this entire section... */
    if(ray.main_etat == 2)
    {
        if ((ray.sub_etat == 0x0F) || (ray.nb_cmd != 0))
        {
            if (ray.flags & 0x4000)
            {
                var_s0 = 0xC;
                if (decalage_en_cours <= 0)
                {
                    var_s0 = 8;
                }
            }
            else
            {
                var_s0 = 8;
                if (decalage_en_cours < 0)
                {
                    var_s0 = 0xC;
                }
            }
        }
        else
        {
            var_s0 = var_a1;
        }
        var_s2 = 0;
    /*default:
block_57:
        var_s2 = 0;
        break;*/
    }
    else if(ray.main_etat == 0 || ray.main_etat == 1 || ray.main_etat == 3)
    {
        if (ray.field20_0x36 != -1)
        {
            var_s0 = 0;
            var_s2 = 0;
        }
        else
        {
            switch (ray.btypes[0])
            {
            case 0:
            case 1:
            case 8:
            case 9:
            case 24:
            case 25:
            case 30:
                /* not sure about this */
                if ((block_flags[ray.btypes[0]] & 1) || (temp_v1_2 = block_flags[ray.btypes[4]], (((temp_v1_2 >> 3) & 1) != 0)) || (var_s0 = var_a1, (((temp_v1_2 >> 1) & 1) == 0)))
                {
                    var_s0 = var_s4;
                    if ((s16) ray.speed_x == 0)
                    {
                        var_s2 = 0;
                        if (decalage_en_cours == 0)
                        {
                            if (ray_wind_force == 0)
                            {
                                var_s0 = var_a1;
                            }
                        }
                    }
                }
                break;
            case 15:
                var_s0 = var_a1;
                switch (ray.btypes[3])
                {
                case 20:
                case 21:
                    var_s0 = var_s4;
                    var_s2 = -4;
                    break;
                case 22:
                case 23:
                    var_s0 = var_s4;
                    var_s2 = 4;
                    break;
                case 18:
                    var_s0 = var_s4;
                    var_s2 = -6;
                    break;
                case 19:
                    var_s0 = var_s4;
                    var_s2 = 6;
                    break;
                }
                break;
            case 20:
            case 21:
                var_s0 = var_s4;
                var_s2 = -4;
                break;
            case 22:
            case 23:
                var_s0 = var_s4;
                var_s2 = 4;
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 12:
            case 14:
                var_s0 = var_a1;
                var_s2 = 0;
                break;
            case 18:
                var_s0 = var_s4;
                var_s2 = -6;
                break;
            case 19:
                var_s0 = var_s4;
                var_s2 = 6;
                break;
            }
        }
    }
    if (ray_on_poelle == 1)
    {
        var_s0 = var_s0 >> 1;
    }
    ray_inertia_speed(var_s0, var_s2, temp_a2, ray_wind_force);
}

/* kinda clueless still. m2c (1600), then ghidra. also tried modelling after android, but no luck */
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", CAN_RAY_HANG_BLOC);*/

void CAN_RAY_HANG_BLOC(void)
{
    s16 temp_s0;
    s16 temp_v0_1; /* s32??? 27fc */
    s16 var_a0;
    s16 var_s5;
    s32 temp_fp;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s4;
    s32 temp_s6;
    s32 temp_v0_2;
    s32 var_s7;
    s32 var_v0;

    if ((RayEvts.flags0 & 2) && !(RayEvts.flags1 & 0x18))
    {
        temp_v0_1 = ray.offset_bx + ray.x_pos;
        temp_v0_2 = (s32) (temp_v0_1 << 0x10) >> 0x14;
        if ((temp_v0_2 > 0) && ((mp.width - 2) >= temp_v0_2))
        {
            temp_s0 = ray.offset_hy + ray.y_pos + 0x20;
            if (ray.scale != 0)
            {
                set_proj_center(temp_v0_1, ray.y_pos + ray.offset_by);
                temp_s0 = get_proj_y(ray.scale, temp_s0);
            }
            var_s5 = -1;
            if (ray.flags & 0x4000)
            {
                var_s5 = 1;
            }
            temp_s2 = temp_v0_2 + (((s32) (temp_s0 << 0x10) >> 0x14) * mp.width);
            temp_s6 = (temp_s2 - mp.width) + var_s5;
            temp_s4 = temp_s2 + mp.width;
            if (temp_s6 >= 0)
            {
                temp_s1 = temp_s4 + mp.width;
                var_s7 = temp_s1 + mp.width;
                temp_fp = temp_s2 + var_s5;
                if (ray.scale != 0)
                {
                    var_s7 = temp_s1;
                }
                if (
                    (
                        ((MUR(temp_fp)) != 0) || ((MUR(var_s5)) != 0) ||
                        ((MUR(temp_s1)) != 0)
                    ) &&
                    (ray.main_etat == 2) && (jump_time >= 9)
                )
                {
                    if (
                        ((AIR(temp_s2)) != 0) && ((AIR(temp_s1)) != 0) &&
                        ((AIR(temp_s4)) != 0) && ((AIR(temp_s6)) != 0) &&
                        ((AIR(var_s7)) != 0) && ((MUR(temp_fp)) != 0)
                    )
                    {
                            Make_Ray_Hang(temp_v0_1, (s16) temp_s0);
                    }
                    else if (
                        (ray.scale == 0) &&
                        (((s32) temp_v0_1 >= 2) || !(ray.flags & 0x4000)) &&
                        (
                            ((((mp.width - 3) < (s32) temp_v0_1) == 0)) ||
                            (((ray.flags & 0x4000) != 0))
                        )
                    )
                    {
                        if (
                            ((AIR(temp_s2 - var_s5)) != 0) && ((AIR(temp_s1 - var_s5)) != 0) &&
                            ((AIR(temp_s4 - var_s5)) != 0) && ((AIR(temp_s6 - var_s5)) != 0) &&
                            ((AIR(var_s7 - var_s5)) != 0) && ((MUR(temp_fp - var_s5)) != 0))
                        {
                            Make_Ray_Hang((s16) temp_v0_1 - (var_s5 * 0x10), (s16) temp_s0);
                        }
                    }
                }
            }
        }
    }
}

void CAN_RAY_HANG_BLOC(void)

{
  s16 temp_v0_1;
  short sVar2;
  short var_s5;
  int temp_v0_2;
  int iVar5;
  s16 temp_s0_1;
  int temp_s1;
  int temp_s4;
  int temp_s6;
  int iVar10;
  s16 temp_s0_2;
  
  if (((RayEvts.flags0 & FLG(RAYEVTS0_HANG)) != FLG_RAYEVTS0_NONE) &&
     ((RayEvts.flags1 & (FLG(RAYEVTS1_FORCE_RUN_TOGGLE)|FLG(RAYEVTS1_FORCE_RUN))) ==
      FLG_RAYEVTS1_NONE)) {
    temp_v0_1 = ray.offset_bx + ray.x_pos;
    temp_v0_2 = (temp_v0_1 << 0x10) >> 0x14;
    if ((0 < temp_v0_2) && (temp_v0_2 <= mp.width + -2)) {
      temp_s0_1 = ray.offset_hy + ray.y_pos + 0x20;
      temp_s0_2 = temp_s0_1;
      if (ray.scale != 0) {
        set_proj_center(temp_v0_1,ray.y_pos + ray.offset_by);
        temp_s0_2 = get_proj_y(ray.scale,temp_s0_1);
      }
      var_s5 = -1;
      if ((ray.flags & FLG(OBJ_FLIP_X)) != FLG_OBJ_NONE) {
        var_s5 = 1;
      }
      iVar5 = mp.width;
      temp_v0_2 = temp_v0_2 + ((int)(temp_s0_2 >> 4)) * iVar5;
      temp_s6 = (temp_v0_2 - iVar5) + var_s5;
      temp_s4 = temp_v0_2 + iVar5;
      if (-1 < temp_s6) {
        temp_s1 = temp_s4 + iVar5;
        iVar10 = temp_v0_2 + var_s5;
        iVar5 = temp_s1 + iVar5;
        if (ray.scale != 0) {
          iVar5 = temp_s1;
        }

        if ((((MUR(iVar10) != 0) || (MUR(var_s5))) ||
            (MUR(temp_s1))) && ((ray.main_etat == 2 && (8 < jump_time))))
        {

          if (!((((AIR(temp_v0_2) == 0) ||
               ((AIR(temp_s1) == 0 || (AIR(temp_s4) == 0)))) ||
              (AIR(temp_s6) == 0)) ||
             ((AIR(iVar5) == 0 || (MUR(iVar10) == 0))))) {
            temp_v0_2 = temp_v0_1;
          }
          else {
            if (ray.scale != 0) {
              return;
            }
            if (((temp_v0_1 >> 4) < 2) && ((ray.flags & FLG(OBJ_FLIP_X)) != FLG_OBJ_NONE)
               ) {
              return;
            }
            if ((mp.width + -3 < (temp_v0_1 >> 4)) &&
               ((ray.flags & FLG(OBJ_FLIP_X)) == FLG_OBJ_NONE)) {
              return;
            }
            temp_s0_1 = var_s5;
            var_s5 = AIR(temp_v0_2 - temp_s0_1);
            if (var_s5 == 0) {
              return;
            }
            var_s5 = AIR(temp_s1 - temp_s0_1);
            if (var_s5 == 0) {
              return;
            }
            var_s5 = AIR(temp_s4 - temp_s0_1);
            if (var_s5 == 0) {
              return;
            }
            var_s5 = AIR(temp_s6 - temp_s0_1);
            if (var_s5 == 0) {
              return;
            }
            var_s5 = AIR(iVar5 - temp_s0_1);
            if (var_s5 == 0) {
              return;
            }
            var_s5 = MUR(iVar10 - temp_s0_1);
            if (var_s5 == 0) {
              return;
            }
            temp_v0_2 = temp_v0_1 + temp_s0_1 * -0x10;
          }
          Make_Ray_Hang(temp_v0_2,temp_s0_2);
        }
      }
    }
  }
  return;
}

/* looked at android (abs), played around with gotos-only
tried replacing var_v0 with returns, tried replacing temp_v1 */
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_BALANCE_ANIM);*/

s16 RAY_BALANCE_ANIM(s16 arg0)
{
    s16 var_v0;
    s16 var_v1;
    s16 temp_v1;

    if (arg0 == 0)
        arg0++;
    
    temp_v1 = (arg0 - 1) >> 3;
    if (temp_v1 < 0x20)
    {
        if (!(ray.flags & 0x4000))
        {
            var_v0 = temp_v1 + 0x1F;
        }
        else if ((0x20 - temp_v1) >= 0) /* some optimization makes this jump to block at the end... */
        {
            var_v0 = 0x20 - temp_v1;
        }
        else
        {
            var_v0 = temp_v1 - 0x20;
        }
    }
    else
    {
        if (!(ray.flags & 0x4000))
        {
            var_v0 = temp_v1 - 0x1F;
        }
        else if ((0x5F - temp_v1) >= 0)
        {
            var_v0 = 0x5F - temp_v1;
        }
        else
        {
            var_v0 = temp_v1 - 0x5F;
        }
    }
    return var_v0;
}

/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_BALANCE);*/

void RAY_BALANCE(void)
{
    s16 sp10;
    s16 sp12;
    Obj *temp_s0;
    s16 temp_a0;
    s16 temp_v1_4;
    s16 var_v0;
    s16 var_v0_2;
    s16 var_v0_4;
    s16 var_v0_5;
    ObjState **temp_s3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a2;
    s32 var_v0_3;
    s16 temp_s2;
    u16 temp_v0_4;
    int new_var;
    s32 test_1;
    s32 test_2;

    temp_s3 = ray.eta;
    temp_s0 = &level.objects[id_obj_grapped];
    temp_s2 = temp_s0->follow_x;
    if (ray.sub_etat == 0)
    {
        RAY_GOING_BALANCE(temp_s0);
    }
    else if (ray.sub_etat == 1)
    {
        if (temp_s0->timer == 0)
        {
            if (temp_s0->follow_y >= 0x65)
            {

                temp_s0->follow_y -= 2;
            }
            else if (temp_s0->follow_y < 0x5F)
            {
                temp_s0->follow_y++;
            }

            abs_sinus_cosinus((s16) temp_s2, &sp10, &sp12);
            /* gotos-only unchanged to default m2c? */
            /* might have broken something already */
            test_1 = 0x80;
            test_2 = 0x180;
            if ((s16) temp_s2 >= 0x180)
            {
                if (temp_s0->field24_0x3e > 0)
                {
                    temp_s0->timer = 5;
                }
                temp_s0->field24_0x3e = -1;
            }
            else if ((s16) temp_s2 <= 0x80)
            {
                
                if (temp_s0->field24_0x3e < 0)
                {
                    temp_s0->timer = 5;
                    temp_s0->field24_0x3e = 1;
                }
                else
                    temp_s0->field24_0x3e = 1;

            }
            if (temp_s2 <= 0x100)
            {
                temp_v1_2 = -((0x100 - temp_s2) << 7);
                temp_v0 = 0x100 - 0x80;
                var_v0_4 = (temp_v1_2 / temp_v0) + 0x100;
            }
            else
            {
                temp_v0_2 = (temp_s2 - 0x100) << 7;
                temp_v1_3 = 0x100 - 0x180;
                var_v0_4 = (temp_v0_2 / temp_v1_3) + 0x100;
            }
            temp_v0_3 = (__builtin_abs(costab[0x100 - var_v0_4]) >> 7) + 1;
            var_a2 = temp_v0_3;
            if (temp_s0->field24_0x3e < 0)
            {
                var_a2 = -temp_v0_3;
            }
            temp_v0_2 = temp_s0->follow_y;
            temp_s0->follow_x = var_a2 + temp_s0->follow_x;
            new_var = temp_s0->offset_by + temp_s0->y_pos;
            ray.speed_x = ((temp_s0->offset_bx + temp_s0->x_pos + ((temp_v0_2 * sp10) >> 9)) - ray.offset_bx) - ray.x_pos;
            ray.speed_y = ((((temp_s0->offset_by + temp_s0->y_pos) - ((temp_v0_2 * sp12) >> 9)) - ray.offset_by) - ray.y_pos);
        }
        else
        {
            temp_s0->timer--;
            ray.speed_x = 0;
            ray.speed_y = 0U;
            decalage_en_cours = 0;
        }
    }
    ray.anim_index = temp_s3[ray.main_etat][ray.sub_etat].anim_index;
    ray.anim_frame = RAY_BALANCE_ANIM((s16) temp_s2);
    ray.speed_x += temp_s0->speed_x;
    ray.speed_y = (ray.speed_y + temp_s0->speed_y);
    if (
        ((u8) block_flags[ray.btypes[0]] >> 1) & 1 &&
        (
            (!(ray.flags & 0x4000) && ((u8) block_flags[ray.btypes[1]] >> 1) & 1) ||
            ((ray.flags & 0x4000) && ((u8) block_flags[ray.btypes[2]] >> 1) & 1)
        )
    )
    {
        if (((s16) ray.speed_y > 0) || (temp_s0->speed_y > 0))
        {
            recale_position(&ray);
            ray.y_pos = ray.y_pos + ray.speed_y;
            ray.speed_y = 0U;
            ray.timer = 0;
            helico_time = -1;
            set_main_and_sub_etat(&ray, 0U, 8U);
            PlaySnd(0x0013, -1);
            ray.field24_0x3e = -1;
            return;
        }
    }
    if ((((u8) block_flags[ray.btypes[2]] >> 4) & 1) || (((u8) block_flags[ray.btypes[1]] >> 4) & 1))
    {
        RAY_FIN_BALANCE();
    }
}

/* tried gotos-only but not very useful it seemed
tried to bring control flow closer to ghidra but not been successful, "var_a1_2 = var_s3 + 1;" is annoying */
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RayEstIlBloque);*/

s32 RayEstIlBloque(void)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    s16 sp20;
    s16 sp22;
    u16 sp24;
    u16 sp26;
    Obj *var_s0;
    s16 temp_a0_2;
    s16 temp_a0_3;
    s16 temp_a0_4;
    s16 temp_a2;
    s16 temp_v0;
    s32 var_a1;
    s16 var_a1_2;
    s16 var_s3;
    s16 var_v0;
    s32 temp_a0;
    s16 temp_s2;
    s32 var_s4;
    s16 test_1;
    int new_var;

    var_s4 = 0;
    if (ray.speed_x != 0)
    {
        var_a1 = ray_zdc_x;
        var_s3 = 0;
        if (ray.speed_x > 0)
        {
            var_a1 += ray_zdc_w;
        }
        temp_s2 = ((u16) ray_zdc_h << 0x10) >> 0x12;
        var_s0 = &level.objects[actobj.objects[0]];
        test_1 = var_a1;
        if (actobj.num_active_objects > 0)
        {
            do
            {
                if (((u8) flags[var_s0->type].flags2 >> 2) & 1)
                {
                    GET_ANIM_POS(var_s0, &sp18, &sp1A, &sp1C, &sp1E);
                    sp18 = sp18 + (sp1C >> 3);
                    sp1C -= sp1C >> 2;
                    if (var_s0->flags & 0x10000)
                    {
                        GET_SPRITE_POS(var_s0, (s32) var_s0->follow_sprite, &sp20, &sp22, &sp24, &sp26);
                        sp1A = sp22 + var_s0->offset_hy + (ray.field20_0x36 == var_s0->id);
                    }
                    else
                    {
                        sp1A = var_s0->offset_hy + var_s0->y_pos;
                    }
                    sp1E = (var_s0->offset_by + var_s0->y_pos) - sp1A;
                    if (((u8) flags[var_s0->type].flags3 >> 4) & 1)
                    {
                        sp1A = sp1A + 2;
                        sp18 = sp18 + 6;
                        sp1C -= 0xC;
                    }
                    if (var_s0->type == 0x6D)
                    {
                        sp18 = sp18 + 4;
                        sp1C -= 8;
                    }
                    temp_v0 = sp18 + sp1C;
                    if ((ray.speed_x <= 0) || (test_1 < (sp18 - ray.speed_x)) || (sp18 < test_1))
                    {
                        if (test_1 >= (temp_v0 + ray.speed_x))
                        {
                            var_a1_2 = var_s3 + 1;
                            if (temp_v0 >= test_1)
                            {
                                goto block_18;
                            }
                            goto block_30;
                        }
                        goto block_29;
                    }
    block_18:
                    temp_a2 = sp1A + sp1E;
                    if (ray_zdc_y < sp1A || temp_a2 < ray_zdc_y)
                    {
                        temp_a0_2 = ray_zdc_y + temp_s2;
                        temp_a0_3 = temp_a0_2 + temp_s2;
                        if(temp_a0_2 < sp1A != 0 || temp_a2 < temp_a0_2)
                        {
                            temp_a0_4 = temp_a0_3 + temp_s2;
                            if(temp_a0_3 < sp1A != 0 || temp_a2 < temp_a0_3)
                            {
                                if(
                                    var_v0 = temp_a0_4 + temp_s2, (temp_a0_4 < sp1A != 0) ||
                                    (var_v0 = temp_a0_4 + temp_s2, (temp_a2 < temp_a0_4 != 0))
                                )
                                {
                                    if (var_v0 >= sp1A)
                                    {
                                        var_a1_2 = var_s3 + 1;
                                        if (temp_a2 >= var_v0)
                                        {
                                            goto block_28;
                                        }
                                        goto block_30;
                                    }
                                    goto block_29;
                                }
                            }
                        }
                    }
    block_28:
                    var_s4 = 1;
                    break;
                }
block_29:
                var_a1_2 = var_s3 + 1;
block_30:
                var_s3 = var_a1_2;
                var_s0 = &level.objects[actobj.objects[var_a1_2]];
            }
            while (var_a1_2 < actobj.num_active_objects);
        }
    }
    return var_s4;
}

/* matches, but do{}while(0); */
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", DO_SURF_CHANGE_HAIRS);*/

void DO_SURF_CHANGE_HAIRS(void)
{
    s16 flip_x_1;
    s32 flip_x_2;
    u8 var_v0;

    if ((ray.main_etat == 0) && (ray.sub_etat == 0x28))
    {
        
        if (ray.flags & 0x4000)
        {
            flip_x_1 = 1;
        }
        else
            flip_x_1 = -1;
        flip_x_2 = flip_x_1;
        if (ray.speed_x >= 0)
        {
            if (ray.speed_x > 0)
            {
do {
                if (flip_x_2 == 1)
                {
                    ray.anim_index = 0x4F;
                }
                else
                {
                    ray.anim_index = 0x50;
                }
} while (0);
            }
            else
            {
                if (flip_x_2 == 0)
                {
                    ray.anim_index = 0x4F;
                }
                else
                {
                    ray.anim_index = 0x50;
                }
            }

        }
        else
        {
            if (flip_x_2 == -1)
            {
                ray.anim_index = 0x4F;
            }
            else
            {
                ray.anim_index = 0x50;
            }
        }
    }
}