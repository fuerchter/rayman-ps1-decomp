#include "bonus_372E0.h"

/*INCLUDE_ASM("asm/nonmatchings/bonus_372E0", DO_WIZARD);*/

/* 372E0 8015BAE0 -O2 */
/*? fix_numlevel(u8 *);
? save_objects_flags();
? set_main_and_sub_etat(s32 *, ?, ?);
? set_sub_etat(u8 *, ?);*/
extern u8 D_801E4D56;
extern u8 D_801F4EBA;
extern u8 D_801F61F6;
extern u8 D_801F61F8;
extern s32 D_801F620C;
extern s32 ray;

void DO_WIZARD(Obj *arg0)
{
  u8 *new_var;
  s32 *new_var2;
  u8 temp_v1;
  temp_v1 = arg0->sub_etat;
  switch (temp_v1)
  {
    case 1:
        if (((u8) D_801E4D56) >= 0xAU)
        {
            arg0->field24_0x3e = (s16) D_801E4D56;
            set_sub_etat(arg0, 2);
            set_main_and_sub_etat(&ray, 3, 9);
            return;
        }
        set_sub_etat(arg0, 0xA);
        arg0->flags = (s32) (arg0->flags & (~0x4000));
        return;

    case 3:
        set_main_and_sub_etat(&ray, 3, 0xA);
        if ((D_801F4EBA == 0) && ((arg0->field24_0x3e - D_801E4D56) < 0xA))
        {
            D_801E4D56 -= 1;
            return;
        }
        return;

    case 5:
        new_var = &D_801F61F6;
        if (((*new_var) == 3) && (((u32) (D_801F61F8 - 0xB)) >= 2U))
        {
            set_sub_etat((&D_801F61F6) - 0x56, 0xB);
        }
        if (((s32) arg0->anim_frame) >= arg0->animations[arg0->anim_index].frames_count - 1)
        {
            set_sub_etat(arg0, 0);
            fix_numlevel(arg0);
            save_objects_flags();

            D_801F620C = (*(new_var2 = &D_801F620C)) | 0x100;
            set_main_and_sub_etat((&D_801F620C) - 0x6C, 0, 0);
        }
        break;
  }
}