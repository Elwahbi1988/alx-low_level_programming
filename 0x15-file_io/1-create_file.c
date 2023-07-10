#include "main.h"

/**
 * create_file - File to created
 * @filename: Pointer the file to create
 * @text_content: Pointer the string write to file
 * Return:--1 the function fails,- 1 otherwise
 */
int create_file(const char *filename, char *text_content)
{
	int w;
	int fd, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);
	close(fd);

	return (1);
}

