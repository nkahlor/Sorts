#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
// uses quicksort to sort an array from a specified start, and end index, returns the sorted array
void swap_notemp(int *x, int *y);
void quickSort(int* array, int start, int end);
int partition(int* array, int start, int end);
void insertionSort(int* array, int start, int end);
void merge(int* array, int start, int key, int end);
void mergeSort(int* array, int start, int end);

#endif 
