#include "monty.h"
/**
*clean - function that cleans everything
*@everything: clean all
*
*Return: void
*/
void clean(int everything)
{
	if (global.line)
	{
		free(global.line);
		global.line = NULL;
		free(global.commands);
		global.commands = NULL;
	}
	if (everything)
	{
		dlistint_free(global.stack);
		global.stack = NULL;
		fclose(global.bytefile);
		global.bytefile = NULL;
	}
}
