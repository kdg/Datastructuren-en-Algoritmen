#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "crc32.h"

int main (int arg, char ** argv) {
	chksum_crc32gentab();
	char * frank  = "Frank";
	char * jef  = "Jef";
	char * dirk = "Dirk";

	printf("crc32(%s) = %ld\n", frank, (long int) chksum_crc32(frank, strlen(frank)));
	printf("crc32(%s) = %ld\n", jef, (long int) chksum_crc32(jef, strlen(jef)));
	printf("crc32(%s) = %ld\n", dirk, (long int) chksum_crc32(dirk, strlen(dirk)));


}
