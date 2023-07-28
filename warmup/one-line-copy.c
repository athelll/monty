#include <stdlib.h>
#include <stdio.h>

/**
 * To use on linux run the commands
 * -----------------------------------
 * gcc one-line-copy -o one-copy
 * mkdir /home/$USER/bin
 * mv one-copy /home/&USER/bin/
 * export PATH="$PATH:/home/$USER/bin"
 * -----------------------------------
 * Usage: one-line-copy <file> <copy>
 * This was a play very-mini project to warmup on c I/O
 * Use at Owners Risk. [like h*ll anyones gonna use this.]
 * Ineffecient and made it overly complicated just to flex on c.
 * there are shorter ways to implement this as ive pointed out in my
 * copy.c file.
 *
 */

#define SUCCESS 0
#define FAILURE -1

int add_felix(char **text, int prev_size)
{
	char *result, *delete_prev, *prev = *text;
	int size_no_null = 25, index = 0;
	char *felix = "\nmade by felix with love\n";

	delete_prev = *text;
	result = malloc(prev_size + size_no_null + 1);
	if (!result)
		return (FAILURE);
	result[prev_size + size_no_null] = '\0';

	while (*prev != '\0')
	{
		result[index++] = *prev;
		prev++;
	}
	while (*felix != '\0')
	{
		result[index++] = *felix;
		felix++;
	}

	*text = result;
	free(delete_prev);
	return (SUCCESS);
}

int my_copy(char *filename, char *copyname)
{
	FILE *file, *copy;
	char *content;
	int content_size;

	file = fopen(filename, "r");
	copy = fopen(copyname, "a");

	if (!file || !copy)
		return (FAILURE);

	fseek(file, 0L, SEEK_END);
	content_size = ftell(file);
	fseek(file, 0L, SEEK_SET);
	content = malloc(content_size + 1);

	fgets(content, content_size + 1, file);
	if (add_felix(&content, content_size) != SUCCESS)
		return (FAILURE);
	fputs(content, copy);

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
