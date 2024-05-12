#include "obj/space_mama.h"

s16 cosinus(s16);
s16 sinus(s16);
Obj * allocateExplosion(Obj *obj);

extern s16 machine_obj_id;
extern s16 mereDenis_weapon_id;
extern s16 circleIndex;
extern s16 circleX;
extern s16 circleY;
extern s16 droppedBombIds[8][8];
extern s16 **bombSequences[7];
extern u8 currentBombSequence;
extern u8 lastDroppedBombIdInSequence[8];
extern s16 lastDroppedBombXCenterPos;

/* 640F0 801888F0 -O2 -msoft-float */
void findMereDenisWeapon(void)
{
    Obj *cur_obj = &level.objects[0];
    s32 nb_objs = level.nb_objects;
    s16 i = 0;

    mereDenis_weapon_id = -1;
    machine_obj_id = -1;
    while (i < nb_objs)
    {
        if (cur_obj->type == TYPE_SMA_WEAPON)
            mereDenis_weapon_id = i;
        else if (cur_obj->type == TYPE_WASHING_MACHINE)
            machine_obj_id = i;
        cur_obj++;
        i++;
    }
}

/* 64174 80188974 -O2 -msoft-float */
void PS1_setBossScrollLimits_spacemama(Obj *obj)
{
    s16 x; s16 y;

    x = obj->offset_bx + obj->init_x_pos - 220;
    bossScrollEndX = x;
    bossScrollStartX = x;
    y = firstFloorBelow(obj);
    floorLine = y;
    bossScrollStartY = y - 256;
    bossScrollEndY = y - 224;

    MAX_2(bossScrollStartX, 0);
    MIN_2(bossScrollStartX, xmapmax);
    MAX_2(bossScrollEndX, 0);
    MIN_2(bossScrollEndX, xmapmax);
    MAX_2(bossScrollStartY, 0);
    MIN_2(bossScrollStartY, ymapmax);
    MAX_2(bossScrollEndY, 0);
    MIN_2(bossScrollEndY, ymapmax);
}

/* 642C0 80188AC0 -O2 -msoft-float */
s32 mereDenisCanAttak(Obj *obj)
{
    if (!scrollLocked)
    {
        scrollLocked =
            xmap >= bossScrollStartX - h_scroll_speed &&
            xmap <= bossScrollEndX + h_scroll_speed &&
            ymap >= bossScrollStartY - v_scroll_speed &&
            ymap <= bossScrollEndY + v_scroll_speed;
        if (scrollLocked)
        {
            scroll_start_x = bossScrollStartX;
            scroll_end_x = bossScrollEndX;
            scroll_start_y = bossScrollStartY;
            scroll_end_y = bossScrollEndY;
        }
    }
    else if (obj->timer != 0 && horloge[2] == 0)
        obj->timer--;

    return scrollLocked && obj->timer == 0;
}

/* 64418 80188C18 -O2 -msoft-float */
s32 setMereDenisAtScrollBorder(Obj *obj, u8 flip_x)
{
    s32 unk_1;
    s16 res;
    u8 offs_bx;

    unk_1 = 320; /* couldn't remove this */
    switch (flip_x)
    {
    case false:
        res = -1;
        obj->x_pos = scroll_start_x - obj->offset_bx;
        obj->flags |= FLG(OBJ_FLIP_X);
        break;
    case true:
        res = 1;
        obj->x_pos = scroll_end_x - (obj->offset_bx - unk_1);
        obj->flags &= ~FLG(OBJ_FLIP_X);
        break;
    default:
        offs_bx = obj->offset_bx;
        res = offs_bx + obj->x_pos - (scroll_start_x + scroll_end_x + 320) / 2;
        if (res > 0)
        {
            obj->x_pos = scroll_end_x - (offs_bx - unk_1);
            obj->flags &= ~FLG(OBJ_FLIP_X);
        }
        else
        {
            obj->x_pos = scroll_start_x - offs_bx;
            obj->flags |= FLG(OBJ_FLIP_X);
        }
        break;
    }
    return res;
}

/* 64514 80188D14 -O2 -msoft-float */
void setCirclePointToReach(void)
{
    bossXToReach = circleX + sinus(circleIndex) * 100 / 512;
    bossYToReach = circleY + cosinus(circleIndex) * 60 / 512;
    circleIndex += 4;
    if (circleIndex > 512)
        circleIndex = -32000;
}

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", allocateMereDenisBombChips);

/* 64810 80189010 -O2 -msoft-float */
void mereDenisExplodeBombs(void)
{
    s16 var_t0; s16 var_v0; /* didn't name yet, because dunno which is y, which is x, if it's spatial repr. */
    s16 id;
    Obj *obj;

    for (var_t0 = 0; var_t0 < 8; var_t0++) /* sizeof instead of constants? */
    {
        for (var_v0 = 0; var_v0 < 8; var_v0++)
        {
            id = droppedBombIds[var_t0][var_v0];
            if (id != -1)
            {
                obj = &level.objects[id];
                obj->timer = 70;
                droppedBombIds[var_t0][var_v0] = -1;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", mereDenisDropBomb);

/* 64D48 80189548 -O2 -msoft-float */
void snapWeaponAnimState(Obj *obj, u8 sub_etat)
{
    set_main_and_sub_etat(obj, 0, sub_etat);
    obj->anim_frame = 0;
    obj->anim_index = obj->eta[0][sub_etat].anim_index;
}

/* 64DA0 801895A0 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/space_mama", swapMereDenisCollZones);
#else
void swapMereDenisCollZones(Obj *obj, u8 smama2)
{
    __asm__("nop");

    if (!smama2)
        obj->type = TYPE_SPACE_MAMA;
    else
        obj->type = TYPE_SPACE_MAMA2;
    obj->zdc = type_zdc[obj->type];
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", prepareNewMereDenisAttack);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", snapLaserToWeapon);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", allocateSpaceMamaLaser);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", doMereDenisCommand);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", changeMereDenisPhase);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", fitSaveCurrentAction);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", doMereDenisHit);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", mereDenisBigLaserCommand);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", mereDenisBombCommand);
