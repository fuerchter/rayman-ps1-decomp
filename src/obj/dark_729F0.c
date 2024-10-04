#include "obj/dark_729F0.h"

/* 729F0 801971F0 -O2 -msoft-float */
void PlaceDarkPhase1et2(Obj *obj)
{
    obj->y_pos = obj->init_y_pos = firstFloorBelow(obj) - obj->offset_by;
    obj->x_pos = obj->init_x_pos = xmapmax + 160;
}

/* 72A38 80197238 -O2 -msoft-float */
void dark_attaque_suivante(void)
{
    dark_attaque++;
    if (dark_attaque != 3)
        type_dark_attaque = dark_sequence[dark_attaque];
    else
        type_dark_attaque = 3;
}

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", init_vitraux);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", poing_face_obj);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DARK_phase1);

/* 732E8 80197AE8 -O2 -msoft-float */
void DARK_phase3(Obj *mr_drk_obj)
{
    Obj *boss_obj;
    s16 unk_1;

    RayEvts.poing = true;
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
        goto_phase5(mr_drk_obj);
        break;
    }
}

/* 735F8 80197DF8 -O2 -msoft-float */
void DO_DARK_COMMAND(Obj *mr_drk_obj)
{
    s16 dark_x; s16 dark_y; s16 dark_w; s16 dark_h;
    s16 sort_x; s16 sort_y;

    if (mr_drk_obj->main_etat == 0)
    {
        if (mr_drk_obj->sub_etat == 39)
        {
            switch (dark_phase)
            {
            case 0:
            case 1:
                goto_phase1(mr_drk_obj);
                break;
            case 2:
                goto_phase2(mr_drk_obj);
                break;
            case 3:
                goto_phase3(mr_drk_obj);
                break;
            case 5:
                goto_phase5(mr_drk_obj);
                break;
            }
        }

        if (mr_drk_obj->main_etat == 0)
        {
            if (mr_drk_obj->sub_etat == 6)
            {
                if (mr_drk_obj->anim_frame == 4)
                    mr_drk_obj->speed_y = -4;
                else
                {
                    if (dark_phase == 4)
                    {
                        if(EOA(mr_drk_obj))
                            goto_phase5(mr_drk_obj);
                    }
                    else
                    {
                        if(EOA(mr_drk_obj))
                        {
                            mr_drk_obj->flags &= ~FLG(OBJ_ACTIVE);
                            mr_drk_obj->flags &= ~FLG(OBJ_ALIVE);
                        }
                    }
                }
            }
            else if (
                (
                    mr_drk_obj->sub_etat == 8 || mr_drk_obj->sub_etat == 10 || mr_drk_obj->sub_etat == 12 ||
                    mr_drk_obj->sub_etat == 14 || mr_drk_obj->sub_etat == 22 || mr_drk_obj->sub_etat == 23 ||
                    mr_drk_obj->sub_etat == 24
                ) &&
                mr_drk_obj->anim_frame == 22
            )
            {
                GET_SPRITE_POS(mr_drk_obj, 3, &dark_x, &dark_y, &dark_w, &dark_h);
                dark_rayon_dx = -5;
                dark_rayon_dy = 0;
                sort_x = dark_x + (dark_w >> 1) - 96;
                sort_y = dark_y + (dark_h >> 1) - 128;
                switch (mr_drk_obj->sub_etat)
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
                if (mr_drk_obj->main_etat == 0)
                {
                    if (mr_drk_obj->sub_etat == 15)
                    {
                        if (mr_drk_obj->anim_frame == 0)
                        {
                            if (horloge[mr_drk_obj->eta[mr_drk_obj->main_etat][mr_drk_obj->sub_etat].anim_speed & 0xF] == 0)
                            {
                                DO_NOVA2(mr_drk_obj);
                                mr_drk_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE)|FLG(OBJ_FLIP_X);
                            }
                        }
                        else if (mr_drk_obj->anim_frame == 22)
                        {
                            GET_SPRITE_POS(mr_drk_obj, 3, &dark_x, &dark_y, &dark_w, &dark_h);
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
                    else if (mr_drk_obj->sub_etat == 21)
                        DARK_phase3(mr_drk_obj);
                    else if (
                        mr_drk_obj->sub_etat == 26 || mr_drk_obj->sub_etat == 27 ||
                        mr_drk_obj->sub_etat == 28 || mr_drk_obj->sub_etat == 29 ||
                        mr_drk_obj->sub_etat == 40
                    )
                        DARK_phase1(mr_drk_obj);
                }
            }
        }
    }
}

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

/* 740D4 801988D4 -O2 -msoft-float */
void DO_DARK_SORT_COLLISION(Obj *obj)
{
    if (obj->hit_points != 0 && !(obj->main_etat == 0 && obj->sub_etat == 4))
    {
        obj->hit_points = 0;
        switch (obj->sub_etat)
        {
        case 0:
            RayEvts.force_run = 1;
            break;
        case 1:
            DO_NOVA(&ray);
            RayEvts.reverse = 0;
            RAY_REVERSE_COMMANDS();
            break;
        case 2:
            DO_NOVA(&ray);
            RAY_DEMIRAY();
            break;
        case 3:
            DO_NOVA(&ray); 
            RayEvts.poing = false;
            break;
        }
    }
}

/* many ??? were had */
/* 741FC 801989FC -O2 -msoft-float */
void allocate_DARK_SORT(s16 x, s16 y, s16 sub_etat, s16 iframes)
{
    s16 unk_1 = 0;
    s16 unk_2;
    Obj *cur_obj = &level.objects[0];
    s16 i = 0;
    s16 nb_objs = level.nb_objects;

    do
    {
        if (cur_obj->type == TYPE_DARK_SORT && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
            unk_1 = 1;
        cur_obj++;
        i++;
    } while (unk_1 == 0 && i < nb_objs);
    cur_obj--;
    if (unk_1 != 0)
    {
        cur_obj->x_pos = x;
        cur_obj->y_pos = y;
        cur_obj->hit_points = 1;
        cur_obj->iframes_timer = iframes;
        cur_obj->field23_0x3c = 0;
        cur_obj->flags |= FLG(OBJ_ACTIVE)|FLG(OBJ_ALIVE);
        set_main_and_sub_etat(cur_obj, 0, sub_etat);
        cur_obj->anim_frame = 0;
    }
    else
    {
        unk_2 = 0;
        cur_obj = &level.objects[0];
        i = 0;
        unk_1 = 0;
        do
        {
            if (cur_obj->type == TYPE_DARK_SORT && unk_2 < cur_obj->anim_frame)
            {
                unk_1 = i;
                unk_2 = cur_obj->anim_frame;
            }
            cur_obj++;
            i++;
        } while (i < nb_objs);
        cur_obj = &level.objects[unk_1];
        cur_obj->x_pos = x;
        cur_obj->y_pos = y;
        cur_obj->hit_points = 1;
        cur_obj->iframes_timer = iframes;
        cur_obj->field23_0x3c = 0;
        cur_obj->flags |= FLG(OBJ_ACTIVE)|FLG(OBJ_ALIVE);
        set_main_and_sub_etat(cur_obj, 0, sub_etat);
        cur_obj->anim_frame = 0;
    }
}

/* 7439C 80198B9C -O2 -msoft-float */
void corde_en_bas(void)
{
    Obj *obj;

    if (corde_dark_obj_id != -1)
    {
        obj = &level.objects[corde_dark_obj_id];
        obj->x_pos = corde_x;
        obj->init_x_pos = corde_x;
        obj->y_pos = corde_y_bas;
        obj->init_y_pos = corde_y_bas;
    }
}

/* 743EC 80198BEC -O2 -msoft-float */
void corde_en_haut(u8 param_1)
{
    Obj *corde_dark_obj;
    Obj *poing_obj;

    if (corde_dark_obj_id != -1)
    {
        corde_dark_obj = &level.objects[corde_dark_obj_id];
        corde_dark_obj->x_pos = corde_x;
        corde_dark_obj->y_pos = corde_y_haut;
        if (param_1)
        {
            poing_obj = &level.objects[poing_obj_id];
            set_main_and_sub_etat(poing_obj, 5, 64);
            poing_obj->x_pos = corde_dark_obj->x_pos + corde_dark_obj->offset_bx - poing_obj->offset_bx;
            poing_obj->y_pos = corde_dark_obj->y_pos + corde_dark_obj->offset_by - poing_obj->offset_by - 5;
            poing_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
        }
    }
}

/* 744CC 80198CCC -O2 -msoft-float */
void init_corde(Obj *obj)
{
    corde_x = 0;
    corde_y_bas = obj->y_pos;
    corde_y_haut = ymap - 184;
    if (corde_dark_obj_id != -1)
        corde_y_haut = obj->y_pos + obj->offset_by - level.objects[corde_dark_obj_id].offset_by - 148;
}

/* 74544 80198D44 -O2 -msoft-float */
void goto_phase1(Obj *mr_drk_obj)
{
    Obj *corde_dark_obj;

    dark_phase = 1;
    scroll_end_x = 0;
    scroll_start_x = 0;
    scroll_end_y = ymap;
    scroll_start_y = ymap;
    flags[mr_drk_obj->type].flags0 &=
        (FLG(OBJ0_ALWAYS)|FLG(OBJ0_BALLE)|FLG(OBJ0_NO_COLLISION)|
        FLG(OBJ0_HIT_RAY)|FLG(OBJ0_KEEP_ACTIVE)|
        FLG(OBJ0_DETECT_ZONE)|FLG(OBJ0_FLAG6));
    mr_drk_obj->field23_0x3c = 0;
    scrollLocked = false;
    RayEvts.poing = false;
    PlaceDarkPhase1et2(mr_drk_obj);
    init_corde(mr_drk_obj);
    if (corde_dark_obj_id != -1)
    {
        corde_dark_obj = &level.objects[corde_dark_obj_id];
        corde_dark_obj->field23_0x3c = 3;
        corde_dark_obj->iframes_timer = 29;
    }
    corde_en_bas();
    set_main_and_sub_etat(mr_drk_obj, 0, 26);
}

/* 74648 80198E48 -O2 -msoft-float */
void goto_phase2(Obj *mr_drk_obj)
{
    dark_phase = 2;
    scroll_end_x = 0;
    scroll_start_x = 0;
    scroll_end_y = ymap;
    scroll_start_y = ymap;
    flags[mr_drk_obj->type].flags0 &=
        (FLG(OBJ0_ALWAYS)|FLG(OBJ0_BALLE)|FLG(OBJ0_NO_COLLISION)|
        FLG(OBJ0_HIT_RAY)|FLG(OBJ0_KEEP_ACTIVE)|
        FLG(OBJ0_DETECT_ZONE)|FLG(OBJ0_FLAG6));
    scrollLocked = false;
    PlaceDarkPhase1et2(mr_drk_obj);
    init_corde(mr_drk_obj);
    corde_en_haut(true);
    mr_drk_obj->field23_0x3c = 0;
    mr_drk_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
    AllocateDarkPhase2(mr_drk_obj);
}

/* 74708 80198F08 -O2 -msoft-float */
void goto_phase3(Obj *mr_drk_obj)
{
    s16 y;

    dark_phase = 3;
    scroll_end_x = 0;
    scroll_start_x = 0;
    scroll_end_y = ymap;
    scroll_start_y = ymap;
    flags[mr_drk_obj->type].flags0 &=
        (FLG(OBJ0_ALWAYS)|FLG(OBJ0_BALLE)|FLG(OBJ0_NO_COLLISION)|
        FLG(OBJ0_HIT_RAY)|FLG(OBJ0_KEEP_ACTIVE)|
        FLG(OBJ0_DETECT_ZONE)|FLG(OBJ0_FLAG6));
    scrollLocked = false;
    PlaceDarkPhase1et2(mr_drk_obj);
    init_corde(mr_drk_obj);
    corde_en_haut(false);
    mr_drk_obj->x_pos = 0;
    mr_drk_obj->init_x_pos = 0;
    mr_drk_obj->speed_x = 0;
    mr_drk_obj->speed_y = 0;
    mr_drk_obj->field23_0x3c = 0;
    y = ymap - mr_drk_obj->offset_by - 20; /* could also write this as one-liner with double assignment */
    mr_drk_obj->y_pos = y;
    mr_drk_obj->init_y_pos = y;
    mr_drk_obj->flags |= FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE);
    set_main_and_sub_etat(mr_drk_obj, 0, 21);
    dark_attaque = 0;
    type_dark_attaque = *dark_sequence;
}

/* 74814 80199014 -O2 -msoft-float */
void goto_phase5(Obj *mr_drk_obj)
{
    s16 y;

    dark_phase = 5;
    scroll_end_x = 0;
    scroll_start_x = 0;
    scroll_end_y = ymap;
    scroll_start_y = ymap;
    flags[mr_drk_obj->type].flags0 &=
        (FLG(OBJ0_ALWAYS)|FLG(OBJ0_BALLE)|FLG(OBJ0_NO_COLLISION)|
        FLG(OBJ0_HIT_RAY)|FLG(OBJ0_KEEP_ACTIVE)|
        FLG(OBJ0_DETECT_ZONE)|FLG(OBJ0_FLAG6));
    scrollLocked = false;
    PlaceDarkPhase1et2(mr_drk_obj);
    init_corde(mr_drk_obj);
    corde_en_haut(false);
    if (RayEvts.demi)
    {
        DO_NOVA(&ray);
        RAY_DEMIRAY();
    }
    mr_drk_obj->x_pos = 0;
    mr_drk_obj->init_x_pos = 0;
    mr_drk_obj->field23_0x3c = 0;
    y = ymap - mr_drk_obj->offset_by - 20;
    mr_drk_obj->y_pos = y;
    mr_drk_obj->init_y_pos = y;
    mr_drk_obj->flags &= ~FLG(OBJ_ALIVE);
    mr_drk_obj->flags &= ~FLG(OBJ_ACTIVE);
    fin_boss = true;
    finBosslevel[0] |= FLG(7);
}