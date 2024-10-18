#include "ray/ray_5D190.h"

/*
matches, but
do{}while(0); and other cleanup
see "var_a1_1 =" for alternative
*/
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", rayMayLandOnAnObject);*/

/*int GET_SPRITE_POS(Obj *obj,int spriteIndex,short *x,short *y,ushort *w,ushort *h);
s16 ashr16(ushort param_1,uint param_2);
extern s16 helico_time;*/

void rayMayLandOnAnObject(u8 *param_1, s16 param_2)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    u8 var_a1_2;
    Obj *var_s1;
    s16 temp_v0;
    s16 var_a0_2;
    s16 var_a0_3;
    s16 var_a1_1;
    s16 var_s0_1;
    s16 var_s0_2;
    s16 var_s2;
    s16 var_v0;
    s16 var_v1;
    s32 var_v1_2;
    s32 temp_v1_4;
    s32 var_v0_2;
    s16 var_a0;
    u8 temp_v0_2;
    u8 temp_v1_1;
    s32 temp_v1_2;
    u8 temp_v1_3;
    ActiveObjects *new_var;
    RaymanEvents *test_1;
    s32 test_2;

    
    if ((RayEvts.demi))
    {
        var_s2 = 8;
    }
    else
        var_s2 = 4;

    ray.field20_0x36 = -1;
    var_s0_1 = 0;
    
    var_s1 = &level.objects[actobj.objects[0]];
    while (var_s0_1 < actobj.num_active_objects)
    {
        if ((var_s1->flags & 0x10000) && var_s1->id != param_2)
        {
            if ((((u8) flags[var_s1->type].flags1 >> 5) & 1))
            {
                var_a0 = instantSpeed(var_s1->speed_y);
            }
            else
            {
                var_a0 = var_s1->speed_y;
            }
            var_v0 = __builtin_abs((s16)(var_a0 + (var_s1->follow_y - ray.speed_y)));
            temp_v0 = var_v0 + 2;
            var_a0_2 = temp_v0;
            if (temp_v0 < var_s2)
            {
                var_a0_2 = var_s2;
            }

            temp_v1_1 = var_s1->type;
            if ((temp_v1_1 == 0x6D) || (temp_v1_1 == 0xF1) || (temp_v1_1 == 0xB3))
            {
                var_a0_2 += 8;
            }

            if (__builtin_abs(var_s1->ray_dist) < var_a0_2 && !(((u8) block_flags[calc_typ_trav(&ray, 2) & 0xFF] >> 4) & 1))
            {
                ray.field20_0x36 = actobj.objects[var_s0_1];
                if ((left_time == -2) && (map_time & 1))
                {
                    map_time += 1;
                }
                ray.field23_0x3c = -1;
                ray_last_ground_btyp = 1;
                if (ray.main_etat == 2)
                {
                    temp_v1_2 = var_s1->type;
                    switch (temp_v1_2)
                    {
                    case 0xa0:
                        PlaySnd(0x006E, var_s1->id);
                        break;
                    case 1:
                    block_52:
                        if (num_world == 1)
                        {
                            var_a0_3 = 0x0013;
                            PlaySnd(var_a0_3, -1);
                            break;
                        }
                        var_a0_3 = 0x00F2;
                        if (num_world == 4)
                        {
                            var_a0_3 = 0x0013;
                            PlaySnd(var_a0_3, -1);
                            break;
                        }
                        PlaySnd(var_a0_3, -1);
                        break;
                    case 0x10:
                    case 0x11:
                    block_55:
                        var_a0_3 = 0x0013;
                        if (num_world == 4 || num_world == 5)
                        {
                            PlaySnd(var_a0_3, -1);
                            break;
                        }
                        var_a0_3 = 0x00F2;
                        PlaySnd(var_a0_3, -1);
                        break;
                    case 0x16:
                    case 0x1a:
                    case 0x1b:
                    case 0x1c:
                    case 0x3f:
                    block_57:
                        var_a0_3 = 0x00F2;
                        if (num_world == 4)
                        {
                            var_a0_3 = 0x0013;
                            PlaySnd(var_a0_3, -1);
                            break;
                        }
                        PlaySnd(var_a0_3, -1);
                        break;
                    case 0x54:
                    case 0x56:
                    case 0x57:
                    case 0x58:
                    case 0x9f:
                    case 0xb2:
                    case 0xb3:
                        break;
                    case 0xed:
                        var_a0_3 = 0x00F8;
                        PlaySnd(var_a0_3, -1);
                        break;
                    case 0xf3:
                        PlaySnd(0x0034, -1);
                        break;
                    default:
                        PlaySnd(0x0013, -1);
                        break;
                    }
                }
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
                    break;
                case 0x8:
                case 0x86:
                case 0xA7:
                    if (var_s1->main_etat != 0)
                    {
                        break;
                    }
                    if (var_s1->sub_etat != 0x0D)
                    {
                        break;
                    }
                    set_main_and_sub_etat(var_s1, 0, 0xF);
                    break;
                case 0x83:
                    if (var_s1->sub_etat != 3)
                    {
                        break;
                    }
                    var_a1_2 = 0;
                    skipToLabel(var_s1, var_a1_2, 1);
                    break;
                case 0x56:
                    if (var_s1->sub_etat == 4)
                    {
                        /* alternative to do{}while(0); */
                        if (/*var_a1_1 = */var_s1->hit_points == 0)
                        {
                            set_sub_etat(var_s1, 5);
                        }
                        else
                        {
                            MARACAS_GO(var_s1);
                        }
                    }
                    break;
                case 0x57:
                    var_s1->field56_0x69 = 0x10;
                    if (var_s1->main_etat == 0)
                    {
                        temp_v1_3 = var_s1->sub_etat;
                        if (temp_v1_3 == 7)
                        {
                            set_main_and_sub_etat(var_s1, 2, 0);
                            PlaySnd(0x006E, var_s1->id);
                        }
                        else if (temp_v1_3 == 9)
                        {
                            set_main_and_sub_etat(var_s1, 2, 2);
                            PlaySnd(0x0070, var_s1->id);
                        }
                    }
                    break;
                case 0x58:
                    var_s1->field56_0x69 = 0x10;
                    set_main_and_sub_etat(var_s1, 2, 1);
                    PlaySnd(0x006F, var_s1->id);
                    break;
                case 0xA9:
                    if (var_s1->main_etat != 0)
                    {
                        break;
                    }
                    if (var_s1->sub_etat != 0x0D)
                    {
                        break;
                    }
                    START_2_PARTS_CYMBAL_ACTION(var_s1);
                    break;
                case 0x8A:
                    if (var_s1->main_etat != 0)
                    {
                        break;
                    }
                    if (var_s1->sub_etat != 0x0A)
                    {
                        break;
                    }
                    skipToLabel(var_s1, 1, 1);
                    break;
                case 0x9A:
                    if (var_s1->main_etat != 0)
                    {
                        break;
                    }
                    if (var_s1->sub_etat != 0x0D)
                    {
                        break;
                    }
                    skipToLabel(var_s1, 1, 1);
                    break;
                case 0x9B:
                    if (var_s1->main_etat != 0)
                    {
                        break;
                    }
                    if (var_s1->sub_etat != 0x0F)
                    {
                        break;
                    }
                    skipToLabel(var_s1, 1, 1);
                    break;
                case 0x31:
                    if (var_s1->main_etat != 0)
                    {
                        break;
                    }
                    if (var_s1->sub_etat != 0)
                    {
                        break;
                    }
                    var_a1_2 = 0;
                    skipToLabel(var_s1, var_a1_2, 1);
                    break;
                case 0x3F:
                    if (var_s1->main_etat != 0)
                    {
                        var_a1_2 = 0;
                        skipToLabel(var_s1, var_a1_2, 1);
                        break;
                    }
                    if (var_s1->sub_etat == 0x0A)
                    {
                        break;
                    }
                case 0x10:
                case 0x11:
                    var_a1_2 = 0;
                    skipToLabel(var_s1, var_a1_2, 1);
                    break;
                case 0xA2:
                    if (!(finBosslevel[1] & 4))
                    {
                        break;
                    }
                    START_UFO(var_s1);
                    break;
                case 0xCF:
                    if (var_s1->main_etat != 0 || var_s1->sub_etat != 1)
                    {
                        set_main_and_sub_etat(var_s1, 0, 1);
                        var_s1->flags &= 0xFFFEFFFF;
                        ray_on_poelle = 1;
                        ray.field20_0x36 = -1;
                        ray.speed_x = 1;
                        PS1_SetSauveRayEvts();
                        RayEvts.poing = true;
                        RayEvts.hang = false;
                        RayEvts.helico = false;
                        RayEvts.super_helico = false;
                        RayEvts.handstand_dash = false;
                        RayEvts.handstand = false;
                        RayEvts.grain = false;
                        RayEvts.grap = false;
                        
                        RayEvts.run = false;
                        RayEvts.demi = false;
                        RayEvts.luciole = false;
                        RayEvts.force_run = false;
                        RayEvts.reverse = false;
                        RayEvts.unused_death = false;
                    }
                    break;
                case 0x43:
                    if (var_s1->main_etat != 0)
                    {
                        break;
                    }
                    if (var_s1->sub_etat != 2)
                    {
                        break;
                    }
                    set_sub_etat(var_s1, 9);
                    break;
                case 0x1B:
                case 0x44:
                    var_v1_2 = ray.speed_y;
                    if (var_v1_2 < 2)
                    {
                        var_v1_2 = 2;
                    }
                    var_s1->field20_0x36 = var_v1_2;
                    break;
                }

                if (ray.main_etat == 2)
                {
                    if (
                        __builtin_abs(ray.speed_x) >= ashr16(ray.eta[1][3].speed_x_right, 4) &&
                        (RayEvts.run)
                    )
                    {
                        do{}while(0);
                        set_main_and_sub_etat(&ray, 1, 3);
                    }
                    else
                    {
                        set_main_etat(&ray, 0);
                        set_sub_etat(&ray, 8);
                        if (ray.field24_0x3e >= 0xC9)
                        {
                            allocateRayLandingSmoke();
                        }
                    }
                }

                GET_SPRITE_POS(var_s1, (s32) var_s1->follow_sprite, &sp18, &sp1A, &sp1C, &sp1E);
                ray.speed_y = ((var_s1->offset_hy + (u16) sp1A) - ray.offset_by) - ray.y_pos;
                *param_1 = 0;
                ray.field24_0x3e = -1;
                helico_time = -1;
                break;
            }
        }

        var_s0_1 = var_s0_1 + 1;
        var_s1 = &level.objects[actobj.objects[var_s0_1]];
    }
