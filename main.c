#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "sorts.h"

// Prototypes
void printArray(int* array, int start, int end);
int* generateArray(int size);
void printMenu();

int main(int argc, char* argv[])
{
	char menuChoice; // recieved from user input	
	int running = 1; // boolean to determine if progam loop should be executed
	int arraySize;	
	int* inputArray;
	int* sortedArray;
	
	do
	{
			printf("How large would you like the array to be?\n>> ");
			scanf("%d", &arraySize);
			// generate a random array
			inputArray = generateArray(arraySize);
			printMenu();
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
					case 'A': // execute all of the algorithms, and compare times
							break;
			}
	} while(running == 1);

	// Memory Management
	free(inputArray);
	free(sortedArray);

	// End of program
	return 0;
}
void printMenu()
{
		printf("\nS:\tExit the program\nQ:\tQuicksort\n");
		printf("I:\tInsertion Sort\nM:\tMerge Sort\n>> ");
}
// prints a 1 indexed integer array, each number on a
// newline after 10 elements
void printArray(int* array, int start, int end)
{
	int lineCount = 0;
	for(int i = start; i <= end; i++)
	{
		if(lineCount % 10 == 0)
			printf("\n");


		printf("%5d ", array[i]);
		lineCount++;
	}
	printf("\n");

}
// generates an array randomly filled with values between 0 and 500
int* generateArray(int size)
{
	srand(time(NULL));
	int* randomArray = (int*)malloc(sizeof(int) * (size+1));
	if(randomArray == NULL)
		abort();
	for(int i = 1; i <= size; i++)
		randomArray[i] = rand() % 500; 

	return randomArray;
}
