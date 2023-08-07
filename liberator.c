#include "monty.h"
#include "stdarg.h"

/**
 * liberate - variadic func that frees dynamically allocated strings.
 * @count: number of args
 */
void liberate(int count, ...)
{
	int index = 0;
	char *current;
	va_list strings;

	va_start(strings, count);

	for (; index < count; index++)
	{
		current = va_arg(strings, char*);
		if (current != NULL)
			free(current);
	}
	va_end(strings);
}
