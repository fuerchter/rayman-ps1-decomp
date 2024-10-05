#include "obj/clown_tnt_command.h"

void DO_CLOWN_TNT_ATTACK(Obj *obj);

/* 4C3A0 80170BA0 -O2 -msoft-float */
void DO_CLOWN_TNT_COMMAND(Obj *obj)
{
    s16 diff_x;
    s32 unk_x;
    s32 offs_bx;

    if (obj->main_etat == 0 && obj->sub_etat == 2)
    {
        obj->speed_y = -8;
        obj->speed_x = 0;
        obj->flags &= ~FLG(OBJ_READ_CMDS);
        return;
    }

    switch (obj->cmd)
    {
    case GO_WAIT:
        break;
    case GO_SPEED:
        obj->speed_x =  obj->iframes_timer;
        obj->speed_y =  obj->field20_0x36;
        break;
    case GO_LEFT:
    case GO_RIGHT:
        if (obj->cmd == GO_LEFT)
            obj->flags &= ~FLG(OBJ_FLIP_X);
        else
            obj->flags |= FLG(OBJ_FLIP_X);
        break;
    default:
        break;
    }

    diff_x = (obj->x_pos + obj->offset_bx) - ray.x_pos - ray.offset_bx - (ray.speed_x * 2);
    unk_x = 10;
    if (diff_x < -unk_x)
    {
        if (!(obj->flags & FLG(OBJ_FLIP_X)))
        {
            if (obj->sub_etat != 6)
            {
                obj->flags |= FLG(OBJ_FLIP_X);
                skipToLabel(obj, 4, true);
            }
        }
        else
            obj->speed_x = 3;
    }
    else if (diff_x > unk_x)
    {
        if (obj->flags & FLG(OBJ_FLIP_X))
        {
            if (obj->sub_etat != 6)
            {
                obj->flags &= ~FLG(OBJ_FLIP_X);
                skipToLabel(obj, 3, true);
            }
        }
        else
            obj->speed_x = -3;
    }
    else
        obj->speed_x = 0;
    
    offs_bx = obj->offset_bx;
    if (obj->flags & FLG(OBJ_FLIP_X))
        offs_bx += 16;
    else
        offs_bx -= 16;
    
    if (on_block_chdir(obj, offs_bx, obj->offset_by))
        obj->speed_x = 0;
    
    if (obj->main_etat == 0)
    {
        if (obj->sub_etat == 3)
        {
            if (obj->y_pos <= obj->init_y_pos)
            {
                obj->speed_y = 0;
                obj->field24_0x3e = 0;
                obj->y_pos = obj->init_y_pos;
                skipToLabel(obj, 2, true);
            }
        }
        else if (obj->sub_etat == 6)
        {
            if (obj->anim_frame > 15 && obj->field24_0x3e == 1)
            {
                DO_CLOWN_TNT_ATTACK(obj);
                obj->field24_0x3e = 2;
            }
        }
    }

    if (obj->field24_0x3e != 0)
    {
        obj->timer++;
        if (obj->timer > 80)
        {
            obj->timer = 0;
            obj->field24_0x3e = 0;
        }
    }
}

/* 4C654 80170E54 -O2 -msoft-float */
void DO_CLOWN_TNT2_COMMAND(Obj *obj)
{
    if (obj->main_etat == 0 && obj->sub_etat == 2)
    {
        obj->speed_y = -8;
        obj->speed_x = 0;
        obj->flags &= ~FLG(OBJ_READ_CMDS);
        return;
    }

    switch (obj->cmd)
    {
    case GO_WAIT:
        break;
    case GO_SPEED:
        obj->speed_x = obj->iframes_timer;
        obj->speed_y = obj->field20_0x36;
        break;
    case GO_LEFT:
    case GO_RIGHT:
        if (obj->cmd == GO_LEFT)
            obj->flags &= ~FLG(OBJ_FLIP_X);
        else
            obj->flags |= FLG(OBJ_FLIP_X);
        break;
    default:
        break;
    }
    if (obj->main_etat == 0 && obj->sub_etat == 8)
    {
        if (obj->field24_0x3e == 0 && obj->anim_frame > 5)
        {
            DO_CLOWN_TNT_ATTACK(obj);
            obj->field24_0x3e = 1;
        }
        else if (obj->anim_frame == 1)
            obj->field24_0x3e = 0;
    }
}

/* 4C780 80170F80 -O2 -msoft-float */
void DO_CLOWN_TNT3_COMMAND(Obj *obj)
{
    s16 diff_x; s16 diff_y;

    if (obj->main_etat == 0 && obj->sub_etat == 2)
    {
        obj->speed_y = -8;
        obj->speed_x = 0;
        obj->flags &= ~FLG(OBJ_READ_CMDS);
        return;
    }

    switch (obj->cmd)
    {
    case GO_WAIT:
        break;
    case GO_SPEED:
        obj->speed_x = obj->iframes_timer;
        obj->speed_y = obj->field20_0x36;
        break;
    case GO_LEFT:
    case GO_RIGHT:
        if (obj->cmd == GO_LEFT)
            obj->flags &= ~FLG(OBJ_FLIP_X);
        else
            obj->flags |= FLG(OBJ_FLIP_X);
        SET_X_SPEED(obj);
        break;
    }
    diff_x = (obj->x_pos + obj->offset_bx) - ray.x_pos - ray.offset_bx;
    diff_y = (ray.y_pos + ray.offset_by) - obj->y_pos - obj->offset_by;
    if (obj->field24_0x3e == 0)
    {
        if (diff_y < 18)
            obj->speed_y = 0;
        else if (diff_y < 40)
            obj->speed_y = 1;
        else if (diff_y < 65)
            obj->speed_y = 2;
        else if (diff_y < 100)
            obj->speed_y = 3;
        else
        {
            if (__builtin_abs(diff_x) < 165)
                obj->speed_y = 4;
            else
                obj->speed_y = 0;
        }

        if (
            (obj->flags & FLG(OBJ_FLIP_X) && diff_x > 90) || /* TODO: use ternary instead? other places like this? */
            (!(obj->flags & FLG(OBJ_FLIP_X)) && diff_x < -90)
        )
            obj->field24_0x3e = 1;
    }
    else
    {
        if (diff_y > 120)
            obj->speed_y = -2;
        else
            obj->speed_y = -1;
    }
}
