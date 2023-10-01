#include "world_map_95CC.h"

INCLUDE_ASM("asm/nonmatchings/world_map_95CC", select_level_prg);

/* 975C 8012DF5C -O2 */
/*void SYNCHRO_LOOP(void *);*/
s16 SELECT_LEVEL(s16 sel)
{
    level_select = sel;
    inter_select = 0;
    SYNCHRO_LOOP(select_level_prg);
    return level_select;
}

INCLUDE_ASM("asm/nonmatchings/world_map_95CC", DISPLAY_STAGE_NAMES);

/* 980C 8012E00C -O2 */
/*? DISPLAY_PLAT_WAY();
? DISPLAY_STAGE_NAMES();
? DO_CHEMIN();
? DO_FADE();
? DisplayJumellesNormal();
? FUN_8013af14();
? FUN_8013eb38(s16, s16, ?, ?);
? PS1_DisplayWorldMapObjects();
s32 SelectButPressed();
? display2(? *);
? readinput();*/

s32 WORLD_CHOICE(void)
{  
    let_shadow = FALSE;
    DO_FADE();
    FUN_8013eb38(xmap, ymap, 0x2C, 0x37);
    DISPLAY_PLAT_WAY();
    PS1_DisplayWorldMapGraphEdges();
    display2(&ray);
    DO_CHEMIN();
    PS1_DisplayWorldMapObjects();
    DisplayJumellesNormal();
    DISPLAY_STAGE_NAMES();

    readinput();
    PROC_EXIT = SelectButPressed() != 0;
    return new_world || PROC_EXIT;
}

INCLUDE_ASM("asm/nonmatchings/world_map_95CC", DO_WORLD_MAP);