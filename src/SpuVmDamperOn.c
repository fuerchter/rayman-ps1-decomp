#include "common.h"

extern s16 __svm_damper;

/* 8EF44 801b3744 */
void SpuVmDamperOn(void) {
    __svm_damper = 2;
}