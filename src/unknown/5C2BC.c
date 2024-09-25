#include "unknown/5C2BC.h"

/* 5C2BC 80180ABC -O2 -msoft-float */
void PS1_ClearScreen(void)
{
    ClearImage(&PS1_Displays[0].drawing_environment.clip, 0, 0, 0);
    ClearImage(&PS1_Displays[1].drawing_environment.clip, 0, 0, 0);
}
