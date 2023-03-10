#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swapped;

	if (array == NULL || size < 2)
		return;
	while (1)
	{
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				swap_ints(array + i, array + i - 1);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
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
