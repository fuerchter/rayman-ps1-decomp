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

void popCmdContext(Obj *obj);
s16 char2short(u8 in_char);

/* are return types correct? */
s32 readNoArg(void);
s32 readOneArg(Obj *obj);

s32 readGoXYArgs(Obj *obj);
s32 readSpeedArgs(Obj *obj);
s32 readInvalidArg(Obj *obj);
s32 skipNoArg(void);
s32 skipOneArg(Obj *obj);

s32 skipGoXYArgs(Obj *obj);
s32 skipSpeedArgs(Obj *obj);
s32 skipInvalidArg(Obj *obj);
s32 handle_GO_WAITSTATE(Obj *obj);

s32 handle_RESERVED_GO_SKIP_and_RESERVED_GO_GOTO(Obj *obj);
s32 handle_RESERVED_GO_BRANCHTRUE(Obj *obj);
s32 handle_RESERVED_GO_BRANCHFALSE(Obj *obj);
s32 handle_RESERVED_GO_SKIPTRUE(Obj *obj);
s32 handle_RESERVED_GO_SKIPFALSE(Obj *obj);
s32 handle_SELF_HANDLED(void);
s32 handle_GO_X(Obj *obj);

#endif