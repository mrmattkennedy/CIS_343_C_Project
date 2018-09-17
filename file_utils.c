#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int read_file (char* filename, char **buffer) {
	//Declare vars
	FILE *fin = fopen(filename, "r");
	char temp;
	
	//If the file failed to open, return with errno.
	if (fin == NULL)
		return errno;
	
	//Get the size of the file.
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//Declare vars to get the info from the file.
	char* tempBuff;
	int curr = 0;
	//*buffer = (char *)malloc(size * sizeof(char));
	tempBuff = (char *)malloc(size * sizeof(char));
	
	while (fscanf(fin, "%c", &temp) != EOF)
	{	
		//printf("Char is %s\n", *buffer);
		tempBuff[curr++] = temp;
		//**buffer = temp;
	}
	//De-reference pointer to pointer, left with pointer.
	//Set pointer equal to tempBuff.
	*buffer = tempBuff;
	free(tempBuff);
	fclose(fin);
	return size;
}

int write_file( char* filename, char *buffer, int size) {
	FILE *fout = fopen (filename, "w");

	for (int i = 0; i < size; i++)
		fprintf(fout, "%c", buffer[i]);
	fclose(fout);
	return errno;
}

