#include "monty.h"

void malloc_error()
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

void usage_error()
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

void notmonty_error()
{
	fprintf(stderr, "This is not a monty file, missing .m extension\n");
	exit(EXIT_FAILURE);
}

void file_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
