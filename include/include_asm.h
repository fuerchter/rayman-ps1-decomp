#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

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

#endif