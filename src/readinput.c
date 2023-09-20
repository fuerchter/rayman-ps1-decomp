#include "common.h"

#if 0
INCLUDE_ASM("asm/nonmatchings/readinput", readinput);
#else
/* ED20 80133520 */
s16 readinput(void) {
    return TOUCHE(0xFF); /* TODO: param is enum */
}
#endif
