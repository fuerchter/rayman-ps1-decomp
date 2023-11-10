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
extern u8 PS1_HasLoadedFont;

#endif