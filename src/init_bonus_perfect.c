#include "common.h"

extern s8 bonus_perfect;

/* 3617C 8015A97C */
void init_bonus_perfect(void) {
    s32 cnt;
    s8* cur;

    cnt = 0x17;
    cur = &bonus_perfect + 0x17;
    do {
        *cur = 0;
        cnt -= 1;
        cur -= 1;
    } while (cnt >= 0);
}