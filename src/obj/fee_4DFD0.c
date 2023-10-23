#include "obj/fee_4DFD0.h"

/* 4DFD0 801727D0 -O2 -msoft-float */
void wait_for_dialogue_fee(Obj *obj, s16 time)
{
  if (obj->timer < time)
    obj->timer++;
  else
  {
    obj->timer = 0;
    display_txt_fee++;
  }
}

/* 4E020 80172820 -O2 -msoft-float */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/obj/fee_4DFD0", DO_FEE_ETAPE);
#else
/*? skipToLabel(Obj *, ?, ?);*/

void DO_FEE_ETAPE(Obj *obj)
{
    u8 state;

    __asm__("nop\nnop\nnop");

    state = obj->field56_0x69;
    switch (state)
    {
    case 1:
        wait_for_dialogue_fee(obj, 100);
        if (display_txt_fee == 5 || text_to_display[display_txt_fee].text[0] == '\0')
        {
            skipToLabel(obj, 1, 0);
            obj->field56_0x69 = 0;
            display_txt_fee = 0xFF;
            obj->timer = 0;
        }
        break;
    case 2:
        wait_for_dialogue_fee(obj, 100);
        if (display_txt_fee == 7)
        {
            display_txt_fee = 0xFF;
            obj->field56_0x69 = 3;
            obj->timer = 0;
        }
        break;
    case 3:
        obj->timer++;
        if (obj->timer >= 51)
        {
            obj->field56_0x69 = 4;
            display_txt_fee = 7;
            obj->timer = 0;
        }
        break;
    case 4:
        if (horloge[2] != 0)
            obj->speed_y = -1;
        else
            obj->speed_y = 0;
        
        if (display_txt_fee < 9 && text_to_display[display_txt_fee + 1].text[0] != '\0')
            wait_for_dialogue_fee(obj, 120);
        break;
    case 0:
    default:
        display_txt_fee = 0xFF;
        break;
    }
}
const u8 rodata_fee_4DFD0[4] = {};
#endif

/* 4E1B4 801729B4 -O2 -msoft-float */
void fee_gives_super_evts(void)
{
    switch (num_world)
    {
    case 1:
        if (num_level == 3)
            RayEvts.flags0 |= FLG(RAYEVTS0_POING);
        if (num_level == 8)
            RayEvts.flags0 |= FLG(RAYEVTS0_HANG);
        if (num_level == 17)
            RayEvts.flags0 |= FLG(RAYEVTS0_GRAP);
        break;
    case 2:
        if (num_level == 11)
            RayEvts.flags0 |= FLG(RAYEVTS0_HELICO);
        break;
    case 3:
        if (num_level == 11)
            RayEvts.flags1 |= FLG(RAYEVTS1_RUN);
        break;
    }
}

/* 4E2D0 80172AD0 -O2 -msoft-float */
INCLUDE_ASM("asm/nonmatchings/obj/fee_4DFD0", DO_FEE);