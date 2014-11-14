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
#define MAX_EXPERIMENTS 20

/*
 * Calculates the average. This function sums over all the ints
 * provided in the numbers array, and then divides the sum by the size
 * to give the average.
 */
float calculate_average(float numbers[], int size) {
	int i;
	float sum = 0;
	for (i = 0; i < size; i++) {
		sum += numbers[i];
	}
	float average = sum/size;
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
			setbuf(stdout, NULL);
			// The file is now opened.
			// Build one record:
			// Get experimenter's name and store in char array name
			// Scan file until you hit first comma
			int x;
			while  (( x = fgetc(file)) != 44 )
			{
				printf("%c", x);
			}
			// print space
			printf(" ");
			int counter = 0;
			float numbers[MAX_EXPERIMENTS];
			fscanf (file, "%f", &numbers[counter]);
			printf("number is: %f\n", numbers[counter]);
			counter++;
			while  (( x = fgetc(file)) != '\n' ) {
				printf("%c",x);
				fscanf (file, "%f", &numbers[counter]);
				printf("number is: %f\n", numbers[counter]);
				counter++;
			}

			printf("counter is: %d\n", counter);

			//print values parsed to int array.
			int j;
			for(j=0; j<counter; ++j) {
				printf("[%i]: %f\n",j,numbers[j]);
			}

			int size = counter;
			printf("size: %d\n", size);
			float average = calculate_average(numbers, size);
			printf("%.2f\n", average);
			// we are now at the first integer
		}
	}

	/*
	 *
			int counter = 0;
			int numbers[MAX_EXPERIMENTS];
			int firstnumber = 0;
			fscanf (file, "%d", &firstnumber);
			printf("%d\n", firstnumber);
			numbers[counter] = firstnumber;
			// while we're reading one record
			while  (( x = fgetc(file)) != '\0' )
			{
				printf("int is: %d", x);
				fscanf(file, "%d,", &numbers[counter] );
				counter++;
			}
	 */

}
