#include "monty.h"

void tokenizer (char *string, int *start, int *end, size_t *index)
{
	for (; string[*index] != '\0'; (*index)++)
	{
		if (!is_space(string, *index))
		{
			*start = *index;
			break;
		}
	}
	for (; string[*index] != '\0'; (*index)++)
	{
		if (is_space(string, *index + 1) || string[*index + 1] == '\0')
		{
			*end = *index;
			++(*index);
			break;
		}
	}
}
