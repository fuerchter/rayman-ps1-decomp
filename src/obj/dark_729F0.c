#include "obj/dark_729F0.h"

extern u8 dark_attaque;
extern u8 dark_sequence[3];
extern u8 type_dark_attaque;
extern VitrauxInfo VitrauxInfos[5];

/* 729F0 801971F0 -O2 -msoft-float */
void PlaceDarkPhase1et2(Obj *obj)
{
    obj->y_pos = obj->init_y_pos = firstFloorBelow(obj) - obj->offset_by;
    obj->x_pos = obj->init_x_pos = xmapmax + 160;
}

/* 72A38 80197238 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu, missing_nop */
INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", dark_attaque_suivante);
#else
void dark_attaque_suivante(void)
{
    dark_attaque++;
    if (dark_attaque != 3)
        type_dark_attaque = dark_sequence[dark_attaque];
    else
        type_dark_attaque = 3;

    __asm__("nop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", init_vitraux);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", poing_face_obj);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DARK_phase1);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DARK_phase3);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_POING_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_REACT);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_SORT_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_SORT_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", allocate_DARK_SORT);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", corde_en_bas);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", corde_en_haut);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", init_corde);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", goto_phase1);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", goto_phase2);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", goto_phase3);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", goto_phase5);
