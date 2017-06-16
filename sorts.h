#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
// uses quicksort to sort an array from a specified start, and end index, returns the sorted array
void swap_notemp(int *x, int *y);
int* quickSort(int* array, int start, int end);
int partition(int* array, int start, int end);
int* insertionSort(int* array, int start, int end);
void merge(int* array, int start, int key, int end);
int* mergeSort(int* array, int start, int end);

#endif 
