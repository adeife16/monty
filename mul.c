#include "monty.h"

/**
 * process_multiply - Multiplies the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed
 *
 * Description: Multiplies the top element by the second element
 * of the stack and replaces the second element with the result.
 * Handles insufficient elements in the stack.
 */
void process_multiply(data_t **head, unsigned int line_number)
{
  data_t *current_node = *head; /* Pointer to the current node */
  int list_length, temp_value; /* Variables for length and temporary value */
  list_length = 0;
  /* Calculate the length of the stack */
  while (current_node)
    {
      current_node = current_node->next;
      list_length++;
    }
  /* Check if the stack has less than two elements */
  if (list_length < 2)
    {
      fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
      fclose(state.file_descriptor);
      free(state.line_buffer);
      free_all_nodes(*head);
      exit(EXIT_FAILURE);
    }
  current_node = *head;
  /* Perform multiplication of the top two elements */
  temp_value = current_node->next->data * current_node->data;
  current_node->next->data = temp_value;
  *head = current_node->next;
  free(current_node); /* Free the previous top element */
}
