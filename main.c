#include "monty.h"

holder_t holder  = {
		.pushArg = 0,
		.opfuns = {
				{"push", push},
				{"pall", pall},
				{"pint", pint},
				{"pop", pop},
				{"swap", swap}
		}
};
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
		execute(line, line_num);
	}
	fclose(file);
	freeHolder(holder);
	return (0);
}
