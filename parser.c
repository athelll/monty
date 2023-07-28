#include "monty.h"
#include <stdio.h>

int file_parser (FILE *file)
{
	char *line_content;
	size_t len;
	int line_counter = 1;

	while (getline(&line_content, &len, file) != EOF)
	{
		printf("%d: %s", line_counter++, line_content);
	}

	return (EXIT_SUCCESS);
}
