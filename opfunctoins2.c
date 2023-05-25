#include "monty.h"

/**
 * add - adds the first 2 elements of the stack
 * @stack: top element of the stack
 * @line_number: line number in the monty source file
 * Return: Success
 */
void add(stack_t **stack, unsigned int line_number)
{
	if ((*stack == NULL) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		freeHolder(holder);
		exit(EXIT_FAILURE);
	}

	((*stack)->next->n) = ((*stack)->n) + ((*stack)->next->n);
	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: top element of the stack
 * @line_number: line number in the monty source file
 * Return: Success
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
