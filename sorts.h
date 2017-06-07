#ifndef SORTS_H
#define SORTS_H

#include <time.h>

// uses quicksort to sort an array from a specified start, and end index, returns the sorted array
int* quickSort(int* array, int start, int end);
int partition(int* array, int start, int end);
int* insertionSort(int* array, int start, int end);
int* mergeSort(int* array, int start, int end);

#endif 
