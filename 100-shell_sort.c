#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using Shell Sort
 *              with the Knuth sequence.
 * @array: is the array to be sorted.
 * @size: is the number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, interval = 1;
	int temp;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		if (interval == 1)
			print_array(array, size);
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		interval = (interval - 1) / 3;
	}
	print_array(array, size);
}
