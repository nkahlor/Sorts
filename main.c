#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "sorts.h"

// Prototypes
int random_int(int upper);
void printArray(int* array, int start, int end);
int* generateArray(int size);
void printMenu();

int main(int argc, char* argv[])
{
	char menuChoice; // recieved from user input	
	int running = 1; // boolean to determine if progam loop should be executed
	int arraySize;	
	int* inputArray = NULL;
	
	do
	{
			// declare clock related variables
			clock_t startI, endI, startQ, endQ, startM, endM;

			printf("\nHow large would you like the array to be?\n>> ");
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

						quickSort(inputArray, 1, arraySize);
						printArray(inputArray, 1, arraySize);
						printf("\n");
				   			break;
					case 'I': // execute insertion sort
						insertionSort(inputArray, 1, arraySize);
						printArray(inputArray, 1, arraySize);
						printf("\n");
							break;
					case 'M': // execute merge sort
						mergeSort(inputArray, 1, arraySize);
						printArray(inputArray, 1, arraySize);
						printf("\n");
							break;
					case 'A': // execute all of the algorithms, and compare times
						startI = clock(); // begin insertion sort
						insertionSort(inputArray, 1, arraySize);
						endI = clock(); // end insertion sort
						double insertionTime = (double)(endI - startI) / CLOCKS_PER_SEC;

						// re-generate an array
						inputArray = generateArray(arraySize);

						startQ = clock();
						quickSort(inputArray, 1, arraySize);
						endQ = clock();
						double quickTime = (double)(endQ - startQ) / CLOCKS_PER_SEC;

						// re-generate an array
						inputArray = generateArray(arraySize);

						startM = clock(); 
						mergeSort(inputArray, 1, arraySize);
						endM = clock();
						double mergeTime = (double)(endM - startM) / CLOCKS_PER_SEC;

						printf("\nTimes:\n--------------------------------------------------------\n");
						printf("Insertion:%20f seconds\nQuick:%24f seconds\nMerge:%24f seconds\n", insertionTime, quickTime, mergeTime);
							break;
			}
	} while(running == 1);

	// Memory Management
	free(inputArray);

	// End of program
	return 0;
}
void printMenu()
{
		printf("\nS:\tExit the program\nQ:\tQuicksort\n");
		printf("I:\tInsertion Sort\nM:\tMerge Sort\nA:\tRun them all and report times\n>> ");
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

int random_int(int upper)
{
	int divisor = RAND_MAX / (upper + 1);
	int number;

	do
	{
		number = rand() / divisor;
	} while(number > upper);

	return number;
}

int* generateArray(int size)
{
	srand(time(NULL));
	int* randomArray = (int*)malloc(sizeof(int) * (size+1));
	if(randomArray == NULL)
		abort();
	for(int i = 1; i <= size; i++)
		randomArray[i] = random_int(size*size); 

	return randomArray;
}


		







