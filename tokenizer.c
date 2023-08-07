#include "monty.h"

/**
 * tokenizer - tokenizes the content of a string
 * by computing the start and ending index of every word or symbol
 * encountered in a string. After finding the start and end index of
 * a word encountered it moves the index [cursor] to the next glyph to
 * begin its next tokenization.
 * @string: string to be tokenized
 * @start: start index to be computed
 * @end: ending index to be computed
 * @index: cursor or index where tokenization begins.
 */
void tokenizer(char *string, int *start, int *end, size_t *index)
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
