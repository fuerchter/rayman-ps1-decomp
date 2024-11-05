#ifndef NUM_LEVEL_36260_H
#define NUM_LEVEL_36260_H

#include "common.h"
#include "common/ray.h"
#include "common/world_map.h"
#include "moteur_init_end.h"
#include "world_map_677C0.h"
#include "cam_scroll_340A4.h"
#include "ray/ray_5D190.h"
#include "main_moteur.h"
#include "unknown/3F0B8.h"

typedef struct FinBosslevel
{
    u8 bzzit : 1;
    u8 moskito : 1;
    u8 mr_sax : 1;
    u8 mr_stone : 1;
    u8 viking_mama : 1;
    u8 space_mama : 1;
    u8 mr_skops : 1;
    u8 mr_dark : 1;

    u8 crazy_drummer : 1;
    u8 helped_joe_1 : 1;
    u8 helped_joe_2 : 1;
    u8 helped_musician : 1;
} FinBosslevel;

/**/
extern s16 departlevel;
extern FinBosslevel finBosslevel;
extern u8 fin_boss;

void new_level_init(void);
void fix_numlevel(Obj *obj);
void TEST_SIGNPOST(void);

#endif