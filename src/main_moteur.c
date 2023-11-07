#include "main_moteur.h"

/* TODO: need to start working on src/unknown/ */
extern s16 D_801CEFC8; /* 7ABA0 */
extern u8 PS1_DebugMode;
extern u8 PS1_15fps;
extern u8 PS1_PictureInPicture;

extern s16 D_801E4BE0; /* 548CC */

/* AD90 8012F590 -O2 -msoft-float */
void DO_GROS_MOTEUR_NORMAL(void)
{
    PS1_DoDemo(&record);
    if ((!PS1_DebugMode || !D_801CEFC8) && !in_pause)
    {
        if (gele == 0)
        {
            DO_MOTEUR();
            DO_MOTEUR2();
        }
        else
            DO_MOTEUR_GELE();
    }
}

INCLUDE_ASM("asm/nonmatchings/main_moteur", DO_MAIN_LOOP);