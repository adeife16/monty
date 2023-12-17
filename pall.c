#include "monty.h"

/**
 * print_all - Prints all elements in the stack
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed (unused)
 *
 * Description: Prints all elements in the stack starting from the
 * top element. It iterates through the stack and prints each element.
 * The line number parameter is not used in this function.
 */
void print_all(data_t **head, unsigned int line_number)
{
  data_t *current_node = *head; /* Pointer to the current node */

  (void)line_number;

  /* If stack is empty, return */
  if (!current_node)
    {
      return;
    }
  /* Iterate through the stack and print each element */
  while (current_node)
    {
      printf("%d\n", current_node->data);
      current_node = current_node->next;
    }
}
