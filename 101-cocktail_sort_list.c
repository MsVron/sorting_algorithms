#include "sort.h"

/**
 *swap_nodes - swaps two nodes in a doubly linked list
 *@list: pointer to the list
 *@a: node to swap
 *@b: node to swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev, *next;

	prev = a->prev;
	next = b->next;

	if (prev)
		prev->next = b;
	if (next)
		next->prev = a;

	a->next = next;
	b->prev = prev;

	a->prev = b;
	b->next = a;

	if (!b->prev)
		*
		list = b;
}

/**
 *cocktail_sort_list - sorts a doubly linked list of integers
 *in ascending order using the Cocktail shaker sort algorithm
 *@list: Pointer to the head of the list
 */
/**
 *cocktail_sort_list - sorts a doubly linked list of integers
 *in ascending order using the Cocktail shaker sort algorithm
 *@list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *current;
	if (!list || !*list) return;
	current = *list;
	while (swapped) {
		swapped = 0;
		while (current->next) {
			if (current->n > current->next->n) {
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list((const listint_t *) *list);
			}
			else current = current->next;
		}
		if (!swapped) break;
		swapped = 0;
		while (current->prev) {
			if (current->n < current->prev->n) {
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list((const listint_t *) *list);
			}
			else current = current->prev;
		}
	}
}
