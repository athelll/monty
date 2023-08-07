#include "monty.h"

/**
 * malloc_error - exits program when malloc fails
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * usage_error - exits program when intepreter args not enough
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - exits program when opening a file fails
 * @file: name of file.
 */
void file_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * opcode_error - exits program when opcode unrecongnized
 * @line: line where opcode was noticed
 * @opcode: name of unrecognized opcode
 */
void opcode_error(int line, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}

/**
 * push_error - exits program when push exec fails
 * @line: line where push exec failed
 */
void push_error(int line)
{
	fprintf(stderr, "L%d: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
