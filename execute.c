#include "monty.h"

/**
 * perform_operation - Perform the specified operation based on the input
 * @line_buffer: Pointer to the line buffer containing the operation
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number being processed
 * @file_descriptor: File descriptor for the input file
 *
 * Description: Executes the operation specified in the line buffer by
 * matching it with the defined operations and their respective functions.
 * Return: Returns 0 on successful operation execution, otherwise 1.
 */
int perform_operation(char *line_buffer, data_t **stack, unsigned int line_number, FILE *file_descriptor)
{
  instruction_t operations[] = {
     {"push", process_push},
     {"pall", print_all},
     {"pint", print_top},
     {"pop", process_pop},
     {"swap", process_swap},
     {"add", process_add},
     {"nop", process_nop},
     {"sub", process_subtract},
     {"div", process_divide},
     {"mul", process_multiply},
     {"mod", process_modulo},
     {"pchar", process_print_character},
     {"pstr", process_print_string},
     {"rotl", process_rotate_left},
     {"rotr", process_rotate_right},
     {"queue", process_queue},
     {"stack", process_stack},
     {NULL, NULL}
    };

    unsigned int index = 0;
    char *operator;

    operator = strtok(line_buffer, " \n\t");

    /* Ignore comment lines starting with '#' */
    if (operator && operator[0] == '#')
      {
	return (0);
      }

    state.argument = strtok(NULL, " \n\t");

    /* Find the matching operation and execute its function */
    while (operations[index].opcode && operator)
      {
	if (strcmp(operator, operations[index].opcode) == 0)
	  {
	    operations[index].function_pointer(stack, line_number);
	    return (0);
	  }
	index++;
      }

    /* Handle unknown instructions */
    if (operator && operations[index].opcode == NULL)
      {
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, operator);
	fclose(file_descriptor);
	free(state.line_buffer);
	free_all_nodes(*stack);
	exit(EXIT_FAILURE);
      }
    return (1);
}
