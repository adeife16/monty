#include "monty.h"

/**
 * process_push - Pushes an integer onto the stack
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed
 *
 * Description: Processes the 'push' instruction by checking if the argument
 * provided is a valid integer. If it is, the integer is pushed onto the stack.
 * Otherwise, an error message is displayed, and the program exits with failure.
 */
void process_push(data_t **head, unsigned int line_number) {
    int number, index, is_numeric;

    /* Check if an argument is provided */
    if (!state.argument) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        fclose(state.file_descriptor);
        free(state.line_buffer);
        free_all_nodes(*head);
        exit(EXIT_FAILURE);
    }

    is_numeric = 1;
    if (state.argument[0] == '-') {
        index++;
    }

    /* Validate if the argument is a numeric value */
    for (; state.argument[index] != '\0'; index++) {
        if (state.argument[index] > 57 || state.argument[index] < 48) {
            is_numeric = 0;
            break;
        }
    }

    /* If not a numeric value, display error and exit */
    if (!is_numeric) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        fclose(state.file_descriptor);
        free(state.line_buffer);
        free_all_nodes(*head);
        exit(EXIT_FAILURE);
    }

    /* Convert argument to integer */
    number = atoi(state.argument);

    /* Push the integer onto the stack based on the mode */
    if (state.mode == 0) {
        addnode(head, number);
    } else {
        add_to_queue(head, number);
    }
}
