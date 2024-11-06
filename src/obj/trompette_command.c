#include "obj/trompette_command.h"

/* 493E0 8016DBE0 -O2 -msoft-float */
void DO_TRP_COMMAND(Obj *obj)
{
    if (obj->main_etat == 0 && obj->sub_etat == 1)
    {
        obj->speed_x = 0;
        obj->speed_y = -8;
    }
    else
    {
        switch (obj->cmd)
        {
        case GO_SPEED:
            obj->speed_x = obj->iframes_timer;
            obj->speed_y = obj->field20_0x36;
            break;
        case GO_LEFT:
        case GO_RIGHT:
            if (obj->cmd == 0)
                obj->flags &= ~FLG(OBJ_FLIP_X);
            else
                obj->flags |= FLG(OBJ_FLIP_X);

            if (
                (obj->main_etat == 0 && obj->sub_etat == 0) ||
                (obj->main_etat == 1 && obj->sub_etat == 0)
            )
            {
                set_main_and_sub_etat(obj, 1, 0);
                SET_X_SPEED(obj);
                CALC_MOV_ON_BLOC(obj);
            }
            break;
        case GO_WAIT:
            CALC_MOV_ON_BLOC(obj);
            break;
        case GO_UP:
        case GO_DOWN:
        case GO_SUBSTATE:
        case GO_SKIP:
        case GO_ADD:
        case GO_STATE:
        case GO_PREPARELOOP:
        case GO_DOLOOP:
        case GO_LABEL:
        case GO_GOTO:
        case GO_GOSUB:
        case GO_RETURN:
        case GO_BRANCHTRUE:
        case GO_BRANCHFALSE:
        case GO_TEST:
        case GO_SETTEST:
        case GO_WAITSTATE:
        case GO_X:
        case GO_Y:
        case RESERVED_GO_SKIP:
        case RESERVED_GO_GOTO:
        case RESERVED_GO_GOSUB:
        case RESERVED_GO_GOTOT:
        case RESERVED_GO_GOTOF:
        case RESERVED_GO_SKIPT:
        case RESERVED_GO_SKIPF:
        case GO_NOP:
        default:
            break;
        }
    }

    DO_TRP_ATTAK(obj);
}
const u8 rodata_DO_TRP_COMMAND[4] = {};
