#include "obj/walk_note_command.h"

/* 4D7DC 80171FDC -O2 */
void DO_WLKNOT_COMMAND(Obj *obj)
{
    s16 bx; s16 by;

    switch (obj->cmd)
    {
    case GO_WAIT:
        SET_X_SPEED(obj);
        CALC_MOV_ON_BLOC(obj);
        break;
    case GO_LEFT:
    case GO_RIGHT:
        if (obj->cmd == GO_LEFT)
            obj->flags &= ~FLG(OBJ_FLIP_X);
        else
            obj->flags |= FLG(OBJ_FLIP_X);
        SET_X_SPEED(obj);
        CALC_MOV_ON_BLOC(obj);
        break;
    }

    if (obj->speed_x != 0)
    {
        bx = obj->offset_bx;
        by = obj->offset_by - 8;
        if ((s16) test_allowed(obj, bx, by) && (s16) on_block_chdir(obj, bx, by))
        {
            if (!(obj->flags & FLG(OBJ_FLIP_X)))
            {
                obj->flags |= FLG(OBJ_FLIP_X);
                skipToLabel(obj, 2, true);
            }
            else
            {
                obj->flags &= ~FLG(OBJ_FLIP_X);
                skipToLabel(obj, 1, true);
            }
        }
    }
}
