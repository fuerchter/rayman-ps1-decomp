#include "bonus_35FB4.h"

/* 35FB4 8015A7B4 -O2 */
/*s32 getbit(? *, s16);*/

u8 get_bonus_map_complete(s16 world, s16 level)
{
    return getbit(&bonus_perfect, (s16) (level - 1 + ((world - 1) << 5)));
}

/* 35FEC 8015A7EC -O2 */
/*? setbit(u8 *, s16);*/

void set_bonus_map_complete(s16 world, s16 level)
{
    setbit(&bonus_perfect, (s16) (level - 1 + ((world - 1) << 5)));
}

/* 36024 8015A824 -O2 */
/*? SYNCHRO_LOOP(? *);
? start_cd_gagne(s16);*/

void DO_PERFECT_BONUS_MAP(void)
{
    if (loop_time < 0)
        loop_time++;

    if (loop_time == -1)
    {
        loop_time++;
        departlevel = 0;
        start_cd_gagne();
        SYNCHRO_LOOP(&do_perfect_bonus);
        status_bar.num_wiz = nb_wiz_save;
        nb_wiz_save = 0;
        set_bonus_map_complete(num_world, num_level);
    }
}

/* 360C8 8015A8C8 -O2 */
/*? Add_One_RAY_lives();
s16 NOVA_STATUS_BAR(u8 *, u8);*/

void DO_WIZ_AFTER_BONUS_MAP(void)
{
    if (!bonus_map && nb_wiz_collected != 0 && horloge[4] == 0)
    {
        status_bar.num_wiz++;
        nb_wiz_collected--;
        if (status_bar.num_wiz >= 100)
        {
            status_bar.num_wiz += 156;
            id_Cling_1up = NOVA_STATUS_BAR();
            if (id_Cling_1up == -1)
                Add_One_RAY_lives();
        }
    }
}

/* 3617C 8015A97C -O2 */
void init_bonus_perfect(void)
{
    s32 i = LEN(bonus_perfect) - 1;
    u8 *cur = &bonus_perfect[i];

    while (i >= 0)
    {
        *cur = 0;
        i--;
        cur--;
    }
}