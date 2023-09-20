#include "common.h"

#if 1
INCLUDE_ASM("asm/nonmatchings/SpuVmDamperOff", SpuVmDamperOff);
#else
extern s16 __svm_damper;

/* 8F060 801b3860 */
void SpuVmDamperOff(void) {
    __svm_damper = 0;
}
#endif
