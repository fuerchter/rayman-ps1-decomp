#include "obj/hyb_bbf2.h"

extern Obj *TirBBF2D;
extern Obj *TirBBF2G;

INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", doBBF2command);

INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", DO_HYB_BBF2_POING_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", AllocateTirBBF2);

INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", DO_HYB_BBF2_LAS);

INCLUDE_ASM("asm/nonmatchings/obj/hyb_bbf2", OBJ_IN_COL_ZDC);
