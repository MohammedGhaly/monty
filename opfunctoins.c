#include "monty.h"

/**
 * push - adds an element to the top of the stack
 * @stack: top element of the stack
 * @line_number: line number in the monty source file
 * Return: Success
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = holder.pushArg;
	new->next = *(holder.top);
	new->prev = NULL;

	if ((*(holder.top)) != NULL)
		(*(holder.top))->prev = new;
	*(holder.top) = new;
}

/**
 * pall - prints the stack
 * @stack: top element of the stack
 * @line_number: line number in the monty source file
 * Return: Success
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!stack)
		return;
	current = *(holder.top);
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - adds an element to the top of the stack
 * @stack: top element of the stack
 * @line_number: line number in the monty source file
 * Return: Success
 */
void pint(stack_t **stack, unsigned int line_number)
{
		printf("I am pint\n");
}

/**
 * swap - adds an element to the top of the stack
 * @stack: top element of the stack
 * @line_number: line number in the monty source file
 * Return: Success
 */
void swap(stack_t **stack, unsigned int line_number)
{
		printf("I am swap\n");
}

/**
 * pop - adds an element to the top of the stack
 * @stack: top element of the stack
 * @line_number: line number in the monty source file
 * Return: Success
 */
void pop(stack_t **stack, unsigned int line_number)
{
		printf("I am pop\n");
}
