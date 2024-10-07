#include "obj/reducteur.h"

/* 4DF88 80172788 -O2 -msoft-float */
void DO_REDUCTEUR(Obj *obj)
{
    if (
        obj->hit_points < obj->init_hit_points &&
        --obj->hit_points == 0
    )
        obj->hit_points = obj->init_hit_points;
}
