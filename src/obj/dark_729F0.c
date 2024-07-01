#include "obj/dark_729F0.h"

extern u8 dark_attaque;
extern u8 dark_sequence[3];
extern u8 type_dark_attaque;
extern VitrauxInfo VitrauxInfos[5];
extern s16 corde_dark_obj_id;
extern s16 corde_x;
extern s16 corde_y_bas;
extern s16 corde_y_haut;
extern s16 oscille[30];
extern u8 vitrail_clignotement[4][5];
extern s16 moskitomama_droite_obj_id;
extern s16 moskitomama_gauche_obj_id;
extern s16 moskitosaxo_obj_id;
extern s16 stosko_obj_id;
extern u8 D_801E5518;
extern s16 dark_rayon_dx;
extern s16 dark_rayon_dy;

/* 729F0 801971F0 -O2 -msoft-float */
void PlaceDarkPhase1et2(Obj *obj)
{
    obj->y_pos = obj->init_y_pos = firstFloorBelow(obj) - obj->offset_by;
    obj->x_pos = obj->init_x_pos = xmapmax + 160;
}

/* 72A38 80197238 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu, missing_nop */
INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", dark_attaque_suivante);
#else
void dark_attaque_suivante(void)
{
    dark_attaque++;
    if (dark_attaque != 3)
        type_dark_attaque = dark_sequence[dark_attaque];
    else
        type_dark_attaque = 3;

    __asm__("nop\nnop");
}
#endif

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", init_vitraux);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", poing_face_obj);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DARK_phase1);

