#include "monty.h"

int main (int argc, char **argv)
{
	char *file;
	FILE *file_pointer;

	if (argc == 1)
		usage_error();

	file = argv[1];
	if (file[strlen(file) - 1] != 'm' && file[strlen(file) - 2] != '.')
		notmonty_error();

	file_pointer = fopen(file, "r");
	if (!file_pointer)
		file_error(file);

	if (parser(file_pointer) == EXIT_FAILURE)
		exit(EXIT_FAILURE);

	fclose(file_pointer);

	return(EXIT_SUCCESS);
}
