#include "monty.h"

/**
 * f_pchar - Output char at top of stack,then a new line.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file
 * Return: Always 0
 */
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;

	if (!h)
	{
		fprintf(stderr, "L%d: Zero result, empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (h->p > 127 || h->p < 0)
	{
		fprintf(stderr, "L%d: Zero result, not in range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", h->p);
}
