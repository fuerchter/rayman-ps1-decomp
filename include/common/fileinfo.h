#ifndef FILEINFO_H
#define FILEINFO_H

#include "common.h"
#include "psyq_3_0/LIBCD.H"

typedef struct FileInfo
{
    u8 * path;
    u8 * dest; /* u32 * based on PS1_LoadFiles/CdRead? */
    u8 * dest_debug;
    CdlFILE file;
} FileInfo;

#endif