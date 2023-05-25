#include "monty.h"
/**
 * execute - executes the op command
 * @line: command string
 * @line_num: line number in the monty code file
 * Return: Success
 */
void execute(char *line, int line_num)
{
	char *cmd = getCommand(line);
	int i;

	if (strncmp(cmd, "push", 4) == 0)
	{
		if (strlen(cmd) < 7 && cmd[5] == 10)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		if (isInteger(cmd + 5))
			holder.pushArg = atoi(cmd + 5);
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	for (i = 0; i < 7; i++)
	{
		if (strncmp(cmd, holder.opfuns[i].opcode, 2) == 0)
		{
			holder.opfuns[i].f(holder.top, line_num);
			break;
		}
	}
	if (i == 7)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, cmd);
		exit(EXIT_FAILURE);
	}
}
/**
 * getCommand - extracts the command from the line passed
 * @line: string containing the command
 * Return: string of the clean command
 */
char *getCommand(const char *line)
{
	static char command[200];
	int j = 0, i = 0;

	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (NULL);
	while (line[i] != '\0' && line[i] != ' ')
	{
		command[j] = line[i];
		i++;
		j++;
	}
	command[j] = '\0';
	if (strcmp(command, "push"))
		return (command);

	if (line[i] == ' ')
	{
		i++;
		command[j] = ' ';
		j++;
		while (line[i] != '\0' && line[i] == ' ')
			i++;
		while (line[i] != '\0' && line[i] != ' ')
		{
			command[j] = line[i];
			i++;
			j++;
		}
		command[j] = '\0';
	}
	return (command);
}

/**
 * isInteger - checks if a string contains an integer
 * @str: string
 * Return: 1 if integer, 0 otherwise
 */
int isInteger(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != 10)
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * freeHolder - frees the holder element
 * @holder: holder of global variables
 * Return: Success
 */
void freeHolder(holder_t holder)
{
	free_stack(*(holder.top));
}
/**
 * free_stack - frees the allocated memory by the stack
 * @head: top element of the atack
 * Return: Success
 */
void free_stack(stack_t *head)
{
	stack_t *nxt;
	stack_t *current;

	current = head;
	if (current == NULL)
		return;
	if (current->next == NULL)
	{
		free(current);
		return;
	}
	nxt = current->next;
	while (nxt != NULL)
	{
		free(current);
		current = nxt;
		nxt = nxt->next;
	}
	free(current);
}
