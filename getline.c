#include "monty.h"

int get_line(char **content, size_t *len, FILE *file)
{
	int glyph;
	int size = 0;
	char *string;
	int counter = 0;

	while ((glyph = fgetc(file)) != '\n')
	{
		if (glyph == EOF)
			return (EOF);
		size++;
	}

	fseek(file, -(size + 1), SEEK_CUR);
	string = (char *) malloc(size + 1);

	while ((glyph = fgetc(file)) != '\n')
	{
		if (glyph == EOF)
			return (EOF);
		string[counter++] = (char) glyph;
	}

	string[counter] = '\0';
	*content = string;

	*len = size == 0 ? 0 : size + 1;
	return (EXIT_SUCCESS);
}
