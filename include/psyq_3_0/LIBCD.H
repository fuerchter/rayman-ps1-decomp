#ifndef _LIBCD_H_
#define _LIBCD_H_

/*
 *	Location
 */
typedef struct {
	u_char minute;		/* minute (BCD) */
	u_char second;		/* second (BCD) */
	u_char sector;		/* sector (BCD) */
	u_char track;		/* track (void) */
} CdlLOC;

/*
 *	File System
 */
typedef struct {
	CdlLOC	pos;		/* file location */
	u_long	size;		/* file size */
	char	name[16];	/* file name (body) */
} CdlFILE;

int CdSync(int mode, u_char *result);

#endif