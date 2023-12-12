#include "monty.h"

/**
 * process_rotate_left - Rotates the stack to the left
 * @head: Double pointer to the head of the stack
 * @line_number: Line number being processed (unused)
 *
 * Description: Rotates the stack to the left by moving the top element
 * to the bottom. If the stack is empty or has only one element, no change
 * is made.
 */
void process_rotate_left(data_t **head, __attribute__((unused)) unsigned int line_number) {
    data_t *temp_node = *head, *auxiliary_node;

    /* If stack is empty or has only one element, no change */
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    auxiliary_node = (*head)->next;
    auxiliary_node->previous = NULL;

    /* Traverse to the last node */
    while (temp_node->next != NULL) {
        temp_node = temp_node->next;
    }

    /* Perform rotation by rearranging pointers */
    temp_node->next = *head;
    (*head)->next = NULL;
    (*head)->previous = temp_node;
    (*head) = auxiliary_node;
}
