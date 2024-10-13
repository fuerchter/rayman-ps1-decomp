#include "menu/menu_6A3BC.h"

/* WorldInfo.state... */
/*INCLUDE_ASM("asm/nonmatchings/menu/menu_6A3BC", INIT_NEW_GAME);*/
void init_finBossLevel(void);

void INIT_NEW_GAME(void)
{
    s16 temp_v0;
    s16 temp_v1;
    s16 var_a1_1;
    s16 var_a1_2;
    s32 temp_a0;
    s32 var_v0;
    s32 var_v0_2;
    s32 test_1;

    new_level = 1;
    new_world = 1;
    status_bar.num_lives = 3;
    ray.hit_points = 2;
    poing.sub_etat = 1;
    departlevel = 1;
    fin_du_jeu = 0;
    nb_continue = 5;
    temp_a0 = ~4;
    ray.flags &= ~0x100;
    memset(wi_save_zone, 0, 0x18);
    memset(save_zone, 0, 0xA80);
    INIT_RAY_BEGIN();

    var_a1_1 = 1;
    *(u32*)&t_world_info[0].state |= FLG(0);
    *(u32*)&t_world_info[0].state &= ~FLG(2) & ~FLG(1);
    t_world_info[0].nb_cages = 0;
    do
    {
        (*(u32*)&t_world_info[var_a1_1].state) &= ~FLG(0) & ~FLG(2) & ~FLG(1);
        t_world_info[var_a1_1].nb_cages = 0;
        var_a1_1 = var_a1_1 + 1;
    } while (var_a1_1 < 0x18);

    loadInfoRay[positiony + -1].num_lives = 3;
    loadInfoRay[positiony + -1].num_wiz = 0;
    loadInfoRay[positiony + -1].num_cages = 0;
    loadInfoRay[positiony + -1].num_continues = 5;
    var_a1_2 = 0;
    do
    {
        bonus_perfect[var_a1_2] = 0;
        var_a1_2 = var_a1_2 + 1;
    } while (var_a1_2 < 0x17);
    init_finBossLevel();
    INIT_WORLD_INFO();
}