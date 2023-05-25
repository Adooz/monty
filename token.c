#include "monty.h"
/**
*parser- function used to parse input into desired strings
*
*@buffer: input to be parsed
*@delim: delimiter used to determine the stopping point
*
*Return: pointer to an arrary of strings created
*/
char **parser(char *buffer, char *delim)
{
	char *tkn;
	char **newStr;
	int ab = 0;

	tkn = strtok(buffer, delim);
	newStr = malloc(sizeof(char *) * 3);
	if (newStr == NULL)
	{
/* Clean(1) means clean all variables calling malloc and closes file pointer */
		clean(1);
		exit(EXIT_FAILURE);
	}
/* Ensuring newStrings at 1 is initialized to be NULL */
	newStr[1] = NULL;
	newStr[2] = NULL;
	while (tkn && ab < 2)
	{
		newStr[ab] = tkn;
		tkn = strtok(NULL, delim);
		ab++;
	}
	newStr[ab] = NULL;
	return (newStr);
}
/**
*numcheck - function checks for valid num
*
*@s: string
*
*Return: True or false
*/
int numcheck(char *s)
{
	int ab = 0;

	if (s[ab] == '-' || s[ab] == '+')
		ab++;

	while (s[ab])
	{
		if (!isdigit(s[ab]))
			return (0);
		ab++;
	}
	return (1);
}
