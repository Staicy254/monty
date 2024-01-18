#include "monty.h"

/**
 * free_stack - Frees a shared list
 * @head: Pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *current, *next_node;

	current = head;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
