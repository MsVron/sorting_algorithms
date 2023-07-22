#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/* Struct for doubly linked list */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b
void counting_sort(int *array, size_t size);

#endif /* SORT_H */
