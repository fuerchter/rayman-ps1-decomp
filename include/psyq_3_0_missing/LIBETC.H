#ifndef _MISSING_LIBETC_H_
#define _MISSING_LIBETC_H_

void PadInit(int mode);
int ResetCallback(void) ;
int StopCallback(void) ;
int VSync(int mode);
int VSyncCallback(void (*f)(void)) ;
void PadStop(void);

#endif