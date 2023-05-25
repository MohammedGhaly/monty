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

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeHolder(holder);
		exit(EXIT_FAILURE);
	}
	new->n = holder.pushArg;
	new->next = *(stack);
	new->prev = NULL;

	if ((*(stack)) != NULL)
		(*(stack))->prev = new;
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

	(void)line_number;
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
 * pint - prints the element at the top of the stack
 * @stack: top element of the stack
 * @line_number: line number in the monty source file
 * Return: Success
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*(stack) != NULL)
		printf("%d\n", (*(stack))->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		freeHolder(holder);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - adds an element to the top of the stack
 * @stack: top element of the stack
 * @line_number: line number in the monty source file
 * Return: Success
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	stack_t *nxt;

	if ((*stack == NULL) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeHolder(holder);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	nxt = current->next;

	current->next = nxt->next;
	nxt->next->prev = current;
	nxt->prev = NULL;
	nxt->next = current;

	*stack = nxt;
}

/**
 * pop - adds an element to the top of the stack
 * @stack: top element of the stack
 * @line_number: line number in the monty source file
 * Return: Success
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		freeHolder(holder);
		exit(EXIT_FAILURE);
	}
	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
}
