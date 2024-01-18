#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file
 * Return: No return
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, result;

	h = *head;

	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: Cannot add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	result = h->p + h->next->p;
	h->next->p = result;
	*head = h->next;
	free(h);
}
