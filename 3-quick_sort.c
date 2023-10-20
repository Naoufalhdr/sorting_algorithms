#include "sort.h"

/**
 * partition - Partitions the array using the Lomuto partition scheme.
 *
 * @array: The array to be partitioned.
 * @low: The index of the low element.
 * @high: The index of the high element.
 * @size: The number of elements in the array.
 *
 * Return: The index of the pivot element after partitioning.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i += 1;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	return (i);
}

/**
 * quicksort - Recursively sorts an array using the Quick Sort algorithm.
 *
 * @array: The array to be sorted.
 * @low: The index of the low element.
 * @high: The index of the high element.
 * @size: The number of elements in the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 *
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

