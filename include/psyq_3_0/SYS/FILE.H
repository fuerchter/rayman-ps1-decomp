#ifndef _SYS_FILE_H
#define _SYS_FILE_H

#include <psyq_3_0/SYS/FCNTL.H>

/* Flag for open() */
#define O_RDONLY        FREAD
#define O_WRONLY        FWRITE
#define O_RDWR          FREAD|FWRITE
#define O_CREAT         FCREAT  /* open with file create */
#define O_NOBUF         FNBUF	/* no device buffer and console interrupt */
#define O_NBLOCK        FNBLOCK	/* non blocking mode */
#define O_NOWAIT        FASYNC	/* asyncronous i/o */

#define SEEK_SET	0
#define SEEK_END	1
#define SEEK_CUR	2

#endif