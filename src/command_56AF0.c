#include "command_56AF0.h"

/* 56AF0 8017B2F0 -O2 */
void popCmdContext(Obj *obj)
{
    u8 *cci;
    s16 to_sub;
    
    cci = &obj->cmd_context_index;
    obj->cmd_offset = obj->cmd_contexts[*cci].cmd_offset;
    to_sub = 1;
    *cci -= to_sub;
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
u8 readNoArg(void)
{
    return FALSE;
}

/* 56B48 8017B348 -O2 */
u8 readOneArg(Obj *obj)
{
    obj->cmd_offset++;
    obj->nb_cmd = obj->cmds[obj->cmd_offset];
    return FALSE;
}

INCLUDE_ASM("asm/nonmatchings/command_56AF0", readTestArgs);

/* 56BE4 8017B3E4 -O2 */
u8 readGoXYArgs(Obj *obj)
{   
    obj->cmd_offset++;
    obj->nb_cmd = char2short(obj->cmds[obj->cmd_offset]);

    obj->cmd_offset++;
    obj->field24_0x3e = char2short(obj->cmds[obj->cmd_offset]);
    return FALSE;
}

/* 56C60 8017B460 -O2 */
u8 readSpeedArgs(Obj *obj)
{
    obj->cmd_offset++;
    obj->nb_cmd = obj->cmds[obj->cmd_offset];

    obj->cmd_offset++;
    obj->iframes_timer = char2short(obj->cmds[obj->cmd_offset]);

    obj->cmd_offset++;
    obj->field20_0x36 = char2short(obj->cmds[obj->cmd_offset]);
    return FALSE;
}

/* 56D00 8017B500 -O2 */
u8 readInvalidArg(Obj *obj)
{
    obj->cmd_offset = -1;
    readOneCommand(obj);
    return TRUE;
}

/* 56D24 8017B524 -O2 */
u8 skipNoArg(void)
{
    return FALSE;
}

/* 56D2C 8017B52C -O2 */
u8 skipOneArg(Obj *obj)
{
    obj->cmd_offset++;
    return FALSE;
}

INCLUDE_ASM("asm/nonmatchings/command_56AF0", skipTestArgs);

/* 56D8C 8017B58C -O2 */
u8 skipGoXYArgs(Obj *obj)
{
    obj->cmd_offset += 2;
    return FALSE;
}

/* 56DA4 8017B5A4 -O2 */
u8 skipSpeedArgs(Obj *obj)
{
    obj->cmd_offset += 3;
    return FALSE;
}

/* 56DBC 8017B5BC -O2 */
u8 skipInvalidArg(Obj *obj)
{
    obj->cmd_offset = -1;
    skipOneCommand(obj);
    return TRUE;
}

/* 56DE0 8017B5E0 -O2 */
u8 handle_GO_WAITSTATE(Obj *obj)
{
    obj->change_anim_mode = ANIMMODE_RESET_IF_NEW;
    obj->cmd = GO_WAIT;
    obj->nb_cmd = vblToEOA(obj, obj->nb_cmd) - 1;
    return FALSE;
}

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_RESERVED_GO_GOSUB);

/* 56E24 8017B624 -O1, -O2 */
u8 handle_RESERVED_GO_SKIP_and_RESERVED_GO_GOTO(Obj *obj)
{
    obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return TRUE;
}

/* 56E90 8017B690 -O1, -O2 */
u8 handle_RESERVED_GO_BRANCHTRUE(Obj *obj)
{
    if (obj->flags & OBJ_CMD_TEST)
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return TRUE;
}


/* 56EC8 8017B6C8 -O1, -O2 */
u8 handle_RESERVED_GO_BRANCHFALSE(Obj *obj)
{
    if (!(obj->flags & OBJ_CMD_TEST))
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return TRUE;
}

/* 56F00 8017B700 -O1, -O2 */
u8 handle_RESERVED_GO_SKIPTRUE(Obj *obj)
{
    if (obj->flags & OBJ_CMD_TEST)
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return TRUE;
}

