#include "sort.h"

/**
 *swap_nodes - Swaps two nodes in a doubly linked list
 *@list: Doubly linked list
 *@node1: First node
 *@node2: Second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node2->next = node1;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else 
		*list = node2;
	node1->prev = node2;
}

/**
 *insertion_sort_list - sorts a doubly linked list of integers in ascending
 *order using the Insertion sort algorithm
 *@list: Pointer to the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			swap_nodes(list, prev, current);
			print_list((const listint_t *) *list);
			prev = current->prev;
		}

		current = current->next;
	}
}
