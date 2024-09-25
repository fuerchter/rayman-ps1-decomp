#include "unknown/3F0B8.h"

/* 3F0B8 801638B8 -O2 -msoft-float */
void test_fin_cling(void)
{
    if (id_Cling_1up != -1)
    {
        id_Cling_1up = -1;
        Add_One_RAY_lives();
        level.objects[id_Cling_1up].flags &= ~FLG(OBJ_ALIVE);
    }

    if (id_Cling_Pow != -1)
    {
        ray.hit_points = 4;
        status_bar.max_hp = 4;
        id_Cling_Pow = -1;
        level.objects[-1].flags &= ~FLG(OBJ_ALIVE);
    }
}
