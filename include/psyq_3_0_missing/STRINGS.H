#ifndef	_MISSING_STRINGS_H
#define	_MISSING_STRINGS_H

extern char *strcat (char *, const char *);
extern char *strcpy (/* char *, char * */);	/* To avoid conflicting */
extern int   strcmp (/* char *, char * */);	/* To avoid conflicting */
extern int   strlen (/* char * */);		/* To avoid conflicting */

#endif