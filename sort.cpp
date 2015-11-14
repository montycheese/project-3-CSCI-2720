#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "sortFunction.h"


int mode = -1;
int * theArray;
int length;


int main(int argc, char *argv[]) {
	if (argv[1][0] == '-') {
		// determine the mode
		if (argv[1][1] == 'i') {
			// insertion sort
			mode = 1;
		} else if (argv[1][1] == 'm') {
			// merge sort
			mode = 2;
		} else if (argv[1][1] == 'q') {
			// quick sort
			mode = 3;
		} else {
			// wrong modes
			printf("Your input is not valid. There are only three modes: -i, -m, and -q.\n");
			return 0;
		}

		// get the numbers given through argv[]
		length = argc - 2;
		theArray = (int *) calloc(length, sizeof(int));

		for (int i = 0; i < length; i++) {
			try {
				sscanf(argv[i+2],"%d", &theArray[i]);
			} 
			catch (int e) {
				printf("The number you provided is not an integer. We only accept integers.\n");
				free(theArray);
				return 0;
			}
		}

		// sort and report
		sortFunction(theArray, mode);
		free(theArray);

	} else {
		// no modes
		printf("Your input is not valid. Try something like ./sort -i 33 12 0 -2 1\n");
	}

	return 0;
}