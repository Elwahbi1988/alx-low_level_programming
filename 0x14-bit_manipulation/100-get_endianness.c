#include "main.h"
/**
 *get_endianness - Checks the endianness big
 *Return: 0 is big, 1 is little
 */
int get_endianness(void)
{
unsigned int i = 1;
char *c = (char *) &i;

return (*c);
}
