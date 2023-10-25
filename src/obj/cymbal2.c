#include "obj/cymbal2.h"

/* 3CE78 80161678 -O2 */
/*? skipToLabel(void *, ?, ?);*/

void START_2_PARTS_CYMBAL_ACTION(Obj *obj)
{
  Obj *linkedCymbal;
  
  skipToLabel(obj, 4, true);
  obj->field24_0x3e = 1;
  if (link_init[obj->id] != obj->id)
  {
    linkedCymbal = &level.objects[link_init[obj->id]];
    if(linkedCymbal->type == TYPE_CYMBAL1)
    {
        skipToLabel(linkedCymbal, 4, true);
        linkedCymbal->field24_0x3e = 1;
    }
  }
}