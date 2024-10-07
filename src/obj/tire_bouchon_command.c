#include "obj/tire_bouchon_command.h"

/* 50C00 80175400 -O2 -msoft-float */
void DO_TIRE_BOUCHON_COMMAND(Obj *obj)
{
    DO_ONE_CMD(obj);
    obj->speed_x = 0;
    obj->speed_y = 0;
}
