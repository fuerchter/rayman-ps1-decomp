#ifndef LOADING_DA64_H
#define LOADING_DA64_H

#include "common.h"
#include "display.h"
#include "obj_update.h"
#include "collision/collision_block.h"
#include "loading_794DC.h"
#include "display_ui.h"

typedef struct Font
{
    Sprite * sprites;
    u8 * img_buffer;
    s32 nb_sprites;
} Font;

typedef struct AllFixData
{
    Font alpha;
    Font alpha2;
    Obj objects[29];
} AllFixData;

extern AllFixData *PS1_AllFixData;

void PS1_LoadLevelMapBlock(MapData *data);
void FUN_80132304(u32 *data, u8 height);
void FUN_8013234c(s32 *param_1);
void FUN_80132424(void);
void PS1_LoadAllFixData(void);
void PS1_LoadLevelEventBlock(void);
void FUN_80132864(s32 param_1);

#endif