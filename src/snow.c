#include "snow.h"

#ifdef BSS_DEFS
s16 floc_ind[8];
FloconTableEntry flocon_tab[512];
s16 nb_floc[8];
s16 VENT_X;
s16 VENT_Y;
s16 tot_nb_flocs[8];
s16 invpx0[8];
s16 invpx320[8];
s16 invpy0[8];
s16 invpy200[8];
s16 SNSEQ_len[64];
s16 SNSEQ_no;
s16 SNSEQ_ptr;
s16 SNSEQ_list[256];
s16 SNSEQ_list_ptr;
#endif

/* 3B264 8015FA64 -O2 -msoft-float */
void add_one_floc(void)
{
    s16 unk_1 = myRand(511);
    s16 i = LEN(floc_ind) - 1;
    s16 done = false;

    while (!done)
    {
        if (floc_ind[i] < unk_1)
        {
            done = true;
            nb_floc[i]++;
        }
        i--;
    }

    if (nb_floc[i + 1] > tot_nb_flocs[i + 1])
        nb_floc[i + 1]--;
}

/* 3B324 8015FB24 -O2 -msoft-float */
void add_256_flocs(void)
{
    /* THEY LIED TO US, IT'S REALLY 251! D: */
    nb_floc[0] = 10;
    nb_floc[1] = 15;
    nb_floc[2] = 25;
    nb_floc[3] = 30;
    nb_floc[4] = 35;
    nb_floc[5] = 40;
    nb_floc[6] = 43;
    nb_floc[7] = 53;
}

/* 3B38C 8015FB8C -O2 -msoft-float */
void sub_one_floc(void)
{
    s16 unk_1 = myRand(511);
    s16 i = LEN(nb_floc) - 1;
    s16 done = false;

    while (!done && i > -1)
    {
        if (floc_ind[i] <= unk_1 && nb_floc[i] > 0)
        {
            nb_floc[i]--;
            done = true;
        }
        i--;
    }

    if (i == -1)
    {
        i = LEN(nb_floc) - 1;
        done = false;
        while (!done && i > -1)
        {
            if (nb_floc[i] > 0)
            {
                nb_floc[i]--;
                done = true;
            }
            i--;
        }
    }
}

/* 3B488 8015FC88 -O2 -msoft-float */
void init_flocons(void)
{
    s16 flc_i;
    s16 i;
    s32 unk_1;
    s16 unk_2; /* param_1 into get_proj_* is sometimes ray.scale, so similar? */
    s16 j;
    s16 unk_3; s16 unk_4;
    u16 unk_5; u16 unk_6;

    tot_nb_flocs[0] = 20;
    tot_nb_flocs[1] = 30;
    tot_nb_flocs[2] = 50;
    tot_nb_flocs[3] = 60;
    tot_nb_flocs[4] = 70;
    tot_nb_flocs[5] = 80;
    tot_nb_flocs[6] = 96;
    tot_nb_flocs[7] = 106;
    flc_i = 0;
    i = 0;
    unk_1 = 0xffff; /* TODO: should be -1 ... */
    while (i < (s16) LEN(nb_floc))
    {
        nb_floc[i] = 0;
        floc_ind[i] = flc_i;
        unk_2 = 5;
        unk_2 = (i << unk_2) - 64;
        invpy0[i] = inverse_proj_y(unk_2, 0);
        invpy200[i] = inverse_proj_y(unk_2, SCREEN_HEIGHT);
        invpx0[i] = inverse_proj_x(unk_2, 0);
        invpx320[i] = inverse_proj_x(unk_2, SCREEN_WIDTH);
        j = 0;
        while (j < tot_nb_flocs[i])
        {
            do
            {
                do
                {
                    unk_3 = myRand(700);
                    unk_4 = myRand(400) - 150;
                    unk_5 = get_proj_x(unk_2, unk_3);
                    unk_6 = get_proj_y(unk_2, unk_4);
                } while ((u16) (unk_5 + unk_1) > SCREEN_WIDTH - 2);
            } while ((u16) (unk_6 + unk_1) > SCREEN_HEIGHT - 2);
            flocon_tab[flc_i].field0_0x0 = unk_3;
            flocon_tab[flc_i].field1_0x2 = unk_4;
            flocon_tab[flc_i].field2_0x4 = unk_2;
            flc_i++;
            j++;
        }
        i++;
    }
    VENT_X = 0;
    VENT_Y = 0;
}

/* 3B718 8015FF18 -O2 -msoft-float */
#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/snow", do_flocons);
#else
/* more cleanup left? */
static inline s32 do_flocons_1(s16 param_1)
{
    return param_1 / 4;
}

static inline s32 do_flocons_2(s16 param_1)
{
    return param_1 - do_flocons_1(param_1) * 4;
}

