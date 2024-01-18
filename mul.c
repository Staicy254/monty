#include "monty.h"

/**
 * f_mul - Does multiplication of the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file
 * Return: No return
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: Cannot multiply, stack too small\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	aux = h->next->p * h->p;
	h->next->p = aux;
	*head = h->next;
	free(h);
}
