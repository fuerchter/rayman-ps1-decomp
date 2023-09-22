#include "common.h"

/* 18A1C 8013D21C */
void DISPLAY_BLACKBOX(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5) {
    if (arg5 != 0) {
        DrawFondBoxNormal(arg0 & 0xFFFF, arg1 & 0xFFFF, arg2 & 0xFFFF, arg3 & 0xFFFF, 0xFF - arg4);
        return;
    }
    DrawBlackBoxNormal(arg0 & 0xFFFF, arg1 & 0xFFFF, arg2 & 0xFFFF, arg3 & 0xFFFF, 0xFF - arg4);
}