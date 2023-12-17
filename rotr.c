#include "monty.h"

/**
 * process_rotate_right - Rotates the stack to the right
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed (unused)
 *
 * Description: Rotates the stack to the right by moving the bottom element
 * to the top. If the stack is empty or has only one element, no change is made.
 */
void process_rotate_right(data_t **head, __attribute__((unused)) unsigned int line_number)
{
  data_t *temp_node = *head;
  /* If stack is empty or has only one element, no change */
  if (*head == NULL || (*head)->next == NULL)
    {
      return;
    }
  /* Traverse to the last node */
  while (temp_node->next)
    {
      temp_node = temp_node->next;
    }
  /* Perform rotation by rearranging pointers */
  temp_node->next = *head;
  (*head)->previous = temp_node;
  (*head) = temp_node;
  temp_node->previous->next = NULL;
  temp_node->previous = NULL;
}
