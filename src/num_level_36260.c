#include "num_level_36260.h"

/* 36260 8015AA60 -O2 -msoft-float */
extern s16 ray_X_main_pos_init;
extern s16 ray_Y_main_pos_init;
extern s16 xmapsave;
extern s16 ymapsave;

void new_level_init(void)
{
  departlevel = 1;
  ray_X_main_pos_init = ray.x_pos;
  ray_Y_main_pos_init = ray.y_pos;
  xmapsave = xmap;
  ymapsave = ymap;
}

INCLUDE_ASM("asm/nonmatchings/num_level_36260", fix_numlevel);

INCLUDE_ASM("asm/nonmatchings/num_level_36260", TEST_SIGNPOST);
