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
#define EXPERIMENTER_TITLE_MAX 20

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
		// entered as the first argument.
		// On the discussion board the prof said we can assume
		// that the data we're given is correctly formatted.
		FILE *file = fopen(argv[1], "r");
		/* fopen returns 0, the NULL pointer, on failure */
		if ( file == 0 )
		{
			printf( "Could not open CSV file.\n" );
			return EXIT_FAILURE;
		}
		else {
			// The file is now opened.
			// Build one record:
			// Get experimenter's name and store in char array name
			// Scan file until you hit first comma
//			char name[EXPERIMENTER_TITLE_MAX];
//			int counter=0;
			int x;
			/* read one character at a time from file, stopping at EOF, which
			               indicates the end of the file.  Note that the idiom of "assign
			               to a variable, check the value" used below works because
			               the assignment statement evaluates to the value assigned. */
			while  (( x = fgetc(file)) != 44 )
			{
				printf("%c", x);
//				name[counter] = x;
//				printf("%c", name[counter]);
//				name[counter] = x;
//				counter++;
			}
			// print space
			printf(" ");

			// we are now at the first integer
		}
	}



}
