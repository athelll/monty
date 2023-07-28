#include "monty.h"

int main (int argc, char **argv)
{
	char *file;
	FILE *file_pointer;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = argv[1];
	if (file[strlen(file) - 1] != 'm' && file[strlen(file) - 2] != '.')
	{
		fprintf(stderr, "This is not a monty file, missing .m extension\n");
		exit(EXIT_FAILURE);
	}
	file_pointer = fopen(file, "r");
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
	if (file_parser(file_pointer) == EXIT_FAILURE)
		exit(EXIT_FAILURE);

	fclose(file_pointer);
	return(EXIT_SUCCESS);
}