/* 56F38 8017B738 -O1, -O2 */
u8 handle_RESERVED_GO_SKIPFALSE(Obj *obj)
{
    if (!(obj->flags & OBJ_CMD_TEST))
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return TRUE;
}

/* 56F70 8017B770 -O1, -O2 */
u8 handle_SELF_HANDLED(void)
{
    return FALSE;
}

/* 56F78 8017B778 -O2 */
u8 handle_GO_X(Obj *obj)
{
    obj->x_pos = obj->nb_cmd * 100 + obj->field24_0x3e;
    return TRUE;
}

/* 56FA4 8017B7A4 -O2 */
u8 handle_GO_Y(Obj *obj)
{
    obj->y_pos = obj->nb_cmd * 100 + obj->field24_0x3e;
    return TRUE;
}

/* 56FD0 8017B7D0 -O2 */
u8 handle_GO_GOTO(Obj *obj)
{
    skipToLabel(obj, obj->nb_cmd, TRUE);
    return FALSE;
}

/* 56FF4 8017B7F4 -O2 */
u8 handle_GO_STATE(Obj *obj)
{
  set_main_etat(obj, obj->nb_cmd);
  obj->speed_x = 0;
  obj->speed_y = 0;
  return TRUE;
}

/* 5702C 8017B82C -O2 */
u8 handle_GO_SUBSTATE(Obj *obj)
{
  set_sub_etat(obj, obj->nb_cmd);
  obj->speed_x = 0;
  obj->speed_y = 0;
  return TRUE;
}

/* 57064 8017B864 -O2 */
u8 handle_GO_SKIP(Obj *obj)
{
    s16 length;
    s16 i;

    length = obj->nb_cmd;
    for (i = 0; i < length; i++)
        skipOneCommand(obj);
    return TRUE;
}

/* 570D0 8017B8D0 -O2 */
u8 handle_GO_LABEL(void)
{
    return TRUE;
}

/* 570D8 8017B8D8 -O2 */
u8 handle_GO_PREPARELOOP(Obj *obj)
{
    pushCmdContext(obj, obj->nb_cmd);
    return TRUE;
}

/* 570FC 8017B8FC -O2 */
u8 handle_GO_GOSUB(Obj *obj)
{
    pushCmdContext(obj, 1);
    skipToLabel(obj, obj->nb_cmd, TRUE);
    return FALSE;
}

/* 57138 8017B938 -O2 */
u8 handle_GO_RETURN(Obj *obj)
{
    popCmdContext(obj);
    return TRUE;
}

/* 57158 8017B958 -O2 */
u8 handle_GO_DOLOOP(Obj *obj)
{
    u8 *cci;
    s32 count;
    s16 to_sub;

    cci = &obj->cmd_context_index;
    count = (obj->cmd_contexts[*cci].count -= 1);
    to_sub = 1;

    if ((s16) count > 0)
        obj->cmd_offset = obj->cmd_contexts[*cci].cmd_offset;
    else
        *cci -= to_sub;
    return TRUE;
}

/* 571B8 8017B9B8 -O2 */
u8 handle_INVALID_CMD(Obj *obj)
{
  obj->cmd_offset = -1;
  return TRUE;
}

/* 571C8 8017B9C8 -O2 */
u8 handle_GO_BRANCHTRUE(Obj *obj)
{
    if (obj->flags & OBJ_CMD_TEST)
    {
        skipToLabel(obj, obj->nb_cmd, TRUE);
        return FALSE;
    }
    return TRUE;
}

/* 57204 8017BA04 -O2 */
u8 handle_GO_BRANCHFALSE(Obj *obj)
{
    if (!(obj->flags & OBJ_CMD_TEST))
    {
        skipToLabel(obj, obj->nb_cmd, TRUE);
        return FALSE;
    }
    return TRUE;
}

/* 57240 8017BA40 -O2 */
u8 handle_GO_SKIPTRUE(Obj *obj)
{
  s16 length;
  s16 i;
  
  if (obj->flags & OBJ_CMD_TEST)
  {
    length = obj->nb_cmd;
    for (i = 0; i < length; i++)
        skipOneCommand(obj);
  }
  return TRUE;
}

