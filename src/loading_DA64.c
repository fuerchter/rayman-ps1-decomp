#include "loading_DA64.h"

extern s16 D_801D7A60;
extern s16 D_801F8188;
extern s16 D_801F84A8;
extern s32 D_801F4A40; /* type? */
extern void *D_801F7E90; /* type? Obj * based on FUN_80132424? */
extern Font alpha;
extern Font alpha2;

/* DA64 80132264 -O2 -msoft-float */
void PS1_LoadLevelMapBlock(MapData *data)
{
  u8 unk_1 = *((u8 *)PS1_LevelMapBlock + 1);

  if ((*(u8 *)PS1_LevelMapBlock == 0x4D) && unk_1 == 0x4D)
    PS1_LevelMapBlock++;
  D_801F84A8 = *PS1_LevelMapBlock;
  PS1_LevelMapBlock++;
  D_801F8188 = *PS1_LevelMapBlock;
  D_801D7A60 = D_801F84A8 * D_801F8188;
  PS1_LevelMapBlock++;

  data->width = D_801F84A8;
  data->height = D_801F8188;
  data->length = D_801D7A60;
  data->map = PS1_LevelMapBlock;
}

/* DB04 80132304 -O2 -msoft-float */
void FUN_80132304(u32 *data, u8 height)
{
  RECT rect;

  rect.x = 768; rect.y = 504;
  rect.w = 256; rect.h = height;
  LoadImage(&rect, data);
}

INCLUDE_ASM("asm/nonmatchings/loading_DA64", FUN_8013234c);

/* DC24 80132424 -O2 -msoft-float */
void FUN_80132424(void)
{
    __builtin_memcpy(&bigray, D_801F7E90, sizeof(bigray));
}

/* didn't get straight up copy of AllFixData fields to work */
/* DCCC 801324CC -O2 -msoft-float */
void PS1_LoadAllFixData(void)
{
    u8 *cur = PS1_AllFixData;
    
    __builtin_memcpy(&alpha, cur, sizeof(Font));
    cur += sizeof(Font);
    __builtin_memcpy(&alpha2, cur, sizeof(Font));
    cur += sizeof(Font);
    __builtin_memcpy(&ray, cur, sizeof(Obj));
    cur += sizeof(Obj);
    __builtin_memcpy(&raylittle, cur, sizeof(Obj));
    cur += sizeof(Obj);
    __builtin_memcpy(&clock_obj, cur, sizeof(Obj));
    cur += sizeof(Obj);
    __builtin_memcpy(&div_obj, cur, sizeof(Obj));
    cur += sizeof(Obj);
    mapobj = cur;
}

INCLUDE_ASM("asm/nonmatchings/loading_DA64", PS1_LoadLevelEventBlock);

INCLUDE_ASM("asm/nonmatchings/loading_DA64", FUN_80132864);
