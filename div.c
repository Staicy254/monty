#include "monty.h"

/**
 * f_div - Performs division of the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file where f_div was called
 * Return: No return
 */
void f_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: cannot div, stack too short\n", counter);
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

	aux = h->next->p / h->p;
	h->next->p = aux;
	*head = h->next;
	free(h);
}
