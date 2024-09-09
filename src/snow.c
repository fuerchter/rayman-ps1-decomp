#include "snow.h"

extern s16 tot_nb_flocs[8];

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

INCLUDE_ASM("asm/nonmatchings/snow", init_flocons);

INCLUDE_ASM("asm/nonmatchings/snow", do_flocons);

INCLUDE_ASM("asm/nonmatchings/snow", set_snow_sequence);

INCLUDE_ASM("asm/nonmatchings/snow", set_SNSEQ_list);

INCLUDE_ASM("asm/nonmatchings/snow", DO_SNOW_SEQUENCE);
