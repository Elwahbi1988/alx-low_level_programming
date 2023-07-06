#include "main.h"

/**
*binary_to_uint - Converts a binary number to an unsigned int
*@b: String containing the binary number
*Return:Unsigned int.
*/

unsigned int binary_to_uint(const char *b)
{
int len, base_two;
unsigned int ui = 0;

if (!b)
return (0);

ui = 0;

for (len = 0; b[len] != '\0'; len++)
	;
for (len--, base_two = 1; len >= 0; len--, base_two *= 2)
{
if (b[len] != '0' && b[len] != '1')
{
return (0);
}
if (b[len] & 1)
{
ui += base_two;
}
}
return (ui);
}
