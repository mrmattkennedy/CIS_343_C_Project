#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int read_file (char* filename, char **buffer) {
	FILE *fin = fopen(filename, "r");
	char temp;
	char *tempBuff;

	if (fin == NULL)
		return errno;

	off_t size = ftello(fin);
	
	tempBuff = (char*)malloc(size * sizeof(char));
	
	int curr = 0;
	while (fscanf(fin, "%c", &temp) != EOF)
	{	
		tempBuff[curr] = temp;
		curr++;

	}

	*buffer = tempBuff;
	return size;
}

int write_file( char* filename, char *buffer, int size) {
	char *p1 = buffer;
   	char *p2 = buffer + size - 1;

	while (p1 < p2) {
		char tmp = *p1;
	        *p1++ = *p2;
        	*p2-- = tmp;
	}	
	printf("%s\n", buffer);
	return errno;
}
