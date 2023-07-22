#include "sort.h"
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
