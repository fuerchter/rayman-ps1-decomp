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
extern FileInfo PS1_ImgFiles[3];
extern FileInfo PS1_LdrFiles[2];
extern FileInfo PS1_VdoFiles[6];
extern FileInfo PS1_TrkFiles[53];
extern FileInfo PS1_PreFiles[5];
extern FileInfo PS1_CrdFiles[6];
extern FileInfo PS1_GamFiles[6];
extern FileInfo PS1_VigWldFiles[6];
extern FileInfo PS1_WldFiles[6];
extern FileInfo PS1_MapFiles[126];
extern FileInfo PS1_FndFiles[31];
extern FileInfo PS1_VabFiles[7];
extern FileInfo PS1_BigFiles[7];
extern FileInfo PS1_Vab4sepFiles[7];
extern FileInfo PS1_FxsFiles[2];
extern FileInfo PS1_IniFiles[1];

/* .data */
extern u8 PS1_HasLoadedFont;

/**/
extern s32 PS1_FileTemp;

#endif