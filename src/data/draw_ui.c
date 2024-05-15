#include "draw_ui.h"

/*
presumably need to finish display_time first?

mips-linux-gnu-ld: build/src/display_ui.c.o: in function `display_time':
src/display_ui.c:(.text+0x11d0): undefined reference to `D_801CEF98'
mips-linux-gnu-ld: src/display_ui.c:(.text+0x11d4): undefined reference to `D_801CEF98'
*/
u8 PS1_star_spr[] = {0x15, 0x16, 0x17, 0x18, 0x15, 0x19, 0x16, 0x15};
u8 s__801cef84[] = "%";
u8 PS1_TingsToGet_Col = 1;
u8 PS1_TingsToGet_ColAdd = 1;
u8 s_time_801cef88[] = "time";
u8 s__801cef90[] = "/";
u8 s_go__801cef94[] = "/go !/";
u8 s_the_end_801cef9c[] = "the end";