#include "draw/rollup_trans.h"

extern DVECTOR D_801CEDE4;
extern DVECTOR D_801CEDE8;
extern s16 D_801D7A78;
extern SVECTOR D_801F3EC0[82];
extern SVECTOR D_801F56B8;
extern VECTOR D_801F57D0;
extern s16 D_801F84D8;
extern s16 D_801F98F8;
extern s16 D_801F9930;
extern s16 D_801F9938;

/* 8830 8012D030 -O2 -msoft-float */
void FUN_8012d030(DVECTOR tpage_pos, DVECTOR param_2, s16 step_width, s16 step_height, s16 poly_count)
{
    s16 cnt_x; s16 pos_x;
    s16 unk_1;
    s16 unk_x_1;
    s16 cnt_y; s16 pos_y;
    u8 unk_y_1;
    u8 unk_y_2;
    u16 tpage_1 = GetTPage(2, 1, tpage_pos.vx, tpage_pos.vy);
    u16 tpage_2 = GetTPage(2, 1, tpage_pos.vx + 128, tpage_pos.vy);
    s16 steps_x = 320 / step_width;
    s16 steps_y = 240 / step_height;
    POLY_FT4 *poly_1 = &PS1_Display1.polygons[poly_count];
    POLY_FT4 *poly_2 = &(&PS1_Display1 + 1)->polygons[poly_count];

    pos_x = 0;
    cnt_x = 0;
    while (cnt_x < steps_x)
    {
        unk_1 = pos_x < 128;
        unk_x_1 = pos_x;
        if (!unk_1)
            unk_x_1 = pos_x - 128;
        
        cnt_y = 0;
        pos_y = 0;
        while (cnt_y < steps_y)
        {
            poly_1->u0 = unk_x_1;
            poly_1->v0 = pos_y;
            poly_1->u1 = unk_x_1 + step_width;
            poly_1->v1 = pos_y;
            poly_1->u2 = unk_x_1;
            unk_y_1 = pos_y + step_height;
            poly_1->v2 = unk_y_1;
            poly_1->u3 = unk_x_1 + step_width;
            poly_1->v3 = unk_y_1;
            if (unk_1)
                poly_1->tpage = tpage_1;
            else
                poly_1->tpage = tpage_2;
            
            poly_2->u0 = unk_x_1;
            poly_2->v0 = pos_y;
            poly_2->u1 = unk_x_1 + step_width;
            poly_2->v1 = pos_y;
            poly_2->u2 = unk_x_1;
            unk_y_2 = pos_y + step_height;
            poly_2->v2 = unk_y_2;
            poly_2->u3 = unk_x_1 + step_width;
            poly_2->v3 = unk_y_2;
            if (unk_1)
                poly_2->tpage = tpage_1;
            else
                poly_2->tpage = tpage_2;
            
            cnt_y++;
            pos_y += step_height;
            poly_1++;
            poly_2++;
        }
        
        cnt_x++;
        pos_x += step_width;
    }
}

/* 8A7C 8012D27C -O2 -msoft-float */
void FUN_8012d27c(void)
{
    InitGeom();
    SetGeomOffset(160, 120);
    SetGeomScreen(1024);
}

/* 8AB0 8012D2B0 -O2 -msoft-float */
void FUN_8012d2b0(s16 param_1)
{
    SVECTOR *cur_vec;
    s16 cnt_x; s16 pos_x;
    s16 cnt_y; s16 pos_y;

    PS1_PolygonsCount = 0;
    FUN_8012d27c();
    D_801F9930 = 8;
    D_801F9938 = 240;
    FUN_8012d030(D_801CEDE4, D_801CEDE8, D_801F9930, D_801F9938 - 1, PS1_PolygonsCount + 2);
    D_801F84D8 = 320 / D_801F9930;
    D_801F98F8 = 240 / D_801F9938;

    cur_vec = D_801F3EC0;
    pos_x = 0;
    cnt_x = 0;
    while (cnt_x < D_801F84D8 + 1)
    {
        pos_y = 0;
        cnt_y = 0;
        while (cnt_y < D_801F98F8 + 1)
        {
            cur_vec->vx = pos_x - 160;
            if (pos_y == 240)
                pos_y = 240 - 1;
            cur_vec->vy = pos_y - 120;
            cur_vec->vz = 0;
            cnt_y++;
            pos_y += D_801F9938;
            cur_vec++;
        }
        cnt_x++;
        pos_x += D_801F9930;
    }
    D_801F56B8.vz = 0; D_801F56B8.vy = 0; D_801F56B8.vx = 0;
    D_801F57D0.vy = 0; D_801F57D0.vx = 0; D_801F57D0.vz = 1024;
    D_801D7A78 = param_1;
}

INCLUDE_ASM("asm/nonmatchings/draw/rollup_trans", PS1_RollUpTransition);

INCLUDE_ASM("asm/nonmatchings/draw/rollup_trans", PS1_RollUpRToL);

INCLUDE_ASM("asm/nonmatchings/draw/rollup_trans", PS1_RollUpLToR);

INCLUDE_ASM("asm/nonmatchings/draw/rollup_trans", FUN_8012da14);
