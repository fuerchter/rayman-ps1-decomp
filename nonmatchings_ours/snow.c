#include "snow.h"

/* matches, but more cleanup left? */
/*INCLUDE_ASM("asm/nonmatchings/snow", do_flocons);*/

void do_flocons(s16 x_map, s16 y_map, s16 x_map_old, s16 y_map_old)
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
    unk_1 = -0x40;
    while (unk_1 < 0xC0)
    {

        flc_i_1 = floc_ind[i];
        unk_y_3 = (y_map_old - y_map);
        unk_y_3 += unk_y_1;
        unk_x_3 = (x_map_old - x_map) + unk_x_1;
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
        unk_1 += 0x20;
        i++;
    }

    VENT_Y = prev_vy;
    VENT_X = prev_vx;
    if (num_world != 1)
        weather_wind = VENT_X / 8;
}