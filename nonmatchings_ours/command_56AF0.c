#include "command_56AF0.h"

/*INCLUDE_ASM("asm/nonmatchings/command_56AF0", readTestArgs);*/

/* 56B78 8017B378 -O2 */
/* matches, but hacky */
s32 readTestArgs(Obj *obj)
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
    return 0;
}

/*INCLUDE_ASM("asm/nonmatchings/command_56AF0", skipTestArgs);*/

/* 56D44 8017B544 -O2 */
s32 skipTestArgs(Obj *obj)
{
    s16 test;
  
    obj->cmd_offset++;
    /*if(obj->cmds[obj->cmd_offset] < 0)
        obj->cmds[obj->cmd_offset] = obj->cmds[obj->cmd_offset];*/
    if (obj->cmds[obj->cmd_offset] < 5) {
        obj->cmd_offset++;
    }
    return 0;
}

/* 56E24 8017B624 -O1 !!! */
s32 handle_RESERVED_GO_GOSUB(Obj *obj)
{
    pushCmdContext(obj, 1);
    obj->cmd_offset = *(s16 *)(obj->cmd_labels + obj->nb_cmd);
    return 1;
}