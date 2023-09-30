#include "bonus_35FB4.h"

/*INCLUDE_ASM("asm/nonmatchings/bonus_35FB4", DO_PERFECT_BONUS_MAP);*/

/* 36024 8015A824 -O2 */
/*? SYNCHRO_LOOP(? *);
? start_cd_gagne(s16);*/
extern u8 D_801E4D56;
extern s16 departlevel;
u8 do_perfect_bonus();
extern s16 loop_time;
extern s32 nb_wiz_save;
extern s16 num_level;
extern s16 num_world;

void DO_PERFECT_BONUS_MAP(void) {
    s16 temp_a0;
    u8 temp;

    if (loop_time < 0) {
        loop_time += 1;
    }
    temp_a0 = loop_time;
    if (loop_time == -1) { /* c0 */
        loop_time = temp_a0 + 1;
        departlevel = 0;
        start_cd_gagne(temp_a0);
        SYNCHRO_LOOP(&do_perfect_bonus);
        temp = nb_wiz_save; /* lbu, but also sw */
        nb_wiz_save = 0;
        D_801E4D56 = temp;
        set_bonus_map_complete(num_world, num_level);
    }
}