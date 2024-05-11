#include "obj/space_mama.h"

extern s16 machine_obj_id;
extern s16 mereDenis_weapon_id;

/* 640F0 801888F0 -O2 -msoft-float */
void findMereDenisWeapon(void)
{
    Obj *cur_obj = level.objects;
    s32 nb_objs = level.nb_objects;
    s16 i;

    mereDenis_weapon_id = -1;
    machine_obj_id = -1;
    for (i = 0; i < nb_objs; i++)
    {
        if (cur_obj->type == TYPE_SMA_WEAPON)
            mereDenis_weapon_id = i;
        else if (cur_obj->type == TYPE_WASHING_MACHINE)
            machine_obj_id = i;
        cur_obj++;
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

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", setMereDenisAtScrollBorder);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", setCirclePointToReach);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", allocateMereDenisBombChips);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", mereDenisExplodeBombs);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", mereDenisDropBomb);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", snapWeaponAnimState);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", swapMereDenisCollZones);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", prepareNewMereDenisAttack);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", snapLaserToWeapon);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", allocateSpaceMamaLaser);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", doMereDenisCommand);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", changeMereDenisPhase);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", fitSaveCurrentAction);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", doMereDenisHit);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", mereDenisBigLaserCommand);

INCLUDE_ASM("asm/nonmatchings/obj/space_mama", mereDenisBombCommand);
