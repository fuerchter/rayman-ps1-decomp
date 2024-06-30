#include "gendoor.h"

/* matches, but can somehow go neither fully var_v0 nor fully constant */
/*INCLUDE_ASM("asm/nonmatchings/gendoor", FUN_80156710);*/

s32 FUN_80156710(Obj *obj)
{
    s32 var_v0;
    s16 type;

    type = obj->type;
    if (
        flags[type].flags0 & 1 ||
        type == 2 || type == 0x57 || type == 0x58 ||
        type == 0x8D || type == 0x9E || type == 0x94 ||
        type == 0x5e || type == 0x5f ||
        type == 0x90 || type == 4 || type == 0xFD ||
        type == 0xF9 || type == 0xfb || type == 0xfc ||
        type == 3 || type == 0xA1 || type == 0xAA ||
        type == 0xEA || type == 0x40 || type == 0xB5 ||
        type == 0x7C || type == 0x63 || type == 0xA2 ||
        type == 0xe7 || type == 0xe8 || type == 0xF6
    )
    {
        var_v0 = 1;
        return true;
    }
    else if (type != 0xD6)
    {
        var_v0 = 0;
        return false;
    }
    var_v0 = 1;
    return true;
}