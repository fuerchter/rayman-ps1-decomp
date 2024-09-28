#include "obj/poi_command.h"

/* 4EFB0 801737B0 -O2 -msoft-float */
void DO_POISSON_VERT_CMD(Obj *obj)
{
    DO_ONE_CMD(obj);
    if (
        (
            !(obj->flags & FLG(OBJ_FLIP_X)) &&
            on_block_chdir(obj, obj->offset_bx - 20, obj->offset_by - 3) &&
            (s16) test_allowed(obj, obj->offset_bx - 20, obj->offset_by - 3)
        ) ||
        (
            obj->flags & FLG(OBJ_FLIP_X) &&
            on_block_chdir(obj, obj->offset_bx + 20, obj->offset_by - 3) &&
            (s16) test_allowed(obj, obj->offset_bx + 20, obj->offset_by - 3)
        )
    )
    {
        if (obj->flags & FLG(OBJ_FLIP_X))
        {
            obj->flags &= ~FLG(OBJ_FLIP_X);
            skipToLabel(obj, 7, true);
        }
        else
        {
            obj->flags |= FLG(OBJ_FLIP_X);
            skipToLabel(obj, 8, true);
        }
    }
    DO_OBJ_COLLISIONS(obj, 4);
}

INCLUDE_ASM("asm/nonmatchings/obj/poi_command", DO_POISSON_BLEU_CMD);