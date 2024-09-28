#include "obj/bb1.h"

/* matches, but "case GO_LEFT" */
/* 59248 8017DA48 -O2 -msoft-float */
#ifndef NONMATCHINGS /* missing_addiu */
INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT_COMMAND);
#else
void DO_BBMONT_COMMAND(Obj *obj)
{
    s16 w; s16 h;
    s32 x_1;
    s32 x_2;
    s32 pos_pierre;
    u8 wait;
    s16 new_dogs;
    s16 new_spd_x_1;
    s16 new_spd_x_2;

    scrollLocked = true;
    if (YaDesChiens != 0 && --horlogeDog < 0)
    {
        horlogeDog = 50;
        allocateDog(obj);
        YaDesChiens--;
    }
    GET_SPRITE_POS(obj, 6, &bb1.sprite6_x, &bb1.sprite6_y, &w, &h);
    w = obj->x_pos;
    h = obj->y_pos;
    if (
        obj->anim_frame == obj->animations[obj->anim_index].frames_count - 1 &&
        horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
    )
        FinAnim = true;
    else
        FinAnim = false;

    if (bb1.field2_0x4 == 2 && FinAnim)
    {
        if (obj->hit_points == obj->init_hit_points - 1)
        {
            skipToLabel(obj, 4, true);
            Phase = 7;
        }
        set_main_and_sub_etat(obj, bb1.saved_main_etat, bb1.saved_sub_etat);
        WaitForFinAtan = 1;
        obj->cmd = bb1.saved_cmd;
    }
    if (bb1.field2_0x4 == 1)
    {
        if (!(obj->main_etat == 0 && obj->sub_etat == 9))
        {
            bb1.saved_main_etat = obj->main_etat;
            bb1.saved_sub_etat = obj->sub_etat;
            set_main_and_sub_etat(obj, 0, 9);
            bb1.field2_0x4 = 2;
            FinAnim = false;
            obj->speed_x = 0;
            obj->hit_points--;
            bb1.saved_cmd = obj->cmd;
            if (obj->hit_points == 0)
            {
                bb1.field2_0x4 = 3;
                set_main_and_sub_etat(obj, 0, 20);
                obj->speed_x = 0;
                bb1.saved_cmd = 420;
            }
        }
        else
            bb1.field2_0x4 = 0;
    }
    
    if (bb1.field2_0x4 == 3)
    {
        if (--bb1.saved_cmd < 1)
        {
            fin_boss = 1;
            bb1.saved_cmd = 999;
            finBosslevel[0] |= 0x08;
        }
    }
    else
    {
        switch(obj->cmd)
        {
        case GO_LEFT:
            obj->flags &= ~FLG(OBJ_FLIP_X);
            if(obj->cmd == GO_RIGHT)
            {
        case GO_RIGHT: /* <--- */
                obj->flags |= FLG(OBJ_FLIP_X);
            }
            SET_X_SPEED(obj);
            if (block_flags[calc_typ_travd(obj, false)] >> BLOCK_FLAG_4 & 1)
            {
                /* ??? */
                obj->flags = obj->flags & ~FLG(OBJ_FLIP_X) | ((obj->flags >> OBJ_FLIP_X ^ 1) & 1) << OBJ_FLIP_X;
                skipToLabel(obj, 6, true);
                if (IndSerie > 3)
                    WaitForFinAtan = 2;
                Phase = 8;
            }
            if (Phase == 7)
            {
                /* different way to write this, or is this the nicest??? */
                pos_pierre = PosPierre;
                x_1 = obj->x_pos;
                if (
                    (obj->flags & FLG(OBJ_FLIP_X) && (x_1 < pos_pierre + 14)) ||
                    (!(obj->flags & FLG(OBJ_FLIP_X))  && (x_1 < pos_pierre - 6)))
                {
                    pos_pierre = PosPierre;
                    x_2 = obj->x_pos;
                    if (
                        (obj->flags & FLG(OBJ_FLIP_X) && (x_2 > pos_pierre + 6)) ||
                        (!(obj->flags & FLG(OBJ_FLIP_X)) && (x_2 > pos_pierre - 14))
                    )
                    {
                        set_main_and_sub_etat(obj,  0,  2);
                        skipToLabel(obj,  0,  1);
                        Phase = 9;
                    }
                }
            }
            CALC_MOV_ON_BLOC(obj);
            break;
        case GO_WAIT:
            switch(Phase)
            {
            case 0:
                if (bb1.field8_0xe != 0)
                {
                    CreateFirstBBL();
                    WaitForAnim = true;
                    bb1.field8_0xe = 0;
                }
                if (FinAnim && WaitForAnim)
                {
                    obj->anim_frame = 0;
                    IndSerie = 0;
                    IndAtak = 0;
                    WaitForFinAtan = SerieAtakBB[0][0].wait_for_fin_atan;
                    NextAtak = SerieAtakBB[0][0].attack;
                    BB_Attaque(obj);
                }
                break;
            case 1:
                if (
                    obj->sub_etat == 4 && obj->anim_frame == 0xe &&
                    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0 &&
                    screen_trembling2 == 0
                )
                {
                    screen_trembling2 = 1;
                    allocateTir(obj, 4);
                }
                if (FinAnim)
                    BB_Atan(obj);
                break;
            case 2:
                if (
                    obj->sub_etat == 11 && obj->anim_frame == 23 &&
                    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
                )
                {
                    allocateTir(obj, 1);
                }
                if (
                    obj->sub_etat == 3 && obj->anim_frame == 14 &&
                    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0 &&
                    screen_trembling2 == 0
                )
                {
                    screen_trembling2 = 1;
                    allocateTir(obj, 3);
                    wait = WaitForFinAtan;
                    if (niveau == 0)
                        WaitForFinAtan = wait + 3;
                    else
                        WaitForFinAtan = wait + 1;

                }
                if (obj->sub_etat == 10 && FinAnim)
                {
                    if (--WaitForFinAtan != 0)
                    {
                        obj->anim_frame = 0;
                        set_sub_etat(obj, 10);
                    }
                }
                if (obj->sub_etat == 11) {
                    if (FinAnim)
                    {
                        Phase = 11;
                        obj->iframes_timer = 35;
                    }
                }
                break;
            case 3:
                if (
                    obj->sub_etat == 6 && obj->anim_frame == 0x40 &&
                    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
                )
                {
                    if (niveau == 0)
                        new_dogs = 3;
                    else
                        new_dogs = 4;
                    YaDesChiens = new_dogs;
                    horlogeDog = 0;
                }
                if (FinAnim)
                    BB_Atan(obj);
                break;
            case 4:
                if (
                    obj->sub_etat == 7 && obj->anim_frame == 44 &&
                    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
                )
                {
                    BBMONT_ETINCELLES(obj);
                    PlaySnd(114, obj->id);
                }
                if (FinAnim)
                    BB_Atan(obj);                
                break;
            case 5:
                if (
                    obj->sub_etat == 2 && obj->anim_frame == 21 &&
                    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
                )
                {
                    BBMONT_ECLAIR(obj);
                    PlaySnd(114, obj->id);
                }
                if (FinAnim)
                {
                    obj->anim_frame = 0;
                    set_sub_etat(obj, 1);
                    Phase = 10;
                }
                break;
            case 6:
                if (FinAnim && --WaitForFinAtan == 0)
                    Fin_BB_Attaque(obj);
                break;
            case 7:
                if (
                    obj->sub_etat == 8 && obj->anim_frame == 14 &&
                    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
                )
                {
                    allocateTir(obj, 0);
                    break;
                }
                if (FinAnim)
                {
                    if (--WaitForFinAtan == 0) {
                        set_main_and_sub_etat(obj, 1, 2);
                        if (obj->flags & FLG(OBJ_FLIP_X))
                            skipToLabel(obj, 5, true);
                        else
                            skipToLabel(obj, 4, true);
                    }
                    else
                        set_sub_etat(obj, 1);
                }
                break;
            case 8:
                if (FinAnim)
                {
                    if (obj->sub_etat != 9)
                    {
                        if (WaitForFinAtan == 2)
                        {
                            set_main_and_sub_etat(obj, 0, 1);
                            WaitForFinAtan--;
                        }
                        else if (bb1.field8_0xe == 0)
                        {
                            WaitForFinAtan = SerieAtakBB[IndSerie][0].wait_for_fin_atan;
                            NextAtak = SerieAtakBB[IndSerie][0].attack;
                            IndAtak = 0;
                            BB_Attaque(obj);
                        }
                        else
                        {
                            Fin_BB_Attaque(obj);
                            bb1.field8_0xe = 0;
                        }
                    }
                }
                break;
            case 9:
                if (
                    obj->anim_frame == 20 &&
                    horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0 &&
                    obj->sub_etat != 9
                )
                    PierreDoitExploser = true;
                if (FinAnim && bb1.field2_0x4 != 2)
                {
                    set_main_and_sub_etat(obj, 1, 0);
                    if (obj->flags & FLG(OBJ_FLIP_X))
                        skipToLabel(obj, 5, true);
                    else
                        skipToLabel(obj, 4, true);
                    PierreDoitExploser = false;
                }
                break;
            case 10:
                if (FinAnim)
                {
                    obj->anim_frame = 0;
                    set_main_and_sub_etat(obj, 1, 1);
                    if (obj->flags & FLG(OBJ_FLIP_X))
                        skipToLabel(obj, 5, true);
                    else
                        skipToLabel(obj, 4, true);
                }
                break;
            case 11:
                switch(obj->sub_etat)
                {
                case 0:
                case 3:
                    if (--obj->iframes_timer > 1)
                    {
                        obj->speed_y = -8;
                        obj->gravity_value_1 = 0;
                        if (obj->flags & FLG(OBJ_FLIP_X))
                            new_spd_x_1 = 4;
                        else
                            new_spd_x_1 = -4;
                        obj->speed_x = new_spd_x_1;
                    }
                    else
                    {
                        set_sub_etat(obj,  4);
                        if (obj->flags & FLG(OBJ_FLIP_X))
                            new_spd_x_2 = 2;
                        else
                            new_spd_x_2 = -2;
                        obj->speed_x = new_spd_x_2;
                    }
                    break;
                case 6:
                    if (FinAnim)
                    {
                        set_main_and_sub_etat(obj, 1, 0);
                        if (obj->flags & FLG(OBJ_FLIP_X))
                            skipToLabel(obj, 5, true);
                        else
                            skipToLabel(obj, 4, true);
                    }
                    break;
                }
                break;
            case 12:
                if (
                    obj->sub_etat == 4 && obj->anim_frame == 14 &&
                    horloge[obj->eta[obj->main_etat][4].anim_speed & 0xf] == 0 &&
                    screen_trembling2 == 0
                )
                {
                    screen_trembling2 = 1;
                    allocateTir(obj, bb1.field8_0xe + 10);
                    bb1.field8_0xe++;
                }
                if (FinAnim && bb1.field8_0xe == 3)
                {
                    bb1.field8_0xe = 0;
                    BB_Atan(obj);
                }
                break;
            case 13:
                if (obj->sub_etat == 22)
                {
                    if (
                        obj->anim_frame == 63 &&
                        horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0
                    )
                        allocateTir(obj, 1);
                    if (
                        obj->anim_frame == 14 &&
                        horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xf] == 0 &&
                        screen_trembling2 == 0
                    )
                    {
                        screen_trembling2 = 1;
                        allocateTir(obj, 3);
                    }
                    if (FinAnim)
                    {
                        Phase = 11;
                        obj->iframes_timer = 35;
                        bb1.field8_0xe = 1;
                    }
                }
            }
            break;
        }
        if (FinAnim && bb1.field2_0x4 == 2)
            bb1.field2_0x4 = 0;
    }

    __asm__("nop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop\nnop");
}
#endif

