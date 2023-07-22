#include "sort.h"

int forward_pass(listint_t **list);
int backward_pass(listint_t **list);

/**
 *cocktail_sort_list - sorts a doubly linked list using cocktail sort
 *@list: pointer to head of list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t * temp;
	int swapped = 1;

	if (!list || ! *list || !(*list)->next)
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
		else *list = (*list)->next;
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
		else *list = (*list)->prev;
	}

	return (swapped);
}
