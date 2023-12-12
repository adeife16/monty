#include "monty.h"

/**
 * process_pop - Removes the top element from the stack
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed
 *
 * Description: Removes the top element from the stack if the stack
 * is not empty. If the stack is empty, exits with failure.
 */
void process_pop(data_t **head, unsigned int line_number) {
    data_t *current_node = *head; /* Pointer to the current node */

    if (*head == NULL) {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        fclose(state.file_descriptor);
        free(state.line_buffer);
        free_all_nodes(*head);
        exit(EXIT_FAILURE);
    }

    *head = current_node->next;
    free(current_node);
}
