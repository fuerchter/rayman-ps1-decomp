#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#ifdef IGNORE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
#else
#define INCLUDE_ASM(FOLDER, NAME) \
__asm__( \
    ".text\n" \
    "\t.align\t2\n" \
    "\t.set noreorder\n" \
    "\t.set noat\n" \
    ".include \""FOLDER"/"#NAME".s\"\n" \
    "\t.set reorder\n" \
    "\t.set at\n" \
)
#define INCLUDE_RODATA(FOLDER, NAME) \
__asm__( \
    ".section .rodata\n" \
    "\t.include \""FOLDER"/"#NAME".s\"\n" \
    ".section .text" \
)
#endif

#endif