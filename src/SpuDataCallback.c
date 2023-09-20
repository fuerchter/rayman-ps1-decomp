#include "common.h"

#if 1
INCLUDE_ASM("asm/nonmatchings/SpuDataCallback", SpuDataCallback);
#else
/* 942D8 801b8ad8 */
void SpuDataCallback(s32 arg0) {
    DMACallback(4, arg0);
}
#endif
