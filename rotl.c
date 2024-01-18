#include "monty.h"

/**
 * f_rotl - does rotation of stack to top.
 * @head: memory allocation of head of stack
 * @counter: Line number in the Monty file (unused)
 * Return: Always 0
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
		return;

	aux = (*head)->next;
	aux->prev = NULL;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
