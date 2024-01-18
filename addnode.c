#include "monty.h"

/**
 * addnode - Add node to the head of the stack
 * @head: Pointer to the head of the stack
 * @p: New value to be added to the stack
 * Return: No return
 */
void addnode(stack_t **head, int p)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->p = p;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;
}
