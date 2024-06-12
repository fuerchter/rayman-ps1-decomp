#include "music.h"

const u8 s__CDPlayer_TEST_80125c28[] = "\n\n\n\t\t CD-Player TEST\n";
const u8 s_Fade02d_80125c40[] = "Fade:%02d ";
const u8 s_ind_faded_80125c4c[] = "ind_fade:%d\n";
const u8 s_stat_02x_trackd_80125c5c[] = "stat  =%02x track=%d";
const u8 s_Ready_data_d_Complete_d_80125c74[] = "Ready data #%d, Complete #%d\n";
const u8 s_occuped_etat_d_pcomd_80125c94[] = "occupe=%d, etat= %d, pcom=%d\n";
const u8 s_intr_datar3d_intr_compl3d_80125cb4[] = "intr_datar=%3d intr_compl=%3d\n";
const u8 s_Deb_2d2d2d_80125cd4[] = "Deb: %2d:%2d:%2d\n";
const u8 s_Pos_2d2d2d_08x_80125ce8[] = "Pos: %2d:%2d:%2d (%08x)\n";
const u8 s_Fin_08x_80125d04[] = "Fin: %08x\n";
const u8 s_Num_seqddd_typd_80125d10[] = "Num_seq:%d-%d-%d typ:%d\n";
const u8 s_iseosd_80125d2c[] = "iseos:%d\n";
const u8 s_will_anticips_fadeouts_80125d38[] = "will anticip:%s  fadeout:%s\n";
const u8 s_2d_markddd_80125d58[] = "%2d mark:%d-%d-%d\n";

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130048);

INCLUDE_ASM("asm/nonmatchings/music", FUN_801300ac);

INCLUDE_ASM("asm/nonmatchings/music", FUN_8013036c);

INCLUDE_ASM("asm/nonmatchings/music", func_80130428);

INCLUDE_ASM("asm/nonmatchings/music", FUN_8013045c);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130514);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130540);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130560);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130588);

INCLUDE_ASM("asm/nonmatchings/music", FUN_801305b4);

INCLUDE_ASM("asm/nonmatchings/music", FUN_801305ec);

INCLUDE_ASM("asm/nonmatchings/music", PS1_InitMusic);

INCLUDE_ASM("asm/nonmatchings/music", FUN_8013066c);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130684);

void FUN_801309b0(void) {}

INCLUDE_ASM("asm/nonmatchings/music", FUN_801309b8);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130a98);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130b18);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130bc4);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130c58);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80130d00);

INCLUDE_ASM("asm/nonmatchings/music", PS1_InitTracks);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131474);

INCLUDE_ASM("asm/nonmatchings/music", FUN_801314c4);

INCLUDE_ASM("asm/nonmatchings/music", PS1_PlayMusic);

INCLUDE_ASM("asm/nonmatchings/music", playLevelMusic);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_gros_rayman);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_suspence);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_credits);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131c94);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_gagne);

INCLUDE_ASM("asm/nonmatchings/music", PS1_PlayDeathMusic);

INCLUDE_ASM("asm/nonmatchings/music", PS1_PlayCDTrack_0_3);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_gameover);

INCLUDE_ASM("asm/nonmatchings/music", start_cd_continue);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131db8);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131dc8);

INCLUDE_ASM("asm/nonmatchings/music", stop_cd);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131e18);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131e40);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131e5c);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80131e94);

INCLUDE_ASM("asm/nonmatchings/music", FUN_8013202c);

INCLUDE_ASM("asm/nonmatchings/music", change_audio_track_moskito_acc);

INCLUDE_ASM("asm/nonmatchings/music", change_audio_track_moskito_dec);

INCLUDE_ASM("asm/nonmatchings/music", change_audio_track_puit);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80132110);

void FUN_80132148(void) {}

void FUN_80132150(void) {}

void FUN_80132158(void) {}

void FUN_80132160(void) {}

INCLUDE_ASM("asm/nonmatchings/music", PS1_SetMusicVolume);

INCLUDE_ASM("asm/nonmatchings/music", FUN_801321fc);

INCLUDE_ASM("asm/nonmatchings/music", FUN_80132244);
