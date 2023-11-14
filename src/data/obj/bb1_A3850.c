#include "obj/bb1.h"

BBAttackEntry SerieAtakBB[6][7] =
{
    {
        {.attack = 0, .wait_for_fin_atan = 2},
        {.attack = 0xff, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0}
    },
    {
        {.attack = 0, .wait_for_fin_atan = 2},
        {.attack = 1, .wait_for_fin_atan = 3},
        {.attack = 0xff, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0}
    },
    {
        {.attack = 6, .wait_for_fin_atan = 2},
        {.attack = 2, .wait_for_fin_atan = 2},
        {.attack = 0, .wait_for_fin_atan = 1},
        {.attack = 1, .wait_for_fin_atan = 1},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 0xff, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0}
    },
    {
        {.attack = 3, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 1},
        {.attack = 1, .wait_for_fin_atan = 1},
        {.attack = 0xff, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0}
    },
    {
        {.attack = 5, .wait_for_fin_atan = 1},
        {.attack = 2, .wait_for_fin_atan = 3},
        {.attack = 0, .wait_for_fin_atan = 0},
        {.attack = 3, .wait_for_fin_atan = 1},
        {.attack = 4, .wait_for_fin_atan = 0},
        {.attack = 0xff, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 0}
    },
    {
        {.attack = 7, .wait_for_fin_atan = 0},
        {.attack = 3, .wait_for_fin_atan = 0},
        {.attack = 6, .wait_for_fin_atan = 0},
        {.attack = 3, .wait_for_fin_atan = 0},
        {.attack = 0, .wait_for_fin_atan = 1},
        {.attack = 4, .wait_for_fin_atan = 0},
        {.attack = 0xff, .wait_for_fin_atan = 0}
    },
};