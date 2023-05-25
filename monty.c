#include "monty.h"

global_t global = GLOBAL_INIT;

/**
 * main - Reads op_codes from a file and implements them
 *
 *@argv: String of arguments
 *@argc: Number of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.bytefile = fopen(argv[1], "r");
	if (global.bytefile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	reader();
	clean(1);
	return (EXIT_SUCCESS);
}
