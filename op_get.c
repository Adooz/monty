#include "monty.h"
/**
 * get_opcode - Compares opcodes and calls correct
 * opcode function from opcode_funcs
 *
 * @s: the opcode
 * Return: 0
 */
void (*get_opcode(char *s))(stack_t **stack, unsigned int n)
{
	instruction_t opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"nop", op_nop},
		{"add", op_add},
		{"swap", op_swap},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{NULL, NULL}
	};
	int ab = 0;

	while (opcodes[ab].opcode)
	{
		if (strcmp(opcodes[ab].opcode, s) == 0)
		{
			return (opcodes[ab].f);
		}
		ab++;
	}
/* Printing the stderr, required message, line_num, opcode */
	fprintf(stderr, "L%i: unknown instruction %s\n",
		global.line_num, s);
	clean(1);
	exit(EXIT_FAILURE);

	return (NULL);
}
