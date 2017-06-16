#include "sorts.h"

// swaps by reference without the use of temp variables
void swap_notemp(int *x, int *y)
{
	// if the values happen to be the same, no swap is necessary
	if(*x == *y)
		return;
	// swapping with bitwise xor
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

// tail recursion so that stack is bounded by O(lgn)
void quickSort(int* array, int start, int end)
{
	int q;
	while(start < end)
	{
		q = partition(array, start, end);

		if(start - q < end - q)
		{
			quickSort(array, start, q - 1);
			start = q + 1;
		}
		else
		{
			quickSort(array, q + 1, end);
			end = q - 1;
		}
	}
}

/* Subroutine for quicksort  */
int partition(int* array, int start, int end)
{
	int key = array[end];
	int i = start - 1;
	
	for(int j = start; j <= end - 1; j++)
	{
		if(array[j] <= key)
		{
			i++;
			swap_notemp(&array[i], &array[j]);
		}
	}

	swap_notemp(&array[i + 1], &array[end]);

	return i + 1;
}

void insertionSort(int* array, int start, int end)
	{
		int key, i;
		for(int j = 2; j <= end; j++)
			{
				key = array[j];
				i = j - 1;
				while(i > 0 && array[i] > key)
					{
						array[i + 1] = array[i];
						i--;
					}
				array[i + 1] = key;
			}
	}

void mergeSort(int* array, int start, int end)
	{
		int q;

		if(start < end)
		{
			q = (start + end) / 2;
			mergeSort(array, start, q);
			mergeSort(array, q + 1, end);
			merge(array, start, q, end);
		}
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
