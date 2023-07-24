#include "sort.h"

/**
 *swap - swap two numbers
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
 *bitonic_compare - recursively sort the input sequence in ascending order,
 *if dir = 1, and in descending order otherwise
 *@array: the array
 *@size: size of the array
 *@start: starting index
 *@dir: direction
 */
void bitonic_compare(int *array, size_t size, int start, int dir)
{
	if (dir == (array[start] > array[start + size / 2]))
	{
		swap(&array[start], &array[start + size / 2]);
		print_array(array, size);
	}
}

/**
 *bitonic_merge - recursively sort the input sequence in ascending order,
 *if dir = 1, and in descending order otherwise
 *@array: the array
 *@size: size of the array
 *@start: starting index
 *@dir: direction
 */
void bitonic_merge(int *array, size_t size, int start, int dir)
{
	if (size > 1)
	{
		bitonic_compare(array, size, start, dir);
		bitonic_merge(array, size / 2, start, dir);
		bitonic_merge(array, size / 2, start + size / 2, dir);
	}
}

/**
 *bitonic_sort_helper - helper function for bitonic_sort
 *@array: the array
 *@size: size of the array
 *@start: starting index
 *@dir: direction
 */
void bitonic_sort_helper(int *array, size_t size, int start, int dir)
{
	if (size > 1)
	{
		int k = size / 2;

		bitonic_sort_helper(array, k, start, !dir);
		bitonic_sort_helper(array, k, start + k, dir);
		bitonic_merge(array, size, start, dir);
	}
}

/**
 *bitonic_sort - produce a bitonic sequence by recursively sorting its two
 *halves in opposite sorting orders, then sorts the obtained sequence
 *@array: the array
 *@size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;

	bitonic_sort_helper(array, size, 0, up);
}
