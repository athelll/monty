#include "monty.h"

char *get_task_details(char *line, int len, int start)
{
	char *detail;
	int index = 0;

	detail = malloc(len + 1);
	if (!detail) { malloc_error(); }

	while (index < len)
		detail[index++] = line[start++];
	detail[index] = '\0';

	return (detail);
}

int parser (FILE *file)
{
	char *line_content;
	size_t line_counter = 1, len;
	int opcode_start = -1, opcode_end = -1;
	int value_start = -1, value_end = -1;
	int opcode_len; int value_len;
	command task;

	while (getline(&line_content, &len, file) != EOF)
	{
		if (len == 0)
		{
			line_counter++;
			continue;
		}

		tokenizer(line_content, &opcode_start, &opcode_end, is_alpha);
		tokenizer(line_content, &value_start, &value_end, is_number);

		if (opcode_start == -1 && value_start == -1)
			continue;

		opcode_len = opcode_start != -1 ? (opcode_end - opcode_start) + 1 : 0;
		value_len = value_start != -1 ? (value_end - value_start) + 1 : 0;

		if (opcode_len != 0)
			task.opcode = get_task_details(line_content, opcode_len, opcode_start);
		else
			task.opcode = NULL;

		if (value_len != 0)
			task.value = get_task_details(line_content, value_len, value_start);
		else
			task.value = NULL;

		execute(task, line_counter);

		line_counter++;
		opcode_start = opcode_end = value_start = value_end = -1; /** reset **/
	}

	return (EXIT_SUCCESS);
}
