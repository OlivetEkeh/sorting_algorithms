#include "sort.h"

/**
 * quick_sort - sorts the array in ascending order
 * using Lomuto's quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		sort_array(array, 0, size - 1, size);
}

/**
 * sort_array - sorts the array
 * @array: the array to be sorted
 * @low: the initial index
 * @high: the last index item
 * @size: the size of the array
 * Return: nothing
 */
void sort_array(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t pivotIndex = partition(array, low, high, size);

		if (pivotIndex > 0)
		{
			sort_array(array, low, pivotIndex - 1, size);
		}
		sort_array(array, pivotIndex + 1, high, size);
	}
}

/**
 * partition - it takes the last item as a pivot
 * and then puts the items greater than it on the right and
 * the ones less than it on the left
 *
 * @array: the array to be sorted
 * @low: just 0 so that the loop can start from the first
 * to the penultimate item in the array
 * @high: the last item in the array which
 * serves also as a pivot
 * @size: the size of the array to be sorted
 * Return: the new index of the pivot
 */
int partition(int array[], size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * swap - to swap the items in the array index
 * @a: one of the items to be swapped
 * @b: another item to be swapped
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
