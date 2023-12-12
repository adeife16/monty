#include "monty.h"

void free_all_nodes(data_t *head) {
  data_t *temp_node;

  while (head) {
    temp_node = head;
    head = head->next;
    free(temp_node);
  }
}
