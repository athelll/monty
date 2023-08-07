#include "monty.h"

void ensure_valid_value(char **value)
{
	int index = 0;
	char *work = *value;

	if (!work)
		return;

	if (work[index] == '-')
		++index;

	for (; work[index] != '\0'; index++)
		if (!is_number(*value, index))
			{ free(work); *value = NULL; break; }
}

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
	size_t line_counter = 1, index = 0, len;
	int opcode_start = -1, opcode_end = -1;
	int value_start = -1, value_end = -1;
	int opcode_len, value_len;
	task task;

	while (get_line(&line_content, &len, file) != EOF)
	{
		if (len == 0)
		{ line_counter++; free(line_content); continue; }

		tokenizer(line_content, &opcode_start, &opcode_end, &index);
		tokenizer(line_content, &value_start, &value_end, &index);

		if (opcode_start == -1 && value_start == -1)
		{ line_counter++; index = 0; free(line_content); continue; }

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
		task.line = line_counter;

		ensure_valid_value(&task.value);
		execute(task);
		free(line_content);

		index = 0;
		line_counter++;
		opcode_start = opcode_end = value_start = value_end = -1; /** reset **/
	}

	return (EXIT_SUCCESS);
}