/* 732E8 80197AE8 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DARK_phase3);
#else
void DARK_phase3(Obj *dark_obj)
{
    Obj *boss_obj;
    s16 unk_1;

    RayEvts.flags0 |= FLG(RAYEVTS0_POING);
    switch (type_dark_attaque)
    {
    case 0:
        if (stosko_obj_id != -1)
        {
            boss_obj = &level.objects[stosko_obj_id];
            unk_1 = boss_obj->field23_0x3c;
            if (unk_1 == 0)
            {
                boss_obj->field23_0x3c = 2;
                allume_vitraux((u8 (*)[5]) vitrail_clignotement[0]);
                flags[boss_obj->type].flags0 |= FLG(OBJ0_BOSS);
                scrollLocked = true;
                allocateSTOSKO();
            }
            else if (unk_1 == 1 && !(boss_obj->flags & FLG(OBJ_ACTIVE)))
            {
                flags[boss_obj->type].flags0 &= ~FLG(OBJ0_BOSS);
                scrollLocked = false;
                boss_obj->flags &= ~FLG(OBJ_ALIVE);
                boss_obj->flags &= ~FLG(OBJ_ACTIVE);
                dark_attaque_suivante();
            }
        }
        break;
    case 1:
        if (moskitomama_droite_obj_id != -1)
        {
            boss_obj = &level.objects[moskitomama_droite_obj_id];
            unk_1 = boss_obj->field23_0x3c;
            if (unk_1 == 0)
            {
                boss_obj->field23_0x3c = 2;
                if (moskitomama_gauche_obj_id != -1)
                    level.objects[moskitomama_gauche_obj_id].field23_0x3c = 2;
                allume_vitraux((u8 (*)[5]) vitrail_clignotement[1]);
                flags[boss_obj->type].flags0 |= FLG(OBJ0_BOSS);
                scrollLocked = true;
                allocateMOSKITOMAMA();
            }
            else if (unk_1 == 1 && !(boss_obj->flags & FLG(OBJ_ACTIVE)))
            {
                flags[boss_obj->type].flags0 &= ~FLG(OBJ0_BOSS);
                scrollLocked = false;
                boss_obj->flags &= ~FLG(OBJ_ALIVE);
                boss_obj->flags &= ~FLG(OBJ_ACTIVE);
                dark_attaque_suivante();
            }
        }
        break;
    case 2:
        if (moskitosaxo_obj_id != -1)
        {
            boss_obj = &level.objects[moskitosaxo_obj_id];
            unk_1 = boss_obj->field23_0x3c;
            if (unk_1 == 0)
            {
                boss_obj->field23_0x3c = 2;
                allume_vitraux((u8 (*)[5]) vitrail_clignotement[2]);
                flags[boss_obj->type].flags0 |= FLG(OBJ0_BOSS);
                scrollLocked = true;
                allocateMOSKITOSAXO();
            }
            else if (unk_1 == 1 && !(boss_obj->flags & FLG(OBJ_ACTIVE)))
            {
                flags[boss_obj->type].flags0 &= ~FLG(OBJ0_BOSS);
                scrollLocked = false;
                boss_obj->flags &= ~FLG(OBJ_ALIVE);
                boss_obj->flags &= ~FLG(OBJ_ACTIVE);
                dark_attaque_suivante();
            }
        }
        break;
    case 3:
        allume_vitraux((u8 (*)[5]) vitrail_clignotement[3]);
        goto_phase5(dark_obj);
        break;
    }

    __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}
#endif

/* 735F8 80197DF8 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_COMMAND);
#else
void DO_DARK_COMMAND(Obj *dark_obj)
{
    u8 flag_set;
    s16 dark_x; s16 dark_y; s16 dark_w; s16 dark_h;
    s16 sort_x; s16 sort_y;

    if (dark_obj->main_etat == 0)
    {
        if (dark_obj->sub_etat == 39)
        {
            switch (dark_phase)
            {
            case 0:
            case 1:
                goto_phase1(dark_obj);
                break;
            case 2:
                goto_phase2(dark_obj);
                break;
            case 3:
                goto_phase3(dark_obj);
                break;
            case 5:
                goto_phase5(dark_obj);
                break;
            }
        }

        if (dark_obj->main_etat == 0)
        {
            if (dark_obj->sub_etat == 6)
            {
                if (dark_obj->anim_frame == 4)
                    dark_obj->speed_y = -4;
                else
                {
                    if (dark_phase == 4)
                    {
                        flag_set = dark_obj->eta[dark_obj->main_etat][dark_obj->sub_etat].flags & 0x10;
                        if(
                            ((flag_set && dark_obj->anim_frame == 0) ||
                            (!flag_set && dark_obj->anim_frame == dark_obj->animations[dark_obj->anim_index].frames_count - 1)) &&
                            horloge[dark_obj->eta[dark_obj->main_etat][dark_obj->sub_etat].anim_speed & 0xf] == 0
                        )
                            goto_phase5(dark_obj);
                    }
                    else
                    {
                        flag_set = dark_obj->eta[dark_obj->main_etat][dark_obj->sub_etat].flags & 0x10;
                        if(
                            ((flag_set && dark_obj->anim_frame == 0) ||
                            (!flag_set && dark_obj->anim_frame == dark_obj->animations[dark_obj->anim_index].frames_count - 1)) &&
                            horloge[dark_obj->eta[dark_obj->main_etat][dark_obj->sub_etat].anim_speed & 0xf] == 0
                        )
                        {
                            dark_obj->flags &= ~FLG(OBJ_ACTIVE);
                            dark_obj->flags &= ~FLG(OBJ_ALIVE);
                        }
                    }
                }
            }
            else if (
                (
                    dark_obj->sub_etat == 8 || dark_obj->sub_etat == 10 || dark_obj->sub_etat == 12 ||
                    dark_obj->sub_etat == 14 || dark_obj->sub_etat == 22 || dark_obj->sub_etat == 23 ||
                    dark_obj->sub_etat == 24
                ) &&
                dark_obj->anim_frame == 22
            )
            {
                GET_SPRITE_POS(dark_obj, 3, &dark_x, &dark_y, &dark_w, &dark_h);
                dark_rayon_dx = -5;
                dark_rayon_dy = 0;
                sort_x = dark_x + (dark_w >> 1) - 96;
                sort_y = dark_y + (dark_h >> 1) - 128;
                switch (dark_obj->sub_etat)
                {
                case 8:
                    allocate_DARK_SORT(sort_x, sort_y, 0, 1);
                    break;
                case 10:
                    allocate_DARK_SORT(sort_x, sort_y, 1, 1);
                    break;
                case 12:
                    allocate_DARK_SORT(sort_x, sort_y, 2, 1);
                    break;
                case 14:
                    allocate_DARK_SORT(sort_x, sort_y, 3, 1);
                    break;
                case 22:
                    D_801E5518 = 2;
                    allume_vitraux((u8 (*)[5]) vitrail_clignotement[0]);
                    allocate_DARK_SORT(sort_x, sort_y, 18, 3);
                    allocate_DARK_SORT(sort_x, sort_y, 18, 5);
                    break;
                case 23:
                    D_801E5518 = 2;
                    allume_vitraux((u8 (*)[5]) vitrail_clignotement[1]);
                    allocate_DARK_SORT(sort_x, sort_y, 19, 1);
                    allocate_DARK_SORT(sort_x, sort_y, 19, 4);
                    break;
                case 24:
                    D_801E5518 = 2;
                    allume_vitraux((u8 (*)[5]) vitrail_clignotement[2]);
                    allocate_DARK_SORT(sort_x, sort_y, 20, 1);
                    allocate_DARK_SORT(sort_x, sort_y, 20, 2);
                    break;
                }
            }
            else
            {
                if (dark_obj->main_etat == 0)
                {
                    if (dark_obj->sub_etat == 15)
                    {
                        if (dark_obj->anim_frame == 0)
                        {
                            if (horloge[dark_obj->eta[dark_obj->main_etat][dark_obj->sub_etat].anim_speed & 0xF] == 0)
                            {
                                DO_NOVA2(dark_obj);
                                dark_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE)|FLG(OBJ_FLIP_X);
                            }
                        }
                        else if (dark_obj->anim_frame == 22)
                        {
                            GET_SPRITE_POS(dark_obj, 3, &dark_x, &dark_y, &dark_w, &dark_h);
                            dark_rayon_dx = -2;
                            dark_rayon_dy = 0;
                            allocate_DARK_SORT(
                                (s16) (dark_x + (dark_w >> 1) - 96),
                                (s16) (dark_y + (dark_h >> 1) - 128),
                                4,
                                1
                            );
                        }
                    }
                    else if (dark_obj->sub_etat == 21)
                        DARK_phase3(dark_obj);
                    else if (
                        dark_obj->sub_etat == 26 || dark_obj->sub_etat == 27 ||
                        dark_obj->sub_etat == 28 || dark_obj->sub_etat == 29 ||
                        dark_obj->sub_etat == 40
                    )
                        DARK_phase1(dark_obj);
                }
            }
        }
    }

    __asm__("nop\nnop\nnop\nnop\nnop");
}
#endif

/* 73C38 80198438 -O2 -msoft-float */
void DO_DARK_POING_COLLISION(Obj *obj)
{
    if (
        obj->main_etat == 0 && (obj->sub_etat == 16 || obj->sub_etat == 17) &&
        obj->display_prio != 0
    )
    {
        obj->hit_points--;
        if (obj->hit_points == 0)
            set_main_and_sub_etat(obj, 0, 6);
    }
}

/* 73CB0 801984B0 -O2 -msoft-float */
void DO_DARK_REACT(Obj *obj)
{
    if (obj->main_etat == 0)
    {
        if (obj->sub_etat == 7)
            set_sub_etat(obj, 8);
        if (obj->sub_etat == 9)
            set_sub_etat(obj, 10);
        if (obj->sub_etat == 11)
            set_sub_etat(obj, 12);
        if (obj->sub_etat == 13)
            set_sub_etat(obj, 14);
    }
}

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_SORT_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_SORT_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", allocate_DARK_SORT);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", corde_en_bas);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", corde_en_haut);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", init_corde);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", goto_phase1);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", goto_phase2);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", goto_phase3);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", goto_phase5);
