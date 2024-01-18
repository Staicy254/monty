#include "monty.h"
#include "execute.h"

int main(int argc, char *argv[]) 
{
struct 
{
FILE *file;
char *content;
size_t lifi;
} 
bus = {NULL, NULL, 1};

size_t size = 0;
ssize_t read_line = 1;
stack_t *stack = NULL;
unsigned int counter = 0;

if (argc != 2) 
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

FILE *file = fopen(argv[1], "r");
if (!file) 
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

bus.file = file; 

while (read_line > 0) 
{
char *content = NULL;
read_line = getline(&content, &size, file);
bus.content = content;
counter++;

if (read_line > 0) 
{
execute(content, &stack, counter, file);
}

free(content);
}

free_stack(stack);
fclose(file);
return (0);
}
