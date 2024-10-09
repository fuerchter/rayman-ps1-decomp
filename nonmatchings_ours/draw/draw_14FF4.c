#include "draw/draw_14FF4.h"

/* matches, but gross */
/*INCLUDE_ASM("asm/nonmatchings/draw/draw_14FF4", display_bar_boss);*/

void display_bar_boss(Obj *boss_obj)
{
    u8 hp;
    Obj *poing_obj;
    u8 init_hp;
    s32 unk_1;
    s32 unk_2;
    s32 unk_3;
    s32 disp_mode;

    if (scrollLocked)
    {
        hp = boss_obj->hit_points;
        if (hp != 0)
        {
            poing_obj = &level.objects[poing_obj_id];
            init_hp = boss_obj->init_hit_points;
            unk_1 = 6;
            unk_2 = (29 - init_hp) * unk_1;
            unk_3 = 20 - unk_2;
            disp_mode = 1;
            display_sprite(poing_obj, 61, unk_3 - (init_hp - hp) * unk_1, 217, disp_mode);
            display_sprite(poing_obj, 60, 20 - unk_2 + 1, 216, disp_mode);
            switch (boss_obj->type)
            {
            case TYPE_MOSKITO:
                display_sprite(poing_obj, 62, 0, 206, disp_mode);
                break;
            case TYPE_MOSKITO2:
                display_sprite(poing_obj, 62, 0, 206, disp_mode);
                break;
            case TYPE_BB1:
                display_sprite(poing_obj, 106, 0, 206, disp_mode);
                break;
            case TYPE_BB12:
                display_sprite(poing_obj, 106, 0, 206, disp_mode);
                break;
            case TYPE_SPACE_MAMA:
                display_sprite(poing_obj, 108, 0, 206, disp_mode);
                break;
            case TYPE_SPACE_MAMA2:
                display_sprite(poing_obj, 108, 0, 206, disp_mode);
                break;
            case TYPE_MAMA_PIRATE:
                display_sprite(poing_obj, 111, 0, 206, disp_mode);
                break;
            case TYPE_SCORPION:
                display_sprite(poing_obj, 107, 0, 206, disp_mode);
                break;
            case TYPE_HYB_BBF2_D:
                display_sprite(poing_obj, 110, 0, 206, disp_mode);
                break;
            case TYPE_HYBRIDE_STOSKO:
                display_sprite(poing_obj, 110, 0, 206, disp_mode);
                break;
            case TYPE_HYBRIDE_MOSAMS:
                display_sprite(poing_obj, 110, 0, 206, disp_mode);
                break;
            case TYPE_DARK:
                display_sprite(poing_obj, 110, 0, 206, disp_mode);
                break;
            case TYPE_SAXO:
            case TYPE_SAXO2:
                display_sprite(poing_obj, 109, 0, 206, disp_mode);
                break;
            }
        }
    }
}

/*INCLUDE_ASM("asm/nonmatchings/draw/draw_14FF4", DISPLAY_ALL_OBJECTS);*/

