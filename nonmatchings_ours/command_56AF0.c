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

/* score of 15 */
/*INCLUDE_ASM("asm/nonmatchings/command_56AF0", skipTestArgs);*/

/* 56D44 8017B544 -O2 */
u8 skipTestArgs(Obj *obj)
{
    s32 test_1;
    s32 test_2;
  
    obj->cmd_offset++;
    /*if(obj->cmds[obj->cmd_offset] < 0)
        obj->cmds[obj->cmd_offset] = obj->cmds[obj->cmd_offset];*/
    test_2 = test_1 = obj->cmds[obj->cmd_offset];
    if (test_1 >= 0 && test_2 < 5) {
        obj->cmd_offset++;
    }
    return false;
}