void do_flocons(s16 in_x_map, s16 in_y_map, s16 in_x_map_old, s16 in_y_map_old)
{
    s16 unk_x_1; s16 unk_y_1;
    s32 remove_1; s32 remove_2; /* TODO: ??? */
    s16 unk_x_2; s16 unk_y_2;
    s16 i;
    s16 unk_1;
    s16 flc_i_1;
    s16 unk_x_3; s16 unk_y_3;
    s16 x_0; s16 x_320; s16 y_0; s16 y_200;
    FloconTableEntry *cur_floc;
    s16 unk_2;
    s16 flc_i_2;
    s16 prev_vy = VENT_Y;
    s16 prev_vx = VENT_X;

    VENT_Y += 4;
    unk_x_1 = VENT_X / 4;
    unk_y_1 = VENT_Y / 4;
    remove_1 = VENT_X - (VENT_X / 4 * 4);
    unk_x_2 = remove_1;
    remove_2 = VENT_Y - (VENT_Y / 4 * 4);
    unk_y_2 = remove_2;
    if (__builtin_abs(unk_x_2) == 1 && horloge[4] == 0)
        unk_x_1 += SGN(VENT_X);

    if (__builtin_abs(unk_x_2) == 2 && horloge[2] == 0)
        unk_x_1 += SGN(VENT_X);

    if (__builtin_abs(unk_x_2) == 3 && horloge[4] < 3)
        unk_x_1 += SGN(VENT_X);

    if (__builtin_abs(unk_y_2) == 1 && horloge[4] == 0)
        unk_y_1 += SGN(VENT_Y);

    if (__builtin_abs(unk_y_2) == 2 && horloge[2] == 0)
        unk_y_1 += SGN(VENT_Y);

    if (__builtin_abs(unk_y_2) == 3 && horloge[4] < 3)
        unk_y_1 += SGN(VENT_Y);

    set_proj_center(SCREEN_WIDTH / 2, 170);
    i = 0;
    unk_1 = -64;
    while (unk_1 < 32 * 6)
    {
        flc_i_1 = floc_ind[i];
        unk_y_3 = in_y_map_old - in_y_map;
        unk_y_3 += unk_y_1;
        unk_x_3 = in_x_map_old - in_x_map + unk_x_1;
        y_0 = invpy0[i];
        y_200 = invpy200[i];
        x_0 = invpx0[i];
        x_320 = invpx320[i];

        cur_floc = &flocon_tab[flc_i_1];
        unk_2 = flc_i_1 + nb_floc[i];
        flc_i_2 = flc_i_1;
        while (flc_i_2 < unk_2)
        {
            cur_floc->field0_0x0 += unk_x_3;
            cur_floc->field1_0x2 += unk_y_3;

            if (cur_floc->field0_0x0 > x_320)
                cur_floc->field0_0x0 = x_0;
            else if (cur_floc->field0_0x0 < x_0)
                cur_floc->field0_0x0 = x_320;

            if (cur_floc->field1_0x2 > y_200)
                cur_floc->field1_0x2 = y_0;
            else if (cur_floc->field1_0x2 < y_0)
                cur_floc->field1_0x2 = y_200;

            cur_floc++;
            flc_i_2++;
        }
        unk_1 += 32;
        i++;
    }

    VENT_Y = prev_vy;
    VENT_X = prev_vx;
    if (num_world != 1)
        weather_wind = VENT_X / 8;
}
#endif

/* 3BBE0 801603E0 -O2 -msoft-float */
void set_snow_sequence(u16 param_1, s16 param_2)
{
    SNSEQ_no = param_1;
    SNSEQ_ptr = 0;
    SNSEQ_len[(s16) param_1] = param_2;
}

