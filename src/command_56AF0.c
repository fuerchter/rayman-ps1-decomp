#include "command_56AF0.h"

/* 56AF0 8017B2F0 -O2 */
void popCmdContext(Obj *obj)
{
    u8 *cci;
    s16 to_sub;
    
    cci = &obj->cmd_context_index;
    obj->cmd_offset = obj->cmd_contexts[*cci].cmd_offset;
    to_sub = 1;
    *cci = *cci - to_sub;
}

/* 56B14 8017B314 -O2 */
s16 char2short(u8 in_char)
{
    s16 out_short;

    if (in_char >= 128)
        out_short = in_char | 0xFF00;
    else
        out_short = in_char;
    
    return out_short;
}

/* 56B40 8017B340 -O2 */
s32 readNoArg(void)
{
    return 0;
}

/* 56B48 8017B348 -O2 */
s32 readOneArg(Obj *obj)
{
    obj->cmd_offset++;
    obj->nb_cmd = obj->cmds[obj->cmd_offset];
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/command_56AF0", readTestArgs);

/* 56BE4 8017B3E4 -O2 */
s32 readGoXYArgs(Obj *obj)
{   
    obj->cmd_offset++;
    obj->nb_cmd = char2short(obj->cmds[obj->cmd_offset]);

    obj->cmd_offset++;
    obj->field24_0x3e = char2short(obj->cmds[obj->cmd_offset]);
    return 0;
}

/* 56C60 8017B460 -O2 */
s32 readSpeedArgs(Obj *obj)
{
    obj->cmd_offset++;
    obj->nb_cmd = obj->cmds[obj->cmd_offset];

    obj->cmd_offset++;
    obj->iframes_timer = char2short(obj->cmds[obj->cmd_offset]);

    obj->cmd_offset++;
    obj->field20_0x36 = char2short(obj->cmds[obj->cmd_offset]);
    return 0;
}

/* 56D00 8017B500 -O2 */
s32 readInvalidArg(Obj *obj)
{
    obj->cmd_offset = -1;
    readOneCommand(obj);
    return 1;
}

/* 56D24 8017B524 -O2 */
s32 skipNoArg(void)
{
    return 0;
}

/* 56D2C 8017B52C -O2 */
s32 skipOneArg(Obj *obj)
{
    obj->cmd_offset++;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/command_56AF0", skipTestArgs);

/* 56D8C 8017B58C -O2 */
s32 skipGoXYArgs(Obj *obj)
{
    obj->cmd_offset += 2;
    return 0;
}

/* 56DA4 8017B5A4 -O2 */
s32 skipSpeedArgs(Obj *obj)
{
    obj->cmd_offset += 3;
    return 0;
}

/* 56DBC 8017B5BC -O2 */
s32 skipInvalidArg(Obj *obj)
{
    obj->cmd_offset = -1;
    skipOneCommand(obj);
    return 1;
}

/* 56DE0 8017B5E0 -O2 */
s32 handle_GO_WAITSTATE(Obj *obj)
{
    obj->change_anim_mode = ANIMMODE_RESET_IF_NEW;
    obj->cmd = GO_WAIT;
    obj->nb_cmd = vblToEOA(obj, obj->nb_cmd) - 1;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_RESERVED_GO_GOSUB);

/* 56E24 8017B624 -O1, -O2 */
s32 handle_RESERVED_GO_SKIP_and_RESERVED_GO_GOTO(Obj *obj)
{
    obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return 1;
}

/* 56E90 8017B690 -O1, -O2 */
s32 handle_RESERVED_GO_BRANCHTRUE(Obj *obj)
{
    if ((obj->flags & OBJ_CMD_TEST) != OBJ_NONE) {
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    }
    return 1;
}


/* 56EC8 8017B6C8 -O1, -O2 */
s32 handle_RESERVED_GO_BRANCHFALSE(Obj *obj)
{
    if ((obj->flags & OBJ_CMD_TEST) == OBJ_NONE) {
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    }
    return 1;
}

/* 56F00 8017B700 -O1, -O2 */
s32 handle_RESERVED_GO_SKIPTRUE(Obj *obj)
{
    if ((obj->flags & OBJ_CMD_TEST) != OBJ_NONE) {
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    }
    return 1;
}

/* 56F38 8017B738 -O1, -O2 */
s32 handle_RESERVED_GO_SKIPFALSE(Obj *obj)
{
    if ((obj->flags & OBJ_CMD_TEST) == OBJ_NONE) {
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    }
    return 1;
}

/* 56F70 8017B770 -O1, -O2 */
s32 handle_SELF_HANDLED(void)
{
    return 0;
}

/* 56F78 8017B778 -O2 */
s32 handle_GO_X(Obj *obj)
{
    obj->x_pos = obj->nb_cmd * 100 + obj->field24_0x3e;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_Y);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_GOTO);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_STATE);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_SUBSTATE);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_SKIP);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_LABEL);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_PREPARELOOP);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_GOSUB);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_RETURN);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_DOLOOP);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_INVALID_CMD);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_BRANCHTRUE);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_BRANCHFALSE);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_SKIPTRUE);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_SKIPFALSE);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_SETTEST);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_TEST);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", readOneCommand);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", skipOneCommand);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", GET_OBJ_CMD);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", pushCmdContext);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", skipToLabel);

INCLUDE_ASM("asm/nonmatchings/command_56AF0", pushToLabel);
