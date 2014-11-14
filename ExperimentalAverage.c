/*
 ============================================================================
 Name        : ExperimentalAverage.c
 Author      : Shivan Kaul Sahib
 Version     : 1.0
 Description : Q1 on assignment 3
 ============================================================================
 */
/*
 * The include files
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
 * Definitions
 */
#define MAX_FILENAME 50 // we specify that the max filename size is 50

/*
 * Calculates the average. This function sums over all the ints
 * provided in the numbers array, and then divides the sum by the size
 * to give the average.
 */
int calculate_average(int numbers[], int size) {
	int i;
	int sum = 0;
	for (i = 0; i < size; i++) {
		sum += numbers[i];
	}
	int average = sum/size;
	return average;
}

int main (int argc, char *argv[]) {
	if (argc != 2) /* argc should be 2 for correct execution */
	{
		printf("Error: please enter CSV filename.\n");
		return EXIT_FAILURE;
	}
	else {
		// try to open the file (we assume that the filename has been
		// entered as the first argument
		FILE *file = fopen(argv[1], "r");
		/* fopen returns 0, the NULL pointer, on failure */
		if ( file == 0 )
		{
			printf( "Could not open CSV file.\n" );
			return EXIT_FAILURE;
		}
	}
	// The file is now opened.


	char filename[MAX_FILENAME];
	/*
	 * get filename from user
	 */
	printf("Enter the name of the CSV file.\n");
	fgets (filename, 50, stdin);

	/*
	 * Check to see if the extension is .txt
	 */
	int size_filename = strlen(filename) - 1;
	printf("The size of the filename is: %d", size_filename);
}
