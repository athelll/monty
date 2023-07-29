#ifndef MONTY_H
#define MONTY_H

/** libraries **/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/** CONSTANTS **/
#define MAX_STACK 100

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
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct commands
{
	int *value;
	char *opcode;
} command;

/** Global stack variable pointer **/
extern stack_t *stack;

/** function declarations **/
stack_t *init_stack(void);
int file_parser (FILE *file);
int getline(char **content, size_t *len, FILE *file);
bool is_alpha (char *string, int index);
bool is_number (char *string, int index);
bool is_space (char *string, int index);

#endif
