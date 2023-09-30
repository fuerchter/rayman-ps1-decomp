#include "bonus_35FB4.h"

/* TODO: what is new_var for these two? */
/* 35FB4 8015A7B4 -O2 */
/*s32 getbit(? *, s16);*/

u8 get_bonus_map_complete(s16 world, s16 level)
{
  s16 new_var;

  new_var = 33;
  return getbit(&bonus_perfect, (s16) (level + ((world << 5) - new_var)));
}

/* 35FEC 8015A7EC -O2 */
/*? setbit(u8 *, s16);*/

void set_bonus_map_complete(s16 world, s16 level) {
    s16 new_var;

    new_var = 33;
    setbit(&bonus_perfect, (s16) (level + ((world << 5) - new_var)));
}

INCLUDE_ASM("asm/nonmatchings/bonus_35FB4", DO_PERFECT_BONUS_MAP);

INCLUDE_ASM("asm/nonmatchings/bonus_35FB4", DO_WIZ_AFTER_BONUS_MAP);

/* 3617C 8015A97C -O2 */
void init_bonus_perfect(void) {
    s32 cnt;
    u8* cur;

    cnt = sizeof(bonus_perfect) / sizeof(u8) - 1;
    cur = &bonus_perfect[cnt];
    do {
        *cur = 0; cnt--; cur--;
    } while (cnt >= 0);
}