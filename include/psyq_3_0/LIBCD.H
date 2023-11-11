#ifndef _LIBCD_H_
#define _LIBCD_H_

/*
 * CD-ROM Primitive Commands
 */
#define CdlNop		0x01	
#define CdlSetloc	0x02	
#define CdlPlay		0x03	
#define CdlForward	0x04	
#define CdlBackward	0x05
#define CdlReadN	0x06
#define CdlStandby	0x07
#define CdlStop		0x08
#define CdlPause	0x09
#define CdlReset	0x0a
#define CdlMute		0x0b
#define CdlDemute	0x0c
#define CdlSetfilter	0x0d
#define CdlSetmode	0x0e
#define CdlGetparam	0x0f
#define CdlGetlocL	0x10
#define CdlGetlocP	0x11
#define CdlReadT	0x12
#define CdlGetTN	0x13
#define CdlGetTD	0x14
#define CdlSeekL	0x15
#define CdlSeekP	0x16
#define CdlReadS	0x1B

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
 *	Attenuator
 */
typedef struct {
	u_char	val0;		/* volume for CD(L) -> SPU (L) */
	u_char	val1;		/* volume for CD(L) -> SPU (R) */
	u_char	val2;		/* volume for CD(R) -> SPU (L) */
	u_char	val3;		/* volume for CD(R) -> SPU (R) */
} CdlATV;

/*
 *	File System
 */
typedef struct {
	CdlLOC	pos;		/* file location */
	u_long	size;		/* file size */
	char	name[16];	/* file name (body) */
} CdlFILE;

int CdSync(int mode, u_char *result);
int CdMix(CdlATV *vol);
int CdControlB(u_char com, u_char *param, u_char *result);

#endif