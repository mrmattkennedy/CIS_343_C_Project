#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>

int read_file (char* filename, char **buffer) {
	FILE *fin = fopen(filename, "r");
	char temp;
	char *tempBuff;

	if (fin == NULL)
		return errno;

	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	
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
	FILE *fout = fopen (filename, "w");

	for (int i = size - 1; i >= 0; i--)
		fprintf(fout, "%c", buffer[i]);

	return errno;
}

