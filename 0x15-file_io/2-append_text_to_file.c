#include "main.h"
/**
 * append_text_to_file - the end of file appends text
 * @filename: Pointer the file name
 * @text_content: add string in the end of file
 * Return: -- 1 function fails or filename NULL
 * -- 1 file not exist user lacks write permission
 * - 1 otherwise
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o;
	int w, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);
	close(o);

	return (1);

}
