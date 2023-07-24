#include "sort.h"

/**
 *max_val - find the max value in an array
 *@array: the array
 *@size: size of the array
 *Return: max value
 */
int max_val(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 *count_sort - implementation of count sort
 *@array: the array
 *@size: size of the array
 *@exp: digit to count around
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output;
	int i, count[10] = { 0 };

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	/*Count occurrence of digits */
	for (i = 0; i < (int) size; i++)
		count[(array[i] / exp) % 10]++;

	/**
     * Change count[i] so that count[i]
     *now contains actual position of this digit in output[]
     */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/*Build the output array */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/**
     *Copy the output array to array[], so that array[] now
	 *contains sorted numbers according to current digit
     */
	for (i = 0; i < (int) size; i++)
		array[i] = output[i];

	/*Print the sorted array */
	print_array(array, size);

	free(output);
}

/**
 *radix_sort - sorts an array in ascending order using the Radix sort algorithm
 *@array: array to be sorted
 *@size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	/*Find the maximum number to know the number of digits */
	max = max_val(array, size);

	/**
     *Do counting sort for every digit. Note that instead
     *of passing digit number, exp is passed. exp is 10^i
	 *where i is current digit number
     */
	for (exp = 1; max / exp > 0; exp *= 10)
		count_sort(array, size, exp);
}
