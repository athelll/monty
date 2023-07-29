#include "monty.h"

int file_parser (FILE *file)
{
	size_t len;
	char *line_content;
	int line_counter = 1, index = 0;
	int opcode_start = -1, opcode_end = -1;
	int value_start = -1, value_end = -1;
	command current;

	while (getline(&line_content, &len, file) != EOF)
	{
		for (; line_content[index] != '\0'; index++)
			if (is_alpha(line_content, index))
			{
				opcode_start = index;
				break;
			}

		for (; line_content[index] != '\0'; index++)
			if (is_alpha(line_content, index + 1) == false)
			{
				opcode_end = index;
				break;
			}

		for (; line_content[index] != '\0'; index++)
			if (is_number(line_content, index))
			{
				value_start = index;
				break;
			}

		for (; line_content[index] != '\0'; index++)
			if (is_number(line_content, index + 1) == false)
			{
				value_end = index;
				break;
			}

		printf("\nopcode_start: %d, opcode_end: %d\n", opcode_start, opcode_end);
		printf("value_start: %d, value_end: %d\n", value_start, value_end);

		/** reset indexes for next line **/
		opcode_start = opcode_end = value_end = value_start =  index = 0;
	}

	putchar((char) 10);
	return (EXIT_SUCCESS);
}
