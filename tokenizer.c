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
	char *opcode , *value;
	int opcode_len; int value_len;
	command current_command;

	while (getline(&line_content, &len, file) != EOF)
	{
		index = tokenizer(line_content, index, &opcode_start, &opcode_end, is_alpha);
		index = tokenizer(line_content, index, &value_start, &value_end, is_number);

		opcode_len = (opcode_end - opcode_start) + 1;
		value_len = (value_end - value_start) + 1;

		opcode = malloc(opcode_len + 1);
		value = malloc(value_len + 1);
		if (!opcode || !value)
			malloc_error();

		index = 0;
		while (index < opcode_len)
			opcode[index++] = line_content[opcode_start++];
		opcode[index] = '\0';

		index = 0;
		while (index < value_len)
			value[index++] = line_content[value_start++];
		value[index] = '\0';

		current_command.value = atoi(value);
		current_command.opcode = opcode;

		printf("[%d]: opcode: %s, value: %d\n",line_counter, current_command.opcode, current_command.value);

		/** reset indexes for next line **/
		opcode_start = opcode_end = value_end = value_start = -1;
		index = 0;
		line_counter++;
	}
	return (EXIT_SUCCESS);
}
