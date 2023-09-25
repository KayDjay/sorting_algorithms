#include "sort.h"

/**
 * shell_sort - Function that sorts an array of integers
 *		using Shell sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void shell_sort(int *array, size_t size)
{
	int gap = 1, a;
	int temp, b;

	if (array == NULL || size < 2)
		return;

	while (gap < (int)size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (a = gap; a < (int)size; a++)
		{
			temp = array[a];
			b = a;

			while (b >= gap && array[b - gap] > temp)
			{
				array[b] = array[b - gap];
				b -= gap;
			}

				array[b] = temp;
		}

		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
