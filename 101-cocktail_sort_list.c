#include "sort.h"

int forward_pass(listint_t **list);
int backward_pass(listint_t **list);

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
 *cocktail_sort_list - sorts a doubly linked list using cocktail sort
 *@list: pointer to head of list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	temp = *list;

	while (swapped)
	{
		swapped = forward_pass(&temp);
		if (!swapped)
			break;
		swapped = backward_pass(&temp);
	}
}

/**
 *forward_pass - make a forward pass through the list
 *@list: pointer to head of list
 *Return: 1 if swap occurred, 0 otherwise
 */
int forward_pass(listint_t **list)
{
	int swapped = 0;

	while ((*list)->next)
	{
		if ((*list)->n > (*list)->next->n)
		{
			swap_nodes(list, *list, (*list)->next);
			print_list((const listint_t *) *list);
			swapped = 1;
		}
		else
			*list = (*list)->next;
	}

	return (swapped);
}

/**
 *backward_pass - make a backward pass through the list
 *@list: pointer to head of list
 *Return: 1 if swap occurred, 0 otherwise
 */
int backward_pass(listint_t **list)
{
	int swapped = 0;

	while ((*list)->prev)
	{
		if ((*list)->prev->n > (*list)->n)
		{
			swap_nodes(list, (*list)->prev, *list);
			print_list((const listint_t *) *list);
			swapped = 1;
		}
		else
			*list = (*list)->prev;
	}

	return (swapped);
}
