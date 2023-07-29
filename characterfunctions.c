#include "monty.h"

bool is_alpha (char *string, int index)
{
	if (((int) string[index] >= 65 && (int) string[index] <= 90) ||
			((int) string[index] >= 97 && (int) string[index] <= 122))
		return (true);
	else
		return (false);
}

bool is_number (char *string, int index)
{
	if ((int) string[index] >= 48 && (int) string[index] <= 57)
		return (true);
	else
		return (false);
}

bool is_space (char *string, int index)
{
	if ((int) string[index] == 32)
		return (true);
	else
		return (false);
}
