#include <stdio.h>

/**
 *print_array - print an array of integers
 *@array: array to print
 *@size: size of the array
 *
 *Return: Nothing.
 */
void print_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

/**
 *bubble_sort - sorts an array of integers in ascending
 *order using the Bubble sort algorithm
 *@array: array to sort
 *@size: size of the array
 *
 *Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{ 	/*Swap array[j] and array[j + 1] */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/*print the array after the swap */
				print_array(array, size);
			}
		}
	}
}
