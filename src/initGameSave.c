//just an example function to test if compiled c is matching

#include "common.h"

extern s8 D_801FA882;

/* 3F170 80163970 */
void initGameSave(void) {
    D_801FA882 = 0; //TODO: actually save1.has_saved in ghidra
}
