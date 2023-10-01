#ifndef OBJ_UPDATE_H
#define OBJ_UPDATE_H

#include "common.h"
#include "display.h"
#include "obj_init_kill.h"
#include "command_56AF0.h"
#include "collision/collision_block.h"

typedef struct AnimationLayer
{
    u8 flip_x;
    u8 x_pos;
    u8 y_pos;
    u8 sprite;
} AnimationLayer;

typedef struct AnimationFrame
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
} AnimationFrame;

typedef struct Animation
{
    AnimationLayer * layers;
    AnimationFrame * frames;
    u16 layers_count;
    u16 frames_count;
} Animation;

typedef enum ChangeAnimMode
{
    ANIMMODE_NONE=0,
    ANIMMODE_RESET_IF_NEW=1,
    ANIMMODE_RESET=2
} ChangeAnimMode;

typedef struct ObjState
{
    u8 speed_x_right;
    u8 speed_x_left;
    u8 anim_index;
    u8 next_main_etat;
    u8 next_sub_etat;
    u8 anim_speed;
    u8 sound;
    u8 flags;
} ObjState;

typedef enum ObjType
{
    TYPE_BADGUY1=0,
    TYPE_PLATFORM=1,
    TYPE_POWERUP=2,
    TYPE_LIDOLPINK=3,
    TYPE_NEUTRAL=4,
    TYPE_WIZARD1=5,
    TYPE_FALLING_YING_OUYE=6,
    TYPE_MORNINGSTAR=7,
    TYPE_FALLING_OBJ=8,
    TYPE_BADGUY2=9,
    TYPE_FISH=10,
    TYPE_BOUM=11,
    TYPE_CHASSEUR1=12,
    TYPE_BALLE1=13,
    TYPE_CHASSEUR2=14,
    TYPE_BALLE2=15,
    TYPE_FALLPLAT=16,
    TYPE_LIFTPLAT=17,
    TYPE_BTBPLAT=18,
    TYPE_SPLASH=19,
    TYPE_GENEBADGUY=20,
    TYPE_PHOTOGRAPHE=21,
    TYPE_MOVE_PLAT=22,
    TYPE_RAYMAN=23,
    TYPE_INTERACTPLT=24,
    TYPE_INST_PLAT=25,
    TYPE_CRUMBLE_PLAT=26,
    TYPE_BOING_PLAT=27,
    TYPE_ONOFF_PLAT=28,
    TYPE_AUTOJUMP_PLAT=29,
    TYPE_AUDIOSTART=30,
    TYPE_ONEUP_ALWAYS=31,
    TYPE_DARK_PHASE2=32,
    TYPE_DARK2_SORT=33,
    TYPE_MOVE_AUTOJUMP_PLAT=34,
    TYPE_STONEMAN1=35,
    TYPE_STONEBOMB=36,
    TYPE_TARZAN=37,
    TYPE_GRAINE=38,
    TYPE_NEN_GRAINE=39,
    TYPE_STONEDOG=40,
    TYPE_OUYE=41,
    TYPE_SIGNPOST=42,
    TYPE_STONEMAN2=43,
    TYPE_CLASH=44,
    TYPE_MOVE_OUYE=45,
    TYPE_BB1=46,
    TYPE_STONEBOMB2=47,
    TYPE_FLAMME2=48,
    TYPE_MOVE_START_PLAT=49,
    TYPE_MOSKITO=50,
    TYPE_MST_FRUIT1=51,
    TYPE_MST_FRUIT2=52,
    TYPE_MST_SHAKY_FRUIT=53,
    TYPE_MEDAILLON=54,
    TYPE_MUS_WAIT=55,
    TYPE_STONEWOMAN2=56,
    TYPE_STALAG=57,
    TYPE_CAGE=58,
    TYPE_CAGE2=59,
    TYPE_BIG_CLOWN=60,
    TYPE_WAT_CLOWN=61,
    TYPE_DROP=62,
    TYPE_MOVE_START_NUA=63,
    TYPE_SCROLL=64,
    TYPE_SPIDER=65,
    TYPE_DARD=66,
    TYPE_SWING_PLAT=67,
    TYPE_BIG_BOING_PLAT=68,
    TYPE_STONEBOMB3=69,
    TYPE_TROMPETTE=70,
    TYPE_NOTE=71,
    TYPE_PIRATE_NGAWE=72,
    TYPE_RING=73,
    TYPE_SAXO=74,
    TYPE_PAILLETTE=75,
    TYPE_DESTROYING_DOOR=76,
    TYPE_PIRATE_GUETTEUR=77,
    TYPE_PIRATE_BOMB=78,
    TYPE_STONECHIP=79,
    TYPE_BIGSTONE=80,
    TYPE_CYMBALE=81,
    TYPE_JAUGEUP=82,
    TYPE_EXPLOSION=83,
    TYPE_TIBETAIN=84,
    TYPE_ROLLING_EYES=85,
    TYPE_MARACAS=86,
    TYPE_TAMBOUR1=87,
    TYPE_TAMBOUR2=88,
    TYPE_JOE=89,
    TYPE_NOTE0=90,
    TYPE_NOTE1=91,
    TYPE_NOTE2=92,
    TYPE_BONNE_NOTE=93,
    TYPE_POING=94,
    TYPE_POING_POWERUP=95,
    TYPE_TOTEM=96,
    TYPE_BBL=97,
    TYPE_SPACE_MAMA=98,
    TYPE_RAY_POS=99,
    TYPE_MITE=100,
    TYPE_MORNINGSTAR_MOUNTAI=101,
    TYPE_BNOTE=102,
    TYPE_POI1=103,
    TYPE_POI2=104,
    TYPE_MARTEAU=105,
    TYPE_MOVE_MARTEAU=106,
    TYPE_GROSPIC=107,
    TYPE_DARK2_PINK_FLY=108,
    TYPE_PI=109,
    TYPE_PI_BOUM=110,
    TYPE_PI_MUS=111,
    TYPE_WASHING_MACHINE=112,
    TYPE_BAG1=113,
    TYPE_UNUSED_114=114,
    TYPE_BB1_PLAT=115,
    TYPE_CLOWN_TNT=116,
    TYPE_CLOWN_TNT2=117,
    TYPE_CLOWN_TNT3=118,
    TYPE_TNT_BOMB=119,
    TYPE_BATTEUR_FOU=120,
    TYPE_ECLAIR=121,
    TYPE_STONEDOG2=122,
    TYPE_BLACKTOON1=123,
    TYPE_PANCARTE=124,
    TYPE_BON3=125,
    TYPE_FOURCHETTE=126,
    TYPE_COUTEAU_SUISSE=127,
    TYPE_TIRE_BOUCHON=128,
    TYPE_PETIT_COUTEAU=129,
    TYPE_BLACKTOON_EYES=130,
    TYPE_BAG3=131,
    TYPE_POI3=132,
    TYPE_SUPERHELICO=133,
    TYPE_FALLING_OBJ2=134,
    TYPE_ETINC=135,
    TYPE_DEMI_RAYMAN=136,
    TYPE_REDUCTEUR=137,
    TYPE_ROULETTE=138,
    TYPE_MARACAS_BAS=139,
    TYPE_PT_GRAPPIN=140,
    TYPE_NEIGE=141,
    TYPE_ONEUP=142,
    TYPE_NOVA2=143,
    TYPE_LIDOLPINK2=144,
    TYPE_KILLING_EYES=145,
    TYPE_FLASH=146,
    TYPE_MST_SCROLL=147,
    TYPE_GRAP_BONUS=148,
    TYPE_CLE_SOL=149,
    TYPE_SCORPION=150,
    TYPE_BULLET=151,
    TYPE_CAISSE_CLAIRE=152,
    TYPE_FEE=153,
    TYPE_ROULETTE2=154,
    TYPE_ROULETTE3=155,
    TYPE_WALK_NOTE_1=156,
    TYPE_EAU=157,
    TYPE_PALETTE_SWAPPER=158,
    TYPE_TIBETAIN_6=159,
    TYPE_TIBETAIN_2=160,
    TYPE_WIZ=161,
    TYPE_UFO_IDC=162,
    TYPE_INDICATOR=163,
    TYPE_GENERATING_DOOR=164,
    TYPE_BADGUY3=165,
    TYPE_LEVIER=166,
    TYPE_FALLING_OBJ3=167,
    TYPE_CYMBAL1=168,
    TYPE_CYMBAL2=169,
    TYPE_RAYON=170,
    TYPE_MST_COPAIN=171,
    TYPE_STONEWOMAN=172,
    TYPE_BATEAU=173,
    TYPE_PIRATE_POELLE=174,
    TYPE_PUNAISE1=175,
    TYPE_CRAYON_BAS=176,
    TYPE_FALLING_YING=177,
    TYPE_HERSE_BAS=178,
    TYPE_HERSE_BAS_NEXT=179,
    TYPE_SAXO2=180,
    TYPE_SCROLL_SAX=181,
    TYPE_NOTE3=182,
    TYPE_SAXO3=183,
    TYPE_PIRATE_POELLE_D=184,
    TYPE_WALK_NOTE_2=185,
    TYPE_POELLE_ALWAYS=186,
    TYPE_MAMA_PIRATE=187,
    TYPE_RUBIS=188,
    TYPE_MOVE_RUBIS=189,
    TYPE_COUTEAU=190,
    TYPE_FALLING_CRAYON=191,
    TYPE_SMA_GRAND_LASER=192,
    TYPE_SMA_BOMB=193,
    TYPE_SMA_BOMB_CHIP=194,
    TYPE_SPIDER_PLAFOND=195,
    TYPE_DARD_PLAFOND=196,
    TYPE_MEDAILLON_TOON=197,
    TYPE_BB12=198,
    TYPE_BB1_VIT=199,
    TYPE_BB13=200,
    TYPE_BB14=201,
    TYPE_RAY_ETOILES=202,
    TYPE_SMA_WEAPON=203,
    TYPE_BLACK_RAY=204,
    TYPE_BLACK_FIST=205,
    TYPE_PIEDS_RAYMAN=206,
    TYPE_POELLE=207,
    TYPE_LANDING_SMOKE=208,
    TYPE_FIRE_LEFT=209,
    TYPE_FIRE_RIGHT=210,
    TYPE_BOUT_TOTEM=211,
    TYPE_DARK=212,
    TYPE_SPACE_MAMA2=213,
    TYPE_BOUEE_JOE=214,
    TYPE_DARK_SORT=215,
    TYPE_ENS=216,
    TYPE_MITE2=217,
    TYPE_HYBRIDE_MOSAMS=218,
    TYPE_CORDE=219,
    TYPE_PIERREACORDE=220,
    TYPE_CFUMEE=221,
    TYPE_CORDEBAS=222,
    TYPE_HYBRIDE_STOSKO=223,
    TYPE_STOSKO_PINCE=224,
    TYPE_PIRATE_P_45=225,
    TYPE_PIRATE_P_D_45=226,
    TYPE_MOSKITO2=227,
    TYPE_PRI=228,
    TYPE_PUNAISE2=229,
    TYPE_PUNAISE3=230,
    TYPE_HYB_BBF2_D=231,
    TYPE_HYB_BBF2_G=232,
    TYPE_HYB_BBF2_LAS=233,
    TYPE_LAVE=234,
    TYPE_PUNAISE4=235,
    TYPE_ANNULE_SORT_DARK=236,
    TYPE_GOMME=237,
    TYPE_POING_FEE=238,
    TYPE_PIRATE_GUETTEUR2=239,
    TYPE_CRAYON_HAUT=240,
    TYPE_HERSE_HAUT=241,
    TYPE_HERSE_HAUT_NEXT=242,
    TYPE_MARK_AUTOJUMP_PLAT=243,
    TYPE_SMA_PETIT_LASER=244,
    TYPE_DUNE=245,
    TYPE_CORDE_DARK=246,
    TYPE_VITRAIL=247,
    TYPE_SKO_PINCE=248,
    TYPE_RIDEAU=249,
    TYPE_PUNAISE5=250,
    TYPE_VAGUE_DEVANT=251,
    TYPE_VAGUE_DERRIERE=252,
    TYPE_PLANCHES=253,
    TYPE_SLOPEY_PLAT=254,
    TYPE_INVALID=255
} ObjType;

