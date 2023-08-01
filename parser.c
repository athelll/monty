#include "monty.h"

int get_trash(char *line, int index)
{
	for(; line[index] != '\0'; index++)
		if (is_number(line, index) == false && is_space(line, index) == false)
			return (index);
	return (-1); /** no middle trash found **/
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
	size_t line_counter = 1, index = 0;
	int opcode_start = -1, opcode_end = -1;
	int value_start = -1, value_end = -1;
	int opcode_len, value_len;
	size_t len; int trash_index;
	command task;

	while (getline(&line_content, &len, file) != EOF)
	{
		if (len == 0)
		{ line_counter++; continue; }

		tokenizer(line_content, &opcode_start, &opcode_end, &index, is_alpha);
		trash_index = index;
		tokenizer(line_content, &value_start, &value_end, &index, is_number);

		trash_index = get_trash(line_content, trash_index);
		if (trash_index != -1 && trash_index < value_start)
		{ value_start = -1; value_end = -1; }

		if (opcode_start == -1 && value_start == -1)
		{ line_counter++; index = 0; continue; }

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
		index = 0;
		line_counter++;
		opcode_start = opcode_end = value_start = value_end = -1; /** reset **/
	}

	return (EXIT_SUCCESS);
}
