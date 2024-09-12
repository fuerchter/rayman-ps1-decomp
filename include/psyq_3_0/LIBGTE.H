#ifndef _LIBGTE_H_
#define _LIBGTE_H_

typedef struct  {
	short	m[3][3];	/* 3x3 rotation matrix */
        long    t[3];		/* transfer vector */
} MATRIX;

typedef struct {		/* long word type 3D vector */
	long	vx, vy;
	long	vz, pad;
} VECTOR;

typedef struct {		/* short word type 3D vector */	
	short	vx, vy;
	short	vz, pad;
} SVECTOR;

typedef struct {		/* color type vector */	
	u_char	r, g, b, cd;
} CVECTOR;
	       
typedef struct {		/* 2D short vector */
	short vx, vy;
} DVECTOR;

void InitGeom();

MATRIX *RotMatrix(SVECTOR *r,MATRIX *m);
MATRIX *TransMatrix(MATRIX *m,VECTOR *v);

void SetRotMatrix(MATRIX *m); 
void SetTransMatrix(MATRIX *m);
void SetGeomOffset(long ofx,long ofy);
void SetGeomScreen(long h);

long RotTransPers(SVECTOR *v0,long *sxy,long *p,long *flag);

long AverageZ4(long sz0,long sz1,long sz2,long sz3);

int rcos(int a);
int rsin(int a);

#endif