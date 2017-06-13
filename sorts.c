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
		int q;

		if(start < end)
		{
			q = (start + end) / 2;
			mergeSort(sortedArray, start, q);
			mergeSort(sortedArray, q + 1, end);
			merge(sortedArray, start, q, end);
		}
		return sortedArray;
	}

/* subrouting for merge sort  */
void merge(int* array, int start, int key, int end)
	{
		int i, j, k; // index variables for left, right, and array respectively
		int n1 = key - start + 1;
		int n2 = end - key;
		int* left = (int*)malloc(sizeof(int) * n1+1);
		int* right = (int*)malloc(sizeof(int) * n2+1);

		for(i = 1; i <= n1; i++)
			left[i] = array[start + i - 1];
		for(j = 1; j <= n2; j++)
			right[j] = array[key + j];

		left[n1 + 1] = INT_MAX;
		right[n2 + 1] = INT_MAX;
		i = 1;
		j = 1;
		k = start;
		while(i <= n1 && j <= n2)
		{
			if(left[i] <= right[j])
			{
				array[k] = left[i];
				i++;
			}
			else
			{
				array[k] = right[j];
				j++;
			}
			k++;
		}
		// copy remaining elements in left
		while(i <= n1)
		{
			array[k] = left[i];
			i++;
			k++;
		}
		while(j <= n2)
		{
			array[k] = right[j];
			j++;
			k++;
		}

	}	
