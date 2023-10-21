#include "bonus_372E0.h"

/* 372E0 8015BAE0 -O2 */
/*? fix_numlevel(u8 *);
? save_objects_flags();
? set_main_and_sub_etat(s32 *, ?, ?);
? set_sub_etat(u8 *, ?);*/

void DO_WIZARD(Obj *obj)
{
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
            status_bar.num_wiz--;
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

/* 374A8 8015BCA8 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/bonus_372E0", get_next_bonus_level);
#else
s16 get_next_bonus_level(u8 level)
{
    s16 res;
    
    __asm__("nop");

    res = 0;
    switch ((s16)(num_world - 1))
    {
    case 0:
        switch (level)
        {
        case 2:
            res = 21;
            break;
        case 4:
            res = 20;
            break;
        case 11:
            res = 18;
            break;
        case 12:
            res = 19;
            break;
        }
        break;
    case 1:
        switch (level)
        {
        case 4:
            res = 17;
            break;
        case 9:
            res = 18;
            break;
        }
        break;
    case 3:
        switch (level)
        {
        case 3:
            res = 12;
            break;
        case 9:
            res = 13;
            break;
        }
        break;
    case 4:
        switch (level)
        {
        case 2:
            res = 12;
            break;
        }
    case 5:
        break;
    }

    return res;
}
#endif

/* 375BC 8015BDBC -O2 */
INCLUDE_ASM("asm/nonmatchings/bonus_372E0", TEST_WIZARD);