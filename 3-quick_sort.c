#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
/**
 * quick_sort_helper - sorts an array of integers in ascending
 * order using the quick sort algorithm
 *
 * @array: The array to be sorted
 * @high: last index at the array
 * @low: first index at the array
 * @size: Number of elements in @array
 */
void quick_sort_helper(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (low >= high)
		return;
	pivot = partion(array, low, high, size);
	if (pivot != 0)
		quick_sort_helper(array, low, pivot - 1, size);
	quick_sort_helper(array, pivot + 1, high, size);
}
/**
 * partion - Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @high: last index at the array
 * @low: first index at the array
 * @size: Number of elements in @array
 * Return: the pivot new index
 */
size_t partion(int *array, size_t low, size_t high, size_t size)
{
	size_t i, minIndx = low;
	int pivot = array[high];

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			if (array[i] != array[minIndx])
			{
				swap_ints(array + i, array + minIndx);
				print_array(array, size);
			}
			minIndx++;
		}
	}
	if (pivot != array[minIndx])
	{
		swap_ints(array + high, array + minIndx);
		print_array(array, size);
	}
	return (minIndx);
}
/**
 * swap_ints - swaps two integers
 *
 * @a: first int pointer
 * @b: second int pointer
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

