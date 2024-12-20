#include "obj/dark2_pink_fly.h"

#ifdef BSS_DEFS
s16 PosArXToon1;
s16 PosArXToon2;
s16 PosArYToon1;
s16 PosArYToon2;
u8 ToonJustGivePoing;
#endif

/* 78004 8019C804 -O2 -msoft-float */
void AllocateToons(void)
{
    s16 unk_1 = -1;
    s16 unk_2 = 0;
    s16 i = 0;
    Obj *cur_obj = &level.objects[i];
    s16 nb_objs = level.nb_objects;

    while (i < nb_objs)
    {
        if (
            unk_2 == 0 &&
            cur_obj->type == TYPE_DARK2_PINK_FLY && !(cur_obj->flags & FLG(OBJ_ACTIVE))
        )
        {
            cur_obj->display_prio = 4;
            cur_obj->init_x_pos =
            cur_obj->x_pos =
                SCREEN_WIDTH;
            cur_obj->init_y_pos = 
            cur_obj->y_pos =
                ymap + 100;
            cur_obj->speed_x = 0;
            cur_obj->speed_y = 0;
            cur_obj->hit_points = 0;
            cur_obj->field23_0x3c = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE);

            unk_1 = i;
            unk_2 = 1;
        }
        else if (
            unk_2 == 1 &&
            cur_obj->type == TYPE_DARK2_PINK_FLY && !(cur_obj->flags & FLG(OBJ_ACTIVE))
        )
        {
            cur_obj->display_prio = 4;
            cur_obj->init_x_pos = 
            cur_obj->x_pos =
                -20;
            cur_obj->init_y_pos = 
            cur_obj->y_pos =
                ymap + 100;
            cur_obj->speed_x = 0;
            cur_obj->speed_y = 0;
            cur_obj->hit_points = 1;
            cur_obj->field23_0x3c = 0;
            cur_obj->flags |= FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE);

            cur_obj->field24_0x3e = unk_1;
            level.objects[unk_1].field24_0x3e = i;
            break;
        }
        i++;
        cur_obj++;
    }
}

