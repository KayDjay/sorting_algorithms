#include "sort.h"


/**
 * swap - it swaps two elements of an array
 *
 * @array: a pointer to an array
 * @i: index of element to be swapped
 * @j: inex of element to be swapped
 */
void swap(int *array, size_t size, int i, int j)
{
	int tmp;

	if (i != j && array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto - lomuto partition scheme used in the Quick Sort.
 *
 * @array: input array to be partitioned.
 * @low: the index of the first element in the range to be partitioned.
 * @high: the index of the last element in the range to be partitioned.
 */
int lomuto(int *array, size_t size, int low, int high)
{
	int index = low - 1;
	int count;

	for (count = low; count < high; count++)
	{
		if (array[count] < array[high])
		{
			index++;
			swap(array, size, index, count);
		}
	}
	swap(array, size, index + 1, high);

	return (index + 1);
}

/*
 * quicksort - quick_sort helper
 *
 * @array: array pointer.
 * @size: array size.
 * @low: index of first element in the sub-array.
 * @high: index of last element in the sub-array.
 */

void quicksort(int *array, size_t size, int low, int high)
{
	int index;

	if (low < high)
	{
		index = lomuto(array, size, low, high);
		quicksort(array, size, low, index - 1);
		quicksort(array, size, index + 1, high);
	}
}

/**
 * quick_sort - it sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: array of n elements
 * @size: number of elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