/* 572C0 8017BAC0 -O2 */
u8 handle_GO_SKIPFALSE(Obj *obj)
{
  s16 length;
  s16 i;
  
  if (!(obj->flags & OBJ_CMD_TEST))
  {
    length = obj->nb_cmd;
    for (i = 0; i < length; i++)
        skipOneCommand(obj);
  }
  return TRUE;
}

/* 57344 8017BB44 -O2 */
u8 handle_GO_SETTEST(Obj *obj)
{
    u8 to_and;
    
    to_and = 1;
    obj->flags = obj->flags & ~OBJ_CMD_TEST | (obj->nb_cmd & to_and) << 9;
    return TRUE;
}

INCLUDE_ASM("asm/nonmatchings/command_56AF0", handle_GO_TEST);
/* 5736C 8017BB6C -O2 */
/* m2c = 4285, ghidra = 9870 */

/* 57528 8017BD28 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/command_56AF0", readOneCommand);
#else
u8 readOneCommand(Obj *obj)
{
    __asm__("nop");
    
    obj->cmd_offset++;
    obj->cmd = obj->cmds[obj->cmd_offset];
    return cptr_tab[obj->cmd].read(obj);
}
#endif

/* 57598 8017BD98 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/command_56AF0", skipOneCommand);
#else
u8 skipOneCommand(Obj *obj)
{
    __asm__("nop");

    obj->cmd_offset++;
    obj->cmd = obj->cmds[obj->cmd_offset];
    return cptr_tab[obj->cmd].skip(obj);
}
#endif

/* 57608 8017BE08 -O2 */
#ifndef MISSING_ADDIU
INCLUDE_ASM("asm/nonmatchings/command_56AF0", GET_OBJ_CMD);
#else
void GET_OBJ_CMD(Obj *obj)
{
    __asm__("nop");

    if (obj->cmds)
    {
        if ((obj->flags & OBJ_READ_CMDS) && --obj->nb_cmd == -1)
        {
            do
            {
                readOneCommand(obj);
            } while (cptr_tab[obj->cmd].handle(obj));
        }
    }
    else
        obj->cmd = GO_NOP;
}
#endif

/* 576BC 8017BEBC -O2 */
void pushCmdContext(Obj *obj, u16 count)
{
    u8 *cci;

    obj->cmd_context_index++;
    cci = &obj->cmd_context_index;
    obj->cmd_contexts[*cci].cmd_offset = obj->cmd_offset;
    obj->cmd_contexts[*cci].count = count & 0x00FF;
}

/* 576F8 8017BEF8 -O2 */
void skipToLabel(Obj *obj, u8 label, u8 skip_label_cmd)
{
    u8 in_rd_cmd;
    s32 to_and;
    s16 in_offs;
    s16 cur_offs;

    in_rd_cmd = *((u8 *) &obj->flags + 1) >> 7;
    to_and = 1;
    in_offs = obj->cmd_offset;
    do
    {
        skipOneCommand(obj);
        cur_offs = obj->cmd_offset;
        if (cur_offs == in_offs)
            break;
    } while (obj->cmd != GO_LABEL || obj->cmds[cur_offs] != label);
    if (skip_label_cmd)
    {
        if (cur_offs != in_offs)
        {
            obj->nb_cmd = 0;
            obj->flags |= OBJ_READ_CMDS;
            GET_OBJ_CMD(obj);

            /* restore in_rd_cmd */
            obj->flags = obj->flags & ~OBJ_READ_CMDS | (in_rd_cmd & to_and) << 15;
        }
    }
    else
        obj->cmd = GO_NOP;
}

/* 577EC 8017BFEC -O2 */
void pushToLabel(Obj *obj, u8 label, u8 skip_label_cmd)
{
    pushCmdContext(obj, 1);
    skipToLabel(obj, label, skip_label_cmd);
}
