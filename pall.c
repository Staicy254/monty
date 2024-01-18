#include "monty.h"

/**
 * f_pall - Prints the stack.
 * @head: Pointer to the head of the stack
 * @counter: Unused parameter
 * Return: Always 0
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		printf("%d\n", h->p);
		h = h->next;
	}
}
