#include "monty.h"

/**
 * process_add - Add the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed
 *
 * Description: Adds the top two elements of the stack and
 * replaces the second element with the sum. If the stack
 * contains less than two elements, it exits with an error.
 */
void process_add(data_t **head, unsigned int line_number)
{
  data_t *current_node = *head; /* Pointer to the current node */
  int list_length = 0, temp_value; /* Variables for length and temporary value */

    /* Calculate the length of the stack */
    while (current_node)
    {
      current_node = current_node->next;
      list_length++;
    }

    /* Check if the stack has less than two elements */
    if (list_length < 2)
    {
      fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
      fclose(state.file_descriptor);
      free(state.line_buffer);
      free_all_nodes(*head);
      exit(EXIT_FAILURE);
    }

    /* Perform addition on the top two elements */
    current_node = *head;
    temp_value = current_node->data + current_node->next->data;
    current_node->next->data = temp_value;
    *head = current_node->next;
    free(current_node); /* Free the previous top element */
}
