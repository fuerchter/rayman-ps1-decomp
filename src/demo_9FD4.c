#include "demo_9FD4.h"

/*
mips-linux-gnu-ld: build/asm/loading_DA64.s.o: in function `FUN_80132864':
(.text+0x608): undefined reference to `D_801C4370'
mips-linux-gnu-ld: (.text+0x60c): undefined reference to `D_801C4370'
mips-linux-gnu-ld: build/asm/loading_794DC.s.o: in function `load_world':
(.text+0x744): undefined reference to `D_801C4370'
mips-linux-gnu-ld: (.text+0x748): undefined reference to `D_801C4370'
*/
/*u8 DemoRecord[6][300] =
{
    {0x00, 0x32, 0x20, 0x32, 0x21, 0x04, 0x20, 0x12, 0x00, 0x18, 0x20, 0x28, 0x22, 0x06, 0x20, 0x09, 0x00, 0x06, 0x20, 0x2a, 0x22, 0x08, 0x20, 0x0a, 0x00, 0x45, 0x80, 0x03, 0xa0, 0x0a, 0x00, 0x05, 0x20, 0x5a, 0x22, 0x09, 0x20, 0x0f, 0x00, 0x07, 0x10, 0x0a, 0x90, 0x17, 0x10, 0x01, 0x00, 0x19, 0x10, 0x35, 0x00, 0x01, 0x80, 0x16, 0x90, 0x01, 0x10, 0x18, 0x90, 0x01, 0x80, 0x17, 0x90, 0x01, 0x10, 0x5f, 0x90, 0x02, 0x80, 0x17, 0x90, 0x01, 0x10, 0x97, 0x90, 0x02, 0x80, 0x10, 0x90, 0x03, 0x10, 0x1c, 0x90, 0x02, 0x80, 0x2c, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x2e, 0x20, 0x07, 0x22, 0x0f, 0x20, 0x03, 0x00, 0x1d, 0x02, 0x07, 0x00, 0x0f, 0x02, 0x06, 0x00, 0x04, 0x02, 0x07, 0x00, 0x20, 0x02, 0x06, 0x00, 0x4c, 0x02, 0x02, 0x00, 0x1c, 0x20, 0x01, 0x00, 0x22, 0x10, 0x02, 0x00, 0x20, 0x12, 0x02, 0x10, 0x01, 0x00, 0x1f, 0x80, 0x07, 0x00, 0x1b, 0x10, 0x04, 0x00, 0x0d, 0x20, 0x01, 0x00, 0x0f, 0x20, 0x04, 0x22, 0x02, 0x20, 0x11, 0xa0, 0x16, 0x80, 0x01, 0x00, 0x0c, 0x10, 0x21, 0x00, 0x17, 0x02, 0x04, 0x00, 0x5a, 0x02, 0x02, 0x00, 0x1d, 0x80, 0x02, 0x00, 0x4f, 0x02, 0x04, 0x00, 0x54, 0x02, 0x02, 0x00, 0x02, 0x10, 0x2d, 0x00, 0x10, 0x20, 0x10, 0x00, 0x05, 0x20, 0x06, 0x00, 0x05, 0x20, 0x01, 0x22, 0x02, 0x20, 0x04, 0x00, 0x07, 0x10, 0x02, 0x90, 0x01, 0x80, 0x02, 0xa0, 0x0c, 0x80, 0x0c, 0x10, 0x0c, 0x00, 0x14, 0x10, 0x04, 0x00, 0x12, 0x20, 0x03, 0x00, 0x06, 0x20, 0x05, 0x22, 0x03, 0x20, 0x21, 0x00, 0x03, 0x10, 0x08, 0x90, 0x16, 0x10, 0x01, 0x00, 0x04, 0x20, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x25, 0x20, 0x4d, 0x00, 0x08, 0x02, 0x0b, 0x00, 0x0c, 0x01, 0x07, 0x00, 0x32, 0x22, 0x0c, 0x20, 0x12, 0x00, 0x09, 0x10, 0x04, 0x00, 0x11, 0x20, 0x02, 0x00, 0x0c, 0x01, 0x1b, 0x00, 0x01, 0x80, 0x31, 0x00, 0x12, 0x01, 0x07, 0x00, 0x0c, 0x80, 0x21, 0x00, 0x13, 0x01, 0x0a, 0x00, 0x0e, 0x80, 0x2a, 0x00, 0x21, 0x10, 0x07, 0x00, 0x11, 0x02, 0x0b, 0x00, 0x27, 0x20, 0x29, 0x00, 0x11, 0x20, 0x47, 0x00, 0x28, 0x02, 0x04, 0x22, 0x04, 0x20, 0x05, 0x00, 0x06, 0x20, 0x1d, 0x00, 0x1f, 0x20, 0x06, 0x22, 0x12, 0x20, 0x07, 0x22, 0x0e, 0x20, 0x0a, 0x22, 0x07, 0x02, 0x02, 0x00, 0x5a, 0x20, 0x05, 0x22, 0x05, 0x20, 0x0e, 0x22, 0x19, 0x20, 0x39, 0x22, 0x06, 0x20, 0x26, 0x00, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x43, 0x01, 0x29, 0x00, 0x7d, 0x10, 0x03, 0x00, 0x14, 0x01, 0x21, 0x00, 0x54, 0x20, 0x05, 0x00, 0x1d, 0x20, 0x15, 0x00, 0x07, 0x01, 0x1e, 0x00, 0x07, 0x20, 0x1f, 0x00, 0x16, 0x01, 0x1a, 0x00, 0x01, 0x20, 0x23, 0x00, 0x06, 0x01, 0x24, 0x00, 0x08, 0x20, 0x23, 0x00, 0x08, 0x01, 0x22, 0x00, 0x26, 0x20, 0x0c, 0x00, 0x07, 0x01, 0x19, 0x00, 0x25, 0x20, 0x08, 0x00, 0x16, 0x02, 0x04, 0x00, 0x1a, 0x01, 0x07, 0x00, 0x37, 0x20, 0x01, 0x22, 0x10, 0x20, 0x0b, 0x00, 0x20, 0x20, 0x0a, 0x00, 0x04, 0x01, 0x28, 0x00, 0x2c, 0x20, 0x02, 0x22, 0x10, 0x20, 0x20, 0x00, 0x06, 0x01, 0x60, 0x00, 0x03, 0x80, 0x3a, 0x00, 0x1b, 0x20, 0x04, 0x00, 0x05, 0x01, 0x45, 0x00, 0x01, 0x80, 0x4d, 0x00, 0x2c, 0x01, 0x13, 0x00, 0x20, 0x20, 0x01, 0x22, 0x08, 0x20, 0x1d, 0x00, 0x05, 0x01, 0x1e, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0x30, 0x20, 0x39, 0x00, 0x63, 0x20, 0x03, 0x22, 0x06, 0x20, 0x14, 0x00, 0x49, 0x20, 0x04, 0x22, 0x1d, 0x20, 0x05, 0x00, 0x18, 0x20, 0x04, 0x00, 0x30, 0x20, 0x02, 0x00, 0x55, 0x20, 0x1a, 0x00, 0x13, 0x20, 0x05, 0x00, 0x0c, 0x80, 0x54, 0x00, 0x17, 0x02, 0x07, 0x22, 0x0f, 0x20, 0x07, 0x00, 0x35, 0x10, 0x01, 0x00, 0x48, 0x02, 0x03, 0x12, 0x0b, 0x10, 0x0b, 0x00, 0x54, 0x10, 0x02, 0x12, 0x16, 0x10, 0x05, 0x00, 0x02, 0x02, 0x0a, 0x00, 0x08, 0x02, 0x02, 0x12, 0x06, 0x00, 0x0d, 0x10, 0x07, 0x00, 0x09, 0x80, 0x45, 0x00, 0x08, 0x10, 0x07, 0x12, 0x05, 0x10, 0x4b, 0x00, 0x06, 0x80, 0x32, 0x90, 0x03, 0x10, 0x03, 0x12, 0x05, 0x10, 0x15, 0x90, 0x04, 0x80, 0x1e, 0x90, 0x02, 0x10, 0x02, 0x12, 0x13, 0x10, 0x0b, 0x00, 0x0a, 0x20, 0x24, 0x22, 0x05, 0x20, 0x1f, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    {0x00, 0xff, 0x00, 0x7e, 0x10, 0x30, 0x00, 0x2b, 0x20, 0x02, 0x00, 0x21, 0x20, 0x03, 0x22, 0x10, 0x20, 0x1c, 0x00, 0x26, 0x10, 0x0a, 0x50, 0x01, 0x52, 0x1d, 0x50, 0x0a, 0x10, 0x06, 0x00, 0x0e, 0x20, 0x02, 0x00, 0x83, 0x22, 0x0e, 0x20, 0x1e, 0x00, 0x30, 0x10, 0x03, 0x12, 0x02, 0x52, 0x19, 0x50, 0x0b, 0x10, 0x03, 0x00, 0x29, 0x20, 0x03, 0x00, 0x6b, 0x02, 0x0e, 0x00, 0x45, 0x02, 0x14, 0x00, 0x45, 0x20, 0x0d, 0x22, 0x1d, 0x20, 0x11, 0x22, 0x0d, 0x02, 0x02, 0x00, 0x14, 0x20, 0x03, 0x00, 0x16, 0x20, 0x15, 0x00, 0x13, 0x20, 0x04, 0x00, 0x17, 0x20, 0x01, 0x00, 0x1e, 0x02, 0x0a, 0x00, 0x0b, 0x20, 0x03, 0x00, 0x0b, 0x20, 0x05, 0x00, 0x31, 0x02, 0x12, 0x12, 0x0b, 0x52, 0x0b, 0x12, 0x01, 0x00, 0x05, 0x20, 0x14, 0x00, 0x43, 0x10, 0x1b, 0x20, 0x12, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
};

s16 DemoRecordSize[6] = {0x0058, 0x0098, 0x0070, 0x0082, 0x0080, 0x007e};
s16 DemoRecordWorld[6] = {0x0002, 0x0003, 0x0004, 0x0005, 0x0004, 0x0005};
s16 DemoRecordMap[6] = {0x0007, 0x0007, 0x0001, 0x0004, 0x000a, 0x000a};*/


