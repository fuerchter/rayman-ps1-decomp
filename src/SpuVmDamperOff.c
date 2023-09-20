#include "common.h"

extern s16 __svm_damper;

/* 8F060 801b3860 */
void SpuVmDamperOff(void) {
    __svm_damper = 0;
}