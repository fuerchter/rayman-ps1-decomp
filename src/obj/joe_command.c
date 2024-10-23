#include "obj/joe_command.h"

/* 50588 80174D88 -O2 -msoft-float */
void DO_JOE_COMMAND(Obj *obj)
{
    if (joe_exp_probleme && obj->main_etat == 0)
    {
        if (obj->sub_etat == 10)
            vignet_joe_affichee = true;

        if (obj->main_etat == 0 && obj->sub_etat == 1)
        {
            if (vignet_joe_affichee)
            {
                Vignet_To_Display = 1;
                vignet_joe_affichee = false;
                finBosslevel.helped_joe_1 = true;
                obj->timer = 0;
            }
            
            obj->timer++;
            if (obj->timer > 100)
            {
                ChangeLevel();
                RayEvts.luciole = true;
            }
        }
    }

    if (num_level == 8)
    {
        if (prise_branchee)
        {
            if (obj->main_etat == 0 && obj->sub_etat == 1)
                skipToLabel(obj, 3, true);
        }
        else
            obj->flags &= ~FLG(OBJ_ALIVE);
    }
}
