#include "monty.h"

/**
 * is_alpha - checks if a character is an alphabet
 * @string: pointer to string
 * @index: index of character in string
 * Return: true or false
 */
bool is_alpha(char *string, int index)
{
	if (((int) string[index] >= 65 && (int) string[index] <= 90) ||
			((int) string[index] >= 97 && (int) string[index] <= 122))
		return (true);
	else
		return (false);
}

/**
 * is_number - checks if a character is a number
 * @string: pointer to string
 * @index: index of character in string
 * Return: true or false
 */
bool is_number(char *string, int index)
{
	if ((int) string[index] >= 48 && (int) string[index] <= 57)
		return (true);
	else
		return (false);
}

/**
 * is_space - checks if a character is a white-space character
 * @string: pointer to string
 * @index: index of character in string
 * Return: true or false
 */
bool is_space(char *string, int index)
{
	if ((int) string[index] == 32)
		return (true);
	else
		return (false);
}
