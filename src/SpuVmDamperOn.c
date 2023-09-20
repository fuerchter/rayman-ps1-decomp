#include "common.h"

#if 1
INCLUDE_ASM("asm/nonmatchings/SpuVmDamperOn", SpuVmDamperOn);
#else
extern s16 __svm_damper;

/* 8EF44 801b3744 */
void SpuVmDamperOn(void) {
    __svm_damper = 2;
}
#endif
