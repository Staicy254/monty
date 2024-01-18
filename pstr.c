#include "monty.h"

/**
 * f_pstr - Prints the string at the top of the stack, followed by a new line.
 * @head: Pointer to the head of the stack
 * @counter: Unused parameter
 * Return: Always 0
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->p > 127 || h->p <= 0)
			break;
	}
	printf("%c", h->p);
	h = h->next;
	printf("\n");
}
