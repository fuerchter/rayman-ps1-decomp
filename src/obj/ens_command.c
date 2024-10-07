#include "obj/ens_command.h"

/* 500FC 801748FC -O2 -msoft-float */
void DO_ENSEIGNE_COMMAND(Obj *obj)
{
    DO_ONE_CMD(obj);
    if (prise_branchee)
    {
        if (obj->main_etat == 0 && obj->sub_etat == 0)
            skipToLabel(obj, 1, true);
        
        if (
            obj->main_etat == 0 && obj->sub_etat == 1 &&
            obj->anim_frame >= obj->animations[1].frames_count - 1
        )
            skipToLabel(obj, 2, true);
        
        if (
            obj->main_etat == 0 && obj->sub_etat == 2 &&
            obj->anim_frame >= obj->animations[2].frames_count - 1
        )
            skipToLabel(obj, 1, true);
    }
    else
        skipToLabel(obj, 0, true);
}
