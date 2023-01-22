#include "search_algos.h"

/**
 * print_array - entry to print array
 * Desc: print_array function to print the sorte array cut in half
 * @array: Array to make search
 * @start: Position to start printing
 * @end: Position to end printing
 * Return: printed array
 */
void print_array(int *array, int start, int end)
{
	int i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		if (i != start)
			printf(", ");
		printf("%d", array[i]);
	}
	putchar('\n');
}

/**
 * sort_search - entry to binary search
 * Desc: sort_search function to sort the array
 * @array: pointer to first element of array
 * @i: int type index 0 in array
 * @j: int type last index in array
 * @value: int value tu search
 * Return: printed sorted array or -1
 */
int sort_search(int *array, int i, int j, int value)
{
	int middle;

	middle = (j + i) / 2;

	if (i > j)
		return (-1);

	print_array(array, i, j);

	if (array[middle] < value)
		return (sort_search(array, middle + 1, j, value));
	if (array[middle] >= value)
		j = middle;

	if (array[i] == value && i == middle)
		return (i);

	return (sort_search(array, i, j, value));
}

/**
 * advanced_binary - entry to advanced binary
 * Desc: advanced_binary function that searches
 * for a value in a sorted array of integers
 * @array: array to sort
 * @size: number of elements in the array
 * @value: value to search for
 * Return: index where valueis located, if no value or NULL return -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	int i = 0, j = size - 1;

	if (!array || size == 0)
		return (-1);

	return (sort_search(array, i, j, value));
}