struct Obj {
    Sprite * sprites;
    Animation * animations;
    u8 * img_buffer;
    ObjState * * eta;
    u8 * cmds;
    u8 * cmd_labels;
    CmdContext cmd_contexts[1];
    s16 x_pos;
    s16 y_pos;
    s16 id;
    s16 screen_x_pos;
    s16 screen_y_pos;
    s16 field12_0x26;
    s16 init_x_pos;
    s16 init_y_pos;
    s16 speed_x;
    s16 speed_y;
    u16 nb_sprites;
    s16 cmd_offset;
    s16 nb_cmd;
    s16 field20_0x36; /*For Rayman this is the current follow obj id*/
    s16 follow_y;
    s16 follow_x;
    s16 field23_0x3c;
    s16 field24_0x3e;
    s16 ray_dist;
    s16 iframes_timer;
    s16 test_block_index;
    s16 scale;
    u16 zdc;
    s16 active_timer;
    BlockType btypes[5];
    u8 field32_0x51;
    u8 offset_bx;
    u8 offset_by;
    u8 anim_index;
    u8 anim_frame;
    u8 main_etat;
    u8 init_main_etat;
    u8 sub_etat;
    u8 init_sub_etat;
    ObjCommand cmd;
    u8 gravity_value_1;
    u8 gravity_value_2;
    ChangeAnimMode change_anim_mode;
    u8 offset_hy;
    u8 follow_sprite;
    u8 hit_points;
    u8 init_hit_points;
    u8 init_flag;
    ObjType type;
    u8 hit_sprite;
    ObjActiveFlag active_flag;
    u8 detect_zone;
    u8 detect_zone_flag;
    u8 cmd_context_index;
    u8 field56_0x69;
    u8 display_prio;
    u8 timer;
    ObjFlags flags;
};

typedef struct ObjHandlers
{
    void (* do_obj)(Obj *);
} ObjHandlers;

typedef struct LevelData
{
    Obj * objects;
    u8 nb_objects;
} LevelData;

#endif