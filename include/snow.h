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
extern s16 tot_nb_flocs[8];
extern s16 invpx0[8];
extern s16 invpx320[8];
extern s16 invpy0[8];
extern s16 invpy200[8];
extern s16 SNSEQ_len[64];
extern s16 SNSEQ_no;
extern s16 SNSEQ_ptr;
extern s16 SNSEQ_list[256];
extern s16 SNSEQ_list_ptr;

void add_one_floc(void);
void add_256_flocs(void);
void sub_one_floc(void);
void init_flocons(void);
void do_flocons(s16 param_1, s16 param_2, s16 param_3, s16 param_4);
void set_snow_sequence(u16 param_1, s16 param_2); /* param_1 likely s16, therefore SNSEQ_list also s16? */
void set_SNSEQ_list(s16 param_1);
void DO_SNOW_SEQUENCE(void);

#endif