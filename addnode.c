#include "monty.h"
/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/

void addnode(data_t **head, int n)
{

	data_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(data_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->previous = new_node;
	new_node->data = n;
	new_node->next = *head;
	new_node->previous = NULL;
	*head = new_node;
}
