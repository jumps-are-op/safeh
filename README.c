/* BY: Jumps Are Op. (jumpsareop@gmail.com)
 * LICENSE: GPLv3-or-later, see LICENSE file.
 * COMPILE USING: gcc ./README.c -o safe.out
 */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "safe.h"

int main(){
	char *buf;

	puts("Hello, world!");

	tryset(buf, malloc, 20) return errno;
	memset(buf, '\0', 20);

	strncpy(buf, "Hello, safe world!", 20);

	try(puts, buf) return errno;
}
