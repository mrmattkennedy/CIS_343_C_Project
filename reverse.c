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

	// If the number of arguments is not 3, then return failure.
	if (argc != 3)
	{
		printf("Incorrect number of arguments. Should be 3.\n");
		printf("syntax: ./reverse [inputfile] [outputfile]\n");
		return EXIT_FAILURE;
	}
	
	// Get the size by calling the read_file function.
	int size = read_file(*(argv + INPUT_FILE), &buffer);

	/* I have no idea what the best way to check errno throughout a program is
	 * without continuously checking it at every step, so that is exactly what
	 * I did. */
	if (errno != 0)
	{
		fprintf(stderr, "\n\nError present. errno is %d\n", errno);
		perror("Error");
		fprintf(stderr, "\n\n");
		return errno;
	}

	//Create and allocate memory for a char pointer that'll reverse buffer
	char* bufferRev = (char*)malloc(size * sizeof(char));
	for (int i = 0; i < size; i++)
		bufferRev[size - 1 - i] = buffer[i];

	//Call the write_file method.
	write_file (*(argv + OUTPUT_FILE), bufferRev, size);

	//Again... no idea what the best way is here.
	if (errno != 0)
	{
		fprintf(stderr, "\n\nError present. errno is %d\n", errno);
		perror("Error");
		fprintf(stderr, "\n\n");
		return errno;
	}

	//Free memory
	free(bufferRev);
	free(buffer);
	return EXIT_SUCCESS;
}
