#include "bonus_35FB4.h"

#ifdef BSS_DEFS
u8 bonus_perfect[24];
s16 loop_time;
s32 nb_wiz_save;
#endif

/* 35FB4 8015A7B4 -O2 */
u8 get_bonus_map_complete(s16 world, s16 lvl)
{
    return getbit(bonus_perfect, (s16) (lvl - 1 + ((world - 1) << 5)));
}

/* 35FEC 8015A7EC -O2 */
void set_bonus_map_complete(s16 world, s16 lvl)
{
    setbit(bonus_perfect, (s16) (lvl - 1 + ((world - 1) << 5)));
}

/* 36024 8015A824 -O2 */
void DO_PERFECT_BONUS_MAP(void)
{
    if (loop_time < 0)
        loop_time++;

    if (loop_time == -1)
    {
        loop_time++;
        departlevel = false;
        start_cd_gagne();
        SYNCHRO_LOOP(do_perfect_bonus);
        status_bar.num_wiz = nb_wiz_save;
        nb_wiz_save = 0;
        set_bonus_map_complete(num_world, num_level);
    }
}

/* 360C8 8015A8C8 -O2 */
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