#ifndef LOADING_E99C_H
#define LOADING_E99C_H

#include "common.h"
#include "loading_794DC.h"

s32 PS1_InitFiles(FileInfo *files, s32 count, u8 *name);
s32 FUN_801331a4(FileInfo *files, s32 count, s32 param_3);
s32 PS1_LoadFiles(FileInfo *files, s32 file_index, s32 count, s16 param_4);
s32 FUN_80133498(FileInfo param_1, s16 param_2, u8 *param_3);

#endif