#include "world_map_95CC.h"

/*INCLUDE_ASM("asm/nonmatchings/world_map_95CC", WORLD_CHOICE);*/

/* 980C 8012E00C */
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
extern u8 PROC_EXIT;
extern s8 let_shadow;
extern s16 new_world;

s32 WORLD_CHOICE(void) {
    s32 var_a0;

    let_shadow = 0;
    DO_FADE();
    FUN_8013eb38(xmap, ymap, 0x2C, 0x37);
    DISPLAY_PLAT_WAY();
    PS1_WldMapGraphEdges();
    display2(&ray);
    DO_CHEMIN();
    PS1_DisplayWorldMapObjects();
    DisplayJumellesNormal();
    DISPLAY_STAGE_NAMES();
    readinput();
    PROC_EXIT = SelectButPressed() != 0;
    var_a0 = new_world;
    if (var_a0 || PROC_EXIT) {
        var_a0 = 1;
    }
    return var_a0;
}