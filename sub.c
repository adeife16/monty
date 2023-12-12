#include "monty.h"

/**
 * process_subtract - Subtracts the top element from the second element in the stack
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed
 *
 * Description: Subtracts the top element from the second element in the stack,
 * storing the result in the second element. If the stack has less than 2 elements,
 * an error message is displayed, and the program exits with failure.
 */
void process_subtract(data_t **head, unsigned int line_number) {
    data_t *temp_node = *head;
    int number_of_nodes = 0;
    int difference;

    // Count the number of nodes in the stack.
    while (temp_node) {
        number_of_nodes++;
        temp_node = temp_node->next;
    }

    if (number_of_nodes < 2) {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        fclose(state.file_descriptor);
        free(state.line_buffer);
        free_all_nodes(*head);
        exit(EXIT_FAILURE);
    }

    temp_node = *head;
    difference = temp_node->next->data - temp_node->data;
    temp_node->next->data = difference;
    *head = temp_node->next;
    free(temp_node);
}
