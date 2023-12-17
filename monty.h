#ifndef _REWRITTEN_H
#define _REWRITTEN_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct data_s - doubly linked list representation of a stack (or queue)
 * @data: integer
 * @previous: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct data_s
{
	int data;
	struct data_s *previous;
	struct data_s *next;
} data_t;

/**
 * struct state_s - variables -args, file, line content
 * @argument: value
 * @file_descriptor: pointer to monty file
 * @line_buffer: line content
 * @mode: flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct state_s
{
	char *argument;
	FILE *file_descriptor;
	char *line_buffer;
	int mode;
} state_t;

extern state_t state;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @function_pointer: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*function_pointer)(data_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t get_stdin(char **lineptr, int file);
char *clean_line(char *content);
void process_push(data_t **head, unsigned int number);
void print_all(data_t **head, unsigned int number);
void print_top(data_t **head, unsigned int number);
int execute(char *content, data_t **head, unsigned int counter, FILE *file);
void free_all_nodes(data_t *head);
void process_pop(data_t **head, unsigned int counter);
void process_swap(data_t **head, unsigned int counter);
void process_add(data_t **head, unsigned int counter);
void process_nop(data_t **head, unsigned int counter);
void process_subtract(data_t **head, unsigned int counter);
void process_divide(data_t **head, unsigned int counter);
void process_multiply(data_t **head, unsigned int counter);
void process_modulo(data_t **head, unsigned int counter);
void process_print_character(data_t **head, unsigned int counter);
void process_print_string(data_t **head, unsigned int counter);
void process_rotate_left(data_t **head, unsigned int counter);
void process_rotate_right(data_t **head, __attribute__((unused)) unsigned int counter);
void add_node(data_t **head, int n);
void add_queue(data_t **head, int n);
void process_queue(data_t **head, unsigned int counter);
void process_stack(data_t **head, unsigned int counter);

#endif /* _REWRITTEN_H */
