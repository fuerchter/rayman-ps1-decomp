#ifndef LOADING_794DC_H
#define LOADING_794DC_H

#include "common.h"
#include "psyq_3_0/LIBCD.H"

typedef struct FileInfo
{
    u8 * path;
    u8 * dest;
    u8 * dest_debug;
    CdlFILE file;
} FileInfo;

/* .data */
extern FileInfo PS1_VabFiles[7];
extern FileInfo PS1_BigFiles[7];
extern FileInfo PS1_Vab4sepFiles[7];

/* .data */
extern u8 PS1_HasLoadedFont;

/**/
extern s32 PS1_FileTemp;

#endif