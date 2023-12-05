#ifndef OBJ_UTIL_H
#define OBJ_UTIL_H

#include "common.h"
#include "common/obj.h"
#include "common/ray.h"
#include "obj_init_kill.h"
#include "ray/ray_32398.h"

/* .data */
extern s16 PS1_Toon_Speeds_x[8]; /* not sure if 7 or 8 in size */
extern s16 PS1_Toon_Speeds_y[8];

/**/
extern u8 lidol_to_allocate;
extern Obj *lidol_source_obj;

void init_obj_in_the_air(Obj *obj);
void make_my_fruit_go_down(Obj *obj, s16 to_add_x);
void allocate_toons(Obj *src_obj, u8 count);
void special_flags_init(void);
void switchOff(Obj *obj);
void obj_hurt(Obj *obj);
void Projectil_to_RM(Obj *obj, s16 *speed_x, s16 *speed_y, s16 param_4, s16 param_5);
void del_actobj(Obj *param_1);

#endif