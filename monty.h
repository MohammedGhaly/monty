#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

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

/**
 * struct holder_s - carries golbal variables
 * @pushArg: argument to be pushed
 * @top: top element in the stack
 * @opfuns: array of the opfunctions
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct holder_s
{
		int pushArg;
	stack_t **top;
	instruction_t opfuns[7];
} holder_t;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

char *getCommand(const char *line);
void execute(char *command, int line_num);
int isInteger(char *str);
void free_stack(stack_t *stack);
void freeHolder(holder_t holder);
int isempty(char *line);
void initializeHolder();

extern holder_t holder;

#endif /*  MONTY_H */
