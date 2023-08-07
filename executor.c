#include "monty.h"

/**
 * execute - executor: executes tasks sent to it.
 * @task: data-structure that holds necessar data for
 * task to be executes < task = { opcode, value, line.no. } >
 * Return: returns 0
 */
int execute(task task)
{
	int index = 0;
	bool opcode_found = false;
	instruction_t execs[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{NULL, NULL}
	};

	while (execs[index].opcode != NULL)
	{
		if (strcmp(execs[index].opcode, task.opcode) == 0)
		{
			execs[index].f(&STACK, task);
			opcode_found = true;
			break;
		}
		index++;
	}

	if (!opcode_found)
		opcode_error(task.line, task.opcode);

	return (0);
}
