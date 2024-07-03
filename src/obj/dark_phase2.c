#include "obj/dark_phase2.h"

extern Obj *dark_obj;
extern s16 phase_dark2;

const u8 s_youre_doomed_rayman__8012c1e4[] ="/you're doomed rayman .../";

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

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK2_AFFICHE_TEXT);

/*INCLUDE_RODATA("asm/nonmatchings/obj/dark_phase2", s_youre_doomed_rayman__8012c1e4);*/

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK_PHASE2_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK2_SORT_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", allocate_DARK2_SORT);
