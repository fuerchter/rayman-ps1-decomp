#include "obj/corde_command.h"

#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/corde_command", DO_CORDE_COMMAND);
#else
/* matches, but... */
/*INCLUDE_ASM("asm/nonmatchings/obj/corde_command", DO_CORDE_COMMAND);*/

void DO_CORDE_COMMAND(Obj *obj)
{
    s32 pa_id;
    s32 bVar2;
    s16 obj_x_pos;
    s16 obj_y_pos;
    s16 ray_x_pos;
    s16 sVar4;
    s16 ray_y_pos;
    u8 obj_y_offs;
    u8 obj_h;
    s16 inter;
    u8 hp;

    pa_id = pierreAcorde_obj_id;
    if (pa_id != -1)
    {
        if (obj->main_etat == 0)
        {
            if (obj->x_pos < level.objects[pa_id].x_pos)
                obj->y_pos = level.objects[pa_id].y_pos + 112;
            else
                obj->y_pos = level.objects[pa_id].y_pos + 120;
        }

        if (ray.main_etat == 2 && ray.sub_etat == 15)
        {
            /* TODO: ... */
            ray_y_pos = obj->y_pos;

            obj_x_pos = obj->x_pos;
            obj_y_pos = obj->y_pos;
            bVar2 = ray.x_pos;
            ray_x_pos = bVar2;
            ray_y_pos = ray.y_pos;
            bVar2 = true;
            switch (obj->sub_etat)
            {
            case 16:
                obj_y_offs = 48;
                obj_h = 24;
                break;
            case 17:
                obj_y_offs = 48;
                obj_h = 32;
                break;
            case 18:
            case 19:
                obj_y_offs = 56;
                obj_h = 40;
                break;
            case 20:
                obj_y_offs = 56;
                obj_h = 64;
                break;
            default:
                bVar2 = false;
                break;
            }
            if (
                bVar2 << 0x10 && /* TODO: type? */
                inter_box(
                    ray_x_pos + 57, ray_y_pos + 26, 46, 4,
                    obj_x_pos + 126, obj_y_pos + obj_y_offs, 4, obj_h
                )
            )
            {
                if (--obj->hit_points == 0)
                {
                    obj->hit_points = obj->init_hit_points;
                    if (obj->sub_etat < 19)
                        set_sub_etat(obj, obj->sub_etat + 1);
                    else
                        DO_CORDE_CASSE(obj);
                }

                if (level.objects[pierreAcorde_obj_id].iframes_timer == 0)
                    DO_FUMEE_CORDE(obj_x_pos + 128, ray_y_pos + 30);

                level.objects[pierreAcorde_obj_id].field23_0x3c = 0;
                return;
            }
        }
        level.objects[pierreAcorde_obj_id].field23_0x3c++;
    }
}
const u8 rodata_DO_CORDE_COMMAND[4] = {};
#endif

/* 4FDF4 801745F4 -O2 -msoft-float */
/*? set_main_and_sub_etat(Obj *, ?, ?);*/

void DO_PAC_COMMAND(Obj *obj)
{
    if (obj->hit_points == 0)
    {
        if (obj->x_pos < (ray.x_pos + 47) && (obj->x_pos + 186) > ray.x_pos)
        {
            obj->hit_points = 10;
            set_main_and_sub_etat(obj, 2, 4);
        }
    }
    if (obj->hit_points >= 2)
    {
        if (obj->speed_y < 16)
        {
            if (horloge[8] == 0)
                obj->speed_y++;
        }
        else if (horloge[16] == 0)
            obj->y_pos++;
    }
    else
        obj->speed_y = 0;

    if (obj->field23_0x3c >= 2)
        obj->iframes_timer = 0;
    else
        obj->iframes_timer = 1;
    obj->field23_0x3c = 0;
}

/* 4FEF8 801746F8 -O2 -msoft-float */
void DO_CFUMEE_COMMAND(Obj *obj)
{
    obj->y_pos = ray.y_pos + -98;
    if (
        obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1 &&
        horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0 &&
        level.objects[pierreAcorde_obj_id].iframes_timer == 0
    )
    {
        obj->flags &= ~FLG(OBJ_ALIVE);
        obj->flags &= ~FLG(OBJ_ACTIVE);
    }
}