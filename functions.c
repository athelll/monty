#include "monty.h"

/**
 * push_stack - pushes new node, ontop of STACK.
 * @stack: double pointer to top node of STACK
 * @task: holds the info necessary to execute this exec.
 */
void push_stack(stack_t **stack, task task)
{
	stack_t *new;
	stack_t *old = *stack;

	new = malloc(sizeof(stack_t));
	if (!new)
		malloc_error();

	if (task.value)
	{
		new->n = atoi(task.value);
		new->next = NULL;
		if (!old)
		{
			new->prev = NULL;
			*stack = new;
			liberate(2, task.value, task.opcode);
			return;
		}
		new->prev = old;
		old->next = new;
		*stack = new;
		liberate(2, task.value, task.opcode);
	} else
	{
		liberate(1, task.opcode);
		push_error(task.line);
	}
}

/**
 * pall_stack - prints all nodes in the STACK.
 * @stack: double pointer to top node of STACK
 * @task: holds the info necessary to execute this exec.
 */
void pall_stack(stack_t **stack, task task)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
	liberate(2, task.value, task.opcode);
}
