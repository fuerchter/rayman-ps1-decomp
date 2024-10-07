#include "obj/bb1_plat_command.h"

/* 4D1C8 801719C8 -O2 -msoft-float */
void DO_BB1_PLAT_CMD(Obj *obj)
{
    switch (obj->cmd)
    {
    case GO_UP:
        obj->speed_y = -1;
        break;
    case GO_WAIT:
        obj->speed_y = 0;
        break;
    }
}
