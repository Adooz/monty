#include "monty.h"
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
/**
*reader- function to read input from main
*
*Return: 0
*/
void reader(void)
{
	ssize_t readbytes;
	size_t x = 0;
	void (*action)(stack_t **, unsigned int);

	while (1)
	{
		readbytes = getline(&global.line, &x, global.bytefile);
		if (readbytes == -1)
		{
			break;
		}
/* This ensures that getline will count even blank, tabbed, etc. lines */
		global.line_num++;

		global.commands = parser(global.line, " \t\n");
		if (global.commands[0])
		{
			action = get_opcode(global.commands[0]);
			action(&global.stack, global.line_num);
		}
		clean(0);
	}
}
