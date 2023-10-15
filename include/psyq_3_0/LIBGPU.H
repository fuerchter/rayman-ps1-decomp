#ifndef _LIBGPU_H_
#define _LIBGPU_H_

/*
 * Rectangle:
 */
typedef struct {
	short x, y;		/* offset point on VRAM */
	short w, h;		/* width and height */
} RECT;

int ClearImage(RECT *rect, u_char r, u_char g, u_char b);
int DrawSync(int mode);
int LoadImage(RECT *rect, u_long *p);

#endif