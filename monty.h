#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s -  A doubly linked list representation of a stack (or queue)
 * @p: integer
 * @prev: Points the previous element of the stack (or queue)
 * @next: Points the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int p;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct  - Variables -args, file, line content
 * @arg: Value
 * @file: Pointer to monty file
 * @content: Line content
 * @lifi: Flag change stack <-> queue
 * Description: Carries the values through the program
 */
typedef struct
{
	char *arg;
	FILE *file;
	char *content;
	size_t lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void f_push(stack_t **head, unsigned int counter);
void f_pall(stack_t **head, unsigned int counter);
void f_pint(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int p);
void addqueue(stack_t **head, int p);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
#endif
