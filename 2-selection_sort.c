#include "sort.h"

/**
 * selection_sort - it sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 *
 * @array: an array of integers.
 * @size: number of the array's elements
 */

void selection_sort(int *array, size_t size)
{
	size_t counter, min, unsorted, tmp;

	for (unsorted = 0; unsorted < size; unsorted++)
	{
		min = unsorted;

		for (counter = min; counter < size; counter++)
		{
			if (array[counter] < array[min])
			{
				min = counter;
			}
		}

		if (array[unsorted] != array[min])
		{
			tmp = array[min];
			array[min] = array[unsorted];
			array[unsorted] = tmp;
			print_array(array, size);
		}

	}
}
