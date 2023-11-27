#include "loading_E99C.h"

void FUN_80133048(s32 param_1, FileInfo *param_2, s32 param_3);

/* E99C 8013319C -O2 -msoft-float */
s32 PS1_InitFiles(FileInfo *files, s32 count, u8 *name){ return 0; }

/* E9A4 801331A4 -O2 -msoft-float */
s32 FUN_801331a4(FileInfo *files, s32 count, s32 param_3)
{
    s16 i;
    s16 j;
    s32 num_not_found = 0;

    for (i = 0; i < count; i++)
    {
        files[i].file.size = 0;
        if (files[i].dest)
        {
            for (j = 0; j < 100; j++)
            {
                CdSync(0, null);
                if(CdSearchFile(&files[i].file, files[i].path))
                    break;
            }
        }
        if (j == 100)
            num_not_found++;
    }

    FUN_80133048(param_3, files, count);
    return num_not_found;
}

/* EAB4 801332B4 -O2 -msoft-float */
s32 PS1_LoadFiles(FileInfo *files, s32 file_index, s32 count, s16 param_4)
{
    FileInfo unk_1;
    s32 num_not_found;
    s16 i;
    s16 j;
    s32 num_sectors;
    s32 sectors_rem;
    s16 unk_2;
    s16 unk_3;

    __builtin_memcpy(&unk_1, &files[0], sizeof(FileInfo));
    num_not_found = 0;
    for (i = file_index; i < file_index + count; i++)
    {
        j = 10000;
        if (files[i].dest)
        {
            if (files[i].file.size != 0)
            {
                for (j = 0; j < 10000; j++)
                {
                    CdSync(0, null);
                    num_sectors = (files[i].file.size + 2047) >> 11;
                    CdControlB(CdlSetloc, &files[i].file.pos.minute, null);
                    CdRead(num_sectors, files[i].dest, CdlModeSpeed);
                    while ((sectors_rem = CdReadSync(1, null)) > 0)
                    {
                        if (param_4 != 0)
                        {
                            unk_2 = xmap;
                            xmap = unk_2;
                            unk_3 = ymap;
                            ymap = unk_3;
                        }
                    }
                    if (sectors_rem == 0)
                        break;
                }
            }
        }
        if (j == 10000)
            num_not_found++;
    }
    return num_not_found;
}

INCLUDE_ASM("asm/nonmatchings/loading_E99C", FUN_80133498);
