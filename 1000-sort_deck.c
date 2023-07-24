#include "deck.h"

/**
 *card_value - Function that returns the integer value of a card.
 *@value: The string value of the card.
 *Return: The integer value of the card.
 */
int card_value(char *value)
{
	if (strcmp(value, "Ace") == 0)
		return (1);
	if (strcmp(value, "Jack") == 0)
		return (11);
	if (strcmp(value, "Queen") == 0)
		return (12);
	if (strcmp(value, "King") == 0)
		return (13);
	return (atoi(value));
}

/**
 *card_compare - Function to compare two cards.
 *@a: The first card.
 *@b: The second card.
 *Return: The difference between the two cards.
 */
int card_compare(const void *a, const void *b)
{
	deck_node_t *cardA = *(deck_node_t **) a;
	deck_node_t *cardB = *(deck_node_t **) b;
	int valueA = card_value((char*) cardA->card->value);
	int valueB = card_value((char*) cardB->card->value);
	int kindA = cardA->card->kind;
	int kindB = cardB->card->kind;

	if (kindA == kindB)
		return (valueA - valueB);
	return (kindA - kindB);
}

/**
 *sort_deck - Function to sort a deck of cards.
 *@deck: A double pointer to the deck.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current = *deck;
	deck_node_t *nodes[52];
	int i = 0;

	while (current != NULL)
	{
		nodes[i++] = current;
		current = current->next;
	}

	qsort(nodes, 52, sizeof(deck_node_t*), card_compare);

	for (i = 0; i < 51; i++)
	{
		nodes[i]->next = nodes[i + 1];
		nodes[i + 1]->prev = nodes[i];
	}

	nodes[0]->prev = NULL;
	nodes[51]->next = NULL;

	*deck = nodes[0];
}
