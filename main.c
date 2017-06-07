#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "sorts.h"

// Prototypes
void printArray(int* array, int start, int end);

int main(int argc, char* argv[])
{
	char menuChoice; // recieved from user input	
	int running = 1; // boolean to determine if progam loop should be executed
	int arraySize;	
	int* inputArray;
	int* sortedArray;
	
	while(running == 1)
	{
			printf("How large would you like the array to be?\n");
			scanf("%d", &arraySize);
			inputArray = (int*)malloc((arraySize + 1) * sizeof(int));
			printf("Input array values:\n");
			for(int i = 1; i <= arraySize; i++)
				scanf("%d", &inputArray[i]);

			printf("S:\tExit the program\nQ:\tQuicksort\n");
			printf("I:\tInsertion Sort\nM:\tMerge Sort\n");
			scanf(" %c", &menuChoice); // read user input
			menuChoice = toupper(menuChoice); // case doesn't matter
			switch(menuChoice)
			{
					case 'S': // end the program
						running = 0; 
					  		break;
					case 'Q': // execute quicksort
						sortedArray =  quickSort(inputArray, 1, arraySize);
						printArray(sortedArray, 1, arraySize);
						printf("\n");
				   			break;
					case 'I': // execute insertion sort
						sortedArray = insertionSort(inputArray, 1, arraySize);
						printArray(sortedArray, 1, arraySize);
						printf("\n");
							break;
					case 'M': // execute merge sort
						sortedArray = mergeSort(inputArray, 1, arraySize);
						printArray(sortedArray, 1, arraySize);
						printf("\n");
							break;
			}
	}

	// Memory Management
	free(inputArray);
	free(sortedArray);

	// End of program
	return 0;
}
// prints a 1 indexed integer array, each number on a new line
void printArray(int* array, int start, int end)
{
	for(int i = start; i <= end; i++)
		printf("%d ", array[i]);
}
