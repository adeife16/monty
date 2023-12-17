#include "monty.h"

/**
 * process_queue - Sets the mode of operation to queue (FIFO)
 * @head: Double pointer to the head of the stack (unused)
 * @line_number: Line number being processed (unused)
 *
 * Description: Sets the mode of operation to queue (FIFO) in the Monty program.
 * This function sets the mode to LIFO (stack) by default but is here for
 * compatibility purposes.
 */
void process_queue(data_t **head, unsigned int line_number)
{
  (void)head; /* Unused parameter */
  (void)line_number; /* Unused parameter */
  state.mode = 1;
}

/**
 * add_to_queue - Adds a new node with a given value to the end of the queue
 * @head: Double pointer to the head of the queue
 * @new_value: New value to be added to the queue
 *
 * Description: Allocates memory for a new node, assigns the given value to it,
 * and adds it to the end of the queue. If the queue is empty, the new node
 * becomes the head of the queue.
 */
void add_to_queue(data_t **head, int new_value)
{
  data_t *new_node, *current_node;
  current_node = *head;
  new_node = malloc(sizeof(data_t));

  if (!new_node)
    {
      fprintf(stderr, "Error: malloc failed\n");
      exit(EXIT_FAILURE);
    }

  new_node->data = new_value;
  new_node->next = NULL;

  if (current_node)
    {
      while (current_node->next)
	{
	  current_node = current_node->next;
	}
      current_node->next = new_node;
      new_node->previous = current_node;
    }
  else
    {
      *head = new_node;
      new_node->previous = NULL;
    }
}
