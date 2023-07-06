#include "main.h"
/**
 * binary_to_uint - Convert a binary number to unsigned int
 * @b: Binary number
 * Return: Converted number
 */
unsigned int binary_to_uint(const char *b)
{
int i;
unsigned int ui = 0;

if (!b)
return (0);
for (i = 0; b[i]; i++)
{
if (b[i] < '0' || b[i] > '1')
return (0);
ui = 2 * ui + (b[i] - '0');
}
return (ui);
}
