#include "monty.h"

/**
 * process_print_character - Prints the ASCII character value of the top element
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed
 *
 * Description: Prints the ASCII character value of the top element of the stack.
 * It checks if the stack is empty or if the value is out of ASCII range.
 * Exits with failure if conditions aren't met.
 */
void process_print_character(data_t **head, unsigned int line_number)
{
  data_t *current_node = *head; /* Pointer to the current node */
  /* If stack is empty, exit with failure */
  if (!current_node)
    {
      fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
      fclose(state.file_descriptor);
      free(state.line_buffer);
      free_all_nodes(*head);
      exit(EXIT_FAILURE);
    }
  /* Check if value is out of ASCII range */
  if (current_node->data > 127 || current_node->data < 0)
    {
      fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
      fclose(state.file_descriptor);
      free(state.line_buffer);
      free_all_nodes(*head);
      exit(EXIT_FAILURE);
    }
  /* Print the ASCII character value of the top element */
  printf("%c\n", (char)current_node->data);
}
