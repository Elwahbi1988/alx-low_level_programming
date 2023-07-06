#include "main.h"
/**
 * binary_to_uint - Convert a binary number to unsigned int
 * @b: Binary number
 * Return: Converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int ui = 0;
if (!b)
	return (0);
for (j = 0; b[j]; j++)
	{
	if (b[j] < '0' || b[j] > '1')
	return (0);
	ui = 2 * ui + (b[j] - '0');
	}
	return (ui);
}