/* 9FD4 8012E7D4 -O2 */
INCLUDE_ASM("asm/nonmatchings/demo_9FD4", InitDemoJeu);

/* A228 8012EA28 -O2 */
/*? DO_FADE_OUT(s32);
? INIT_RAY(?);
? POINTEUR_BOUTONS_OPTIONS_BIS(u8 *, u8 *, OptionsJeu *, OptionsJeu *);
? PS1_PlayVideo(?);*/

void FinDemoJeu(void)
{
    if (record.repeat_index == record.repeat_length)
        RunTimeDemo = 180;
    else
        RunTimeDemo = 1800;
    ModeDemo = 0;
    TempsDemo = 0;
    INIT_RAY(1);
    RayEvts = SauveRayEvtsDemo;
    record.is_playing = FALSE;
    record.current_offset = 0;
    record.length = 0;
    record.data = 0;
    new_world = FALSE;
    new_level = FALSE;
    num_world = 0;
    num_level = 0;
    num_world_choice = 0;
    num_level_choice = 0;
    finBosslevel[1] &= 0xF5;
    __builtin_memcpy(&options_jeu, &options_jeu_save, sizeof(OptionsJeu));
    POINTEUR_BOUTONS_OPTIONS_BIS();
    NumDemo++;
    if (record.repeat_index == record.repeat_length)
    {
        DO_FADE_OUT();
        PS1_PlayVideo(VIDEO_DEMO);
        if (PS1_VideoState == VIDEOST_SKIPPED)
            RunTimeDemo = 1800;
    }
}