#include "monty.h"

/**
 * reset - resets parsers parameter for next line parsing
 * @line_number: pointer to line_number variable in parser to reset
 * @line_string: pointer to line_string variable in parser to free
 * @index: pointer to index variable in parser to reset
 */
void reset(size_t *line_number, char *line_string, size_t *index)
{
	++(*line_number);
	if (line_string)
		free(line_string);
	*index = 0;
}

/**
 * ensure_valid_value - ensures that value string in parser
 * can be accurately atoi'd to a negative or positive integer
 * @value: double pointer to value string.
 * Note: if valid does nothing else: assigns NULL to string
 */
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
		{
			free(work);
			*value = NULL;
			break;
		}
}

/**
 * get_task_details - uses start index and len. to get details for task.
 * @line: string [line_content in parser] to get details from
 * @len: length of needed detail
 * @start: starting index.
 * Return: returns pointer to new allocated string [detail].
 */
char *get_task_details(char *line, int len, int start)
{
	char *detail;
	int index = 0;

	detail = malloc(len + 1);
	if (!detail)
		malloc_error();

	while (index < len)
		detail[index++] = line[start++];
	detail[index] = '\0';

	return (detail);
}

/**
 * parser - parses file and calls executor for execution of tasks
 * generated line by line.
 * @file: pointer to file to be parsed
 * NOTE: uses the tokenizer to generate task details and use the
 * generated data to assign tasks line by line.
 * Also handles invalid details generated [assigns them to NULL].
 * Return: returns EXIT_SUCCESS or EXIT_FAILURE.
 */
int parser(FILE *file)
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
		{
			reset(&line_counter, line_content, &index);
			continue;
		}

		tokenizer(line_content, &opcode_start, &opcode_end, &index);
		tokenizer(line_content, &value_start, &value_end, &index);
		if (opcode_start == -1 && value_start == -1)
		{
			reset(&line_counter, line_content, &index);
			continue;
		}

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
		reset(&line_counter, line_content, &index);
		opcode_start = opcode_end = value_start = value_end = -1; /** reset **/
	}
	return (EXIT_SUCCESS);
}
