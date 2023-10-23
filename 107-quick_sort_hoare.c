#include "sort.h"

/**
 * swap - swaps two integers in an array.
 * @a: a pointer to the first integer.
 * @b: a pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - partitions the array using the Hoare partition scheme.
 * @array: the array to be sorted.
 * @low: start index of the partition.
 * @high: end index of the partition.
 * @size: the number of elements in the array.
 *
 * Return: the final position of the pivot element.
 */
size_t hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot;
	size_t i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(array + i, array + j);
			print_array(array, size);
		}
		else
			return (i);
	}
}

/**
 * hoare_sort_recursive - Recursively sorts an array using the Hoare partition
 *                        scheme.
 * @array: the array to be sorted.
 * @low: start index of the partition.
 * @high: end index of the partition.
 * @size: is the number of elements in the array.
 */
void hoare_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (high - low > 0)
	{
		pivot = hoare_partition(array, low, high, size);

		hoare_recursive(array, low, pivot - 1, size);
		hoare_recursive(array, pivot, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 *                    the Quick sort algorithm with the Hoare partition scheme
 * @array: is the array to be sorted.
 * @size: the number of elements in the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort_recursive(array, 0, size - 1, size);
}
