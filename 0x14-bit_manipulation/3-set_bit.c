#include "main.h"
/**
 *set_bit - Sets bit give index 1
 *@n: Pointer number to change
 *@index: Index of the bit to set 1
 *Return:1 (success), -1 failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);
*n = ((1UL << index) | *n);
return (1);
}
