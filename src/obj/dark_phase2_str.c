#include "obj/dark_phase2.h"

/*
"/you're doomed rayman ." jtbl starts at 8012c1fc
jtbl SHOULD start at 8012c200
"/you're doomed rayman .." jtbl starts at 8012c204

tried different versions of:
__attribute__ ((aligned ()))
__attribute__ ((packed))

tried using it in place instead of as var
*/
const u8 s_youre_doomed_rayman__8012c1e4[] = "/you're doomed rayman .../";