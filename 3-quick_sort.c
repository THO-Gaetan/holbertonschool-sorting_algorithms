#include "sort.h"

void lomuto_sort(int *array, int low, int high, size_t size);

int lomuto_partition(int *array, int low, int high, size_t size);

void swap(int *a, int *b);

/**
* quick_sort - Sorts an array of integers in ascending order using Quick sort
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}

/**
* lomuto_sort - Recursive function to perform Quick sort
* @array: The array to be sorted
* @low: Starting index of the partition to be sorted
* @high: Ending index of the partition to be sorted
* @size: Number of elements in the array
*/
void lomuto_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot;

		pivot = lomuto_partition(array, low, high, size);
		lomuto_sort(array, low, pivot - 1, size);
		lomuto_sort(array, pivot + 1, high, size);
	}
}

/**
* lomuto_partition - Lomuto partition scheme
* @array: The array to be partitioned
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Number of elements in the array
* Return: The final position of the pivot element
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	i = low - 1;
	pivot = array[high];
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
* swap - Swaps two integers
* @a: Pointer to the first integer
* @b: Pointer to the second integer
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
