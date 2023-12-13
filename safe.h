/* BY: Jumps Are Op. (jumpsareop@gmail.com)
 * LICENSE: GPLv3-or-later
 */

#ifndef _SAFE_H
#define _SAFE_H

/* We are ISO-C99 compliant, no need for _POSIX_C_SOURCE */
#include <errno.h>
#include <stdlib.h>

char _safe_e = 0;

/* try(func, arg1, arg2, ...) error_statement; */
#define try(x, ...)                 \
	_safe_e = 0;                \
	errno = 0;                  \
	x(__VA_ARGS__);             \
	if(errno)                   \
		if(!_safe_e){       \
			perror(#x); \
			_safe_e=1;  \
		}else

/* tryset(var, func, arg1, arg2, ...) error_statement; */
#define tryset(v, x, ...)           \
	_safe_e = 0;                \
	errno = 0;                  \
	v = x(__VA_ARGS__);         \
	if(errno)                   \
		if(!_safe_e){       \
			perror(#x); \
			_safe_e=1;  \
		}else

#endif /* _SAFE_H */
