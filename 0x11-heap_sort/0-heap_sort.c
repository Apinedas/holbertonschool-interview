#include "sort.h"

/**
 * swap_values - interchange 2 values of a given list
 * @array: list of numbers
 * @i: index of the value1
 * @j: index of the value2
 * @size: original
 * Return: nothing
 */
void swap_values(int *array, int i, int j, int size)
{
	int temp = 0;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * heapify - list into max heap
 * @array: list
 * @si: len
 * @bin: node
 * @size: original
 * Return: nothing
 */
void heapify(int *array, int si, int bin, int size)
{
	int largt = bin, left = (bin * 2) + 1, rigth = (bin * 2) + 2;

	if (left < si && array[left] > array[largt])
		largt = left;

	if (rigth < si && array[rigth] > array[largt])
		largt = rigth;

	if (largt != bin)
	{
		swap_values(array, bin, largt, size);
		heapify(array, si, largt, size);
	}
}

/**
 * heap_sort - list using heapsort
 * @array: list
 * @size: len
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int bin = 0, si = size;

	for (bin = (size / 2) - 1; bin >= 0; bin--)
		heapify(array, si, bin, size);

	for (bin = size - 1; bin >= 0; bin--)
	{
		if (bin != 0)
			swap_values(array, bin, 0, size);
		heapify(array, bin, 0, size);
	}
}
