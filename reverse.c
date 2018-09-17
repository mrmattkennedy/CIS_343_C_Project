#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "file_utils.h"

//Input file is arg 1, output file is arg 2.
#define INPUT_FILE 1
#define OUTPUT_FILE 2

extern int errno;

int main (int argc, char** argv) {

	char* buffer;

	/* If the number of arguments is not 3, then return failure. */
	if (argc != 3)
	{
		printf("Incorrect number of arguments. Should be 3.\n");
		printf("syntax: ./reverse [inputfile] [outputfile]\n");
		return EXIT_FAILURE;
	}

	int size = read_file(*(argv + INPUT_FILE), &buffer);
	if (errno != 0)
	{
		fprintf(stderr, "\n\nError present. errno is %d\n", errno);
		perror("Error");
		fprintf(stderr, "\n\n");
		return errno;
	}
	printf("Buffer is %s\n", buffer);
	/*
	char* bufferRev = (char*)malloc(size * sizeof(char));
	for (int i = 0; i < size; i++)
		bufferRev[size - 1 - i] = buffer[i];

	write_file (*(argv + OUTPUT_FILE), bufferRev, size);
	if (errno != 0)
	{
		fprintf(stderr, "\n\nError present. errno is %d\n", errno);
		perror("Error");
		fprintf(stderr, "\n\n");
		return errno;
	}
	printf("%s\n%s\n", buffer, bufferRev);
	free(bufferRev);
	*/
	return EXIT_SUCCESS;
}
