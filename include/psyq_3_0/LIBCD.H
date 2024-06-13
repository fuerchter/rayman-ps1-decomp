#ifndef _LIBCD_H_
#define _LIBCD_H_

/*
 * CD-ROM Mode
 */
#define CdlModeStream  0x100    /* 0: not streaming     1: streaming    */
#define CdlModeSpeed	0x80	/* 0: normal speed	1: double speed	*/
#define CdlModeRT	0x40	/* 0: ADPCM off		1: ADPCM on	*/
#define CdlModeSize1	0x20	/* 0: 2048 byte		1: 2340byte	*/
#define CdlModeSize0	0x10	/* 0: -			1: 2328byte	*/
#define CdlModeSF	0x08	/* 0: Channel off	1: Channel on	*/
#define CdlModeRept  	0x04	/* 0: Report off	1: Report on	*/
#define CdlModeAP	0x02	/* 0: AutoPause off	1: AutoPause on */
#define CdlModeDA	0x01	/* 0: CD-DA off		1: CD-DA on	*/

/*
 * Status
 */
#define CdlStatPlay	0x80	/* playing CD-DA */
#define CdlStatSeek	0x40	/* seeking */
#define CdlStatRead	0x20	/* reading data sectors */
#define CdlStatStandby	0x02	/* spindle motor rotating */

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
 * Interrupts
 */
#define CdlNoIntr	0x00	/* No interrupt */
#define CdlDataReady	0x01	/* Data Ready */
#define CdlComplete	0x02	/* Command Complete */
#define CdlAcknowledge	0x03	/* Acknowledge (reserved) */
#define CdlDataEnd	0x04	/* End of Data Detected */
#define CdlDiskError	0x05	/* Error Detected */

/*
 * Library Macros
 */
#define btoi(b)		((b)/16*10 + (b)%16)		/* BCD to u_char */
#define itob(i)		((i)/10*16 + (i)%10)		/* u_char to BCD */

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

CdlFILE *CdSearchFile(CdlFILE *fp, char *name);
int CdControl(u_char com, u_char *param, u_char *result);
int CdControlB(u_char com, u_char *param, u_char *result);
int CdMix(CdlATV *vol);
int CdRead(int sectors, u_long *buf, int mode);
int CdReadSync(int mode, u_char *result);
int CdSync(int mode, u_char *result);
u_long CdReadyCallback(void (*func)());
u_long CdSyncCallback(void (*func)());

#endif