#include "monty.h"

/**
 * f_mod - Computes the rest of the division of the second
 *         top element of the stack by the top element of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file
 * Return: No return
 */
void f_mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	if (h->p == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	aux = h->next->p % h->p;
	h->next->p = aux;
	*head = h->next;
	free(h);
}
