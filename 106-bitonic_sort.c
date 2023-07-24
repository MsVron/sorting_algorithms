#include "sort.h"

/**
 *swap - Swap two numbers
 *@a: the first number
 *@b: the second number
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 *bitonic_merge - Recursively sort the input sequence in ascending or descending order,
 *@array: the array to sort
 *@size: size of the array
 *@start: starting index
 *@dir: direction, 1 means ascending and 0 means descending
 *@total_size: total size of the original array
 */
void bitonic_merge(int *array, size_t size, size_t start, int dir, size_t total_size)
{
	if (size > 1)
	{
		size_t m = size / 2, i;

		for (i = start; i < start + m; i++)
		{
			if (dir == (array[i] > array[i + m]))
			{
				swap(&array[i], &array[i + m]);
				printf("Result[%lu/%lu] (%s):\n", size, total_size, dir ? "UP" : "DOWN");
				print_array(array, total_size);
			}
		}

		bitonic_merge(array, m, start, dir, total_size);
		bitonic_merge(array, m, start + m, dir, total_size);
	}
}

/**
 *bitonic_sort_helper - Helper function that generates bitonic sequence
 *@array: the array to sort
 *@size: size of the array
 *@start: starting index
 *@dir: direction, 1 means ascending and 0 means descending
 *@total_size: total size of the original array
 */
void bitonic_sort_helper(int *array, size_t size, size_t start, int dir, size_t total_size)
{
	if (size > 1)
	{
		size_t m = size / 2;

		bitonic_sort_helper(array, m, start, 1, total_size);
		bitonic_sort_helper(array, m, start + m, 0, total_size);
		printf("Merging[%lu/%lu] (%s):\n", size, total_size, dir ? "UP" : "DOWN");
		print_array(array, total_size);
		bitonic_merge(array, size, start, dir, total_size);
	}
}

/**
 *bitonic_sort - Bitonic sort function
 *@array: the array to sort
 *@size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;

	bitonic_sort_helper(array, size, 0, up, size);
}
