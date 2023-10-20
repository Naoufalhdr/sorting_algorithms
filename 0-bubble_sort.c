#include "sort.h"

/**
 * bubble_sort - sorts an integer array using the Bubble Sort algorithm.
 * @array: an array of integers to be sorted.
 * @size: is the number of elements in the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp;

	while (i < size - 1)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		i++;
	}
}
