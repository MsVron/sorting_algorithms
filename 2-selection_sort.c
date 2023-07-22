#include "sort.h"

/**
 *swap_int - swaps the values of two integers
 *@a: the first integer
 *@b: the second integer
 */
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *selection_sort - sorts an array of integers in ascending order
 *                 using the Selection sort algorithm
 *@array: the array of integers
 *@size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (min != i)
		{
			swap_int(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
