#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include "execute.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: number
 */
bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	bus_t bus = {NULL, NULL, NULL, 0};
	size_t size = 0;
	char *content;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	bus.file = fopen(argv[1], "r");

	if (!bus.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, bus.file);
		bus.content = content;
		counter++;
	}

	if (read_line > 0)
		execute(content, &stack, counter, bus.file);

	free(content);
	free_stack(stack);
	fclose(bus.file);
	return (0);
}
