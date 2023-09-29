#include "world_map_95CC.h"

INCLUDE_ASM("asm/nonmatchings/world_map_95CC", select_level_prg);

/* 975C 8012DF5C -O2 */
/*void SYNCHRO_LOOP(void *);*/
s16 SELECT_LEVEL(s16 sel) {
    level_select = sel;
    inter_select = 0;
    SYNCHRO_LOOP(select_level_prg);
    return level_select;
}

INCLUDE_ASM("asm/nonmatchings/world_map_95CC", DISPLAY_STAGE_NAMES);

INCLUDE_ASM("asm/nonmatchings/world_map_95CC", WORLD_CHOICE);

INCLUDE_ASM("asm/nonmatchings/world_map_95CC", DO_WORLD_MAP);