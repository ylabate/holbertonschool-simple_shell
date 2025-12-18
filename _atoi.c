#include "main.h"
/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: the integer value
 */

int _atoi(char *s)
{
	unsigned int o = 0;
	int i;
	int ii = 0;
	int negative = 1;
	int n;

	for (i = 0; ii == 0; i++)
	{
		if ((s[i] >= 48 && s[i] <= 57))
		{
			for (; s[i + ii] >= 48 && s[i + ii] <= 57; ii++)
			{
				o = (s[i + ii] - 48 + (o * 10));
			}
		}
		else if (s[i] == '\0')
			return (0);
	}
	for (n = 0; s[n] != 'n'; n++)
		if (s[n] == 45)
			negative = -negative;
	if (negative < 0)
		return (-o);
	return (o);
}
