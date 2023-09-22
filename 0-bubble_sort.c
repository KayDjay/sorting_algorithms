#include "sort.h"

/**
 * bubble_sort -  sorts an array of integers in ascending order
 * using bubble sort.
 *
 * @array: pointer to the array of integers to be sorted.
 * @size: number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t counter, n_unsorted;
	int tmp;

	n_unsorted = size;
	while (n_unsorted > 0)
	{
		for (counter = 0; counter < n_unsorted; counter++)
		{
			if (array[counter] > array[counter + 1])
			{
				tmp = array[counter];
				array[counter] = array[counter + 1];
				array[counter + 1] = tmp;
				print_array(array, size);
			}
		}
		n_unsorted--;
	}
}
