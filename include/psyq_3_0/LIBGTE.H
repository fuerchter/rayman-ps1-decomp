#ifndef _LIBGTE_H_
#define _LIBGTE_H_

typedef struct {		/* color type vector */	
	u_char	r, g, b, cd;
} CVECTOR;
	       
typedef struct {		/* 2D short vector */
	short vx, vy;
} DVECTOR;

void InitGeom();

void SetGeomOffset(long ofx,long ofy);
void SetGeomScreen(long h);

int rcos(int a);
int rsin(int a);

#endif