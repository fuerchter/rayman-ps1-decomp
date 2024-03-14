#ifndef _KERNEL_H
#define _KERNEL_H

struct DIRENTRY {
	char name[20];
	long attr;
	long size;
	struct DIRENTRY *next;
	long head;
	char system[4];
};

#endif