#include "common.h"

#if 1
INCLUDE_ASM("asm/nonmatchings/SsVabTransCompleted", SsVabTransCompleted);
#else
/* 8F450 801b3c50 */
s16 SsVabTransCompleted(s16 arg0) {
    return SpuIsTransferCompleted(arg0);
}
#endif
