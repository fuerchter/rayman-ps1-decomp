#include "bonus_372E0.h"

/* 372E0 8015BAE0 -O2 */
/*? fix_numlevel(u8 *);
? save_objects_flags();
? set_main_and_sub_etat(s32 *, ?, ?);
? set_sub_etat(u8 *, ?);*/

void DO_WIZARD(Obj *obj)
{
  s16 one;
  
  switch (obj->sub_etat)
  {
    case 1:
        if (status_bar.num_wiz >= 10)
        {
            obj->field24_0x3e = status_bar.num_wiz;
            set_sub_etat(obj, 2);
            set_main_and_sub_etat(&ray, 3, 9);
            return;
        }
        set_sub_etat(obj, 0xA);
        obj->flags &= ~OBJ_FLIP_X;
        return;

    case 3:
        set_main_and_sub_etat(&ray, 3, 0xA);
        if (horloge[2] == 0 && (obj->field24_0x3e - status_bar.num_wiz < 10))
        {
            one = 1;
            status_bar.num_wiz -= one;
            return;
        }
        return;

    case 5:
        if (ray.main_etat == 3 && (ray.sub_etat - 0xB >= 2U))
            set_sub_etat(&ray, 0xB);

        if (obj->anim_frame >= obj->animations[obj->anim_index].frames_count - 1)
        {
            set_sub_etat(obj, 0);
            fix_numlevel(obj);
            save_objects_flags();

            ray.flags |= OBJ_FLAG_0;
            set_main_and_sub_etat((&ray), 0, 0);
        }
        break;
  }
}

INCLUDE_ASM("asm/nonmatchings/bonus_372E0", get_next_bonus_level);

INCLUDE_ASM("asm/nonmatchings/bonus_372E0", TEST_WIZARD);