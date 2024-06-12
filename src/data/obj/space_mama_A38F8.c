#include "obj/space_mama.h"

s16 droppedBombLine0[] = { 8, 8, 8, 8, 8, 8, 8, 8 };
s16 droppedBombLine1[] = { 2, 8, 8, 8, 8, 8, 8, 6 };
s16 droppedBombLine2[] = { 0, 0, 0, 0, 8, 0, 0, 0 };
s16 droppedBombLine3[] = { 7, 8, 8, 0, 0, 8, 8, 1 };
s16 droppedBombLine4[] = { 8, 8, 1, 8, 8, 7, 8, 8 };
s16 droppedBombLine5[] = { 0, 0, 0, 0, 0, 0, 0, 8 };
s16 droppedBombLine6[] = { 0, 0, 0, 0, 0, 8, 0, 0 };
s16 droppedBombLine7[] = { 8, 7, 8, 8, 8, 8, 1, 8 };
s16 droppedBombLine8[] = { 7, 8, 8, 8, 8, 8, 8, 1 };
s16 droppedBombLine9[] = { 7, 8, 8, 8, 8, 8, 8, 8 };
s16 droppedBombLineA[] = { 8, 7, 8, 8, 8, 8, 8, 8 };
s16 droppedBombLineB[] = { 8, 8, 7, 8, 8, 8, 8, 8 };
s16 *droppedBombSequence1[] =
{
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine1
};
s16 *droppedBombSequence2[] =
{
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine6
};
s16 *droppedBombSequence3[] =
{
    droppedBombLine0,
    droppedBombLineB,
    droppedBombLine0,
    droppedBombLineA,
    droppedBombLine0,
    droppedBombLine9,
    droppedBombLine0,
    droppedBombLine0
};
s16 *droppedBombSequence4[] =
{
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine3,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0
};
s16 *droppedBombSequence5[] =
{
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine4,
    droppedBombLine0,
    droppedBombLine1,
    droppedBombLine0
};
s16 *droppedBombSequence6[] =
{
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine5,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0
};
s16 *droppedBombSequence7[] =
{
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine0,
    droppedBombLine2,
    droppedBombLine0
};
s16 **bombSequences[] =
{
    droppedBombSequence1,
    droppedBombSequence2,
    droppedBombSequence3,
    droppedBombSequence4,
    droppedBombSequence5,
    droppedBombSequence6,
    droppedBombSequence7
};
u8 mereDenisDyingSequence[] = { 42, 46, 5, 0 };
u8 mereDenisMachineHitSequence[] = { 44, 2, 0, 0 };
u8 mereDenisHitSequence[] = { 40, 2, 0, 0 };
u8 mereDenisArrivalSequence[] = { 7, 8, 12, 38, 13, 14, 0, 0 };
u8 mereDenisEncounter1[] = { 41, 15, 16, 41, 26, 18, 19, 1 };
u8 mereDenisEncounter2[] = { 21, 22, 45, 24, 41, 26, 18, 19, 1, 0, 0, 0 };
u8 mereDenisEncounter3[] =
{
   27,  28,   0,   0,  29,  28,  32, 254,  29,  28, 
    0,   1,  29,  28,  32, 254,  29,  28,  16,   2, 
   29,  28,  16,   2,  29,  28,  48,   3,  29,  28, 
    0,   4,  29,  28,  92,   5,  29,  28,  54,   5, 
   29,  28,  16,   5,  29,  28,   0,   6,  29,  30, 
   24,  41,  26,  18,  19,   0
};
u8 mereDenisGoBehindMachine[] = { 21, 22, 25, 31, 0, 0, 0, 0 };
u8 mereDenisBehindMachine[] =
{
   36,  35,  43,   1,  34,  36,  34,  33,   1,  35, 
   36,  35,  43,   1,  34,  34,  33,   1,  35,  35, 
   43,   2,  34,  34,  33,   1,  35,  35,  43,   2, 
   34,  32,   1,  34,  33,   3,  35,  35,  43,   1, 
   34,  34,  33,   3,  35,  35,  43,   1,  34,  34, 
   33,   3,  35,  35,  43,   3,  34,   1,   0,   0
};
u8 mereDenisMachineFlies[] = { 37, 39, 0, 0 };
u8 mereDenisMedley[] =
{
   45,  24,  41,  26,  18,  19,  27,  28,  16, 255, 
   29,  45,  24,  41,  26,  18,  18,  19,  21,  22, 
   28,  32, 254,  29,   1,   0,   0,   0
};
u8 *mereDenisActionSequences[] =
{
    mereDenisArrivalSequence,
    mereDenisEncounter1,
    mereDenisEncounter2,
    mereDenisEncounter3,
    mereDenisGoBehindMachine,
    mereDenisBehindMachine,
    mereDenisMachineFlies,
    mereDenisMedley,
    mereDenisHitSequence,
    mereDenisMachineHitSequence,
    mereDenisDyingSequence
};