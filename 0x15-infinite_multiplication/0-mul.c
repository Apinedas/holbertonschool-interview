#include "holberton.h"

/**
 * _isdigit - entry to isdigit
 * Desc: _isdigit function to now if in the string
 * there are characters
 * @s: pointer to string
 * Return: 1 if only digits 0 if there's a character
 */
int _isdigit(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) < '0' || *(s + i) > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - entry to strlen
 * Desc: _strlen function to know the length of a string
 * @s: pointer to string
 * Return: string length with count
 */
int _strlen(char *s)
{
	int count = 0;

	while (*s)
	{
		s++;
		count++;
	}
	return (count);
}

/**
 * infinite_multiply - entry to infinite multiply
 * Desc: infinite_multiply function to multiply int strings
 * @s1: 1st string to multiply
 * @s2: 2nd string to multiply
 * Return: result
 */

char *infinite_multiply(char *s1, char *s2)
{
	char *result;
	int x, y, z, total_length, len_s1, len_s2;

	len_s1 = _strlen(s1), len_s2 = _strlen(s2);
	total_length = len_s1 + len_s2;

	result = malloc(total_length);
	if (result == 0)
		printf("Error\n"), exit(98);

	for (len_s1--; len_s1 >= 0; len_s1--)
	{
		x = s1[len_s1] - '0';
		z = 0;
		for (len_s2 = _strlen(s2) - 1; len_s2 >= 0; len_s2--)
		{
			y = s2[len_s2] - '0';
			z += result[len_s1 + len_s2 + 1] + (x * y);
			result[len_s1 + len_s2 + 1] = z % 10;
			z /= 10;
		}
		if (z)
			result[len_s1 + len_s2 + 1] += z;
	}
	return (result);
}

/**
 * main - entry to main
 * Desc: main function that passes base
 * base 10 numbers to be multiplied
 * @argc: number of arguments
 * @argv: arguments
 * Return: multiplied numbers
 */
int main(int argc, char *argv[])
{
	int i, x = 0, length = 0;
	char *result;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
		puts("Error"), exit(98);

	length = _strlen(argv[1]) + _strlen(argv[2]);
	result = infinite_multiply(argv[1], argv[2]);

	for (i = 0; i < length; i++)
	{
		if (result[i])
			x = 1;
		if (x)
			_putchar(result[i] + '0');
	}
	if (x == 0)
		_putchar('0');
	puts("");
	free(result);
	return (0);
}
