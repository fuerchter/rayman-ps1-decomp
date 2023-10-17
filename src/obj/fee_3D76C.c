#include "obj/fee_3D76C.h"

extern u8 display_txt_fee;
extern u8 old_txt_fee;

/* 3D76C 80161F6C -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/obj/fee_3D76C", INIT_TXT_FEE);
#else
/*? INIT_TXT_BOX(u8 *);*/
/*int strlen(char *s);*/ /* missing from 3.0 psyq .h but present in 3.3? */

void INIT_TXT_FEE(void)
{
  s16 i;
  
  __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");

  i = 0;
  while (i < 10)
  {
    if (strlen(text_to_display[i].text) != 0)
    {
      text_to_display[i].font_size = 2;
      text_to_display[i].x_pos = 150;
      text_to_display[i].y_pos = 218;
      text_to_display[i].field8_0x3d = 0;
      text_to_display[i].is_fond = FALSE;
      INIT_TXT_BOX(&text_to_display[i]);
      text_to_display[i].text[0] = ' ';
      text_to_display[i].x_pos = text_to_display[i].centered_x_pos;
    }
    else
      text_to_display[i].field8_0x3d = 0;
    i++;
  }
  display_txt_fee = 0xff;
  old_txt_fee = 0xff;
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj/fee_3D76C", allocate_poing_or_fee);

INCLUDE_ASM("asm/nonmatchings/obj/fee_3D76C", init_moustique);

INCLUDE_ASM("asm/nonmatchings/obj/fee_3D76C", init_fee);
