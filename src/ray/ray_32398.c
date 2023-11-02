#include "ray/ray_32398.h"

/* 32398 80156B98 -O2 -msoft-float */
void INIT_RAY_BEGIN(void)
{
  status_bar.max_hp = 2;
  status_bar.num_wiz = 0;
  RayEvts.flags0 &= 0xF8; /* wow, so clean :) */
  RayEvts.flags1 &= 0xFE;
  RayEvts.flags0 &= 0xC8;
  RayEvts.flags1 &= (FLG(RAYEVTS1_DEMI)|FLG(RAYEVTS1_UNUSED_DEATH));
  RayEvts.flags0 &= (FLG(RAYEVTS0_SUPER_HELICO)|FLG(RAYEVTS0_GRAIN));
  ray.flags = ray.flags & ~FLG(OBJ_FLAG_0);
}

INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", INIT_RAY);

INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", is_icy_pente);

INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", STOPPE_RAY_EN_XY);

INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", RAY_RESPOND_TO_ALL_DIRS);

INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", DO_RAYMAN);

INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", DO_RAY_ON_MS);

INCLUDE_ASM("asm/nonmatchings/ray/ray_32398", DO_PLACE_RAY);
