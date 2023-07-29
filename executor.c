#include "monty.h"

int execute(command task, int number)
{
	printf("[%d]: opcode: %s, value: %s\n", number, task.opcode, task.value);
	return (0);
}
