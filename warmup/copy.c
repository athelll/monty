#include <stdlib.h>
#include <stdio.h>

int my_copy(char *filename, char *copyname)
{
	FILE *file, *copy;
	char *content;
	int content_size;
	size_t read = 0;

	file = fopen(filename, "r");
	copy = fopen(copyname, "a");

	if (!file || !copy)
		return (FAILURE);

	while ((read = getline(&content, &read, file)) != -1)
		fputs(content, copy);
	fputs("\nmade by felix with love\n", copy);

	fclose(file);
	fclose(copy);
	free(content);

	return (SUCCESS);
}

void main(int argc, char **argv)
{
	if (argc == 1)
		return;
	if (argc != 3)
	{
		printf("Error. Usage: copy <file_destination>, <copy_destination>\n");
		return;
	}
	if (my_copy(argv[1], argv[2]) != SUCCESS)
	{
		printf("Operation not succesful\n");
		return;
	}
}
