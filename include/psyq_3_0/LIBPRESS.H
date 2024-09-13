#ifndef _LIBPRESS_H_
#define _LIBPRESS_H_

extern void DecDCTReset(int mode);
extern void DecDCTvlc(u_long *bs, u_long *buf);
extern void DecDCTin(u_long *buf, int mode);
extern void DecDCTout(u_long *buf, int size);

#endif