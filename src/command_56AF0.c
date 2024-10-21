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
u8 readNoArg(Obj *obj)
{
    return false;
}

/* 56B48 8017B348 -O2 */
u8 readOneArg(Obj *obj)
{
    obj->cmd_offset++;
    obj->nb_cmd = obj->cmds[obj->cmd_offset];
    return false;
}

/* 56B78 8017B378 -O2 -msoft-float */
u8 readTestArgs(Obj *obj)
{
    obj->nb_cmd = obj->cmds[++obj->cmd_offset];
    switch (obj->nb_cmd)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        obj->field23_0x3c = obj->cmds[++obj->cmd_offset];
        break;
    case 6:
    case 7:
        break;
    }

    return false;
}

/* 56BE4 8017B3E4 -O2 */
u8 readGoXYArgs(Obj *obj)
{   
    obj->cmd_offset++;
    obj->nb_cmd = char2short(obj->cmds[obj->cmd_offset]);

    obj->cmd_offset++;
    obj->field24_0x3e = char2short(obj->cmds[obj->cmd_offset]);
    return false;
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
    return false;
}

/* 56D00 8017B500 -O2 */
u8 readInvalidArg(Obj *obj)
{
    obj->cmd_offset = -1;
    readOneCommand(obj);
    return true;
}

/* 56D24 8017B524 -O2 */
u8 skipNoArg(Obj *obj)
{
    return false;
}

/* 56D2C 8017B52C -O2 */
u8 skipOneArg(Obj *obj)
{
    obj->cmd_offset++;
    return false;
}

/* thanks! https://decomp.me/scratch/Cvb8F */
/* 56D44 8017B544 -O2 -msoft-float */
u8 skipTestArgs(Obj *obj)
{
    switch (obj->cmds[++obj->cmd_offset])
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        obj->cmd_offset++;
        break;
    case 6:
    case 7:
        break;
    }
    
    return false;
}

/* 56D8C 8017B58C -O2 */
u8 skipGoXYArgs(Obj *obj)
{
    obj->cmd_offset += 2;
    return false;
}

/* 56DA4 8017B5A4 -O2 */
u8 skipSpeedArgs(Obj *obj)
{
    obj->cmd_offset += 3;
    return false;
}

/* 56DBC 8017B5BC -O2 */
u8 skipInvalidArg(Obj *obj)
{
    obj->cmd_offset = -1;
    skipOneCommand(obj);
    return true;
}

/* 56DE0 8017B5E0 -O2 */
u8 handle_GO_WAITSTATE(Obj *obj)
{
    obj->change_anim_mode = ANIMMODE_RESET_IF_NEW;
    obj->cmd = GO_WAIT;
    obj->nb_cmd = vblToEOA(obj, obj->nb_cmd) - 1;
    return false;
}

/* 56E24 8017B624 -O1 */
u8 handle_RESERVED_GO_GOSUB(Obj *obj)
{
    pushCmdContext(obj, 1);
    obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return true;
}

/* 56E24 8017B624 -O1, -O2 */
u8 handle_RESERVED_GO_SKIP_and_RESERVED_GO_GOTO(Obj *obj)
{
    obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return true;
}

/* 56E90 8017B690 -O1, -O2 */
u8 handle_RESERVED_GO_BRANCHTRUE(Obj *obj)
{
    if (obj->flags & FLG(OBJ_CMD_TEST))
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return true;
}


/* 56EC8 8017B6C8 -O1, -O2 */
u8 handle_RESERVED_GO_BRANCHFALSE(Obj *obj)
{
    if (!(obj->flags & FLG(OBJ_CMD_TEST)))
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return true;
}

/* 56F00 8017B700 -O1, -O2 */
u8 handle_RESERVED_GO_SKIPTRUE(Obj *obj)
{
    if (obj->flags & FLG(OBJ_CMD_TEST))
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return true;
}

