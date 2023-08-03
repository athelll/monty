#include "monty.h"

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
			return;
		}
		new->prev = old;
		old->next = new;
		*stack = new;
	} else
	{
		push_error(task.line);
	}
}

void pall_stack(stack_t **stack, task task)
{
	stack_t *current = *stack;

	while(current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