/* still very rough */
/* 5A2A4 8017EAA4 -O2 -msoft-float */
/*INCLUDE_ASM("asm/nonmatchings/obj/bb1", DO_BBMONT2_COMMAND);*/

/*? CALC_MOV_ON_BLOC(Obj *);
? SET_X_SPEED(Obj *);*/
void set_main_and_sub_etat(Obj *, u8, u8);
/*extern s32 D_801F4438;
extern u8 D_801F4EBD;
extern ? D_801F4EDA;
extern s16 bb1.saved_cmd;
extern ? D_801F4EE2;
extern s16 bb1.sprite6_y;
extern s16 ray.speed_x;*/

void DO_BBMONT2_COMMAND(Obj *obj)
{
    s16 temp_s2;
    s16 temp_s3;
    s32 temp_v0_2;
    s16 temp_v0_3;
    s16 var_v0_2;
    s16 var_v1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v1_2;
    u16 temp_v0_4;
    u16 var_v0;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;

    temp_s2 = (u16) obj->x_pos + obj->offset_bx;
    temp_s3 = obj->offset_hy + (u16) obj->y_pos + 0x40;
    if ((obj->anim_frame == (obj->animations[obj->anim_index].frames_count - 1)) && (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0))
    {
        FinAnim = 1;
    }
    else
    {
        FinAnim = 0;
    }
    if (((u8) Phase < 2U) && (obj->main_etat != 2) && ((u32) ((ray_zdc_x - temp_s2) + 0x10) < 0x21U) && (ray_zdc_y < (temp_s3 - 0x20)))
    {
        set_main_and_sub_etat(obj, 0U, 0x10U);
        obj->speed_x = 0;
        obj->speed_y = 0;
    }
    if (obj->main_etat == 1)
    {
        if (Phase == 0)
        {
            Phase = 1;
        }
        SET_X_SPEED(obj);
        if ((u8) Phase < 4U)
        {
            CALC_MOV_ON_BLOC(obj);
        }
        if ((FinAnim != 0) && (bb1.speed_x != (obj->sub_etat + 1)))
        {
            switch (bb1.speed_x)
            {
            case 2:
                set_main_and_sub_etat(obj, 1U, 1U);
                break;
            case 3:
                set_main_and_sub_etat(obj, 1U, 2U);
                break;
            case 0:
            default:
                set_main_and_sub_etat(obj, 1U, 0U);
                break;
            }
        }
    }
    if ((bb1.field1_0x2 < 8) && (Phase != 0) && (Phase != 5))
    {
        if (scroll_end_x == xmapmax)
        {
            scroll_end_x = (s16) (u16) xmap;
            if ((s16) (u16) xmap < temp_s2)
            {
                scroll_end_x = temp_s2;
            }
        }
        else if (scroll_end_x < temp_s2)
        {
            bb1.saved_cmd = 1;
        }
        if (bb1.saved_cmd != 0)
        {
            if (obj->main_etat == 1)
            {
                scroll_end_x = (u16) scroll_end_x + (obj->sub_etat + 1);
            }
            else
            {
                var_v0 = (u16) scroll_end_x + (u16) obj->speed_x;
                goto block_37;
            }
        }
    }
    else
    {
        var_v0 = (u16) xmapmax;
block_37:
        scroll_end_x = (s16) var_v0;
    }
    switch (Phase)
    {
    case 0:
        temp_v0 = ((u8) block_flags[obj->btypes[0]] >> 1) & 5;
        var_a0 = 0x28;
        if ((temp_v0 == 0) && (var_a0 = 0x3C, (temp_v0 == 0)))
        {
            if (((temp_s2 + var_a0) < ray_zdc_x) && (obj->main_etat == 0) && (bb1.speed_x != 0))
            {
                obj->flags |= 0x4000;
                set_main_and_sub_etat(obj, 2U, 1U);
                obj->speed_y = 2;
                return;
            }
        }
        else if ((obj->main_etat == 0) && (obj->sub_etat == 0) && ((var_a0 + temp_s2) < ray_zdc_x))
        {
            Phase = 1;
            switch (bb1.speed_x)
            {
            case 2:
                set_main_and_sub_etat(obj, 1, 1);
                return;
            case 3:
                set_main_and_sub_etat(obj, 1, 2);
                return;
            case 0:
            default:
                set_main_and_sub_etat(obj, 1, 0);
                return;
            }
        }
        else
        {
            return;
        }
        break;
    case 1:
        if ((obj->main_etat == 1) &&
          ((block_flags
            [*(ushort *)
              (((((int)((int)obj->x_pos + (uint)obj->offset_bx) >> 4) +
                (int)mp.width * ((int)((int)obj->y_pos + (uint)obj->offset_by + 8) >> 4)) * 0x10000 >>
                0xf) + (int)mp.map) >> 10] >> 1 & 1) == 0)) {
            set_main_and_sub_etat(obj, 2U, 4U);
            obj->gravity_value_2 = 5;
            obj->gravity_value_1 = 0;
            obj->speed_y = -8;
            obj->speed_x = 3;
            return;
        }
        break;
    case 2:
        if ((obj->main_etat == 1) &&
          ((block_flags
            [*(ushort *)
              (((((int)((int)obj->x_pos + (obj->offset_bx - 8)) >> 4) +
                (int)mp.width * ((int)((int)obj->y_pos + (uint)obj->offset_by + 8) >> 4)) * 0x10000 >>
                0xf) + (int)mp.map) >> 10] >> 1 & 1) == 0)) {
            set_main_and_sub_etat(obj, 2U, 1U);
            obj->gravity_value_2 = 5;
            obj->gravity_value_1 = 0;
            obj->speed_y = 0;
            obj->speed_x = 0;
            bb1.field1_0x2 = -1;
            return;
        }
        break;
    case 3:
        if (scroll_end_x < 0x15CC)
        {
            var_v1 = 0x15CC;
        }
        scroll_end_x = var_v1;
        
        if (((temp_s2 + 0x20) < ray_zdc_x) && (bb1.field1_0x2 == -1) && (temp_s3 < ray_zdc_y))
        {
            if (bb1.speed_x != bb1.field1_0x2)
            {
                switch (bb1.speed_x)
                {
                case 2:
                    set_main_and_sub_etat(obj, 1U, 1U);
                    break;
                case 3:
                    set_main_and_sub_etat(obj, 1U, 2U);
                    break;
                case 0:
                default:
                    set_main_and_sub_etat(obj, 1U, 0U);
                    break;
                }
                bb1.field1_0x2 = 0;
            }
            else
            {
                temp_v0_2 = obj->field23_0x3c;
                temp_v0_3 = temp_v0_2 + 1; /* remove temp_v0_3 ? */
                if (temp_v0_2 < 0xC8)
                {
                    obj->field23_0x3c = temp_v0_3;
                    if (temp_v0_3 == 0x00C8)
                    {
                        bb1.speed_x = 1;
                        set_main_and_sub_etat(obj, 1U, 0U);
                        bb1.field1_0x2 = 0;
                        obj->field23_0x3c = 0x00FF;
                    }
                }
                scroll_end_x = xmap;
                if (xmap < temp_s2)
                {
                    var_v0_2 = xmap + ray.speed_x;
                    if (ray.speed_x <= 0)
                    {
                        var_v0_2 = xmap + 1;
                    }
                    scroll_end_x = var_v0_2;
                }
            }
        }
        if (FinAnim != 0)
        {
            if ((obj->main_etat == 0) && (obj->sub_etat == 0x10))
            {
                switch (bb1.speed_x)
                {
                case 2:
                    set_main_and_sub_etat(obj, 1U, 1U);
                    break;
                case 3:
                    set_main_and_sub_etat(obj, 1U, 2U);
                    break;
                case 0:
                default:
                    set_main_and_sub_etat(obj, 1U, 0U);
                    break;
                }
            }
            if ((FinAnim != 0) && (obj->main_etat == 0) && (obj->sub_etat == 1))
            {
                switch (bb1.speed_x)
                {
                case 2:
                    set_main_and_sub_etat(obj, 1U, 1U);
                    break;
                case 3:
                    set_main_and_sub_etat(obj, 1U, 2U);
                    break;
                case 0:
                default:
                    set_main_and_sub_etat(obj, 1U, 0U);
                    break;
                }
            }
        }
        if (obj->main_etat == 1)
        {
            if ((block_flags
                [*(ushort *)
                  (((((int)((int)obj->x_pos + (obj->offset_bx - 8)) >> 4) +
                    (int)mp.width * ((int)((int)obj->y_pos + (uint)obj->offset_by + 8) >> 4)) * 0x10000
                    >> 0xf) + (int)mp.map) >> 10] >> 1 & 1) == 0) {
                obj->speed_y = -6;
                obj->speed_x = 3;
                set_main_and_sub_etat(obj, 2U, 4U);
                obj->gravity_value_2 = 5;
                obj->gravity_value_1 = 0;
            }
            if ((obj->main_etat != 2) && ((u32) ((ray_zdc_x - temp_s2) + 0x10) < 0x21U))
            {
                if (ray_zdc_y < (temp_s3 - 0x20))
                {
                    set_main_and_sub_etat(obj, 0U, 0x10U);
                    obj->speed_y = 0;
                }
                else
                {
                    set_main_and_sub_etat(obj, 0U, 1U);
                    obj->speed_y = 0;
                }
                obj->speed_x = 0;
                return;
            }
        }
        break;
    case 4:
        if (bb1.sprite6_y < scroll_end_y)
        {
            scroll_end_y -= 1;
        }
        if (FinAnim != 0)
        {
            temp_v1 = obj->main_etat;
            if ((temp_v1 == 2) && (obj->sub_etat == temp_v1))
            {
                bb1.speed_x = 1;
                goto block_124;
            }
            if ((obj->main_etat == 0) && (obj->sub_etat == 5))
            {
                temp_v0_4 = bb1.sprite6_x + 1;
                bb1.sprite6_x = temp_v0_4;
                if ((s16) temp_v0_4 < 3)
                {
                    bb1.speed_x = 1;
block_124:
                    set_main_and_sub_etat(obj, 1U, 0U);
                }
                else
                {
                    set_main_and_sub_etat(obj, 0U, 2U);
                    Phase = 5;
                    bb1.sprite6_y = ymap;
                }
            }
        }
        var_v0_3 = temp_s2 << 0x10;
        if (obj->main_etat == 1)
        {
            temp_v1_2 = obj->offset_bx;
            var_v0_4 = temp_v1_2 + 0x10;
            if (!(obj->flags & 0x4000))
            {
                var_v0_4 = temp_v1_2 - 0x10;
            }
            var_v0_3 = temp_s2 << 0x10;
            if ((block_flags
                [*(ushort *)
                  ((((obj->x_pos + var_v0_4 >> 4) +
                    (int)mp.width * ((int)((int)obj->y_pos + (uint)obj->offset_by + 8) >> 4)) * 0x10000
                    >> 0xf) + (int)mp.map) >> 10] >> 1 & 1) == 0) {
                obj->speed_y = 0;
                obj->speed_x = 0;
                obj->flags = (obj->flags & ~0x4000) | (((1 - (((u32) obj->flags >> 0xE) & 1)) & 1) << 0xE);
                set_main_and_sub_etat(obj, 0U, 5U);
                var_v0_3 = temp_s2 << 0x10;
            }
        }
        if (((var_v0_3 >> 0x10) - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) >= 0)
        {
            if ((temp_s2 - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) < 0xFB)
            {
                return;
            }
            goto block_172;
        }
        var_v1_2 = ((ray_zdc_x + ((s16) ray_zdc_w >> 1)) - temp_s2) < 0xFB;
block_171:
        if (var_v1_2 == 0)
        {
block_172:
            obj->flags &= ~0x400;
            IsBossThere = 0;
            Phase = 0;
            scroll_end_x = (s16) (u16) xmapmax;
            scroll_end_y = (s16) (u16) ymapmax;
            obj->flags &= ~0x800;
        }
        break;
    case 5:
        if (bb1.field1_0x2 < 0)
        {
            scroll_end_y = (u16) bb1.sprite6_y - horloge[5];
            bb1.field1_0x2 = (s16) ((u16) bb1.field1_0x2 + 1);
        }
        if (FinAnim != 0)
        {
            if (obj->main_etat == 0)
            {
                if (obj->sub_etat == 5)
                {
                    bb1.speed_x = 3;
                    switch (bb1.speed_x)
                    {
                    case 2:
                        set_main_and_sub_etat(obj, 1U, 1U);
                        break;
                    case 3:
                        set_main_and_sub_etat(obj, 1U, 2U);
                        break;
                    default:
                        set_main_and_sub_etat(obj, 1U, 0U);
                        break;
                    }
                }
                goto block_147;
            }
        }
        else
        {
block_147:
            if ((obj->main_etat == 0) && (obj->sub_etat == 2))
            {
                if (FinAnim != 0)
                {
                    bb1.speed_x = 2;
                    switch (bb1.speed_x)
                    {
                    case 2:
                        set_main_and_sub_etat(obj, 1U, 1U);
                        break;
                    case 3:
                        set_main_and_sub_etat(obj, 1U, 2U);
                        break;
                    default:
                        set_main_and_sub_etat(obj, 1U, 0U);
                        break;
                    }
                }
                else if ((obj->anim_frame == 0x15) && (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0))
                {
                    bb1.field1_0x2 = -0x001E;
                }
            }
        }
        var_v0_5 = temp_s2 << 0x10;
        if (obj->main_etat == 1)
        {
            temp_v1_3 = obj->offset_bx;
            var_v0_6 = temp_v1_3 + 0x10;
            if (!(obj->flags & 0x4000))
            {
                var_v0_6 = temp_v1_3 - 0x10;
            }
            var_v0_5 = temp_s2 << 0x10;
            if ((block_flags
           [*(ushort *)
             ((((obj->x_pos + var_v0_6 >> 4) +
               (int)mp.width * ((int)((int)obj->y_pos + (uint)obj->offset_by + 8) >> 4)) * 0x10000
              >> 0xf) + (int)mp.map) >> 10] >> 1 & 1) == 0) {
                if (bb1.speed_x == 3)
                {
                    set_main_and_sub_etat(obj, 2U, 4U);
                    obj->gravity_value_2 = 0xFF;
                    obj->gravity_value_1 = 0;
                    obj->speed_y = -2;
                    obj->speed_x = 4;
                    scroll_end_y = (s16) (u16) ymapmax;
                    scroll_end_x = (s16) (u16) xmapmax;
                    var_v0_5 = temp_s2 << 0x10;
                }
                else
                {
                    obj->speed_y = 0;
                    obj->speed_x = 0;
                    obj->flags = (obj->flags & ~0x4000) | (((1 - (((u32) obj->flags >> 0xE) & 1)) & 1) << 0xE);
                    set_main_and_sub_etat(obj, 0U, 5U);
                    var_v0_5 = temp_s2 << 0x10;
                }
            }
        }
        if (((var_v0_5 >> 0x10) - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) >= 0)
        {
            if ((temp_s2 - (ray_zdc_x + ((s16) ray_zdc_w >> 1))) < 0x191)
            {
                return;
            }
            goto block_172;
        }
        var_v1_2 = ((ray_zdc_x + ((s16) ray_zdc_w >> 1)) - temp_s2) < 0x191;
        goto block_171;
    }
}