/* 78170 8019C970 -O2 -msoft-float */
#ifndef MATCHES_BUT
INCLUDE_ASM("asm/nonmatchings/obj/dark2_pink_fly", DO_DARK2_TOONS_COMMAND);
#else
/* more to clean up */
void DO_DARK2_TOONS_COMMAND(Obj *d2fly_obj)
{
    Obj *poing_obj_1;
    s16 diff_x; s16 diff_y;
    s16 ray_x; s16 ray_y;
    Obj *poing_obj_2;
    s16 dist;
    Obj *unk_obj;

    poing_obj_1 = &level.objects[poing_obj_id];
    if (d2fly_obj->hit_points == 0)
    {
        diff_x = PosArXToon1 - (d2fly_obj->x_pos + d2fly_obj->offset_bx);
        diff_y = PosArYToon1 - (d2fly_obj->y_pos + d2fly_obj->offset_by);
    }
    else
    {
        diff_x = PosArXToon2 - (d2fly_obj->x_pos + d2fly_obj->offset_bx);
        diff_y = PosArYToon2 - (d2fly_obj->y_pos + d2fly_obj->offset_by);
    }

    /*
    TODO:
    replace level.objects[d2fly_obj->field24_0x3e] ???
    look at ToonDonnePoing?
    */
    if (
        d2fly_obj->field23_0x3c != 0 &&
        level.objects[d2fly_obj->field24_0x3e].field23_0x3c != 0
    )
    {
        if (d2fly_obj->flags & FLG(OBJ_ACTIVE))
        {
            if (level.objects[d2fly_obj->field24_0x3e].flags & FLG(OBJ_ACTIVE))
            {
                poing_obj_1->x_pos = 
                    ((
                        d2fly_obj->x_pos + d2fly_obj->offset_bx +
                        level.objects[d2fly_obj->field24_0x3e].x_pos + level.objects[d2fly_obj->field24_0x3e].offset_bx
                    ) >> 1) - poing_obj_1->offset_bx;
                poing_obj_1->y_pos =
                    ((
                        d2fly_obj->y_pos + d2fly_obj->offset_by +
                        level.objects[d2fly_obj->field24_0x3e].y_pos + level.objects[d2fly_obj->field24_0x3e].offset_by
                    ) >> 1) - poing_obj_1->offset_by;
            }
            else
            {
                poing_obj_1->x_pos = (d2fly_obj->x_pos + d2fly_obj->offset_bx) - poing_obj_1->offset_bx;
                poing_obj_1->y_pos = (d2fly_obj->y_pos + d2fly_obj->offset_by) - poing_obj_1->offset_by;
            }
        }
        else
        {
            if (level.objects[d2fly_obj->field24_0x3e].flags & FLG(OBJ_ACTIVE))
            {
                poing_obj_1->x_pos = (level.objects[d2fly_obj->field24_0x3e].offset_bx + level.objects[d2fly_obj->field24_0x3e].x_pos) - poing_obj_1->offset_bx;
                poing_obj_1->y_pos = (level.objects[d2fly_obj->field24_0x3e].offset_by + level.objects[d2fly_obj->field24_0x3e].y_pos) - poing_obj_1->offset_by;
                /*temp_v0 = &level.objects[d2fly_obj->field24_0x3e];
                poing_obj->y_pos = (temp_v0->offset_by + temp_v0->y_pos) - poing_obj->offset_by;*/
            }
        }

        /* get both ray_x, ray_y first? */
        ray_x = ray.x_pos + ray.offset_bx;
        PosArXToon1 = (d2fly_obj->offset_bx >> 1) + ray_x;
        ray_y = ray.y_pos + (ray.offset_by >> 1);
        PosArYToon1 = ray_y;
        PosArXToon2 = ray_x - (d2fly_obj->offset_bx >> 1);
        PosArYToon2 = ray_y;
    }
    else
    {
        if (!RayEvts.poing)
        {
            poing_obj_2 = &level.objects[poing_obj_id];
            PosArXToon1 = poing_obj_2->x_pos + 64;
            PosArYToon1 = poing_obj_2->y_pos + 50;
            PosArXToon2 = poing_obj_2->x_pos + 48;
            PosArYToon2 = poing_obj_2->y_pos + 50;
        }
    }

    dist = __builtin_abs(diff_x) + __builtin_abs(diff_y);
    if (dist < 2)
    {
        if (d2fly_obj->field23_0x3c == 0)
        {
            d2fly_obj->field23_0x3c = 1;
            unk_obj = &level.objects[d2fly_obj->field24_0x3e];
            if (!(unk_obj->flags & FLG(OBJ_ACTIVE)))
                unk_obj->field23_0x3c = 1;
        }
    }
    if (dist > 0)
    {
        diff_x = ashl16(diff_x, 5) / dist;
        diff_y = ashl16(diff_y, 5) / dist;
    }

    d2fly_obj->speed_y = MAX_1(-40, MIN_1(40,
        SGN(diff_y - d2fly_obj->speed_y) + d2fly_obj->speed_y));
    d2fly_obj->speed_x = MAX_1(-40, MIN_1(40,
        SGN(diff_x - d2fly_obj->speed_x) + d2fly_obj->speed_x));

    if (d2fly_obj->speed_x > 0 && !(d2fly_obj->flags & FLG(OBJ_FLIP_X)))
        d2fly_obj->flags |= FLG(OBJ_FLIP_X);
    else if (d2fly_obj->speed_x < 0 && d2fly_obj->flags & FLG(OBJ_FLIP_X))
        d2fly_obj->flags &= ~FLG(OBJ_FLIP_X);

    if (d2fly_obj->y_pos < ymap - 200)
    {
        d2fly_obj->flags &= ~FLG(OBJ_ALIVE);
        d2fly_obj->flags &= ~FLG(OBJ_ACTIVE);
    }
}
#endif

/* 78870 8019D070 -O2 -msoft-float */
void ToonDonnePoing(Obj *d2fly_obj)
{
    Obj *poing_obj;
    s16 *unk_1 = &d2fly_obj->field24_0x3e;

    if (d2fly_obj->field23_0x3c != 0 && level.objects[*unk_1].field23_0x3c != 0)
    {
        RayEvts.poing = true;
        PosArXToon1 = 10;
        PosArXToon2 = 300;
        poing_obj = &level.objects[poing_obj_id];
        d2fly_obj->field23_0x3c = 0;
        level.objects[*unk_1].field23_0x3c = 0;
        PosArYToon2 =
        PosArYToon1 =
            ymap - 200;
        DO_NOVA(poing_obj);
        ToonJustGivePoing = 1;
        poing_obj->init_sub_etat = 8;
        poing_obj->flags &= ~FLG(OBJ_ACTIVE);
        poing_obj->flags &= ~FLG(OBJ_ALIVE);
    }
}
