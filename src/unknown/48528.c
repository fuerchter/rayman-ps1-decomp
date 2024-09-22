#include "unknown/48528.h"

extern s16 PS1_VRAMDisplayXPos;
extern s16 PS1_VRAMDisplayYPos;

/* 48528 8016CD28 -O2 -msoft-float */
void PS1_DisplayVRAM(void)
{
    s32 l1_pressed;
    DISPENV prev_disp_env;

    TOUCHE(INPUT_READ);
    l1_pressed = 0;
    prev_disp_env = PS1_Displays[0].field0_0x0;
    while (l1_pressed == 0)
    {
        if (FUN_80133714(0))
            PS1_VRAMDisplayXPos -= 32;
        if (FUN_80133764(0))
            PS1_VRAMDisplayXPos += 32;
        if (FUN_801336c4(0))
            PS1_VRAMDisplayYPos -= 32;
        if (FUN_801337b4(0))
            PS1_VRAMDisplayYPos += 32;
        
        if (FUN_80134080(0))
            l1_pressed = 0xFF;
        
        if (PS1_VRAMDisplayYPos > 304)
            PS1_VRAMDisplayYPos = 280;
        if (PS1_VRAMDisplayYPos < 0)
            PS1_VRAMDisplayYPos = 0;
        if (PS1_VRAMDisplayXPos > 736)
            PS1_VRAMDisplayXPos = 712;
        if (PS1_VRAMDisplayXPos < 0)
            PS1_VRAMDisplayXPos = 0;
        
        SetDefDispEnv(
            &PS1_Displays[0].field0_0x0,
            PS1_VRAMDisplayXPos, PS1_VRAMDisplayYPos,
            320, 240
        );
        PS1_Displays[0].field0_0x0.pad0 =
        PS1_Displays[1].field0_0x0.pad0 = 1;
        PutDispEnv(&PS1_Displays[0].field0_0x0);
        TOUCHE(INPUT_READ);
    }

    while (FUN_80133fe0(0) == 0)
        TOUCHE(INPUT_READ);

    PS1_Displays[0].field0_0x0 = prev_disp_env;
}

/* 487A4 8016CFA4 -O2 -msoft-float */
u8 test_allowed(Obj *obj, s16 unk_x, s16 unk_y)
{
    s16 map_index =
        ((unk_x + obj->x_pos) >> 4) +
        ((unk_y + obj->y_pos) >> 4) * mp.width;
    u8 res = false;
    
    if (map_index != obj->test_block_index)
    {
        obj->test_block_index = map_index;
        res = true;
    }
    return res;
}

/* 4880C 8016D00C -O2 -msoft-float */
void obj_jump(Obj *obj)
{
    s16 spd_y;
    u8 unk_1 = 0;
    s16 spd_x = obj->speed_x;
    u8 label = 0xFF;
    
    switch (obj->type)
    {
    case TYPE_STONEWOMAN:
        if (obj->eta[obj->main_etat][obj->sub_etat].flags & 1)
        {
            label = 15;
            set_main_and_sub_etat(obj, 2, 3);
            spd_y = -3;
            unk_1 = 5;
        }
        break;
    case TYPE_BLACKTOON1:
        if (obj->field56_0x69 & 2)
        {
            label = 1;
            set_main_and_sub_etat(obj, 2, 5);
            spd_y = -3;
        }
        break;
    }

    if (label != 0xFF)
    {
        skipToLabel(obj, label, true);
        obj->speed_x = spd_x;
        obj->speed_y = spd_y;
        obj->gravity_value_1 = 0;
        obj->gravity_value_2 = unk_1;
        obj->y_pos -= 12;
        calc_btyp(obj);
    }
}

INCLUDE_ASM("asm/nonmatchings/unknown/48528", DO_ONE_PINK_CMD);

INCLUDE_ASM("asm/nonmatchings/unknown/48528", FUN_8016d418);
