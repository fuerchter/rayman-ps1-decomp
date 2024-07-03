#include "obj/dark_phase2.h"

const u8 s_youre_doomed_rayman__8012c1e4[] ="/you're doomed rayman .../";

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", AllocateDarkPhase2);

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK2_AFFICHE_TEXT);

/*INCLUDE_RODATA("asm/nonmatchings/obj/dark_phase2", s_youre_doomed_rayman__8012c1e4);*/

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK_PHASE2_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", DO_DARK2_SORT_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark_phase2", allocate_DARK2_SORT);
