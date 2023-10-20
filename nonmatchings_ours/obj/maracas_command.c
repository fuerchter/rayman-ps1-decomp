#include "obj/maracas_command.h"

extern MapData mp;

/* gotos-only... */
/* 4CB88 80171388 -O2 */
/*INCLUDE_ASM("asm/nonmatchings/obj/maracas_command", MarCoince);*/

extern s16 *D_801F4438;

s16 MarCoince(Obj *arg0, s16 arg1)
{
  s16 temp_a2;
  s16 temp_a3;
  s16 var_t0;
  s32 var_v0;
  s32 var_v0_3;
  s16 var_v0_4;
  s16 new_var;
  s16 var_v0_5;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 temp_v1_3;
  s32 temp_v1_4;
  s32 temp_v1_5;
  s32 var_v0_2;
  s32 var_v1;
  s16 *new_var2;
  
  var_t0 = 0;
  temp_a3 = (arg0->offset_bx + ((u16) arg0->x_pos)) - 0x19;
  temp_a2 = arg0->offset_hy + ((u16) arg0->y_pos);
  if (arg1 == 1)
  {
    goto block_27;
  }
  if (arg1 >= 2)
  {
    goto block_4;
  }
  if (arg1 == 0)
  {
    goto block_23;
  }
  goto block_38;
block_4:
  if (arg1 == 2)
  {
    goto block_7;
  }

  if (arg1 == 3)
  {
    goto block_15;
  }
  goto block_38;
block_7:
  var_v0 = 0; /*var_v0 = temp_a2;*/

  if (temp_a2 >= 0)
  {
    goto block_9;
  }
  var_v0 = temp_a2 + 0xF;
block_9:
  if (((s16) (temp_a2 - ((var_v0 >> 4) << 4))) >= 3)
  {
    goto block_38;
  }

  temp_v1 = (((temp_a3 << 0x10)) >> 0x14) + (mp.width * (((temp_a2 << 0x10)) >> 0x14));
  temp_v1_2 = temp_v1 + 1;
  if (!(block_flags[(u16) mp.map[temp_v1] >> 0xA] >> 1 & 1))
  {
    goto block_12;
  }
  var_t0 = 1;
block_12:
  if (!(block_flags[(u16) mp.map[temp_v1_2] >> 0xA] >> 1 & 1))
  {
    goto block_14;
  }

  var_t0 = 1;
block_14:
  var_v0_2 = (temp_v1_2 + 1) * 2;

  goto block_36;
block_15:
  var_v0_3 = temp_a2;

  if (temp_a2 >= 0)
  {
    goto block_17;
  }
  var_v0_3 = temp_a2 + 0xF;
block_17:
  if (((s16) (temp_a2 - ((var_v0_3 >> 4) << 4))) < 0xD)
  {
    goto block_38;
  }

  temp_v1_3 = (((s32) (temp_a3 << 0x10)) >> 0x14) + (mp.width * (((s32) (temp_a2 + 0x30)) >> 4));
  temp_v1_4 = temp_v1_3 + 1;
  new_var = temp_a3;
  
  if (!(block_flags[(u16) mp.map[temp_v1_3] >> 0xA] >> 1 & 1))
  {
    goto block_20;
  }
  var_t0 = 1;
block_20:
  if (!(block_flags[(u16) mp.map[temp_v1_4] >> 0xA] >> 1 & 1))
  {
    goto block_22;
  }

  var_t0 = 1;
  new_var2 = mp.map;
block_22:
  var_v0_2 = (temp_v1_4 + 1) * 2;

  goto block_36;
block_23:
  var_v0_4 = new_var;

  if (new_var >= 0)
  {
    goto block_25;
  }
  var_v0_4 = new_var + 0xF;
block_25:
  if (((s16) (new_var - ((var_v0_4 >> 4) * 0x10))) >= 3)
  {
    goto block_38;
  }

  var_v1 = ((((s32) (new_var << 0x10)) >> 0x14) + (mp.width * (((s32) (temp_a2 + 0x10)) >> 4))) - 1;
  goto block_31;
block_27:
  var_v0_5 = new_var;

  if (new_var >= 0)
  {
    goto block_29;
  }
  var_v0_5 = new_var + 0xF;
block_29:
  if (((s16) (new_var - ((var_v0_5 >> 4) * 0x10))) < 0xD)
  {
    goto block_38;
  }

  var_v1 = ((((s32) (new_var << 0x10)) >> 0x14) + (mp.width * (((s32) (temp_a2 + 0x10)) >> 4))) + 3;
block_31:
  temp_v1_5 = var_v1 + mp.width;

  if (!(block_flags[(u16) mp.map[var_v1 * 2] >> 0xA] >> 1 & 1))
  {
    goto block_33;
  }
  var_t0 = 1;
block_33:
  if (!(block_flags[(u16) mp.map[temp_v1_5 * 2] >> 0xA] >> 1 & 1))
  {
    goto block_35;
  }

  var_t0 = 1;
block_35:
  var_v0_2 = (temp_v1_5 + mp.width) * 2;

block_36:
  if (!(block_flags[(u16) new_var2[var_v0_2] >> 0xA] >> 1 & 1))
  {
    goto block_38;
  }

  var_t0 = 1;
block_38:
  return var_t0;

}