#include "monty.h"

int execute(command cmd, int number) 
{
	printf("[%d]: opcode: %s, value: %s\n",number, cmd.opcode, cmd.value);
	return (0);
}
