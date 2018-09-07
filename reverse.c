#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//Input file is arg 1, output file is arg 2.
#define INPUT_FILE 1;
#define OUTPUT_FILE 2;

extern int errno;

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);

int main (int argc, char** argv) {

	char* buffer;

	/* If the number of arguments is not 3, then return failure. */
	if (argc != 3)
	{
		printf("Incorrect number of arguments. Should be 3.\n");
		printf("syntax: ./reverse [inputfile] [outputfile]\n");
		return EXIT_FAILURE;
	}
	
	read_file(*(argv+1), &buffer);



	if (errno != 0)
	{
		printf("\n\nError number is %d.\n", errno);
		perror("Error");
		return errno;
	}

	return EXIT_SUCCESS;
}

int read_file (char* filename, char **buffer) {
	FILE *fin = fopen(filename, "r");
	char temp;

	while (fscanf(fin, "%c", &temp) != EOF)
	{
		(*buffer)+=temp;
	}
	return errno;
}

int write_file( char* filename, char *buffer, int size) {
	return errno;
}

