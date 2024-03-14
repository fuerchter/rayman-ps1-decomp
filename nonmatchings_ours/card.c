#include "card.h"

/*
matches, but doubled counter vars...
removing cnt2_2 on decomp.me still matches, but not locally
*/
/*INCLUDE_ASM("asm/nonmatchings/card", PS1_CardFilenameChecksum);*/

s32 PS1_CardFilenameChecksum(u8 chan)
{
    struct DIRENTRY dirs[15];
    u8 name_start[8];
    s32 nbre_files;
    u8 cnt1_1; s32 cnt1_2;
    u8 cnt2_1; u32 cnt2_2;
    struct DIRENTRY *cur_dir;
    s32 sum = 0;

    sprintf(name_start, s_bu02x_801cf040, chan);
    nbre_files = PS1_GetNbreFiles(name_start, dirs);
    for (cnt1_1 = 0; cnt1_1 < nbre_files; cnt1_1++)
    {
        cnt2_1 = 0;
        cnt1_2 = cnt1_1;
        cur_dir = &dirs[cnt1_2];
        for (; cnt2_2 = cnt2_1, cnt2_2 < strlen(cur_dir->name); cnt2_1++)
            sum += (u8) cur_dir->name[cnt2_2] << cnt1_2;
    }
    return sum;
}