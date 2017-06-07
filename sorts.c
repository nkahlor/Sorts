#include "sorts.h"

int* quickSort(int* array, int start, int end)
{
	int q;
	int* sortedArray = array;
	if(start < end)
	{
		q = partition(sortedArray, start, end);
		quickSort(sortedArray, start, q - 1);
		quickSort(sortedArray, q + 1, end);
	}
	return sortedArray;
}
/* Subroutine for quicksort  */
int partition(int* array, int start, int end)
{
	int key = array[end];
	int i = start - 1;
	int temp;
	for(int j = start; j <= end - 1; j++)
	{
		if(array[j] <= key)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;

	return i + 1;
}
/* ----------------end of quicksort---------------------------------  */

int* insertionSort(int* array, int start, int end)
	{
		int* sortedArray = array;
		int key, i;
		for(int j = 2; j <= end; j++)
			{
				key = sortedArray[j];
				i = j - 1;
				while(i > 0 && sortedArray[i] > key)
					{
						sortedArray[i + 1] = sortedArray[i];
						i--;
					}
				sortedArray[i + 1] = key;
			}
		return sortedArray;
	}
/* --------------------end of insertion sort ------------------------- */
int* mergeSort(int* array, int start, int end)
	{
		int* sortedArray = array;
		return sortedArray;
	}

