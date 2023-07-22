#include "sort.h"

/**
 *lomuto_partition - partitions the sub-array
 *@array: the array
 *@low: low index
 *@high: high index
 *@size: size of the original array
 *Return: final partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 *quick_sort_lomuto - helper function that does the recursive steps
 *@array: array to sort
 *@low: low index
 *@high: high index
 *@size: size of the original array
 */
void quick_sort_lomuto(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_lomuto(array, low, pi - 1, size);
		quick_sort_lomuto(array, pi + 1, high, size);
	}
}

/**
 *quick_sort - sorts an array of integers in ascending order using
 *the Quick sort algorithm with the Lomuto partition scheme.
 *@array: array to sort
 *@size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_lomuto(array, 0, size - 1, size);
}
