#include "obj/cage_init.h"

/*INCLUDE_ASM("asm/nonmatchings/obj/cage_init", allocateGrille);*/

/* 361A0 8015A9A0 -O2 */
extern u8 D_801D7AE4;
extern LevelData level;

void allocateGrille(Obj *obj)
{
  Obj *psVar3;
  u8 new_var;
  s16 iVar1;

  new_var = level.nb_objects;
  iVar1 = 0;
  if (new_var != 0)
  {
    /*psVar3 = &level.objects;*/
    do
    {
      if ((psVar3->type == TYPE_CAGE2) && ((psVar3->flags & OBJ_ACTIVE) == OBJ_NONE))
      {
        psVar3->flags = psVar3->flags | (OBJ_ALIVE | OBJ_ACTIVE);
        psVar3->x_pos = obj->x_pos;
        psVar3->y_pos = obj->y_pos;
        psVar3->speed_y = -4;
        psVar3->screen_x_pos = psVar3->x_pos - xmap;
        psVar3->screen_y_pos = psVar3->y_pos - ymap;
        return;
      }
      iVar1++;
      psVar3 = psVar3 + 1;
    }
    while (iVar1 < new_var);
  }
  return;
}