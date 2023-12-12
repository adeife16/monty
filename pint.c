#include "monty.h"

/**
 * print_top - Prints the value of the top element in the stack
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed
 *
 * Description: Prints the value of the top element of the stack if
 * the stack is not empty. If the stack is empty, exits with failure.
 */
void print_top(data_t **head, unsigned int line_number) {
    if (*head == NULL) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        fclose(state.file_descriptor);
        free(state.line_buffer);
        free_all_nodes(*head);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*head)->data);
}
