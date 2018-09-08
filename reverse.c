#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern int errno;

int main (int argc, char** argv) {
	if (argc != 3)
	{
		printf("Incorrect number of arguments.\n");
		return EXIT_FAILURE;
	}

	if (errno != 0)
	{
		printf("\n\nError number is %d.\n", errno);
		perror("Error");
		return errno;
	}

	return EXIT_SUCCESS;
}
