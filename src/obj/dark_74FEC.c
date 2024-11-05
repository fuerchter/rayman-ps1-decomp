#include "obj/dark_74FEC.h"

/* 74FEC 801997EC -O2 -msoft-float */
void allocateSTOSKO(void)
{
    s16 y;
    Obj *obj = &level.objects[stosko_obj_id];

    obj->flags |= FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE);
    obj->x_pos = 160;
    obj->y_pos = ymap - 50;
    y = firstFloorBelow(obj) - obj->offset_by;
    obj->init_y_pos = y;
    obj->y_pos = y;
    obj->x_pos = xmapmax + SCREEN_WIDTH;
    obj->init_x_pos = xmap - obj->offset_bx + 260;
    obj->timer = 50;
    obj->flags &= ~FLG(OBJ_FLIP_X);
    RayEvts.poing = true;
    level.objects[poing_obj_id].init_sub_etat = 8;
}

/* 750E0 801998E0 -O2 -msoft-float */
void allocateMOSKITOMAMA(void)
{
    s16 unk_1;
    Obj *boss_obj;

    unk_1 = 90;
    YPosBBF2D =
        (NiveauSol - (ray.offset_by - ray.offset_hy)) -
        (((ray.x_pos + ray.offset_bx - xmap) >> 1) - unk_1);
    boss_obj = &level.objects[moskitomama_droite_obj_id];
    boss_obj->flags &= ~FLG(OBJ_FLIP_X);
    boss_obj->init_x_pos = boss_obj->x_pos = 160;
    boss_obj->init_y_pos = boss_obj->y_pos = ymap;
    NiveauSol = firstFloorBelow(boss_obj);
    boss_obj->speed_x = 0;
    boss_obj->speed_y = 0;
    boss_obj->init_x_pos = boss_obj->x_pos = 280 - boss_obj->offset_bx;
    boss_obj->init_y_pos = boss_obj->y_pos = ymap - 200;
    boss_obj->flags |= FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE);
    BBF2DEsk = 0;

    unk_1 = 70;
    YPosBBF2G =
        (NiveauSol - (ray.offset_by - ray.offset_hy)) +
        (((ray.x_pos + ray.offset_bx - xmap) >> 1) - unk_1);
    boss_obj = &level.objects[moskitomama_gauche_obj_id];
    boss_obj->flags |= FLG(OBJ_FLIP_X);
    boss_obj->init_x_pos = boss_obj->x_pos = 40 - boss_obj->offset_bx;
    boss_obj->init_y_pos = boss_obj->y_pos = ymap - 200;
    boss_obj->speed_x = 0;
    boss_obj->speed_y = 0;
    boss_obj->flags |= FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE);
    BBF2GEsk = 0;

    RayEvts.poing = true;
    level.objects[poing_obj_id].init_sub_etat = 8;
}

/* 752EC 80199AEC -O2 -msoft-float */
void allocateMOSKITOSAXO(void)
{
    Obj *obj = &level.objects[moskitosaxo_obj_id];

    if (!RayEvts.demi)
    {
        DO_NOVA(&ray);
        RAY_DEMIRAY();
    }
    RayEvts.run = true;
    obj->flags |= FLG(OBJ_ALIVE) | FLG(OBJ_ACTIVE);
    obj->init_x_pos = obj->x_pos = xmap - (obj->offset_bx - 160);
    obj->init_y_pos = obj->y_pos = ymap - obj->offset_by;
    RayEvts.poing = true;
    level.objects[poing_obj_id].init_sub_etat = 8;
}