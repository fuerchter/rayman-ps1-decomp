#include "obj/saxo.h"

/*
only when building WITHOUT MISSING_ADDIU (since we have allocateNote in c otherwise)

mips-linux-gnu-ld: build/src/obj/saxo.c.o: in function `allocateNote':
src/obj/saxo.c:(.text+0xbdc): undefined reference to `D_801C7DA8'
mips-linux-gnu-ld: src/obj/saxo.c:(.text+0xbe0): undefined reference to `D_801C7DA8'
*/
SaxNoteEntry atak[] =
{
  {.type = 0, .speed_x = 1, .speed_y = -1, .initial_iframes = 0, .field4_0x8 = 0},
  {.type = 1, .speed_x = 1, .speed_y = -3, .initial_iframes = 60, .field4_0x8 = 0},
  {.type = 2, .speed_x = 2, .speed_y = -2, .initial_iframes = 0, .field4_0x8 = 0},
  {.type = 1, .speed_x = 3, .speed_y = -4, .initial_iframes = 30, .field4_0x8 = 0},
  {.type = 1, .speed_x = 2, .speed_y = -4, .initial_iframes = 30, .field4_0x8 = 0},
  {.type = 1, .speed_x = 2, .speed_y = -3, .initial_iframes = 42, .field4_0x8 = 0},
  {.type = 1, .speed_x = 1, .speed_y = -4, .initial_iframes = 80, .field4_0x8 = 0}
};

SaxAttackEntry SerieDatak[4][11] =
{
  {
    {.next_note = 1, .time = 1, .end = false},
    {.next_note = 3, .time = 0xFF, .end = false},
    {.next_note = 1, .time = 1, .end = false},
    {.next_note = 0, .time = 0, .end = true},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
  },
  {
    {.next_note = 9, .time = 0, .end = false},
    {.next_note = 1, .time = 0, .end = false},
    {.next_note = 3, .time = 0xFF, .end = false},
    {.next_note = 5, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = true},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
  },
  {
    {.next_note = 2, .time = 1, .end = false},
    {.next_note = 7, .time = 0, .end = false},
    {.next_note = 2, .time = 0, .end = false},
    {.next_note = 8, .time = 0, .end = false},
    {.next_note = 1, .time = 0xFF, .end = false},
    {.next_note = 0, .time = 0, .end = true},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
  },
  {
    {.next_note = 3, .time = 0xFF, .end = false},
    {.next_note = 4, .time = 0xFF, .end = false},
    {.next_note = 6, .time = 1, .end = false},
    {.next_note = 9, .time = 0, .end = false},
    {.next_note = 2, .time = 0, .end = false},
    {.next_note = 2, .time = 0, .end = false},
    {.next_note = 9, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 9, .time = 0, .end = true},
    {.next_note = 0, .time = 0, .end = false},
    {.next_note = 0, .time = 0, .end = false},
  }
};