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

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_COMMAND);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_POING_COLLISION);

INCLUDE_ASM("asm/nonmatchings/obj/dark_729F0", DO_DARK_REACT);

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
