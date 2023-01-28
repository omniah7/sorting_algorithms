#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (array[min] != array[i])
		{
			swap_ints(array + i, array + min);
			print_array(array, size);
		}
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

