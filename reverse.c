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
	int size;	
	if (errno == 0)
		size = read_file(*(argv + INPUT_FILE), &buffer);

	write_file (*(argv + OUTPUT_FILE), buffer, size);

	if (errno != 0)
	{
		fprintf(stderr, "\n\nError number is %d.\n", errno);
		perror("Error");
		return errno;
	}

	return EXIT_SUCCESS;
}

