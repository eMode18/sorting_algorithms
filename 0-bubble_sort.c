#include "sort.h"

/**
 * swap_elements - Swap elements (int) in an array.
 * @n: first element to swap.
 * @m: second element to swap.
 */
void swap_elements(int *n, int *m)
{
	int tmp;

	tmp = *n;
	*n = *m;
	*m = tmp;
}

/**
 * bubble_sort - function to Sort an int array in ascending order.
 * @array: the int array to sort.
 * @size: array size.
 *
 * Description: after each swap, print the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_elements(array + i, array + i + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		length--;
	}
}
