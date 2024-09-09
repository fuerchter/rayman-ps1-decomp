#ifndef SNOW_H
#define SNOW_H

#include "common.h"
#include "collision/block_22C84.h"

typedef struct FloconTableEntry
{
    s16 field0_0x0;
    s16 field1_0x2;
    s16 field2_0x4;
    u8 field3_0x6;
    u8 field4_0x7;
} FloconTableEntry;

/**/
extern s16 floc_ind[8];
extern FloconTableEntry flocon_tab[512];
extern s16 nb_floc[8];
extern s16 VENT_X;
extern s16 VENT_Y;

void add_one_floc(void);
void add_256_flocs(void);
void sub_one_floc(void);
void init_flocons(void);
void do_flocons(s16 param_1, s16 param_2, s16 param_3, s16 param_4);
void set_snow_sequence(u16 param_1, s16 param_2);
void set_SNSEQ_list(s16 param_1);
void DO_SNOW_SEQUENCE(void);

#endif