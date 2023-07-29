#include "monty.h"

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
		if (len == 0)
		{
			line_counter++;
			continue;
		}

		tokenizer(line_content, index, &opcode_start, &opcode_end, is_alpha);
		tokenizer(line_content, index, &value_start, &value_end, is_number);

		if (opcode_start == -1 && value_start == -1)
			continue;

		opcode_len = opcode_start != -1 ? (opcode_end - opcode_start) + 1 : 0;
		value_len = value_start != -1 ? (value_end - value_start) + 1 : 0;

		if (opcode_len != 0)
		{
			opcode = malloc(opcode_len + 1);
			if (!opcode) { malloc_error(); }

			index = 0;
			while (index < opcode_len)
				opcode[index++] = line_content[opcode_start++];
			opcode[index] = '\0';
			current_command.opcode = opcode;
		}
		else
			current_command.opcode = NULL;

		if (value_len != 0)
		{
			value = malloc(value_len + 1);
			if (!value) { malloc_error(); }

			index = 0;
			while (index < value_len)
				value[index++] = line_content[value_start++];
			value[index] = '\0';
			current_command.value = value;
		}
		else
			current_command.value = NULL;

		/** execute(current_command, line_number); **/
		printf("[%d]: opcode: %s, value: %s\n",line_counter, current_command.opcode, current_command.value);

		/** reset **/
		opcode_start = opcode_end = value_start = value_end = -1;
		index = 0;
		line_counter++;
	}
	return (EXIT_SUCCESS);
}
