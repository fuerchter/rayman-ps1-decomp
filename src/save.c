#include "save.h"

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
    state->rayevts_0 = RayEvts.reverse; /* RAYEVTS1_REVERSE and RAYEVTS1_FLAG6 */
    state->rayevts_1 = RayEvts.super_helico;
    state->rayevts_2 = RayEvts.poing;
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
}

INCLUDE_ASM("asm/nonmatchings/save", restoreGameState);

/* 3F9C0 801641C0 -O2 -msoft-float */
void PS1_PhotographerCollision(void)
{
    s16 i = 0;
    Obj *cur_obj = &level.objects[actobj.objects[i]];
    
    while (i < actobj.num_active_objects)
    {
        if (cur_obj->type == TYPE_PHOTOGRAPHE)
        {
            if (cur_obj->sub_etat == 1)
            {
                if (++cur_obj->timer == 0)
                    cur_obj->timer++;
            }
            else
            {
                if (cur_obj->timer != 0)
                {
                    ray.flags |= FLG(OBJ_ACTIVE);
                    restore_gendoor_link();
                    saveGameState(cur_obj, &save1);
                    correct_gendoor_link();
                    cur_obj->timer = 0;
                }
                else
                {
                    if (
                        !RayEvts.demi && !(cur_obj->flags & FLG(OBJ_FLAG_0)) && (s16) OBJ_IN_ZONE(cur_obj) &&
                        ray.field20_0x36 == -1 && decalage_en_cours == 0 &&
                        ray.main_etat == 0 && ray.sub_etat == 0 &&
                        inter_box(
                            (s16) (cur_obj->x_pos + 42), (s16) (cur_obj->y_pos + 48), 5, 15,
                            ray_zdc_x, ray_zdc_y, ray_zdc_w, ray_zdc_h
                        )
                    )
                    {
                        ray.speed_x = 0;
                        cur_obj->flags |= FLG(OBJ_FLAG_0);
                        ray.flags &= ~FLG(OBJ_ACTIVE);
                        skipToLabel(cur_obj, 0, true);
                    }
                }

            }
        }
        i++;
        cur_obj = &level.objects[actobj.objects[i]];
    }
}

/* 3FC20 80164420 -O2 -msoft-float */
s16 get_offset_in_save_zone(s16 event_index)
{
    s16 unk_1 = 0;
    s16 i = 1;
    while (i < num_world)
    {
        unk_1 += nb_levels_in_world[i] * 32;
        i++;
    }

    i = 1;
    while (i < num_level)
    {
        unk_1 += 32;
        i++;
    }

    return (unk_1 + ashr16(event_index, 3));
}

/* 3FCE4 801644E4 -O2 -msoft-float */
void reset_save_zone_level(void)
{
    memset(&save_zone[get_offset_in_save_zone(0)], 0, 32);
}

/* 3FD24 80164524 -O2 -msoft-float */
void take_bonus(s16 event_index)
{
    save_zone[get_offset_in_save_zone(event_index)] |= ashr16(1 << 7, event_index & 7);
}

/* 3FD98 80164598 -O2 -msoft-float */
u8 bonus_taken(s16 event_index)
{
    return save_zone[get_offset_in_save_zone(event_index)] & ashr16(1 << 7, event_index & 7);
}

INCLUDE_ASM("asm/nonmatchings/save", PS1_WriteWiSaveZone);

INCLUDE_ASM("asm/nonmatchings/save", PS1_LoadWiSaveZone);