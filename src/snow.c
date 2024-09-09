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

INCLUDE_ASM("asm/nonmatchings/snow", add_256_flocs);

INCLUDE_ASM("asm/nonmatchings/snow", sub_one_floc);

INCLUDE_ASM("asm/nonmatchings/snow", init_flocons);

INCLUDE_ASM("asm/nonmatchings/snow", do_flocons);

INCLUDE_ASM("asm/nonmatchings/snow", set_snow_sequence);

INCLUDE_ASM("asm/nonmatchings/snow", set_SNSEQ_list);

INCLUDE_ASM("asm/nonmatchings/snow", DO_SNOW_SEQUENCE);
