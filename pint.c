#include "monty.h"

/**
 * f_pint - Prints the value at the top of the stack, followed by a new line.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file
 * Return: Always 0
 */
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: Zero result, empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->p);
}
