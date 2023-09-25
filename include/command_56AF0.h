#ifndef COMMAND_56AF0_H
#define COMMAND_56AF0_H

#include "common.h"
typedef struct Obj Obj;

typedef struct {
    s16 cmd_offset;
    u16 count;
} CmdContext;

typedef enum {
    GO_LEFT=0,
    GO_RIGHT=1,
    GO_WAIT=2,
    GO_UP=3,
    GO_DOWN=4,
    GO_SUBSTATE=5,
    GO_SKIP=6,
    GO_ADD=7,
    GO_STATE=8,
    GO_PREPARELOOP=9,
    GO_DOLOOP=10,
    GO_LABEL=11,
    GO_GOTO=12,
    GO_GOSUB=13,
    GO_RETURN=14,
    GO_BRANCHTRUE=15,
    GO_BRANCHFALSE=16,
    GO_TEST=17,
    GO_SETTEST=18,
    GO_WAITSTATE=19,
    GO_SPEED=20,
    GO_X=21,
    GO_Y=22,
    RESERVED_GO_SKIP=23,
    RESERVED_GO_GOTO=24,
    RESERVED_GO_GOSUB=25,
    RESERVED_GO_GOTOT=26,
    RESERVED_GO_GOTOF=27,
    RESERVED_GO_SKIPT=28,
    RESERVED_GO_SKIPF=29,
    GO_NOP=30,
    GO_SKIPTRUE=31,
    GO_SKIPFALSE=32,
    INVALID_CMD=33
} ObjCommand;

typedef struct {
    u8 (* read)(Obj *);
    u8 (* skip)(Obj *);
    u8 (* handle)(Obj *);
} CommandTableEntry;

#endif