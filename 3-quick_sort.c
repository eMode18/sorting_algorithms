#include "sort.h"

void swap_elements(int *n, int *m);
int lomuto_partition(int *array, size_t size, int back, int forward);
void lomuto_sort(int *array, size_t size, int back, int forward);
void quick_sort(int *array, size_t size);

/**
 * swap_elements - Exchange the positions of two integers within an array.
 * @n: Pointer to the first integer to be swapped.
 * @m: Pointer to the second integer to be swapped.
 */

void swap_elements(int *n, int *m)
{
	int temp;

	temp = *n;
	*n = *m;
	*m = temp;
}

/**
 * lomuto_partition - Rearrange a portion of an integer array
 * using the Lomuto partition scheme with the last element as the pivot.
 * @array: Pointer to the array of integers.
 * @size: The total size of the array.
 * @back: The starting index of the segment to rearrange.
 * @forward: The ending index of the segment to rearrange.
 *
 * Return: The index of the final partition point.
 */

int lomuto_partition(int *array, size_t size, int back, int forward)
{
	int *pivot, up, down;

	pivot = array + forward;
	for (up = down = back; down < forward; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_elements(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_elements(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - Apply the quicksort algorithm recursively
 * to sort a segment of an integer array.
 * @array: Pointer to the array of integers to be sorted.
 * @size: The total size of the array.
 * @back: The starting index of the array segment to be sorted.
 * @forward: The ending index of the array segment to be sorted.
 *
 * Description: Implements quicksort using the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int back, int forward)
{
	int sect;

	if (forward - back > 0)
	{
		sect = lomuto_partition(array, size, back, forward);
		lomuto_sort(array, size, back, sect - 1);
		lomuto_sort(array, size, sect + 1, forward);
	}
}

/**
 * quick_sort - a function to sort an int array in an ascending order.
 * @array: int array.
 * @size: int array size.
 *
 * Description: this function implements the Lomuto partition techique
 * while printing
 * the array with each swap
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
