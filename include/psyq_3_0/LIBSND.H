#ifndef _LIBSND_H_
#define _LIBSND_H_

/*
 * Macro 
 */
#define SSPLAY_INFINITY  0 
#define SS_NOTICK	 0x1000
#define SS_NOTICK0	 0
#define SS_TICK60	 1
#define SS_TICK240	 2
#define SS_TICK120	 3
#define SS_TICKMODE_MAX  4
#define SSPLAY_PAUSE     0
#define SSPLAY_PLAY      1
#define SS_SOFF          0      
#define SS_SON           1     
#define SS_MIX           0    
#define SS_REV           1   
#define SS_SERIAL_A      0 
#define SS_SERIAL_B      1     
#define SS_MUTE_OFF      0     
#define SS_MUTE_ON       1     

#define SS_IMEDIATE 	    0
#define SS_IMMEDIATE        0
#define SS_WAIT_COMPLETED   1

#define SS_REV_TYPE_OFF        0
#define SS_REV_TYPE_ROOM       1
#define SS_REV_TYPE_STUDIO_A   2
#define SS_REV_TYPE_STUDIO_B   3
#define SS_REV_TYPE_STUDIO_C   4
#define SS_REV_TYPE_HALL       5
#define SS_REV_TYPE_SPACE      6
#define SS_REV_TYPE_ECHO       7
#define SS_REV_TYPE_DELAY      8
#define SS_REV_TYPE_PIPE       9

#define SS_SEQ_TABSIZ     172

/*
 * CallBack
 */
typedef void (*SsMarkCallbackProc)(short, short, short);

extern void  SsVabClose (short);          
extern short SsVabTransCompleted (short);
extern short SsVabOpenHead (unsigned char*, short);
extern short SsVabTransBody (unsigned char*, short);

extern void  SsInit (void);
extern void  SsSetTableSize (char*, short, short);
extern void  SsSetTickMode (long);
extern void  SsStart (void);
extern void  SsEnd (void);

extern void  SsSeqCalledTbyT (void);           
extern void  SsSeqPlay (short, char, short);    
extern void  SsSeqSetVol (short, short, short);  
extern void  SsSeqSetCrescendo (short, short, long); 

extern short SsSepOpen (unsigned long*, short, short);
extern void  SsSepPlay (short, short, char, short);
extern void  SsSepStop (short, short);
extern void  SsSepSetVol (short, short, short, short);
extern void  SsSepClose (short);

extern void  SsSetMVol (short, short);              
extern void  SsSetSerialAttr (char, char, char);     
extern void  SsSetSerialVol (char, short, short);    
extern void  SsSetStereo (void);                       

extern short SsIsEos (short, short);
extern void  SsSetMarkCallback (short, short, SsMarkCallbackProc);

extern short SsUtKeyOn (short, short, short, short, short, short, short);
extern short SsUtKeyOff (short, short, short, short, short);

extern short SsUtSetVVol (short, short, short);
extern void  SsUtReverbOn (void);
extern void  SsUtReverbOff (void);
extern short SsUtSetReverbType (short);
extern void  SsUtSetReverbDepth (short, short);

extern void  SsUtAllKeyOff (short);

#endif