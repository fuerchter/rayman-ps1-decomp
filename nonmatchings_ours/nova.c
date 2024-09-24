#include "nova.h"

/*INCLUDE_ASM("asm/nonmatchings/nova", DO_NOVA);*/

void DO_NOVA(Obj *in_obj)
{
    s16 sp18;
    s16 sp1A;
    s16 sp1C;
    s16 sp1E;
    s16 sp20;
    s16 sp22;
    s16 sp24;
    s16 sp26;
    Obj *temp_v0;
    s16 test_1;
    s16 test_2;
    s16 test_3;
    s16 test_4;
    s16 test_5;
    s16 test_6;
    s16 test_7;
    s16 test_8;

    temp_v0 = allocateNOVA();
    if (temp_v0 != 0)
    {
        temp_v0->x_pos = in_obj->x_pos;
        temp_v0->y_pos = in_obj->y_pos;
        GET_ANIM_POS(temp_v0, &sp18, &sp1A, &sp1C, &sp1E);
        GET_ANIM_POS(in_obj, &sp20, &sp22, &sp24, &sp26);
        test_1 = sp24;
        test_2 = sp20;
        test_3 = sp1C;
        test_4 = sp18;
        test_5 = sp26;
        test_6 = sp22;
        test_7 = sp1E;
        test_8 = sp1A;
        temp_v0->display_prio = 1;
        temp_v0->field23_0x3c = 0;
        temp_v0->flags |= 0x800;
        temp_v0->x_pos += ((test_2 + (test_1 >> 0x1)) - (test_4 + (test_3 >> 0x1)));
        temp_v0->y_pos += ((test_6 + (test_5 >> 0x1)) - (test_8 + (test_7 >> 0x1)));
        calc_obj_pos(temp_v0);
    }
}