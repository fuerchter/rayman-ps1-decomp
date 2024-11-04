#ifndef MOTEUR_INIT_END
#define MOTEUR_INIT_END

#include "common.h"
#include "common/rayconst.h"
#include "common/obj.h"
#include "obj_update.h"
#include "obj/scorpion.h"
#include "bonus_372E0.h"
#include "unknown/2539C.h"

/**/
extern s16 bonus_map;
extern s16 xmapmax;
extern s16 ymapmax;
extern Obj rms;
extern s16 ray_X_main_pos_init;
extern s16 ray_Y_main_pos_init;
extern s16 xmapsave;
extern s16 ymapsave;
extern u8 D_801F75C0;
extern u8 NewMs;

void INIT_MOTEUR(u8 new_lvl);
void INIT_MOTEUR_BEGIN(void);
void INIT_MOTEUR_WORLD(void);
void INIT_MOTEUR_LEVEL(s16 new_lvl);
void restore_gendoor_link(void);
void DONE_MOTEUR_LEVEL(void);
void INIT_MOTEUR_DEAD(void);
void INIT_RAY_ON_MS(u8 *new_ms);

#endif