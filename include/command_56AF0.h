#ifndef COMMAND_56AF0_H
#define COMMAND_56AF0_H

#include "common.h"
#include "obj_update.h"

typedef struct CommandTableEntry
{
    u8 (* read)(Obj *);
    u8 (* skip)(Obj *);
    u8 (* handle)(Obj *);
} CommandTableEntry;

extern CommandTableEntry cptr_tab[34];

void popCmdContext(Obj *obj);
s16 char2short(u8 in_char);
u8 readNoArg(void);
u8 readOneArg(Obj *obj);
u8 readTestArgs(Obj *obj);
u8 readGoXYArgs(Obj *obj);
u8 readSpeedArgs(Obj *obj);
u8 readInvalidArg(Obj *obj);
u8 skipNoArg(void);
u8 skipOneArg(Obj *obj);
u8 skipTestArgs(Obj *obj);
u8 skipGoXYArgs(Obj *obj);
u8 skipSpeedArgs(Obj *obj);
u8 skipInvalidArg(Obj *obj);
u8 handle_GO_WAITSTATE(Obj *obj);
u8 handle_RESERVED_GO_GOSUB(Obj *obj);
u8 handle_RESERVED_GO_SKIP_and_RESERVED_GO_GOTO(Obj *obj);
u8 handle_RESERVED_GO_BRANCHTRUE(Obj *obj);
u8 handle_RESERVED_GO_BRANCHFALSE(Obj *obj);
u8 handle_RESERVED_GO_SKIPTRUE(Obj *obj);
u8 handle_RESERVED_GO_SKIPFALSE(Obj *obj);
u8 handle_SELF_HANDLED(void);
u8 handle_GO_X(Obj *obj);
u8 handle_GO_Y(Obj *obj);
u8 handle_GO_GOTO(Obj *obj);
u8 handle_GO_STATE(Obj *obj);
u8 handle_GO_SUBSTATE(Obj *obj);
u8 handle_GO_SKIP(Obj *obj);
u8 handle_GO_LABEL(void);
u8 handle_GO_PREPARELOOP(Obj *obj);
u8 handle_GO_GOSUB(Obj *obj);
u8 handle_GO_RETURN(Obj *obj);
u8 handle_GO_DOLOOP(Obj *obj);
u8 handle_INVALID_CMD(Obj *obj);
u8 handle_GO_BRANCHTRUE(Obj *obj);
u8 handle_GO_BRANCHFALSE(Obj *obj);
u8 handle_GO_SKIPTRUE(Obj *obj);
u8 handle_GO_SKIPFALSE(Obj *obj);
u8 handle_GO_SETTEST(Obj *obj);
u8 handle_GO_TEST(Obj *obj);
u8 readOneCommand(Obj *arg0);
u8 skipOneCommand(Obj *obj);
void GET_OBJ_CMD(Obj *obj);
void pushCmdContext(Obj *obj,u16 count);
void skipToLabel(Obj *obj, u8 label, u8 skip_label_cmd);
void pushToLabel(Obj *obj, u8 label, u8 skip_label_cmd);

#endif