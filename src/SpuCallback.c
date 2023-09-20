#include "common.h"

#if 1
INCLUDE_ASM("asm/nonmatchings/SpuCallback", SpuCallback);
#else
/* 94344 801b8b44 */
void SpuCallback(s32 arg0) {
    InterruptCallback(9, arg0);
}
#endif
