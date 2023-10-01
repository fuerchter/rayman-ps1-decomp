#include "world_map_95CC.h"

/* 95CC 8012DDCC -O2 */
/*? DISPLAY_FOND_SELECT();
? atoi(s16, ? *, ?);
s32 but0pressed(?);
s32 but1pressed(?);
? display_text(? *, ?, ?, ?, s32);
s32 leftjoy(?);
? readinput();
s32 rightjoy(?);*/

s32 select_level_prg(void)
{
    u8 num[16];

    readinput();

    DISPLAY_FOND_SELECT();
    display_text(&s_level_801cedf4, 100, 100, 0, colour);
    PS1_sprintf(level_select, &num, 10);
    display_text(&num, 200, 100, 0, colour);

    if (rightjoy(0) && !inter_select)
        level_select++;
    else if (leftjoy(0) && !inter_select)
        level_select--;

    if (level_select > 30)
        level_select = 30;
    if (level_select < 1)
        level_select = 1;

    inter_select++;
    if (inter_select > 3)
        inter_select = 0;

    return but0pressed(0) << 16 || but1pressed(0) << 16;
}

/* 975C 8012DF5C -O2 */
/*void SYNCHRO_LOOP(void *);*/
s16 SELECT_LEVEL(s16 sel)
{
    level_select = sel;
    inter_select = 0;
    SYNCHRO_LOOP(select_level_prg);
    return level_select;
}

/* 979C 8012DF9C -O2 */
/*? display_box_text(? *);*/

void DISPLAY_STAGE_NAMES(void)
{
    TextToDisplay *cur;

    if (&text_to_display[1])
       display_box_text(&text_to_display[1]);

    cur = &text_to_display[0];
    if (cur)
       display_box_text(cur);

    cur = &text_to_display[3];
    if (cur)
       display_box_text(cur);

    cur = &text_to_display[2];
    if (cur)
       display_box_text(cur);
}

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