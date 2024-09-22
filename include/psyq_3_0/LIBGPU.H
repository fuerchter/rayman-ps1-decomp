#ifndef _LIBGPU_H_
#define _LIBGPU_H_

/*
 * Rectangle:
 */
typedef struct {
	short x, y;		/* offset point on VRAM */
	short w, h;		/* width and height */
} RECT;

/*
 * Environment 
 */
typedef struct {
	u_long	tag;
	u_long	code[15];
} DR_ENV;				/* Packed Drawing Environment */

typedef struct {
	RECT	clip;		/* clip area */
	short	ofs[2];		/* drawing offset */
	RECT	tw;		/* texture window */
	u_short tpage;		/* texture page */	
	u_char	dtd;		/* dither flag (0:off, 1:on) */
	u_char	dfe;		/* flag to draw on display area (0:off 1:on) */
	u_char	isbg;		/* enable to auto-clear */
	u_char	r0, g0, b0;	/* initital background color */
	DR_ENV	dr_env;		/* reserved */
} DRAWENV;

typedef struct {
	RECT	disp;		/* display area */
	RECT	screen;		/* display start point */
	u_char	isinter;	/* interlace 0: off 1: on */
	u_char	isrgb24;	/* RGB24 bit mode */
	u_char	pad0, pad1;	/* reserved */
} DISPENV;

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	short	x1,	y1;
	short	x2,	y2;
	short	x3,	y3;
} POLY_F4;				/* Flat Quadrangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
	short	x1,	y1;
	u_char	u1, v1;	u_short	tpage;
	short	x2,	y2;
	u_char	u2, v2;	u_short	pad1;
	short	x3,	y3;
	u_char	u3, v3;	u_short	pad2;
} POLY_FT4;				/* Flat Textured Quadrangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	r1, g1, b1, pad1;
	short	x1,	y1;
	u_char	r2, g2, b2, pad2;
	short	x2,	y2;
} POLY_G3;				/* Gouraud Triangle */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	r1, g1, b1, pad1;
	short	x1,	y1;
	u_char	r2, g2, b2, pad2;
	short	x2,	y2;
	u_char	r3, g3, b3, pad3;
	short	x3,	y3;
} POLY_G4;				/* Gouraud Quadrangle */

/*
 * Sprite Primitive Definitions
 */
typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
	short	w,	h;
} SPRT;					/* free size Sprite */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
} SPRT_16;				/* 16x16 Sprite */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	u_char	u0, v0;	u_short	clut;
} SPRT_8;				/* 8x8 Sprite */

/*
 * Tile Primitive Definitions
 */
typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
	short	w,	h;
} TILE;					/* free size Tile */

typedef struct {
	u_long	tag;
	u_char	r0, g0, b0, code;
	short	x0, 	y0;
} TILE_1;				/* 1x1 Tile */

DISPENV *PutDispEnv(DISPENV *env);
DISPENV *SetDefDispEnv(DISPENV *env, int x, int y, int w, int h);
DRAWENV *PutDrawEnv(DRAWENV *env);
DRAWENV *SetDefDrawEnv(DRAWENV *env, int x, int y, int w, int h);
int ClearImage(RECT *rect, u_char r, u_char g, u_char b);
int DrawSync(int mode);
int GetGraphType(void) ;
int LoadImage(RECT *rect, u_long *p);
int MoveImage(RECT *rect, int x, int y);
int ResetGraph(int mode);
int SetGraphDebug(int level);
int StoreImage(RECT *rect, u_long *p);
u_long *ClearOTag(u_long *ot, int n);
u_short GetClut(int x, int y) ;
u_short GetTPage(int tp, int abr, int x, int y) ;
u_short LoadClut(u_long *clut, int x, int y);
void AddPrim(void *ot, void *p) ;
void DrawOTag(u_long *p);
void SetDispMask(int mask);
void SetDrawEnv(DR_ENV *dr_env, DRAWENV *env);
void SetPolyF4(POLY_F4 *p) ;
void SetPolyFT4(POLY_FT4 *p) ;
void SetPolyG3(POLY_G3 *p) ;
void SetPolyG4(POLY_G4 *p) ;
void SetSemiTrans(void *p, int abe) ;
void SetShadeTex(void *p, int tge) ;
void SetSprt(SPRT *p) ;
void SetSprt16(SPRT_16 *p) ;
void SetSprt8(SPRT_8 *p) ;
void SetTile(TILE *p) ;
void SetTile1(TILE_1 *p) ;

#endif