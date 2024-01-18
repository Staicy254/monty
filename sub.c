#include "monty.h"

/**
 * f_sub - Subtracts the top two elements of the stack.
 * @head: Memory allocation head of the stack
 * @counter: Line number in the Monty file
 * Return: Always 0
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int result, nodes;

	aux = *head;

	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: No result, small stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	aux = *head;
	result = aux->next->p - aux->p;
	aux->next->p = result;
	*head = aux->next;
	free(aux);
}
