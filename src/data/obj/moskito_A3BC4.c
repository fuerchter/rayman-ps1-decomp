#include "obj/moskito.h"

u8 dyingSequence[] = { 16, 23, 24, 22, 25, 0, 0, 0 };
u8 hitSequence[] = { 16, 17, 15, 26, 11, 5, 0, 0 };
u8 arrivalSequence[] = { 13, 26, 14, 3 };
u8 firstEncounterSequence[] =
{
    13,  26,  14,   4,  19,  21,   4,  20,  18,  21, 
    4,  20,  19,  21,   4,  20,  18,  21,   4,  20, 
    10,  26,  14,   4,  18,  21,   4,  20,  10,  26, 
    14,   4,  19,  21,   4,  20,  10,  26,  14,   2
};
u8 secondEncounterSequence1[] =
{
    13, 26, 14, 4, 7, 0, 7, 0, 10, 26, 
    14, 4, 3, 0, 0, 0
};
u8 secondEncounterSequenceSuite[] =
{
    7, 4, 7, 8, 10, 26, 14, 13, 26, 14, 4, 2
};
u8 secondEncounterSequence2[] =
{
    8,   0,   8,   0,   8,   0,   8,   4,  18,  21, 
    4,  20,  19,  21,   4,  20,  10,  26,  14,   4, 
    2,   0,   0,   0
};
u8 secondEncounterSequence3[] =
{
    9, 0, 18, 21, 4, 20, 9, 4, 18, 21, 
    4, 20, 10, 26, 14, 13, 14, 4, 2, 0
};
u8 secondEncounterSequence4[] =
{
    7,   8,   8,   8,   9,   0,  19,  21,   4,  20, 
    9,   8,  18,  21,   4,  20,  10,  26,  14,   4, 
    2,   0,   0,   0
};
u8 *moskitoActionSequences[] =
{
    arrivalSequence,
    firstEncounterSequence,
    arrivalSequence,
    secondEncounterSequence1,
    secondEncounterSequenceSuite,
    secondEncounterSequence2,
    secondEncounterSequence3,
    secondEncounterSequence4,
    hitSequence,
    dyingSequence
};