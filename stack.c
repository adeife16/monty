#include "monty.h"

/**
 * process_stack - Sets the mode of operation to stack (LIFO)
 * @head: Double pointer to the head of the stack (unused)
 * @line_number: Line number being processed (unused)
 *
 * Description: Sets the mode of operation to stack (LIFO) in the Monty program.
 * This function sets the mode to LIFO (stack) explicitly, but is here for
 * compatibility purposes.
 */
void process_stack(data_t **head, unsigned int line_number) {
    (void)head; /* Unused parameter */
    (void)line_number; /* Unused parameter */
    state.mode = 0;
}
