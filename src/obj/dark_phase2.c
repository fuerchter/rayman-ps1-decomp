#include "obj/dark_phase2.h"

/* 76A14 8019B214 -O2 -msoft-float */
void AllocateDarkPhase2(Obj *mr_drk_obj)
{
    Obj *cur_obj = &level.objects[0];
    s16 i = 0;
    s16 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {
        if ((cur_obj->type == TYPE_DARK_PHASE2) && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
            cur_obj->init_x_pos = cur_obj->x_pos = mr_drk_obj->x_pos;
            cur_obj->init_y_pos = cur_obj->y_pos = mr_drk_obj->y_pos;
            cur_obj->speed_x = 0;
            cur_obj->speed_y = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
            set_main_and_sub_etat(cur_obj, 0, 38);

            dark_obj = mr_drk_obj;
            phase_dark2 = 0;
            mr_drk_obj->flags &= ~FLG(OBJ_ALIVE);
            mr_drk_obj->flags &= ~FLG(OBJ_ACTIVE);
            break;
        }
        cur_obj++;
        i++;
    }
}

/* 76B00 8019B300 -O2 -msoft-float */
void DO_DARK2_AFFICHE_TEXT(void)
{
    s32 x; s32 y;

    if (TextDark2_Affiche)
    {
        let_shadow = true;
        x = XText; y = YText;
        temps_text += 3;
        display_text_sin(txt_dark2, x, y, temps_text & 0xFFFF, 2, 10);
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK_PHASE2_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK2_SORT_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", allocate_DARK2_SORT);
