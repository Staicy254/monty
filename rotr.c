#include "monty.h"

/**
 * f_rotr - does rotation of stack to bottom.
 * @head: memory allocation of head of the stack
 * @counter: Line number in the Monty file (unused)
 * Return: Always 0
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	if (*head == NULL || (*head)->next == NULL)
		return;

	copy = *head;

	while (copy->next)
		copy = copy->next;

	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
