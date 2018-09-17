#ifndef INC_GRD
#define INC_GRD

/**********************************************************************
 * Read file method. Takes a filename and a double pointer char.
 * Reads chars in from a file, and places them into the buffer.
 *
 * @param filename The name of the file.
 * @param buffer The double pointer to hold the input.
 * @return the size of the input.
 *********************************************************************/
int read_file( char* filename, char **buffer);

/**********************************************************************
 * Write file method. Takes the filename to write to, a char pointer, 
 * and the size of the input found in read_file. Writes the data in
 * the char pointer to the file.
 *
 * @param filename The name of the file to write to.
 * @param buffer The pointer that holds the data to write.
 * @param size The size of the input in buffer.
 *
 * @return errno Any errors while writing to the file.
 */
int write_file( char* filename, char *buffer, int size);

#endif
