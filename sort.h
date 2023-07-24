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
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int size, int mid, int *temp);
void swap(int *a, int *b);
void sift_down(int *array, size_t start, size_t end, size_t size);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);
int max_val(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void bitonic_compare(int *array, size_t size, int start, int dir);
void bitonic_merge(int *array, size_t size, size_t start, int dir, size_t total_size);
void bitonic_sort_helper(int *array, size_t size, size_t start, int dir, size_t total_size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
