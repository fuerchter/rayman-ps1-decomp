
#ifndef LEVEL_H
#define LEVEL_H

#include "common.h"
#include "common/obj.h"

typedef struct LevelData
{
    Obj * objects;
    u8 nb_objects;
} LevelData;

extern LevelData level;

#endif