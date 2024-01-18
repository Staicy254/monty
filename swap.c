#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: memory allocation of head of the stack
 * @counter: Line number in the Monty file
 * Return: Always 0
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;

	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: No result, small stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	temp = h->p;
	h->p = h->next->p;
	h->next->p = temp;
}
