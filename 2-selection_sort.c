#include "sort.h"

/**
 * swap_elements - Exchange the positions of two integers within an array.
 * @n: The initial integer to be swapped.
 * @m: The subsequent integer to be swapped.
 */
void swap_elements(int *n, int *m)
{
	int temp;

	temp = *n;
	*n = *m;
	*m = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Note: The function prints the array after each swap operation.
 */

void selection_sort(int *array, size_t size)
{
	int *minmum;
	size_t i, k;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minmum = array + i;
		for (k = i + 1; k < size; k++)
			minmum = (array[k] < *minmum) ? (array + k) : minmum;

		if ((array + i) != minmum)
		{
			swap_elements(array + i, minmum);
			print_array(array, size);
		}
	}
}
