#include "monty.h"

void tokenizer (char *string, int index, int *start, int *end, bool (*func) (char *, int))
{
	for (; string[index] != '\0'; index++)
		if (func(string, index))
		{
			*start = index;
			break;
		}
	for (; string[index] != '\0'; index++)
		if (func(string, index + 1) == false)
		{
			*end = index;
			break;
		}
}
