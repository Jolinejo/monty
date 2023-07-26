#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_vars - to store our global vars
 * @head: the first element in out stack
 *
 * Description: global variables
 */
typedef struct global_vars
{
	stack_t *head;
	char *av[20];
	FILE *fp;
	char *line;
} globals;

extern globals glob;

int arguments(char **buffer, char **av);
void (*get_op_func(char *s))(stack_t**, unsigned int);
void safe_exit(int exit_status);

void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void div(stack_t **head, unsigned int line_number);
#endif
