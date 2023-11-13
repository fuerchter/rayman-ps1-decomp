#include "command_56AF0.h"

/*INCLUDE_ASM("asm/nonmatchings/command_56AF0", readTestArgs);*/

/* 56B78 8017B378 -O2 */
/* matches, but hacky */
u8 readTestArgs(Obj *obj)
{
    obj->cmd_offset++;
    obj->nb_cmd = obj->cmds[obj->cmd_offset];
    if (obj->nb_cmd < 0)
        obj->nb_cmd = obj->nb_cmd;
    else if (obj->nb_cmd < 5)
    {
        obj->cmd_offset++;
        obj->field23_0x3c = obj->cmds[obj->cmd_offset];
    }
    return false;
}

/*INCLUDE_ASM("asm/nonmatchings/command_56AF0", skipTestArgs);*/

/* 56D44 8017B544 -O2 */
u8 skipTestArgs(Obj *obj)
{
    s16 test;
  
    obj->cmd_offset++;
    /*if(obj->cmds[obj->cmd_offset] < 0)
        obj->cmds[obj->cmd_offset] = obj->cmds[obj->cmd_offset];*/
    if (obj->cmds[obj->cmd_offset] < 5) {
        obj->cmd_offset++;
    }
    return false;
}

/*INCLUDE_ASM("asm/nonmatchings/command_56AF0", GET_OBJ_CMD);*/

/* version that tries to use D_801C7EC0 instead of CommandTableEntry struct */
/* 57608 8017BE08 -O2 */
extern CommandTableEntry cptr_tab[34];
u8 (* D_801C7EC0)(Obj *);

void GET_OBJ_CMD(Obj *obj)
{
  u8 (*handle)(Obj *);
  int new_var;
  u8 bVar1;
  s16 sVar2;
  if (obj->cmds)
  {
    if (((obj->flags & OBJ_READ_CMDS) != OBJ_NONE) && ((sVar2 = obj->nb_cmd + (-1), obj->nb_cmd = sVar2, sVar2 == (new_var = -1))))
    {
      sVar2 = obj->cmd;
      do
      {
        new_var = sVar2;
        readOneCommand(obj);
        handle = *((&D_801C7EC0) - (-(new_var * 0xC)));
        bVar1 = handle(obj);
      }
      while (bVar1);
    }
  }
  else
  {
    obj->cmd = GO_NOP;
  }
}