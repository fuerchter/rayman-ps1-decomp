#ifndef	_SYS_TYPES_H
#define	_SYS_TYPES_H

typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
typedef	unsigned short	ushort;		/* sys III compat */
#ifndef __psx__
typedef	unsigned int	uint;		/* sys V compat */
typedef	unsigned long	ulong;		/* sys V compat */
#endif /* ! __psx__ */

#endif