#include "monty.h"

int execute(task task)
{
	int index = 0;
	instruction_t execs [] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{NULL, NULL}
	};

	while (execs[index].opcode != NULL)
	{
		if (strcmp(execs[index].opcode, task.opcode) == 0)
		{
			execs[index].f(&STACK, task);
			break;
		}
		index++;
	}

	return (0);
}
