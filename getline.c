#include "monty.h"

/**
 * get_line - custom implementation of gcc std >= c99
 * getline function.
 * @content: double pointer to string to be dynamically updated.
 * @len: length variable to be updated to the length of the new
 * allocated line string content.
 * @file: pointer to the file to be operated on.
 * Description:
 * With every call to this function its starts from the first line
 * and updates string with its content, and with another call
 * moves to the next line and updates the string again.
 * keeps doing this untill EOF is reached.
 * NOTE: doesnt handle deallocation of memory the line previously
 * pointed to when operating on the next line.
 * Return: returns EXIT_SUCCESS or EXIT_FAILURE.
 */
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
	if (!string)
		malloc_error();

	while ((glyph = fgetc(file)) != '\n')
	{
		if (glyph == EOF)
		{
			free(string);
			return (EOF);
		}
		string[counter++] = (char) glyph;
	}

	string[counter] = '\0';
	*content = string;
	*len = size == 0 ? 0 : size + 1;

	return (EXIT_SUCCESS);
}
