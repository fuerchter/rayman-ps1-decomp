#include "input_ED20.h"

/*INCLUDE_ASM("asm/nonmatchings/input_ED20", TOUCHE);*/

s32 TOUCHE(Input param_1)
{
    s16 temp_v0_3;
    s16 var_a2;
    s32 temp_t7;
    s32 temp_v0_1;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_a3;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    u32 temp_a0;
    s32 test_1;
    s32 *new_var;

    /*var_v0 = *(&jtbl_80127304 + (temp_a0 * 4));*/
    switch (param_1)
    {
    case 0xFF:
        PS1_ButtonStates[1] = *PS1_ButtonStates;
        *PS1_ButtonStates = 0;
        
        *PS1_ButtonStates = PS1_PadReceiveBuffer[3] + (PS1_PadReceiveBuffer[2] << 8);
        if (*PS1_ButtonStates != 0)
        {
            *PS1_ButtonStates ^= 0xFFFF;
        }
        
        if (++D_801E4DF8 >= 5)
        {
            D_801E4DF8 = 0;
            PS1_GlobalTimer -= 1;
        }
        if ((ModeDemo == 1) && (*PS1_ButtonStates & 0x840))
        {
            ModeDemo = 2;
            new_world = 1;
        }
        new_var = PS1_ButtonStates;
        if (PS1_ButtonStates[1] != *new_var)
        {
            D_801E4B60 = 0;
            /*__builtin_memcpy(&PS1_ButtonStates[2], &PS1_ButtonStates[1], 15 * sizeof(s32));*/
            PS1_ButtonStates[16] = PS1_ButtonStates[15];
            PS1_ButtonStates[15] = PS1_ButtonStates[14];
            PS1_ButtonStates[14] = PS1_ButtonStates[13];
            PS1_ButtonStates[13] = PS1_ButtonStates[12];
            PS1_ButtonStates[12] = PS1_ButtonStates[11];
            PS1_ButtonStates[11] = PS1_ButtonStates[10];
            PS1_ButtonStates[10] = PS1_ButtonStates[9];
            PS1_ButtonStates[9] = PS1_ButtonStates[8];
            PS1_ButtonStates[8] = PS1_ButtonStates[7];
            PS1_ButtonStates[7] = PS1_ButtonStates[6];
            PS1_ButtonStates[6] = PS1_ButtonStates[5];
            PS1_ButtonStates[5] = PS1_ButtonStates[4];
            PS1_ButtonStates[4] = PS1_ButtonStates[3];
            PS1_ButtonStates[3] = PS1_ButtonStates[2];
            PS1_ButtonStates[2] = PS1_ButtonStates[1];
        }
        else
        {
            D_801E4B60 += 1;
        }
        PS1_DisableInputs = 0;
        return 0;
    case 0xF:
    case 0x10:
    case 0x12:
    case 0x15:
    case 0x16:
    case 0x19:
    case 0x1A:
        return 0;
    case 0x0:
        return *PS1_ButtonStates == 0;
    case 0x1:
        return *PS1_ButtonStates & 0x8000;
    case 0x2:
        return *PS1_ButtonStates & 0x2000;
    case 0x3:
        return *PS1_ButtonStates & 0x1000;
    case 0x4:
        return *PS1_ButtonStates & 0x4000;
    case 0x5:
        return *PS1_ButtonStates & 0x40;
    case 0x6:
        return *PS1_ButtonStates & 0x20;
    case 0x7:
        return *PS1_ButtonStates & 0x80;
    case 0x8:
        return *PS1_ButtonStates & 0x10;
    case 0x9:
        return *PS1_ButtonStates & 0x800 && !(PS1_ButtonStates[2] & 0x800);
    case 0xA:
        return *PS1_ButtonStates & 0x100;
    case 0xB:
        return *PS1_ButtonStates & 8;
    case 0xC:
        return *PS1_ButtonStates & 2;
    case 0xD:
        return *PS1_ButtonStates & 4;
    case 0xE:
        return *PS1_ButtonStates & 1;
    case 0x13:
        if (
            (*PS1_ButtonStates != PS1_ButtonStates[1]) &&
            (*PS1_ButtonStates == 0x0000100B) &&
            (PS1_ButtonStates[2] == 0x0000000B) &&
            (PS1_ButtonStates[3] == 0x0000200B) &&
            (PS1_ButtonStates[4] == PS1_ButtonStates[2]) &&
            (PS1_ButtonStates[5] == 0x0000400B) &&
            (PS1_ButtonStates[6] == PS1_ButtonStates[4]) &&
            (PS1_ButtonStates[7] == 0x0000800B) &&
            (PS1_ButtonStates[8] == PS1_ButtonStates[6]) &&
            PS1_ButtonStates[9] == 0x0000800B
        )
        {
            var_a2 = 1;
        }
        else
            var_a2 = 0;
        D_801F5688 = var_a2;
        return 0;
    case 0x14:
        if (
            *PS1_ButtonStates != PS1_ButtonStates[1] &&
            *PS1_ButtonStates == 0x00000022 &&
            (PS1_ButtonStates[2] == 2) &&
            (PS1_ButtonStates[3] == *PS1_ButtonStates) &&
            PS1_ButtonStates[4] == PS1_ButtonStates[2] &&
            PS1_ButtonStates[5] == 0x00008002 &&
            PS1_ButtonStates[6] == PS1_ButtonStates[4] &&
            PS1_ButtonStates[7] == PS1_ButtonStates[3] &&
            PS1_ButtonStates[8] == PS1_ButtonStates[6] &&
            PS1_ButtonStates[9] == 0x00000022
        )
        {
            var_a3 = 1;
        }
        else
            var_a3 = 0;
        return var_a3;
    case 0x17:
        var_a2 = 0;
        if (
            *PS1_ButtonStates != PS1_ButtonStates[1] &&
            *PS1_ButtonStates == 0x00008003 &&
            PS1_ButtonStates[2] == 3 &&
            PS1_ButtonStates[2] == 3 && /* ??? */
            PS1_ButtonStates[3] == 0x00004003
        )
        {
            /*var_v0 = PS1_ButtonStates[4];*/ /* TODO: nope */
            __asm__("lui        $a0, %hi(D_801CEF0C)");
            __asm__("lw         $a0, %lo(D_801CEF0C)($a0)");
        }
        return var_a2;
    
    case 0x18:
        if (
            *PS1_ButtonStates != PS1_ButtonStates[1] &&
            *PS1_ButtonStates == 0x00000020 &&
            PS1_ButtonStates[2] == 0x000000A0 &&
            PS1_ButtonStates[3] == 0x000000B0 &&
            PS1_ButtonStates[4] == 0x000080B0 &&
            PS1_ButtonStates[5] == 0x000080A0 &&
            PS1_ButtonStates[6] == 0x00008020 &&
            PS1_ButtonStates[7] == 0x00008000 &&
            PS1_ButtonStates[8] == 0 &&
            PS1_ButtonStates[9] == *PS1_ButtonStates &&
            PS1_ButtonStates[10] == 0 &&
            PS1_ButtonStates[11] == 8 &&
            PS1_ButtonStates[12] == 0x0000000A &&
            PS1_ButtonStates[13] == 0x0000000B &&
            PS1_ButtonStates[14] == 0x0000000F &&
            PS1_ButtonStates[15] == 0x0000000D &&
            PS1_ButtonStates[16] == 9
        )
        {
            var_a1 = 1;
        }
        else
            var_a1 = 0;
        return var_a1;
    case 0x11:
        
        if (*PS1_ButtonStates != PS1_ButtonStates[1] && *PS1_ButtonStates == 0x00000900)
        {
            var_v0 = 1;
        }
        else
            var_v0 = 0;
        
        return var_v0;
    default:
        /* TODO: no explicit return? */
        break;
    }
}