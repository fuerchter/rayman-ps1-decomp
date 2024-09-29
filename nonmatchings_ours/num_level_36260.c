#include "num_level_36260.h"

/* only issues left are with WorldInfo.state */
/*INCLUDE_ASM("asm/nonmatchings/num_level_36260", fix_numlevel);*/

void fix_numlevel(Obj *obj)
{
    s16 temp_v0_1;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 var_v0_2;
    s32 *var_a0;
    s32 temp_v1;
    s16 var_s0;
    s32 var_v0;

    var_s0 = 0;
    if (departlevel != 0)
    {
        new_level_init();
        if (obj->type != 5)
        {
            switch (num_world)
            {
            case 1:
                if ((num_level == 2) && (RayEvts.poing))
                {
                    num_level_choice = (u16) num_level_choice + 1;
                }
                if ((num_level == 5) && (*finBosslevel & 1))
                {
                    num_level_choice = (u16) num_level_choice + 1;
                }
                if (num_level == 7)
                {
                    if (RayEvts.hang)
                    {
                        new_world = 1;
                    }
                }
                if ((num_level == 0x000D) && (*finBosslevel & 2))
                {
                    num_level_choice = (u16) num_level_choice + 1;
                }
                if (num_level == 0x000F)
                {
                    if (*finBosslevel & 2)
                    {
                        new_world = 1;
                    }
                }
                if (num_level == 0x0010)
                {
                    if (RayEvts.grap)
                    {
                        new_world = 1;
                    }
                }
                break;
            case 2:
                if (num_level == 5)
                {
                    if (finBosslevel[1] & 1)
                    {
                        new_world = 1;
                    }
                }
                if ((num_level == 9) && (*finBosslevel & 4))
                {
                    new_world = 1;
                }
                if (num_level == 0x000A)
                {
                    if (RayEvts.helico)
                    {
                        new_world = 1;
                    }
                }
                if (num_level == 0x000E)
                {
                    var_v0 = *finBosslevel & 4;
                    if (var_v0 != 0)
                    {
                        new_world = 1;
                    }
                }
                break;
            case 3:
                if (num_level == 1)
                {
                    if (*finBosslevel & 8)
                    {
                        new_world = 1;
                    }
                }
                if ((num_level == 9) && (*finBosslevel & 8))
                {
                    new_world = 1;
                }
                if (num_level == 0x000A)
                {
                    var_v0 = RayEvts.run;
                    if (var_v0 != 0)
                    {
                        new_world = 1;
                    }
                }
                break;
            case 4:
                if (num_level == 3)
                {
                    if (*finBosslevel & 0x10)
                    {
                        new_world = 1;
                    }
                }
                if (num_level == 0x000A)
                {
                    var_v0 = *finBosslevel & 0x20;
                    if (var_v0 != 0)
                    {
                        new_world = 1;
                    }
                }
                break;
            case 5:
                if (num_level == 9)
                {
                    var_v0 = *finBosslevel & 0x40;
                    if (var_v0 != 0)
                    {
                        new_world = 1;
                    }
                }
                break;
            case 6:
                if (num_level == 1)
                {
                    var_v0 = *finBosslevel & 0x80;
                    if (var_v0 != 0)
                    {
                        new_world = 1;
                    }
                }
                break;
            }
        }
    }
    switch (num_world)
    {
    case 1:
        switch (num_level)
        {
        case 2:
            if (obj->type == 5)
            {
                num_level_choice = 0x0015;
                var_s0 = 1;
            }
            break;
        case 4:
            if (obj->type == 5)
            {
                num_level_choice = 0x0014;
                var_s0 = 1;
                break;
            }
            new_world = 1;
            if (!(t_world_info[1].state & 1))
            {
                t_world_info[1].state |= 4;
                t_world_info[18].state |= 4;
            }
            break;
        case 8:
            new_world = 1;
            if (!(t_world_info[2].state & 1))
            {
                t_world_info[2].state |= 4;
            }
            if (!(t_world_info[4].state & 1))
            {
                t_world_info[4].state |= 4;
            }
            break;
        case 11:
            if (obj->type != 5)
            {
                var_a0 = &t_world_info[3].state;
                temp_v1 = *var_a0;
                new_world = 1;
                if (!(temp_v1 & 1))
                {
                    *var_a0 = temp_v1 | 4;
                }
            }
            else
            {
                num_level_choice = 0x0012;
                var_s0 = 1;
                break;
            }
            break;
        case 12:
            if (obj->type == 5)
            {
                num_level_choice = 0x0013;
                var_s0 = 1;
                break;
            }
            break;
        case 17:
            new_world = 1;
            break;
        case 18:
            num_level_choice = 0x000B;
            var_s0 = 1;
            break;
        case 19:
            num_level_choice = 0x000C;
            var_s0 = 1;
            break;
        case 20:
            num_level_choice = 4;
            var_s0 = 1;
            break;

        case 21:
            num_level_choice = 2;
            var_s0 = 1;
            break;
        }
        break;
    case 2:
        switch (num_level)
        {
        case 4:
            if (obj->type == 5)
            {
                num_level_choice = 0x0011;
                var_s0 = 1;
                break;
            }
            break;
        case 6:
            new_world = 1;
            if (!(t_world_info[5].state & 1))
            {
                t_world_info[5].state |= 4;
                t_world_info[19].state |= 4;
            }
            break;
        case 9:
            if (obj->type == 5)
            {
                num_level_choice = 0x0012;
                var_s0 = 1;
                break;
            }
            break;
        case 11:
            new_world = 1;
            if (!(t_world_info[6].state & 1))
            {
                t_world_info[6].state |= 4;
            }
            if (!(t_world_info[8].state & 1))
            {
                t_world_info[8].state |= 4;
            }
            break;
        case 13:
            new_world = 1;
            if (!(t_world_info[7].state & 1))
            {
                t_world_info[7].state |= 4;
                t_world_info[20].state |= 4;
            }
            break;
        case 16:
            new_world = 1;
            break;
        case 17:
            num_level_choice = 4;
            var_s0 = 1;
            break;
        case 18:
            num_level_choice = 9;
            var_s0 = 1;
            break;
        }
        break;
    case 3:
        switch (num_level)
        {
        case 2:
            var_a0 = &t_world_info[9].state;
            temp_v1 = *var_a0;
            new_world = 1;
            if (!(temp_v1 & 1))
            {
                *var_a0 = temp_v1 | 4;
            }
            break;
        case 4:
            if (obj->type == 5)
            {
                num_level_choice = 0x000C;
                var_s0 = 1;
                break;
            }
            break;
        case 5:
            new_world = 1;
            if (!(t_world_info[10].state & 1))
            {
                t_world_info[10].state |= 4;
                t_world_info[21].state |= 4;
            }
            break;
        case 9:
            if (obj->type == 5)
            {
                num_level_choice = 0x000D;
                var_s0 = 1;
                break;
            }
            break;
        case 11:
            var_a0 = &t_world_info[11].state;
            temp_v1 = *var_a0;
            new_world = 1;
            if (!(temp_v1 & 1))
            {
                *var_a0 = temp_v1 | 4;
            }
            break;
        case 12:
            num_level_choice = 4;
            var_s0 = 1;
            break;
        case 13:
            num_level_choice = 9;
            var_s0 = 1;
            break;
        }
        break;
    case 4:
        switch (num_level)
        {
        case 3:
            if (obj->type == 5)
            {
                num_level_choice = 0x000C;
                var_s0 = 1;
                break;
            }
            break;
        case 4:
            var_a0 = &t_world_info[12].state;
            temp_v1 = *var_a0;
            new_world = 1;
            if (!(temp_v1 & 1))
            {
                *var_a0 = temp_v1 | 4;
            }
            break;
        case 7:
            var_a0 = &t_world_info[13].state;
            temp_v1 = *var_a0;
            new_world = 1;
            if (!(temp_v1 & 1))
            {
                *var_a0 = temp_v1 | 4;
            }
            break;
        case 9:
            if (obj->type == 5)
            {
                num_level_choice = 0x000D;
                var_s0 = 1;
                break;
            }
            break;
        case 11:
            new_world = 1;
            if (!(t_world_info[14].state & 1))
            {
                Vignet_To_Display = 1;
                t_world_info[14].state |= 4;
block_132:
                t_world_info[22].state |= 4;
            }
            break;
        case 12:
            num_level_choice = 3;
            var_s0 = 1;
            break;
        case 13:
            num_level_choice = 9;
            var_s0 = 1;
            break;
        }
        break;
    case 5:
        switch (num_level)
        {
        case 2:
            if (obj->type == 5)
            {
                num_level_choice = 0x000C;
                var_s0 = 1;
                break;
            }
            new_world = 1;
            if (!(t_world_info[15].state & 1))
            {
                t_world_info[15].state |= 4;
                t_world_info[22].state |= 4;
            }
            break;
        case 8:
            new_world = 1;
            if (!(t_world_info[16].state & 1))
            {
                t_world_info[16].state |= 4;
                t_world_info[23].state |= 4;
            }
            break;
        case 11:
            new_world = 1;
            Vignet_To_Display = 1;
            break;
        case 12:
            num_level_choice = 2;
            var_s0 = 1;
            break;
        }
        break;
    case 6:
        if (num_level == 4)
        {
            new_world = 1;
            You_Win = 1;
            fin_du_jeu = 1;
            fin_dark = 1;
        }
        break;
    }
    if (!(t_world_info[17].state & 1) && (Nb_total_cages >= 102))
    {
        t_world_info[17].state |= 4;
    }
    if ((new_world == 0) && (var_s0 == 0))
    {
        num_level_choice++;
    }
    new_level = 1;
}