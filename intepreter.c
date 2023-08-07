#include "monty.h"

/**
 * main - entry point for the interpreter
 *
 * @argc: number of arguments passed
 * @argv: array of argument strings.
 *
 * Description:
 * Monty bytecode intepreter block schematic:
 * entry => parser => tokenizer => assignment => execution.
 * Return: returns EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	char *file;
	FILE *file_pointer;
	stack_t *buffer;

	if (argc != 2)
		usage_error();

	file = argv[1];
	file_pointer = fopen(file, "r");
	if (!file_pointer)
		file_error(file);

	if (parser(file_pointer) == EXIT_FAILURE)
		exit(EXIT_FAILURE);

	fclose(file_pointer);
	while (STACK)
	{
		buffer = STACK;
		STACK = STACK->prev;
		free(buffer);
	}
	return (EXIT_SUCCESS);
}
