#include "sort.h"

/**
 *swap_int - swaps the values of two integers
 *@a: first integer to be swapped
 *@b: second integer to be swapped
 */
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *hoare_partition - orders a subset of an array of integers according to
 *the hoare partition scheme (last element as pivot)
 *@array: array of integers
 *@size: total size of array
 *@low: lowest index of the subset to order
 *@high: highest index of the subset to order
 *Return: final partition index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do { 	i++;
		} while (i <= high && array[i] < pivot);
		do { 	j--;
		} while (j >= low && array[j] > pivot);

		if (i >= j)
			return (j);

		swap_int(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 *hoare_sort - sorts an array of integers in ascending order using
 *the QuickSort algorithm with the Hoare partition scheme
 *@array: array of integers
 *@size: total size of array
 *@low: lowest index of the subset to order
 *@high: highest index of the subset to order
 */
void hoare_sort(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, size, low, high);
		hoare_sort(array, size, low, pivot - 1);
		hoare_sort(array, size, pivot + 1, high);
	}
}

/**
 *quick_sort_hoare - sorts an array of integers in ascending order using
 *the QuickSort algorithm with the Hoare partition scheme
 *@array: array of integers
 *@size: total size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
