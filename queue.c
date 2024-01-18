#include "monty.h"

/**
 * f_queue - Changes the order to queue mode (FIFO).
 * @head: Pointer to the head of the stack
 * @counter: Line number in the Monty file
 * Return: No return
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - Add node to the tail of the queue.
 * @head: Pointer to the head of the stack
 * @p: New value to add to the queue
 * Return: No return
 */
void addqueue(stack_t **head, int p)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	new_node->p = p;
	new_node->next = NULL;

	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}

	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
