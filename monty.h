#ifndef MONTY_H
#define MONTY_H

/** libraries **/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
  struct stack_s *next;
} stack_t;

typedef struct commands
{
	char *value;
	char *opcode;
	int line;
} task;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
  char *opcode;
  void (*f)(stack_t **stack, task task);
} instruction_t;

/** Global stack variable pointer **/

/** function declarations **/
stack_t *init_stack(void);
int parser (FILE *file);
int get_line(char **content, size_t *len, FILE *file);
bool is_alpha (char *string, int index);
bool is_number (char *string, int index);
bool is_space (char *string, int index);
void tokenizer (char *string, int *start, int *end, size_t *index);
char *get_task_details(char *line, int len, int start);
int execute(task task);
void liberate(int count, ...);
void push_stack(stack_t **stack, task task);
void pall_stack(stack_t **stack, task task);

extern stack_t* STACK;

/** error handlers **/
void malloc_error();
void usage_error();
void notmonty_error();
void file_error(char *file);
void syntax_error(int line, char *opcode);
void push_error(int line);

#endif
