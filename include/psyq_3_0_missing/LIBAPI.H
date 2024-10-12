#ifndef _MISSING_LIBAPI_H_
#define _MISSING_LIBAPI_H_

extern long open(char *, unsigned long);
extern struct DIRENTRY * firstfile(char *, struct DIRENTRY *);
extern struct DIRENTRY * nextfile(struct DIRENTRY *);

extern long InitPAD(char *,long ,char *,long);
extern long StartPAD(void);
extern void StopPAD(void);

extern void _96_remove(void);

extern void ChangeClearPAD( long );

#endif