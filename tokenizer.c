#include "monty.h"
int tokenizer (char *string, int index, int *start, int *end, bool (*func) (char *, int))
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

	return (index);
}

int parser (FILE *file)
{
	size_t len;
	char *line_content;
	int line_counter = 1, index = 0;
	int opcode_start = -1, opcode_end = -1;
	int value_start = -1, value_end = -1;
	command current;

	while (getline(&line_content, &len, file) != EOF)
	{
		index = tokenizer(line_content, index, &opcode_start, &opcode_end, is_alpha);
		index = tokenizer(line_content, index, &value_start, &value_end, is_number);

		printf("\nopcode_start: %d, opcode_end: %d\n", opcode_start, opcode_end);
		printf("value_start: %d, value_end: %d\n", value_start, value_end);

		/** reset indexes for next line **/
		opcode_start = opcode_end = value_end = value_start =  index = 0;
		line_counter++;
	}

	putchar((char) 10);
	return (EXIT_SUCCESS);
}
