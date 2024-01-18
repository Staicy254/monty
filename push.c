#include "monty.h"

/**
 * f_push - Add node to stack or queue.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file
 * Return: Always 0
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, q = 0, flag = 0;

	if (!bus.arg)
	{
		fprintf(stderr, "L%d: Usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (bus.arg[0] == '-')
		q++;

	for (; bus.arg[q] != '\0'; q++)
	{
		if (bus.arg[q] < '0' || bus.arg[q] > '9')
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		fprintf(stderr, "L%d: Usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
