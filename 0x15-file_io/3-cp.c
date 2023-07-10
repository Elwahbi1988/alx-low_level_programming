#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void close_file(int fd);
char *creat_buffer(char *file);
/**
 *creat_buffer -buffer to allocate 1024 bytes
 *@file: storing chars in to the file name of buffer
 *Return: Pointer new allocate buffer
 */

char *creat_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s/n", file);
		exit(99);
	}
	return (buffer);
}
/**
 * close_file - descriptors of closes file
 * @fd: descriptor file to close
 */

void close_file(int fd)
{
	int cl;

	cl = close(fd);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d/n", fd);
		exit(100);
	}
}

/**
 *main - the contents file copies to another file
 *@argc: Argument spullied to program
 *@argv: Array of pointer in arguments
 *Return: 0 on success
 *Description:  exit code 97 if count is incorrect
 *exit code 98 if file_form doesn't exist or not read
 *exit code 99 if file_to not created or written
 *exit code 100 if file_to not closed
 */
int main(int argc, char *argv[])
{
	int from;
	int to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = creat_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);

			free(buffer);
			exit(98);
		}
		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);
	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}