void DISPLAY_ALL_OBJECTS(void)
{
    short sVar1;
    Display *pDVar2;
    Display *pDVar3;
    s16 uVar4;
    u_short uVar5;
    s16 iVar6;
    Obj *new_var4;
    ObjType obj_type;
    uint uVar8;
    short cnt_1;
    Obj *obj;
    s16 iVar10;
    s16 prio;
    Obj *new_var;
    s16 test_1;
    s16 *test_2;
    ActiveObjects *new_var2;
    s16 *new_var3;

    PS1_BossObj = null;
    prio = 7;
    PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[6];
    while (true)
    {
        cnt_1 = 0;
        obj = &level.objects[actobj.objects[cnt_1]];
        while (cnt_1 < actobj.num_active_objects)
        {
            if (prio == 1 && (flags[obj->type].flags0 >> OBJ0_BOSS & 1))
                PS1_BossObj = obj;
            
            if (obj->display_prio == prio)
            {
                if (num_world == 5 && num_level == 4 && obj->type == TYPE_MEDAILLON_TOON)
                {
                    PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[10];
                    display2(obj);
                    PS1_PrevPrim = &PS1_CurrentDisplay->ordering_table[6];
                }
                else if (obj->type == TYPE_EAU && num_world == 5 && num_level == 8)
                {
                    PS1_DrawSpriteSemiTrans = true;
                    if (obj->x_pos >= 300)
                        display2(obj);
                    PS1_DrawSpriteSemiTrans = false;
                }
                else
                {
                    obj_type = obj->type;
                    if (obj_type == TYPE_CYMBALE)
                        DISPLAY_CYMBALE(obj, true);
                    else if (
                        !(
                            obj_type == TYPE_NEIGE || obj_type == TYPE_PALETTE_SWAPPER ||
                            obj_type == TYPE_GENERATING_DOOR ||
                            (obj_type == TYPE_MST_SCROLL && obj->hit_points != 0) ||
                            obj_type == TYPE_SCROLL_SAX || obj_type == TYPE_BB1_VIT
                        )
                    )
                    {
                        if (obj_type == TYPE_LAVE)
                        {
                            if (D_801E4DF8 != D_801CEF7A)
                            {
                                SetPolyG4(&PS1_CurrentDisplay->field_0x6094_0x60b7);
                                SetSemiTrans(&PS1_CurrentDisplay->field_0x6094_0x60b7, true);
                                SetShadeTex(&PS1_CurrentDisplay->field_0x6094_0x60b7, true);
                                
                                PS1_CurrentDisplay->field_0x6094_0x60b7.x0 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.y0 = obj->screen_y_pos + 25;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.x1 = SCREEN_WIDTH;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.y1 = obj->screen_y_pos + 25;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.x2 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.y2 = obj->screen_y_pos + 90;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.x3 = SCREEN_WIDTH;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.y3 = obj->screen_y_pos + 90;

                                PS1_CurrentDisplay->field_0x6094_0x60b7.r0 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.g0 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.b0 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.r1 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.g1 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.b1 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.r2 = 173;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.g2 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.b2 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.r3 = 176;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.g3 = 0;
                                PS1_CurrentDisplay->field_0x6094_0x60b7.b3 = 0;
                                AddPrim(&PS1_CurrentDisplay->ordering_table[9], &PS1_CurrentDisplay->field_0x6094_0x60b7);
                                PS1_CurrentDisplay->drawing_environment.tpage = GetTPage(1, 1, 256, 0);
                                SetDrawEnv(
                                    &PS1_CurrentDisplay->map_drawing_environment_primitives[(u16) D_801E4BE0],
                                    &PS1_CurrentDisplay->drawing_environment
                                );
                                AddPrim(
                                    &PS1_CurrentDisplay->ordering_table[9],
                                    &PS1_CurrentDisplay->map_drawing_environment_primitives[(u16) D_801E4BE0]
                                );
                                D_801E4BE0++;
                                D_801CEF7A = D_801E4DF8;
                            }
                            PS1_DrawSpriteSemiTrans = false;
                            display2(obj);
                        }
                        else
                        {
                            PS1_DrawSpriteSemiTrans = false;
                            display2(obj);
                            PS1_DrawSpriteSemiTrans = false;
                        }
                    }
                }
            }
            cnt_1++;
            obj = &level.objects[actobj.objects[cnt_1]];
        }

        if (prio == 3)
        {
            if (ray.iframes_timer % 2 || ray.iframes_timer > 90)
            {
                if (((ray.flags & (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE))) == (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE))))
                    display2(&ray);
            }
            DISPLAY_POING();
        }
        else if (prio == 2 && nb_cymbal_in_map != 0)
        {
            for (cnt_1 = 0; cnt_1 < nb_cymbal_in_map; cnt_1++)
            {
                obj = (new_var4 = &level.objects[cymbal_obj_id[cnt_1]]);
                if (obj->flags & FLG(OBJ_ACTIVE)) /* getting rid of brackets worsens score??? */
                {
                    DISPLAY_CYMBALE(obj, false);
                }
            }
        }
        
        prio--;
        if (prio < 1)
        {
            cnt_1 = 0;
            new_var2 = &actobj;
            new_var3 = actobj.objects;
            obj = &level.objects[new_var3[cnt_1]];
            while (cnt_1 < new_var2->num_active_objects)
            {
                cnt_1 = cnt_1 + 1;
                new_var3 = actobj.objects;
                if ((obj->display_prio == 0) && (obj->type == TYPE_DUNE))
                {
                    display2(obj);
                    PS1_DrawSpriteSemiTrans = false;
                    return;
                }
                obj = &level.objects[new_var3[cnt_1]];
            }

            PS1_DrawSpriteSemiTrans = false;
            return;
        }
    }
}