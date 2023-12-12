#include "monty.h"

/**
 * process_print_string - Prints the string represented by the stack's values
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed (unused)
 *
 * Description: Iterates through the stack's elements, interpreting them as
 * ASCII character values. It prints characters until reaching a non-printable
 * ASCII character or the end of the stack. The line number parameter is not used.
 */
void process_print_string(data_t **head, unsigned int line_number) {
    data_t *current_node = *head; /* Pointer to the current node */
    (void)line_number; /* Unused parameter */

    while (current_node) {
        if (current_node->data > 127 || current_node->data <= 0) {
            break;
        }
        printf("%c", (char)current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}