block_122:
    if (param_2 != -1 && ray.field20_0x36 == -1)
    {
        ray.field20_0x36 = param_2;
    }
    else if (ray.field20_0x36 != -1)
    {
        level.objects[ray.field20_0x36].ray_dist = 0;
    }
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

/*
score of (m2c: 435, m2c gotos: 1350)
attempts: 4
*/
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_SWIP);*/

void RAY_SWIP(void)
{
    u8 sp10;
    Obj *temp_s1;
    s16 temp_a2;
    s16 temp_v0;
    s16 temp_v1_1;
    s16 var_s2;
    s32 var_v0_1;
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
        temp_v1_1 = temp_s1->ray_dist;
        var_v0_1 = __builtin_abs(temp_v1_1); /* abs? */
        if ((var_v0_1 >= 9) || (temp_v1_1 < 0) || (ray.field20_0x36 == -1))
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
block_1:
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
                if (
                    !(!((block_flags[ray.btypes[0]] & 1) ||
                    (block_flags[ray.btypes[4]] >> 3 & 1) ||
                    !(block_flags[ray.btypes[4]] >> 1 & 1)))
                )
                {
                    if ((ray.speed_x != 0 || decalage_en_cours != 0 || ray_wind_force != 0))
                    {
                        var_s0 = var_s4;
                        var_s2 = 0;
                    }
                    else
                    {

                        var_s0 = var_a1;
                        var_s2 = 0;
                    }
                }
                else
                {
                    var_s0 = var_a1;
                    var_s2 = 0;
                }
                break;
            case 15:
                
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
                default:
                    var_s0 = var_a1;
                    var_s2 = 0;
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

void RAY_SWIP(void)
{
    u8 sp10;
    Obj *temp_s1;
    s16 temp_v1_1;
    s16 var_s2;
    s32 var_v0_1;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 temp_v0;
    s32 var_a1;
    u8 var_s0;
    s32 var_s4;
    s32 var_v1;
    u8 temp_s1_2;
    u8 temp_v1_2;

    /*var_s0 = saved_reg_s0;*/
    var_s2 = 0;
    var_s4 = 0x10;
    if (num_world != 3)
    {
        goto block_2;
    }
    var_s4 = 0x20;
block_2:
    if (ray.field20_0x36 == -1)
    {
        goto block_29;
    }
    temp_s1 = &level.objects[ray.field20_0x36];
    if (temp_s1->flags & 0x10000)
    {
        goto block_5;
    }
    ray.field20_0x36 = -1;
block_5:
    temp_v1_1 = temp_s1->ray_dist;
    var_v0_1 = __builtin_abs(temp_v1_1);
block_7:
    if (var_v0_1 >= 9)
    {
        goto block_10;
    }
    if (temp_v1_1 < 0)
    {
        goto block_10;
    }
    if (ray.field20_0x36 != -1)
    {
        goto block_29;
    }
block_10:
    rayMayLandOnAnObject(&sp10, ray.field20_0x36);
    if (ray.field20_0x36 == -1)
    {
        goto block_29;
    }

    if (__builtin_abs(temp_s1->ray_dist) < 9)
    {
        goto block_29;
    }
    ray.field20_0x36 = -1;
    temp_s1_2 = ray.main_etat;
    set_main_etat(&ray, 2U);
    if (ray_on_poelle == 0)
    {
        goto block_19;
    }
    if (temp_s1_2 != 0)
    {
        goto block_18;
    }
    if (ray.sub_etat != 0x28)
    {
        goto block_18;
    }
    set_sub_etat(&ray, 0x1AU);
    goto block_28;
block_18:
    set_sub_etat(&ray, 0x1CU);
    goto block_28;
block_19:
    if ((temp_s1_2 & 0xFF) != 1)
    {
        goto block_27;
    }
    if (ray.sub_etat == 9)
    {
        goto block_22;
    }
    if (ray.sub_etat != 0x0B)
    {
        goto block_23;
    }
block_22:
    ray.flags = (ray.flags & ~0x4000) | (((((u32) ray.flags >> 0xE) ^ 1) & 1) << 0xE);
block_23:
    if (temp_s1_2 != 1)
    {
        goto block_27;
    }
    if (ray.sub_etat != 3)
    {
        goto block_26;
    }
    set_sub_etat(&ray, 0x20U);
    goto block_28;
block_26:
    set_sub_etat(&ray, 0x18U);
    goto block_28;
block_27:
    set_sub_etat(&ray, 1U);
block_28:
    ray.field24_0x3e = 0;
    jump_time = 0;
block_29:
    if (ray_in_fee_zone != 0)
    {
        goto block_31;
    }
    SET_X_SPEED(&ray);
block_31:
    if (ray.main_etat != 1)
    {
        goto block_36;
    }
    if (ray.sub_etat == 9)
    {
        goto block_35;
    }
    if (ray.sub_etat == 0x30)
    {
        goto block_35;
    }
    if (ray.sub_etat != 0x0B)
    {
        goto block_36;
    }
block_35:
    ray.speed_x = (u16) -(s32) ray.speed_x;
block_36:
    temp_v0 = ashl16((s16) ray.speed_x, 4U);
    /* TODO: temp_a2? */
    if ((s16) ray.speed_x == 0)
    {
        goto block_43;
    }
block_39:
    var_a1 = -(__builtin_abs(temp_v0) < 0x101);
    if (ray_wind_force <= 0)
    {
        goto block_41;
    }
    ray.speed_x = (s16) ray.speed_x + 0xA;
    goto block_44;
block_41:
    if (ray_wind_force >= 0)
    {
        goto block_44;
    }
    ray.speed_x = (s16) ray.speed_x - 0xA;
    goto block_44;
block_43:
    var_a1 = 0;
block_44:
    if (ray.main_etat != 2)
    {
        goto block_53;
    }
    if (ray.sub_etat == 0x0F)
    {
        goto block_47;
    }
    if (ray.nb_cmd == 0)
    {
        goto block_52;
    }
block_47:
    if (!(ray.flags & 0x4000))
    {
        goto block_50;
    }
    var_s0 = 0xC;
    if (decalage_en_cours > 0)
    {
        var_s2 = 0;
        goto block_75;
    }
    var_s0 = 8;
    var_s2 = 0;
    goto block_75;
block_50:
    var_s0 = 8;
    if (decalage_en_cours >= 0)
    {
        var_s2 = 0;
        goto block_75;
    }
    var_s0 = 0xC;
    var_s2 = 0;
    goto block_75;
block_52:
    var_s0 = var_a1;
    var_s2 = 0;
    goto block_75;
block_53:
    if (!(ray.main_etat == 0 || ray.main_etat == 1 || ray.main_etat == 3))
    {
        goto block_75;
    }
block_55:
    if (ray.field20_0x36 == -1)
    {
        goto block_58;
    }
    var_s0 = 0;
block_57:
    var_s2 = 0;
    goto block_75;
block_58:
    /*if ((u8) ray.btypes[0] > 0x1EU)
    {
        goto block_75;
    }*/
    switch (ray.btypes[0])
    {
    case 0:
    case 1:
    case 8:
    case 9:
    case 24:
    case 25:
    case 30:
        if (block_flags[ray.btypes[0]] & 1)
        {
            goto block_63;
        }
        temp_v1_2 = block_flags[ray.btypes[4]];
        if ((temp_v1_2 >> 3) & 1)
        {
            goto block_63;
        }
        var_s0 = var_a1;
        if ((temp_v1_2 >> 1) & 1)
        {
            var_s2 = 0;
        goto block_75;
        }
    block_63:
        var_s0 = var_s4;
        if ((s16) ray.speed_x != 0)
        {
            goto block_66;
        }
        var_s2 = 0;
        if (decalage_en_cours != 0)
        {
            goto block_75;
        }
        if (ray_wind_force == 0)
        {
            goto block_67;
        }
    block_66:
        var_s2 = 0;
        goto block_75;
    block_67:
        var_s0 = var_a1;
        var_s2 = 0;
        goto block_75;
    case 15:
        var_s0 = var_a1;
        /*if ((u32) (ray.btypes[3] - 0x12) > 5U)
        {
            var_s2 = 0;
            goto block_75;
        }*/
        switch (ray.btypes[3])
        {
        case 20:
        case 21:
            var_s0 = var_s4;
            var_s2 = -4;
            goto block_75;
        case 22:
        case 23:
            var_s0 = var_s4;
            var_s2 = 4;
            goto block_75;
        /*case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 12:
        case 14:
            var_s0 = var_a1;
            var_s2 = 0;
            goto block_75;*/
        case 18:
            var_s0 = var_s4;
            var_s2 = -6;
            goto block_75;
        case 19:
            var_s0 = var_s4;
            var_s2 = 6;
        }
        break;
    case 20:
    case 21:
        var_s0 = var_s4;
        var_s2 = -4;
        goto block_75;
    case 22:
    case 23:
        var_s0 = var_s4;
        var_s2 = 4;
        goto block_75;
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
        goto block_75;
    case 18:
        var_s0 = var_s4;
        var_s2 = -6;
        goto block_75;
    case 19:
        var_s0 = var_s4;
        var_s2 = 6;
    }

block_75:
    if (ray_on_poelle != 1)
    {
        goto block_77;
    }
    var_s0 = var_s0 >> 1;
block_77:
    ray_inertia_speed(var_s0, var_s2, temp_v0, ray_wind_force);
    return;
}

/* matches, but cleanup*/
/*INCLUDE_ASM("asm/nonmatchings/ray/ray_5D190", RAY_BALANCE);*/

void RAY_BALANCE(void)
{
    s16 unk_math_1; s16 unk_math_2;
    s16 unk_1;
    s16 unk_2;
    s16 unk_grp_ang_1;
    s16 unk_grp_ang_2;
    s32 unk_3;
    s16 unk_4;
    s16 unk_spd_x; s16 unk_spd_y;
    ObjState **ray_eta = ray.eta;
    Obj *obj_grp = &level.objects[id_obj_grapped];
    s16 grp_angle = obj_grp->follow_x;
    
    if (ray.sub_etat == 0)
        RAY_GOING_BALANCE(obj_grp);
    else if (ray.sub_etat == 1)
    {
        if (obj_grp->timer == 0)
        {
            if (obj_grp->follow_y > 100)
                obj_grp->follow_y -= 2;
            else if (obj_grp->follow_y < 95)
                obj_grp->follow_y += 1;

            abs_sinus_cosinus(grp_angle, &unk_math_1, &unk_math_2);
            
            /* not in bottom half of circle? */
            unk_1 = 128;
            unk_2 = 384;
            if (grp_angle >= unk_2)
            {
                if (obj_grp->field24_0x3e > 0)
                    obj_grp->timer = 5;
                obj_grp->field24_0x3e = -1;
            }
            else if (grp_angle <= unk_1)
            {
                if (obj_grp->field24_0x3e < 0)
                    obj_grp->timer = 5;
                obj_grp->field24_0x3e = 1;
            }

            /*test_3 = 256;*/ /* TODO: ???*/
            if (grp_angle <= 256)
                unk_grp_ang_1 = -((256 - grp_angle) << 7) / (256 - unk_1) + 256;
            else
                unk_grp_ang_1 = ((grp_angle - 256) << 7) / (256 - unk_2) + 256;

            unk_grp_ang_2 = (__builtin_abs(costab[256 - unk_grp_ang_1]) >> 7) + 1;
            if (obj_grp->field24_0x3e < 0)
                unk_grp_ang_2 = -unk_grp_ang_2;
            obj_grp->follow_x += unk_grp_ang_2;

            /* TODO: unk_spd_*??? */
            unk_3 = obj_grp->follow_y;
            unk_4 = ray.x_pos;
            unk_spd_x = obj_grp->offset_bx + obj_grp->x_pos + ((unk_3 * unk_math_1) >> 9) - ray.offset_bx - unk_4;
            unk_spd_y = obj_grp->offset_by + obj_grp->y_pos - ((unk_3 * unk_math_2) >> 9) - ray.offset_by - ray.y_pos;
            ray.speed_x = unk_spd_x;
            ray.speed_y = unk_spd_y;
        }
        else
        {
            obj_grp->timer--;
            ray.speed_x = 0;
            ray.speed_y = 0;
            decalage_en_cours = 0;
        }
    }
    ray.anim_index = ray_eta[ray.main_etat][ray.sub_etat].anim_index;
    ray.anim_frame = RAY_BALANCE_ANIM(grp_angle);
    ray.speed_x += obj_grp->speed_x;
    ray.speed_y += obj_grp->speed_y;
    if (
        block_flags[ray.btypes[0]] >> BLOCK_SOLID & 1 &&
        (
            (!(ray.flags & FLG(OBJ_FLIP_X)) && (block_flags[ray.btypes[1]] >> BLOCK_SOLID & 1)) ||
            (ray.flags & FLG(OBJ_FLIP_X) && (block_flags[ray.btypes[2]] >> BLOCK_SOLID & 1))
        ) &&
        (ray.speed_y > 0 || obj_grp->speed_y > 0)
    )
    {
        recale_position(&ray);
        ray.y_pos += ray.speed_y;
        ray.speed_y = 0;
        ray.timer = 0;
        helico_time = -1;
        set_main_and_sub_etat(&ray, 0, 8);
        PlaySnd(19, -1);
        ray.field24_0x3e = -1;
    }
    else if (
        (block_flags[ray.btypes[2]] >> BLOCK_FLAG_4 & 1) ||
        (block_flags[ray.btypes[1]] >> BLOCK_FLAG_4 & 1)
    )
        RAY_FIN_BALANCE();
}

/* matches, but cleanup last section with goto */

s32 RayEstIlBloque(void)
{
    s32 unk_x_1;
    s16 unk_x_2;
    s16 unk_h;
    Obj *cur_obj;
    s16 i;
    s16 ani_x; s16 ani_y; s16 ani_w; s16 ani_h;
    s16 spr_x; s16 spr_y; s16 spr_w; s16 spr_h;
    s16 ani_xw;
    s16 ani_yh;
    s16 unk_y;
    u8 res = false;
    
    if (ray.speed_x != 0)
    {
        unk_x_1 = ray_zdc_x;
        if (ray.speed_x > 0)
        {
            unk_x_1 += ray_zdc_w;
        }
        unk_x_2 = unk_x_1;
        unk_h = ray_zdc_h >> 2;

        cur_obj = &level.objects[actobj.objects[0]];
        i = 0;
        while (i < actobj.num_active_objects)
        {
            if (flags[cur_obj->type].flags2 >> OBJ2_BLOCKS_RAY & 1)
            {
                GET_ANIM_POS(cur_obj, &ani_x, &ani_y, &ani_w, &ani_h);
                ani_x += ani_w >> 3;
                ani_w -= ani_w >> 2;
                if (cur_obj->flags & FLG(OBJ_FOLLOW_ENABLED))
                {
                    GET_SPRITE_POS(cur_obj, cur_obj->follow_sprite, &spr_x, &spr_y, &spr_w, &spr_h);
                    ani_y = spr_y + cur_obj->offset_hy + (ray.field20_0x36 == cur_obj->id);
                }
                else
                    ani_y = cur_obj->y_pos + cur_obj->offset_hy;
                ani_h = cur_obj->y_pos + cur_obj->offset_by - ani_y;
                
                if (flags[cur_obj->type].flags3 >> OBJ3_FLAG4 & 1)
                {
                    ani_x += 6;
                    ani_w -= 12;
                    ani_y += 2;
                }
                if (cur_obj->type == TYPE_PI)
                {
                    ani_x += 4;
                    ani_w -= 8;
                }

                ani_xw = ani_x + ani_w;
                if (
                    (ray.speed_x <= 0 || unk_x_2 < ani_x - ray.speed_x || unk_x_2 > ani_x) &&
                    (unk_x_2 < ani_xw + ray.speed_x || unk_x_2 > ani_xw)
                )
                {
                    goto block_30;
                }

                ani_yh = ani_y + ani_h;
                unk_y = ray_zdc_y;
                if (unk_y < ani_y || unk_y > ani_yh)
                {
                    unk_y += unk_h;
                    if (unk_y < ani_y || unk_y > ani_yh)
                    {
                        unk_y += unk_h;
                        if (unk_y < ani_y || unk_y > ani_yh)
                        {
                            unk_y += unk_h;
                            if (unk_y < ani_y || unk_y > ani_yh)
                            {
                                unk_y += unk_h;
                                if (unk_y < ani_y || unk_y > ani_yh)
                                {
                                    goto block_30;
                                }
                            }
                        }
                    }
                }
                res = true;
                break;
            }
block_30:
            i++;
            cur_obj = &level.objects[actobj.objects[i]];
        }
    }
    return res;
}