/* 56F38 8017B738 -O1, -O2 */
u8 handle_RESERVED_GO_SKIPFALSE(Obj *obj)
{
    if (!(obj->flags & FLG(OBJ_CMD_TEST)))
        obj->cmd_offset = obj->cmd_labels[obj->nb_cmd];
    return true;
}

/* 56F70 8017B770 -O1, -O2 */
u8 handle_SELF_HANDLED(Obj *obj)
{
    return false;
}

/* 56F78 8017B778 -O2 */
u8 handle_GO_X(Obj *obj)
{
    obj->x_pos = obj->nb_cmd * 100 + obj->field24_0x3e;
    return true;
}

/* 56FA4 8017B7A4 -O2 */
u8 handle_GO_Y(Obj *obj)
{
    obj->y_pos = obj->nb_cmd * 100 + obj->field24_0x3e;
    return true;
}

/* 56FD0 8017B7D0 -O2 */
u8 handle_GO_GOTO(Obj *obj)
{
    skipToLabel(obj, obj->nb_cmd, true);
    return false;
}

/* 56FF4 8017B7F4 -O2 */
u8 handle_GO_STATE(Obj *obj)
{
  set_main_etat(obj, obj->nb_cmd);
  obj->speed_x = 0;
  obj->speed_y = 0;
  return true;
}

/* 5702C 8017B82C -O2 */
u8 handle_GO_SUBSTATE(Obj *obj)
{
  set_sub_etat(obj, obj->nb_cmd);
  obj->speed_x = 0;
  obj->speed_y = 0;
  return true;
}

/* 57064 8017B864 -O2 */
u8 handle_GO_SKIP(Obj *obj)
{
    s16 length;
    s16 i;

    length = obj->nb_cmd;
    for (i = 0; i < length; i++)
        skipOneCommand(obj);
    return true;
}

/* 570D0 8017B8D0 -O2 */
u8 handle_GO_LABEL(Obj *obj)
{
    return true;
}

/* 570D8 8017B8D8 -O2 */
u8 handle_GO_PREPARELOOP(Obj *obj)
{
    pushCmdContext(obj, obj->nb_cmd);
    return true;
}

/* 570FC 8017B8FC -O2 */
u8 handle_GO_GOSUB(Obj *obj)
{
    pushCmdContext(obj, 1);
    skipToLabel(obj, obj->nb_cmd, true);
    return false;
}

/* 57138 8017B938 -O2 */
u8 handle_GO_RETURN(Obj *obj)
{
    popCmdContext(obj);
    return true;
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
    return true;
}

/* 571B8 8017B9B8 -O2 */
u8 handle_INVALID_CMD(Obj *obj)
{
  obj->cmd_offset = -1;
  return true;
}

/* 571C8 8017B9C8 -O2 */
u8 handle_GO_BRANCHTRUE(Obj *obj)
{
    if (obj->flags & FLG(OBJ_CMD_TEST))
    {
        skipToLabel(obj, obj->nb_cmd, true);
        return false;
    }
    return true;
}

/* 57204 8017BA04 -O2 */
u8 handle_GO_BRANCHFALSE(Obj *obj)
{
    if (!(obj->flags & FLG(OBJ_CMD_TEST)))
    {
        skipToLabel(obj, obj->nb_cmd, true);
        return false;
    }
    return true;
}

/* 57240 8017BA40 -O2 */
u8 handle_GO_SKIPTRUE(Obj *obj)
{
  s16 length;
  s16 i;
  
  if (obj->flags & FLG(OBJ_CMD_TEST))
  {
    length = obj->nb_cmd;
    for (i = 0; i < length; i++)
        skipOneCommand(obj);
  }
  return true;
}

/* 572C0 8017BAC0 -O2 */
u8 handle_GO_SKIPFALSE(Obj *obj)
{
  s16 length;
  s16 i;
  
  if (!(obj->flags & FLG(OBJ_CMD_TEST)))
  {
    length = obj->nb_cmd;
    for (i = 0; i < length; i++)
        skipOneCommand(obj);
  }
  return true;
}