/* 3BC10 80160410 -O2 -msoft-float */
void set_SNSEQ_list(s16 param_1)
{
    s16 *cur_sn = SNSEQ_list; /* TODO: can't tell if this should be in dec or hex (flags?) */

    if (param_1 == 0)
    {
        *cur_sn++ = 4;
        *cur_sn++ = 2;
        *cur_sn++ = 0x80;
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }
    else if (param_1 == 1)
    {
        *cur_sn++ = 4;
        *cur_sn++ = 3;
        *cur_sn++ = 0x80;
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }
    else if (param_1 == 2)
    {
        *cur_sn++ = 4;
        *cur_sn++ = 3;
        *cur_sn++ = 0x0200;
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }
    else if (param_1 == 3)
    {
        if (VENT_Y == 8)
            *cur_sn++ = 2;
        else
            *cur_sn++ = 4;

        if (VENT_Y > 8)
        {
            *cur_sn++ = 8;
            *cur_sn++ = (VENT_Y * 2) - 0x10;
        }
        else if (VENT_Y < 8)
        {
            *cur_sn++ = 9;
            *cur_sn++ = 0x10 - (VENT_Y * 2);
        }
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }
    else if (param_1 == 4)
    {
        if (VENT_Y == 0)
            *cur_sn++ = 2;
        else
            *cur_sn++ = 4;

        if (VENT_Y > 0)
        {
            *cur_sn++ = 8;
            *cur_sn++ = (VENT_Y * 2);
        }
        else if (VENT_Y < 0)
        {
            *cur_sn++ = 9;
            *cur_sn++ = (-VENT_Y * 2);
        }
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }
    else if (param_1 == 5)
    {
        if (VENT_X == -8)
            *cur_sn++ = 2;
        else
            *cur_sn++ = 4;

        if (VENT_X > -8)
        {
            *cur_sn++ = 6;
            *cur_sn++ = (VENT_X * 2) + 0x10;
        }
        else if (VENT_X < -8)
        {
            *cur_sn++ = 7;
            *cur_sn++ = -0x10 - (VENT_X * 2);
        }
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }
    else if (param_1 == 6)
    {
        if (VENT_X == 8)
            *cur_sn++ = 2;
        else
            *cur_sn++ = 4;

        if (VENT_X > 8)
        {
            *cur_sn++ = 6;
            *cur_sn++ = (VENT_X * 2) - 0x10;
        }
        else if (VENT_X < 8)
        {
            *cur_sn++ = 7;
            *cur_sn++ = 0x10 - (VENT_X * 2);
        }
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }
    else if (param_1 == 7)
    {
        if (VENT_X == -16)
            *cur_sn++ = 2;
        else
            *cur_sn++ = 4;

        if (VENT_X > -16)
        {
            *cur_sn++ = 6;
            *cur_sn++ = (VENT_X * 2) + 0x20;
        }
        else if (VENT_X < -0x10)
        {
            *cur_sn++ = 7;
            *cur_sn++ = -0x20 - (VENT_X * 2);
        }
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }
    else if (param_1 == 8)
    {
        if (VENT_X == 16)
            *cur_sn++ = 2;
        else
            *cur_sn++ = 4;

        if (VENT_X > 16)
        {
            *cur_sn++ = 6;
            *cur_sn++ = (VENT_X * 2) - 0x20;
        }
        else if (VENT_X < 16)
        {
            *cur_sn++ = 7;
            *cur_sn++ = 0x20 - (VENT_X * 2);
        }
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }
    else if (param_1 == 9)
    {
        if (VENT_X == 0)
            *cur_sn++ = 2;
        else
            *cur_sn++ = 4;

        if (VENT_X > 0)
        {
            *cur_sn++ = 6;
            *cur_sn++ = ((u16) VENT_X * 2);
        }
        else if (VENT_X < 0)
        {
            *cur_sn++ = 7;
            *cur_sn++ = (-(u16) VENT_X * 2);
        }
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }
    else if (param_1 == 10)
    {
        if (VENT_Y == -16)
            *cur_sn++ = 4;
        else
            *cur_sn++ = 6;

        if (VENT_Y > -16)
        {
            *cur_sn++ = 8;
            *cur_sn++ = (VENT_Y * 2) + 0x20;
        }
        else if (VENT_Y < -0x10)
        {
            *cur_sn++ = 9;
            *cur_sn++ = -0x20 - (VENT_Y * 2);
        }
        *cur_sn++ = 0;
        *cur_sn++ = 0x0080;
        *cur_sn++ = 9;
        *cur_sn++ = 0x0020;
    }
    else if (param_1 == 11)
    {
        *cur_sn++ = 4;
        *cur_sn++ = 10;
        *cur_sn++ = 1;
        *cur_sn++ = 0;
        *cur_sn++ = 0x7FFF;
    }

    SNSEQ_list_ptr = 1;
    set_snow_sequence(SNSEQ_list[1], SNSEQ_list[2]);
    SNSEQ_list_ptr += 2;
}

/* 3C164 80160964 -O2 -msoft-float */
void DO_SNOW_SEQUENCE(void)
{
    s16 first; s16 second;

    switch (SNSEQ_no)
    {
    case 0:
        break;
    case 1:
        VENT_X = 0;
        VENT_Y = 0;
        break;
    case 2:
        add_one_floc();
        break;
    case 3:
        sub_one_floc();
        break;
    case 6:
        if (horloge[2] == 0)
            VENT_X--;
        break;
    case 4:
        VENT_X--;
        break;
    case 7:
        if (horloge[2] == 0)
            VENT_X++;
        break;
    case 5:
        VENT_X++;
        break;
    case 8:
        if (horloge[2] == 0)
            VENT_Y--;
        break;
    case 9:
        if (horloge[2] == 0)
            VENT_Y++;
        break;
    case 10:
        VENT_X = -8;
        VENT_Y = 8;
        add_256_flocs();
    }

    if (++SNSEQ_ptr == SNSEQ_len[SNSEQ_no])
    {
        first = SNSEQ_list[SNSEQ_list_ptr];
        SNSEQ_list_ptr++;
        second = SNSEQ_list[SNSEQ_list_ptr];
        SNSEQ_list_ptr++;

        set_snow_sequence(first, second);
        if (SNSEQ_list_ptr == SNSEQ_list[0])
            SNSEQ_list_ptr = 0;
    }
}
const u8 rodata_DO_SNOW_SEQUENCE[4] = {};
