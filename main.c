#include "monty.h"

holder_t holder;

/**
 * main - entry point
 * @ac: number of arguments
 * @av: pointer to the arguments
 * Return: 0 on Success, EXIT_FAILURE otherwise
 */
int main(int ac, char **av)
{
	char line[1024];
	FILE *file;
	int line_num = 0;
	stack_t *stack1 = NULL;

	initializeHolder();
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	holder.top = &stack1;
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		++line_num;
		if (!isempty(line))
			execute(line, line_num);
	}
	fclose(file);
	freeHolder(holder);
	return (0);
}
/**
 * isempty - checks for empty lines
 * @line: string
 * Return: 1 if empty, 0 otherwise
 */
int isempty(char *line)
{
	int i = 0;

	if (!line)
		return (1);
	for (i = 0; line[i] == ' ' || line[i] == '\t'; i++)
		;
	if (line[i] == 10)
		return (1);
	return (0);
}
/**
 * initializeHolder - initializes the fields of holder struct
 * Return: Success
 */
void initializeHolder(void)
{
	holder.pushArg = 0;
	holder.opfuns[0].opcode = "push";
	holder.opfuns[0].f = push;
	holder.opfuns[1].opcode = "pall";
	holder.opfuns[1].f = pall;
	holder.opfuns[2].opcode = "pint";
	holder.opfuns[2].f = pint;
	holder.opfuns[3].opcode = "pop";
	holder.opfuns[3].f = pop;
	holder.opfuns[4].opcode = "swap";
	holder.opfuns[4].f = swap;
	holder.opfuns[5].opcode = "add";
	holder.opfuns[5].f = add;
	holder.opfuns[6].opcode = "nop";
	holder.opfuns[6].f = nop;
}
