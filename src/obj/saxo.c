#include "obj/saxo.h"

/* 50CDC 801754DC -O2 -msoft-float */
void INIT_SAXO(Obj *sax_obj)
{
  sax_obj->y_pos = firstFloorBelow(sax_obj) - sax_obj->offset_by;
  calc_obj_pos(sax_obj);
  sax_obj->speed_x = 0;
  sax_obj->speed_y = 0;
  Phase = 0;
  IsBossThere = false;
  IndexSerie = 0;
  sax_obj->flags = (sax_obj->flags | FLG(OBJ_ALIVE)) & ~FLG(OBJ_ACTIVE);
  if (sax_obj->type == TYPE_SAXO)
    sax_obj->hit_points = Sax.saved_hp;
  Sax.coup = 0;
  D_801F7FA0 = 0;
  Sax.field10_0x10 = 0;
}

/* TODO: param_2 */
/* 50D7C 8017557C -O2 -msoft-float */
void allocateNote2(Obj *note_obj, s16 param_2)
{
  Obj *cur_obj;
  s16 i;
  u8 nb_objs;
  u8 offs_half;
  u16 offs_x;
  
  if (note_obj->iframes_timer > 0)
  {
    cur_obj = level.objects;
    i = 0;
    nb_objs = level.nb_objects;
    if (nb_objs != 0)
    {
      do {
        if (cur_obj->type == TYPE_NOTE2 && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
        {
          cur_obj->flags &= ~FLG(OBJ_FLIP_X);
          cur_obj->speed_y = 0;
          cur_obj->speed_x = 0;

          offs_half = note_obj->offset_bx / 2;
          offs_x = offs_half;
          if (param_2 != 0)
            offs_x = -offs_half;
          cur_obj->x_pos = offs_x + note_obj->x_pos;
          cur_obj->y_pos = note_obj->y_pos;
          
          cur_obj->main_etat = 0;
          cur_obj->sub_etat = param_2 + 2;
          cur_obj->init_x_pos = cur_obj->x_pos;
          cur_obj->init_y_pos = cur_obj->y_pos;
          skipToLabel(cur_obj,1,true);
          calc_obj_pos(cur_obj);
          cur_obj->flags = (cur_obj->flags | FLG(OBJ_ALIVE)) & ~FLG(OBJ_FLAG_9) | FLG(OBJ_ACTIVE);
          cur_obj->gravity_value_1 = 0;
          cur_obj->iframes_timer = note_obj->iframes_timer - 1;
          calc_obj_pos(cur_obj);
          cur_obj->field23_0x3c = 10;
          allocateExplosion(cur_obj);
          break;
        }
        cur_obj++;
        i++;
      } while (i < nb_objs);
    }
  }
}

/* 50EE0 801756E0 -O2 -msoft-float */
void DO_EXPLOSE_NOTE2(Obj *obj)
{
  obj->speed_x = 0;
  obj->speed_y = 0;
  calc_obj_pos(obj);
  set_main_and_sub_etat(obj, 0, 1);
  PlaySnd(0xf6, obj->id);
  allocateExplosion(obj);
  obj->field23_0x3c = 10;
  obj->iframes_timer = 3;
}

/* 50F40 80175740 -O2 -msoft-float */
/*? PlaySnd(?, s16, s16);
? allocateExplosion(Obj *);
? set_main_and_sub_etat(Obj *, ?, ?);*/

void DO_NOTE_CMD(Obj *obj)
{
    s16 calc_x;
    s32 offs_x;
    u8 var_v1;
    u8 temp_v0_2;

    switch (obj->type)
    {
    case TYPE_NOTE3:
        if (obj->speed_x == 0)
        {
            calc_x = obj->offset_bx + obj->x_pos - Sax.note_box_coll_x;
            if (calc_x < 20)
            {
                set_main_and_sub_etat(obj, 2, 0);
                obj->speed_x = 3;
                obj->flags |= FLG(OBJ_FLIP_X);
            }
            else if (calc_x < 200)
            {
                /* vibrate back and forth the closer sax gets */
                var_v1 = (calc_x >> 3) - 2;
                offs_x = 1;
                if (var_v1 < 2)
                    var_v1 = 2;
                temp_v0_2 = var_v1;
                if (calc_x < 50)
                    offs_x = 2;
                
                if (horloge[temp_v0_2] < (temp_v0_2 / 2))
                    obj->x_pos = obj->init_x_pos + offs_x;
                else
                    obj->x_pos = obj->init_x_pos;
            }
        }
        break;
    case TYPE_NOTE2:
        if (obj->main_etat == 0)
        {
            obj->field23_0x3c--;
            if(obj->field23_0x3c == 0)
            {
                switch (obj->sub_etat)
                {
                case 1:
                    allocateNote2(obj, 1);
                    /* fall through */
                case 2:
                    allocateNote2(obj, 0);
                    obj->flags &= ~FLG(OBJ_ACTIVE);
                    obj->flags &= ~FLG(OBJ_ALIVE);
                    break;
                case 3:
                    allocateNote2(obj, 1);
                    obj->flags &= ~FLG(OBJ_ACTIVE);
                    obj->flags &= ~FLG(OBJ_ALIVE);
                    break;
                }
            }
        }
        break;
    case TYPE_BONNE_NOTE:
        if (
            inter_box(
                obj->x_pos + obj->offset_bx - 8,
                obj->y_pos + obj->offset_by - 8,
                16,
                16,
                Sax.note_box_coll_x,
                Sax.note_box_coll_y,
                20,
                140
            )
        )
        {
            if (Sax.coup == 0)
                Sax.coup = 1;
            obj->flags &= ~FLG(OBJ_ACTIVE);
            obj->flags &= ~FLG(OBJ_ALIVE);
            obj->y_pos += 30;
            PlaySnd(0xF3, obj->id);
            allocateExplosion(obj);
        }
        break;
    }
}

/* 511C4 801759C4 -O2 -msoft-float */
/*? calc_obj_pos(Obj *);
? skipToLabel(Obj *, ?, ?);*/

void Cree_Eclat_Note(Obj *bnote, Obj *note1, s16 index)
{
  s16 speed_x;
  
  if (bnote->type == TYPE_BNOTE)
  {
    if (bnote->flags & FLG(OBJ_ACTIVE))
    {
        do {
            bnote++;
            if (bnote->type != TYPE_BNOTE)
                return;
        } while (bnote->flags & FLG(OBJ_ACTIVE));
    }
  }

  if (bnote->type == TYPE_BNOTE)
  {
    if (index < 4)
    {
        bnote->flags = (bnote->flags & ~FLG(OBJ_FLIP_X)) | ((index % 2) & 1) << OBJ_FLIP_X;
        if (index < 2)
            bnote->speed_y = -1;
        else
            bnote->speed_y = 1;

        if (bnote->flags & FLG(OBJ_FLIP_X))
            speed_x = 1;
        else
            speed_x = -1;
        bnote->speed_x = speed_x;
    }
    else
    {
        bnote->flags = (bnote->flags & ~FLG(OBJ_FLIP_X)) | ((index % 2) & 1) << OBJ_FLIP_X;
        switch(index)
        {
        case 4:
            bnote->speed_y = 0;
            bnote->speed_x = -2;
            break;
        case 5:
            bnote->speed_x = 2;
            bnote->speed_y = 0;
            break;
        case 6:
            bnote->speed_x = 0;
            bnote->speed_y = -2;
            break;
        case 7:
            bnote->speed_x = 0;
            bnote->speed_y = 2;
            break;
        }
    }
    bnote->x_pos = note1->x_pos;
    bnote->y_pos = note1->y_pos;
    bnote->main_etat = 2;
    bnote->sub_etat = 5;
    skipToLabel(bnote, 1, true);
    calc_obj_pos(bnote);
    bnote->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
    calc_obj_pos(bnote);
  }
}

/* 513AC 80175BAC -O2 -msoft-float */
void DO_EXPLOSE_NOTE1(Obj *obj)
{
  Obj *cur_obj;
  s16 i;
  u8 nb_objs_1;
  u8 nb_objs_2;
  
  cur_obj = level.objects;
  i = 0;
  nb_objs_1 = level.nb_objects;
  if (nb_objs_1 != 0)
  {
    nb_objs_2 = nb_objs_1;
    do {
      if (cur_obj->type == TYPE_BNOTE && !(cur_obj->flags & FLG(OBJ_ACTIVE)))
      {
        PlaySnd(0xf4,obj->id);
        allocateExplosion(obj);
        Cree_Eclat_Note(cur_obj,obj,0);
        cur_obj++;
        Cree_Eclat_Note(cur_obj,obj,1);
        cur_obj++;
        Cree_Eclat_Note(cur_obj,obj,2);
        cur_obj++;
        Cree_Eclat_Note(cur_obj,obj,3);
        cur_obj++;
        Cree_Eclat_Note(cur_obj,obj,4);
        cur_obj++;
        Cree_Eclat_Note(cur_obj,obj,5);
        cur_obj++;
        Cree_Eclat_Note(cur_obj,obj,6);
        cur_obj++;
        Cree_Eclat_Note(cur_obj,obj,7);
        obj->flags &= ~FLG(OBJ_ACTIVE);
        obj->flags &= ~FLG(OBJ_ALIVE);
        break;
      }
      cur_obj++;
      i++;
    } while (i < nb_objs_2);
  }
}

/* 514F4 80175CF4 -O2 -msoft-float */
void BonneNote(Obj *orig_obj)
{
  Obj *obj;
  s16 i;
  u8 nb_objs;
  s16 speed_x;
  
  obj = level.objects;
  i = 0;
  nb_objs = level.nb_objects;
  if (nb_objs != 0)
  {
    do {
      if (obj->type == TYPE_BONNE_NOTE && !(obj->flags & FLG(OBJ_ACTIVE)))
      {
        if (orig_obj->speed_x == 0)
        {
          obj->flags &= ~FLG(OBJ_FLIP_X);
          obj->speed_x = -1;
          obj->speed_y = -4;
          obj->gravity_value_2 = 10;
          obj->field23_0x3c = 2;
        }
        else
        {
          speed_x = 4;
          if (level.objects[poing_obj_id].speed_x < 0)
            speed_x = -4;
          obj->speed_x = speed_x;
          if (speed_x < 0)
            obj->flags &= ~FLG(OBJ_FLIP_X);
          else
            obj->flags |= FLG(OBJ_FLIP_X);
          obj->gravity_value_2 = 0xff;
          obj->field23_0x3c = 1;
          obj->speed_y = -1;
        }
        obj->x_pos = orig_obj->x_pos;
        obj->y_pos = orig_obj->y_pos;
        obj->main_etat = 2;
        obj->sub_etat = 3;
        obj->init_x_pos = obj->x_pos;
        skipToLabel(obj, 1, true);
        calc_obj_pos(obj);
        obj->gravity_value_1 = 0;
        
        obj->flags |= (FLG(OBJ_ALIVE)|FLG(OBJ_ACTIVE));
        obj->iframes_timer = 200;
        orig_obj->flags &= ~FLG(OBJ_ACTIVE);
        orig_obj->flags &= ~FLG(OBJ_ALIVE);
        calc_obj_pos(obj);
        break;
      }
      obj++;
      i++;
    } while (i < nb_objs);
  }
}

/* 516B4 80175EB4 -O2 -msoft-float */
void DO_NOTE_TOUCHEE(Obj *obj)
{
    switch (obj->type)
    {
    case TYPE_NOTE0:
    case TYPE_NOTE3:
        BonneNote(obj);
        break;
    case TYPE_NOTE1:
        DO_EXPLOSE_NOTE1(obj);
        break;
    case TYPE_BONNE_NOTE:
        obj->speed_x += level.objects[poing_obj_id].speed_x;
        obj->speed_y = -1;
        obj->gravity_value_2 = 0xFF;
        obj->field23_0x3c = 1;
        break;
    }
}

/* 51774 80175F74 -O2 -msoft-float */
void DO_NOTE_REBOND(Obj *obj)
{
    switch (obj->type)
    {
    case TYPE_NOTE2:
        DO_EXPLOSE_NOTE2(obj);
        break;
    case TYPE_NOTE0:
    case TYPE_NOTE3:
    case TYPE_BONNE_NOTE:
        obj->speed_y = -__builtin_abs(obj->speed_y);
        if (obj->speed_y > -3)
            obj->speed_y--;

        obj->gravity_value_1 = 10 - obj->gravity_value_1;
        calc_obj_pos(obj);
        break;
    }
}

/* 51828 80176028 -O2 -msoft-float */
/*? calc_obj_pos(Obj *, s32);
? skipToLabel(Obj *, ?, ?, s16);*/

void allocateNote(Obj *obj)
{
  Obj *noteObj;
  s16 i;
  u8 nb_objs_1;
  u8 nb_objs_2;

  noteObj = level.objects;
  i = 0;
  nb_objs_1 = level.nb_objects;
  if (nb_objs_1 != 0)
  {
    nb_objs_2 = nb_objs_1;
    do {
      if ((noteObj->type == atak[NextNote].type + TYPE_NOTE0))
      {
        if(!(noteObj->flags & FLG(OBJ_ACTIVE)))
        {
            noteObj->flags = noteObj->flags & ~FLG(OBJ_FLIP_X) | obj->flags & FLG(OBJ_FLIP_X);
            noteObj->speed_y = atak[NextNote].speed_y;
            if (noteObj->flags & FLG(OBJ_FLIP_X))
            {
                noteObj->speed_x = atak[NextNote].speed_x;
                noteObj->x_pos = Sax.sprite2_x + 0x17 - noteObj->offset_bx;
            }
            else
            {
                noteObj->speed_x = -atak[NextNote].speed_x;
                noteObj->x_pos = Sax.sprite2_x + 9 - noteObj->offset_bx;
            }
            noteObj->y_pos = (Sax.sprite2_y - noteObj->offset_by) + 0x19;
            noteObj->main_etat = 2;
            noteObj->sub_etat = atak[NextNote].type;
            skipToLabel(noteObj, 1, true);
            calc_obj_pos(noteObj);
            noteObj->flags = (noteObj->flags | FLG(OBJ_ALIVE)) & ~FLG(OBJ_FLAG_9) | FLG(OBJ_ACTIVE);
            noteObj->gravity_value_1 = 0;
            noteObj->gravity_value_2 = 10;
            noteObj->iframes_timer = atak[NextNote].initial_iframes;
            calc_obj_pos(noteObj);
            break;
        }
      }
      noteObj++;
      i++;
    } while (i < nb_objs_2);
  }
}

/* 51A30 80176230 -O2 -msoft-float */
u8 PrepareAtak(void)
{
  s16 is;
  s16 ia;
  
  is = IndexSerie;
  ia = IndexAtak;
  attaque.next_note = SerieDatak[is][ia].next_note;
  attaque.time = SerieDatak[is][ia].time;
  attaque.end = SerieDatak[is][ia].end;
  if (attaque.end)
    IndexAtak = 0;
  else
    IndexAtak++;

  return attaque.next_note;
}

/* 51AE0 801762E0 -O2 -msoft-float */
void SAXO_TIRE(Obj *obj)
{
  if (obj->type == TYPE_SAXO)
  {
    if (NextNote > 6)
      NextNote--;
    allocateNote(obj);
    WaitForFinAtan = attaque.time + 1;
    NextNote = PrepareAtak();
  }
  else
  {
    NextNote = 0;
    allocateNote(obj);
  }
}

/* 51B80 80176380 -O2 -msoft-float */
void DO_SAXO_COUP(Obj *obj)
{
    u8 hp;

    if (Phase != 100)
    {
        hp = --obj->hit_points;
        if (hp != 0)
        {
            if (obj->main_etat != 2)
            {
                Sax.field8_0xe = obj->main_etat;
                Sax.field9_0xf = obj->sub_etat;
                set_main_and_sub_etat(obj, 0, 3);
                Sax.coup = 2;
            }
            else
                Sax.coup = 0;
            
            IndexSerie++;
            if (IndexSerie >= 4)
                IndexSerie = 3;
            else
                IndexAtak = 0;
            NextNote = PrepareAtak();
        }
        else
            Sax.coup = 0;
    }
}

/* 51C7C 8017647C -O2 -msoft-float */
/*? set_main_and_sub_etat(Obj *, ?, ?);
? set_sub_etat(Obj *, ?);*/

void DO_SAXO2_COUP(Obj *obj)
{
    switch (Phase)
    {
    case 1:
        obj->hit_points--;
        if (obj->init_hit_points - obj->hit_points >= 3)
            Phase = 2;
        FinAnim = false;
        set_sub_etat(obj, 3);
        Sax.coup = 2;
        break;
    case 2:
        obj->hit_points--;
        Sax.coup = 0;
        break;
    case 3:
        set_main_and_sub_etat(obj, 0, 3);
        obj->speed_x = 0;
        obj->hit_points--;
        FinAnim = false;
        Sax.coup = 2;
        break;
    }
}

/* 51D7C 8017657C -O2 -msoft-float */
void SetSaxoCollNoteBox(Obj *obj)
{
  s16 x2;
  s16 y2;
  s16 w2;
  s16 h2;
  s16 x5;
  s16 y5;
  s16 w5;
  s16 h5;
  
  GET_SPRITE_POS(obj, 2, &x2, &y2, &w2, &h2);
  GET_SPRITE_POS(obj, 5, &x5, &y5, &w5, &h5);
  Sax.note_box_coll_y = y5 + 20;
  Sax.note_box_coll_x = x2 + ((w2 - 20) >> 1);
}

INCLUDE_ASM("asm/nonmatchings/obj/saxo", DO_SAXO_COMMAND);

/* 52BC4 801773C4 -O2 -msoft-float */
void DO_SAXO_ATTER(Obj *obj)
{
  if (obj->speed_y > 0)
  {
    CALC_MOV_ON_BLOC(obj);
    screen_trembling = 1;
    set_main_and_sub_etat(obj, 0, 0xb);
    obj->speed_x = 0;
    obj->speed_y = 0;
    allocateLandingSmoke(obj);
  }
}

/* 52C28 80177428 -O2 -msoft-float */
/*? CALC_MOV_ON_BLOC(Obj *, s16, s32);
? GET_SPRITE_POS(?, u16 *, u16 *, u16 *, ? *);
? set_main_and_sub_etat(Obj *, ?, ?);
? set_sub_etat(Obj *, ?, s32);*/

void DO_SAXO2_COMMAND(Obj *obj)
{
    s16 sprite_w;
    s16 sprite_h;
    u16 temp_x;
    s16 x_pos;
    u8 anim_frame;
    s32 main_etat;
    s32 offs_x;
    u8 should_dec;
    s32 next_x;

    scrollLocked = true;
    GET_SPRITE_POS(obj, 2, &Sax.sprite2_x, &Sax.sprite2_y, &sprite_w, &sprite_h);
    if (obj->flags & FLG(OBJ_FLIP_X))
    {
        temp_x = Sax.sprite2_x - 32;
        Sax.sprite2_x = temp_x + sprite_w;
    }
    Sax.sprite2_x += 12;
    Sax.sprite2_y += 12;
    Sax.x_pos = obj->x_pos;
    Sax.y_pos = obj->y_pos;
    SetSaxoCollNoteBox(obj);
    if (Sax.coup == 1)
        DO_SAXO2_COUP(obj);
    if (
      obj->anim_frame == (obj->animations[obj->anim_index].frames_count - 1) &&
      horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
    )
    {
        FinAnim = true;
        WaitForAnim = false;
    }
    else
        FinAnim = false;
    
    x_pos = obj->x_pos;
    if (xmapmax < ray.x_pos + 150 && (mp.height * 16 - 110) < ray.y_pos)
        Sax.saved_hp = obj->hit_points;
    
    switch (Phase)
    {
    case 0:
        CALC_MOV_ON_BLOC(obj);
        if (ray.x_pos < x_pos + 220 && ray.x_pos + 220 > x_pos)
            WaitForAnim = true;
        
        if (WaitForAnim && FinAnim)
        {
            Phase = 1;
            WaitForFinAtan = 2;
            NiveauDansPhase = 0;
            set_main_and_sub_etat(obj, 0, 1);
        }
        break;
    case 1:
        switch (obj->sub_etat)
        {
        case 1:
            if (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0)
            {
                anim_frame = obj->anim_frame;
                if(
                  anim_frame == 24 ||
                  (anim_frame == 28 && NiveauDansPhase >= 2) ||
                  (anim_frame == 32 && NiveauDansPhase >= 4)
                )
                {
                  SAXO_TIRE(obj);
                  NiveauDansPhase++;
                }
            }
            break;
        case 2:
            if (FinAnim)
            {
                if (WaitForFinAtan < 2)
                    set_sub_etat(obj, 1);
                else
                    WaitForFinAtan--;
            }
            break;
        case 3:
            if (FinAnim)
                Sax.coup = 0;
            break;
        }
        break;
    case 2:
        switch (obj->sub_etat)
        {
        case 3:
            if (FinAnim)
            {
                Sax.coup = 0;
                set_main_and_sub_etat(obj, 0, 0xA);
            }
            break;
        case 10:
            if (FinAnim)
            {
                obj->gravity_value_2 = 5;
                obj->gravity_value_1 = 0;
                obj->speed_y = -6;
                obj->speed_x = -1;
                obj->y_pos -= 6;
                Sax.field10_0x10 = 2;
            }
            break;
        case 11:
            if (FinAnim)
            {
                if (obj->x_pos < ray.x_pos - 50)
                {
                    /* TODO: last part is obj->flags ^ (1 << OBJ_FLIP_X) ? */
                    obj->flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (((1 - ((obj->flags >> OBJ_FLIP_X) & 1)) & 1) << OBJ_FLIP_X);
                    set_sub_etat(obj, 0);
                    Phase = 3;
                }
                else
                    set_main_and_sub_etat(obj, 0, 0xA);
            }
            break;
        }
        break;
    case 3:
        /* TODO: m2c output was switch */
        main_etat = obj->main_etat;
        if (main_etat != 1)
        {
          if (main_etat < 2 && main_etat == 0 && FinAnim)
          {
            switch (obj->sub_etat)
            {
            case 0:
            case 2:
            case 3:
            case 11:
                set_main_and_sub_etat(obj, 1, 0);
                obj->speed_x = Sax.field10_0x10;
                Sax.coup = 0;
                break;
            case 10:
                set_main_and_sub_etat(obj, 2, 1);
                obj->anim_frame = obj->gravity_value_2;
                obj->gravity_value_2 = 5;
                obj->gravity_value_1 = 0;
                obj->speed_y = -7;
                obj->speed_x = 2;
                obj->y_pos -= 7;
                break;
            }
          }
        }
        else
        {
            offs_x = obj->offset_bx + 50;
            /* TODO: shifts/div? */
            if (
              !((block_flags[
                (u16)mp.map[(s16)(
                  ((obj->x_pos + offs_x) >> 4) +
                  (mp.width * ((obj->y_pos + obj->offset_by + 8) >> 4))
                )] >> 10
              ] >> BLOCK_SOLID) & 1)
            )
            {
              set_main_and_sub_etat(obj, 0, 0xA);
              obj->speed_x = 0;
            }
            else if (xmap < obj->x_pos + 150)
            {
              if (Sax.field10_0x10 == 2)
              {
                  if (horloge[2] != 0)
                  {
                    obj->speed_x = 1;
                    should_dec = horloge[4] < 2;
                  }
                  else
                  {
                    obj->speed_x = 2;
                    break;
                  }
              }
              else
              {
                obj->speed_x = 1;
                should_dec = horloge[2];
              }
              
              if (should_dec != 0)
                obj->anim_frame--;
            }
            else
              obj->speed_x = 2;
            break;
        }
    }
    next_x = obj->x_pos + obj->offset_bx + obj->speed_x;
    if (next_x < 0 || (xmapmax + SCREEN_WIDTH - 1) < next_x)
        obj->speed_x = 0;
}

/* 533C8 80177BC8 -O2 -msoft-float */
void DO_SAXO2_ATTER(Obj *obj)
{
  s32 four = 4;
  s32 two = 2;

  if (Phase < four && Phase >= two && obj->speed_y > 0) {
    CALC_MOV_ON_BLOC(obj);
    screen_trembling3 = 1;
    set_main_and_sub_etat(obj, 0, 0xb);
    obj->speed_x = 0;
    obj->speed_y = 0;
    allocateLandingSmoke(obj);
  }
}

/* 53448 80177C48 -O2 -msoft-float */
void DO_SAXO_MARCHE(s16 hp)
{
  Sax.field10_0x10 = hp + 1;
}

/* 5345C 80177C5C -O2 -msoft-float */
/*? GET_SPRITE_POS(?, u16 *, u16 *, u16 *, ? *);
? set_main_and_sub_etat(Obj *, ?, ?);
? set_sub_etat(Obj *, ?, u32);*/

void DO_SAXO3_COMMAND(Obj *obj)
{
    s16 sprite_w;
    s16 sprite_h;
    u16 temp_x;
    s32 temp_flags;

    GET_SPRITE_POS(obj, 2, &Sax.sprite2_x, &Sax.sprite2_y, &sprite_w, &sprite_h);
    if (obj->flags & FLG(OBJ_FLIP_X))
    {
        temp_x = Sax.sprite2_x - 32;
        Sax.sprite2_x = temp_x + sprite_w;
    }
    Sax.sprite2_x += 12;
    Sax.sprite2_y += 12;
    Sax.x_pos = obj->x_pos;
    Sax.y_pos = obj->y_pos;
    SetSaxoCollNoteBox(obj);
    if (Phase == 2 && obj->main_etat == 0 && obj->sub_etat != 0)
        Phase = 0;
    if (
      obj->anim_frame == (obj->animations[obj->anim_index].frames_count - 1) &&
      horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0
    )
    {
        FinAnim = true;
        WaitForAnim = false;
    }
    else
        FinAnim = false;
    
    switch (Phase)
    {
    case 0:
      break;
    case 1:
        switch(obj->sub_etat)
        {
          case 1:
            if ((obj->anim_frame == 24) && (horloge[obj->eta[obj->main_etat][obj->sub_etat].anim_speed & 0xF] == 0))
                SAXO_TIRE(obj);
            if (FinAnim)
            {
                /* TODO: see DO_SAXO2_COMMAND also */
                temp_flags = (obj->flags & ~FLG(OBJ_FLIP_X)) | (((1 - ((obj->flags >> OBJ_FLIP_X) & 1)) & 1) << OBJ_FLIP_X);
                obj->flags = temp_flags;
                set_sub_etat(obj, 0);
                Phase++;
            }
            break;
          case 3:
            if (FinAnim)
                Sax.coup = 0;
            break;
        }
        break;
    case 2:
        if (FinAnim && obj->sub_etat == 0)
        {
            obj->speed_x = 2;
            set_main_and_sub_etat(obj, 1, 0);
        }
        break;
    }
}

/* 53758 80177F58 -O2 -msoft-float */
void DO_SAXO3_DEBUT(Obj *obj)
{
  if (Phase == 0)
  {
    Phase = 1;
    WaitForFinAtan = 1;
    set_main_and_sub_etat(obj,0,1);
  }
}

/* 5379C 80177F9C -O2 -msoft-float */
s32 saxo2_get_eject_sens(void)
{
  if (Phase <= 1)
    return -1;
  else
    return 1;
}