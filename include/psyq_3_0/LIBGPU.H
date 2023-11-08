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
	u_char	u0, v0;	u_short	clut;
	short	x1,	y1;
	u_char	u1, v1;	u_short	tpage;
	short	x2,	y2;
	u_char	u2, v2;	u_short	pad1;
	short	x3,	y3;
	u_char	u3, v3;	u_short	pad2;
} POLY_FT4;				/* Flat Textured Quadrangle */

int sprintf(char *buffer, char *fmt, ...);
int ClearImage(RECT *rect, u_char r, u_char g, u_char b);
int DrawSync(int mode);
int LoadImage(RECT *rect, u_long *p);
u_long *ClearOTag(u_long *ot, int n);
void DrawOTag(u_long *p);
DISPENV *PutDispEnv(DISPENV *env);
DRAWENV *PutDrawEnv(DRAWENV *env);
void SetPolyFT4(POLY_FT4 *p) ;
void SetSemiTrans(void *p, int abe) ;
void SetShadeTex(void *p, int tge) ;

#endif