#include "sort.h"

/**
 *counting_sort - Sorts an array of integers in ascending
 *                order using the counting sort algorithm
 *@array: The array to be sorted
 *@size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	int i, k = 0;
	int *count;

	if (!array || size < 2)
		return;

	/*Get maximum number in the array */
	for (i = 1; i < (int) size; i++)
		if (array[i] > max)
			max = array[i];

	/*Initialize the count array */
	count = malloc((max + 1) * sizeof(int));
	if (!count)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/*Count occurrences of each number in the array */
	for (i = 0; i < (int) size; i++)
		count[array[i]]++;

	/*Print counting array */
	for (i = 0; i <= max; i++)
	{
		printf("%d", count[i]);
		if (i < max)
			printf(", ");
	}

	printf("\n");

	/*Reconstruct the sorted array */
	for (i = 0; i <= max; i++)
		while (count[i]-- > 0)
			array[k++] = i;

	/*Free the count array */
	free(count);
}
