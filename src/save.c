#include "save.h"

extern s16 VENT_X;
extern s16 VENT_Y;

/* 3F170 80163970 -O2 -msoft-float */
void initGameSave(void)
{
    save1.has_saved = false;
}

/* 3F180 80163980 -O2 -msoft-float */
void doneGameSave(void)
{
    save1.has_saved = false;
}

/* 3F190 80163990 -O2 -msoft-float */
void saveGameState(Obj *obj, SaveState *state)
{
    u8 i;
    s16 j;
    Obj *cur_obj;
    s16 nb_objs;
    s32 unk_1;
    s32 unk_2;

    state->num_wiz = status_bar.num_wiz;
    state->x_map = xmap;
    state->y_map = ymap;
    state->time = PS1_MoteurTime;
    state->ray_x_pos = ray.x_pos;
    state->ray_y_pos = ray.y_pos;
    state->ray_screen_x = ray.screen_x_pos;
    state->ray_screen_y = ray.screen_y_pos;
    state->ray_flip_x = ray.flags >> OBJ_FLIP_X & 1;
    state->rayevts_0 = (RayEvts.flags1 >> 5) & 3; /* RAYEVTS1_REVERSE and RAYEVTS1_FLAG6 */
    state->rayevts_1 = RayEvts.flags0 >> RAYEVTS0_SUPER_HELICO & 1;
    state->rayevts_2 = RayEvts.flags0 >> RAYEVTS0_POING & 1;
    if (obj)
    {
        state->save_obj_id = obj->id;
        state->save_obj_x_pos = obj->x_pos;
        state->save_obj_y_pos = obj->y_pos;
        state->save_obj_detect_zone_flag = obj->detect_zone_flag;
        state->field18_0x14b = obj->flags >> OBJ_FLAG_0 & 1;
    }
    else
        state->save_obj_id = -1;
    
    memcpy(state->link_init, link_init, level.nb_objects);
    
    for (i = 0; i < LEN(ray.btypes); i++)
        state->ray_btypes[i] = ray.btypes[i];
    state->ray_anim_index = ray.anim_index;
    state->ray_anim_frame = ray.anim_frame;
    state->ray_main_etat = ray.main_etat;
    state->ray_sub_etat = ray.sub_etat;
    
    for (i = 0; i < LEN(nb_floc); i++)
        state->nb_floc[i] = nb_floc[i];
    state->vent_x = VENT_X;
    state->vent_y = VENT_Y;
    state->poing_sub_etat = poing.sub_etat;

    j = 0;
    cur_obj = &level.objects[0];
    nb_objs = level.nb_objects;
    while (j < nb_objs)
    {
        if (cur_obj->type == TYPE_NEIGE || cur_obj->type == TYPE_GENERATING_DOOR)
        {
            unk_1 = (j << 0x10) >> 0x15;
            unk_2 = 1 << (j & 0x1F);
            if (cur_obj->flags & FLG(OBJ_ALIVE))
                state->triggered_objects[unk_1] |= unk_2;
            else
                state->triggered_objects[unk_1] &= ~unk_2;
        }
        j++;
        cur_obj++;
    }
    state->dead_time = dead_time;
    state->has_saved = true;

    __asm__("nop");
}

INCLUDE_ASM("asm/nonmatchings/save", restoreGameState);

INCLUDE_ASM("asm/nonmatchings/save", PS1_PhotographerCollision);

INCLUDE_ASM("asm/nonmatchings/save", get_offset_in_save_zone);

INCLUDE_ASM("asm/nonmatchings/save", reset_save_zone_level);

INCLUDE_ASM("asm/nonmatchings/save", take_bonus);

INCLUDE_ASM("asm/nonmatchings/save", bonus_taken);

INCLUDE_ASM("asm/nonmatchings/save", PS1_WriteWiSaveZone);

INCLUDE_ASM("asm/nonmatchings/save", PS1_LoadWiSaveZone);
