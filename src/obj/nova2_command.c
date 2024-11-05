#include "obj/nova2_command.h"

/* 4FFD0 801747D0 -O2 -msoft-float */
void DO_NOVA2_COMMAND(Obj *obj)
{
    s16 unk_1 = obj->field23_0x3c;

    if (unk_1 != 0x00FF)
    {
        if (unk_1 == -1)
        {
            if (EOA(obj))
            {
                obj->flags &= ~FLG(OBJ_ALIVE);
                obj->flags &= ~FLG(OBJ_ACTIVE);
            }
        }
        else if (unk_1 == 0)
        {
            obj->anim_frame = 0;
            obj->field23_0x3c = -1;
            obj->display_prio = 2;
        }
        else
            obj->field23_0x3c = unk_1 - 1;
    }
}
