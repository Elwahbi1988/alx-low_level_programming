#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - read text file and prot STDOUT
 * @filename: Read being text file
 * @letters: Read number of letters
 * Return: w- number  of bytes read actually and printed 0
 * is fuction fails or filname is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd;
	ssize_t t;
	ssize_t w;
	char *buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);

	w = write(STDOUT_FILENO, buf, t);
	free(buf);
	close(fd);
	return (w);
}
