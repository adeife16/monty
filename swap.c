#include "monty.h"

/**
 * process_swap - Swaps the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed
 *
 * Description: Swaps the positions of the top two elements in the stack.
 * If the stack has less than 2 elements, an error message is displayed,
 * and the program exits with failure.
 */
void process_swap(data_t **head, unsigned int line_number) {
    data_t *temp_node = *head;
    int temp_value, number_of_nodes = 0;

    // Count the number of nodes in the stack.
    while (temp_node) {
        number_of_nodes++;
        temp_node = temp_node->next;
    }

    if (number_of_nodes < 2) {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        fclose(state.file_descriptor);
        free(state.line_buffer);
        free_all_nodes(*head);
        exit(EXIT_FAILURE);
    }

    temp_node = *head;
    temp_value = temp_node->data;
    temp_node->data = temp_node->next->data;
    temp_node->next->data = temp_value;
}
