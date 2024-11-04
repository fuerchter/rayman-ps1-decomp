#ifndef _MISSING_LIBAPI_H_
#define _MISSING_LIBAPI_H_

extern long OpenEvent(unsigned long,long,long,long (*func)());
extern long TestEvent(long);
extern long EnableEvent(long);

extern long open(char *, unsigned long);
extern long close(long);
extern long read(long, void *, long);
extern long write(long, void *, long);
extern struct DIRENTRY * firstfile(char *, struct DIRENTRY *);
extern struct DIRENTRY * nextfile(struct DIRENTRY *);
extern long delete(char *); /* named "erase" in later psyq? */

extern long format(char *);

extern long InitPAD(char *,long ,char *,long);
extern long StartPAD(void);
extern void StopPAD(void);

extern int  EnterCriticalSection(void);
extern void ExitCriticalSection(void);

extern void _96_remove(void);

extern void ChangeClearPAD( long );

extern void InitCARD(long val);
extern long StartCARD(void);
extern void _bu_init(void);
extern long _card_info(long chan);
extern long _card_clear(long chan);
extern long _card_load(long chan);
extern long _card_auto(long val);

#endif