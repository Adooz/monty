#ifndef _MONTY_H_
#define _MONTY_H_
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

#include "lists.h"

/**
*global_s - our one global variable
*@stack: point to linked list
*@line: NULL pointer for getline
*@line_num: line counter
*@bytefile: name for file opened
*@commands: array of pointers for parsed lines
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct global_s
{
	stack_t *stack;
	char *line;
	int line_num;
	FILE *bytefile;
	char **commands;
} global_t;
extern global_t global;
#define GLOBAL_INIT {NULL, NULL, 0, NULL, NULL}
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* parse.c */
char **parser(char *buffer, char *delim);
int numcheck(char *s);

int counter(char *buffer, char *delim);

/* opcode_functions.c */
void op_pall(stack_t **head, unsigned int n);
void op_push(stack_t **head, unsigned int n);
void op_pint(stack_t **head, unsigned int n);
void op_pop(stack_t **head, unsigned int n);
void op_nop(stack_t **head, unsigned int n);

/* opcode_functions2.c */
void op_add(stack_t **head, unsigned int n);
void op_swap(stack_t **head, unsigned int n);
void op_sub(stack_t **head, unsigned int n);
void op_div(stack_t **head, unsigned int n);
void op_mul(stack_t **head, unsigned int n);
void op_mod(stack_t **head, unsigned int n);

/* opcode_functions3.c */
stack_t **op_rotl(stack_t **head);

/* bridge */
void bridge(char *command, int c);

/* get_opcode.c */
void (*get_opcode(char *s))(stack_t **stack, unsigned int n);

/* reader.c */
void reader(void);

/*cleaner.c*/
void clean(int everything);

#endif /*_MONTY_H_ */
