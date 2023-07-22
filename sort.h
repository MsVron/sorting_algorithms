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
void print_list(const listint_t *list)

#endif /* SORT_H */