/* 57344 8017BB44 -O2 */
u8 handle_GO_SETTEST(Obj *obj)
{
    u8 to_and;
    
    to_and = 1;
    obj->flags = obj->flags & ~FLG(OBJ_CMD_TEST) | (obj->nb_cmd & to_and) << OBJ_CMD_TEST;
    return true;
}

/* 5736C 8017BB6C -O2 */
u8 handle_GO_TEST(Obj *obj)
{
    s32 flip_x;

    switch (obj->nb_cmd)
    {
    case 70:
        if ((s16)OBJ_IN_ZONE(obj))
            obj->flags |= FLG(OBJ_CMD_TEST);
        else
            obj->flags &= ~FLG(OBJ_CMD_TEST);
        break;
    case 71:
        if (obj->flags & FLG(OBJ_FLAG_0))
            obj->flags |= FLG(OBJ_CMD_TEST);
        else
            obj->flags &= ~FLG(OBJ_CMD_TEST);
        break;
    case 72:
        if (!(obj->flags & FLG(OBJ_READ_CMDS)))
            obj->flags |= FLG(OBJ_CMD_TEST);
        else
            obj->flags &= ~FLG(OBJ_CMD_TEST);
        break;
    case 0:
        if ((obj->flags >> OBJ_FLIP_X & 1) == obj->field23_0x3c)
            obj->flags |= FLG(OBJ_CMD_TEST);
        else
            obj->flags &= ~FLG(OBJ_CMD_TEST);
        break;
    case 1:
        if ((s16) myRand(obj->field23_0x3c) == 0)
            obj->flags |= FLG(OBJ_CMD_TEST);
        else
            obj->flags &= ~FLG(OBJ_CMD_TEST);
        break;
    case 2:
        flip_x = obj->flags >> OBJ_FLIP_X & 1;
        calc_obj_dir(obj);
        if ((obj->flags >> OBJ_FLIP_X & 1) == obj->field23_0x3c)
            obj->flags |= FLG(OBJ_CMD_TEST);
        else
            obj->flags &= ~FLG(OBJ_CMD_TEST);
        obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (flip_x << OBJ_FLIP_X);
        break;
    case 3:
        if (obj->main_etat == obj->field23_0x3c)
            obj->flags |= FLG(OBJ_CMD_TEST);
        else
            obj->flags &= ~FLG(OBJ_CMD_TEST);
        break;
    case 4:
        if (obj->sub_etat == obj->field23_0x3c)
            obj->flags |= FLG(OBJ_CMD_TEST);
        else
            obj->flags &= ~FLG(OBJ_CMD_TEST);
        break;
    }
    return true;
}

/* 57528 8017BD28 -O2 */
u8 readOneCommand(Obj *obj)
{
    obj->cmd_offset++;
    obj->cmd = obj->cmds[obj->cmd_offset];
    return cptr_tab[obj->cmd].read(obj);
}

/* 57598 8017BD98 -O2 */
u8 skipOneCommand(Obj *obj)
{
    obj->cmd_offset++;
    obj->cmd = obj->cmds[obj->cmd_offset];
    return cptr_tab[obj->cmd].skip(obj);
}

/* 57608 8017BE08 -O2 */
void GET_OBJ_CMD(Obj *obj)
{
    if (obj->cmds)
    {
        if ((obj->flags & FLG(OBJ_READ_CMDS)) && --obj->nb_cmd == -1)
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
            obj->flags |= FLG(OBJ_READ_CMDS);
            GET_OBJ_CMD(obj);

            /* restore in_rd_cmd */
            obj->flags = obj->flags & ~FLG(OBJ_READ_CMDS) | (in_rd_cmd & to_and) << OBJ_READ_CMDS;
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
