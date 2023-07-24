#include "sort.h"

/**
 *merge - merge two subarrays of array.
 *@array: array to sort
 *@size: size of the array
 *@mid: middle index in the array
 *@temp: temporary array
 */
void merge(int *array, int size, int mid, int *temp)
{
	int i = 0, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	while (i < mid && j < size)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];
	while (j < size)
		temp[k++] = array[j++];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 *merge_sort - sorts an array of integers in ascending
 *             order using the Merge sort algorithm
 *@array: The array to be sorted
 *@size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int mid;
	int *temp;

	if (size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	mid = size / 2;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	merge(array, size, mid, temp);

	free(temp);
}
