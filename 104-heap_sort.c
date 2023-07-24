#include "sort.h"

/**
 *sift_down - repair the heap whose root element is at index start
 *@array: array
 *@start: root index
 *@end: end index
 *@size: size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			swap(&array[root], &array[child]);
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
 *heapify - create a heap from the array
 *@array: array
 *@size: size of the array
 */
void heapify(int *array, size_t size)
{
	int start;

	for (start = (size - 2) / 2; start >= 0; start--)
		sift_down(array, start, size - 1, size);
}

/**
 *heap_sort - sorts an array of integers in ascending order using the
 *Heap sort algorithm
 *@array: The array to be sorted
 *@size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);

	for (end = size - 1; end > 0; end--)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		sift_down(array, 0, end - 1, size);
	}
}
