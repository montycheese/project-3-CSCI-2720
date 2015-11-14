#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "sortFunction.h"

using namespace std;

// set up seed
int seed = 0;
int * data;
int whetherReport = 0;
long * avgCmp;
long totalCmp = 0;
int totalNum = 100;
int rounds = 50;
char fileName[16];

int arrayLength = 0;

// generate n random numbers, given a n
void generator(int seed, int n, int* array) {
	srand (seed);
	for (int i = 0; i < n; i++) {
		// array[i] = rand() % n;
		array[i] = rand() % 100;
	}
}

//  main program
int main(int argc, char *argv[]) {

	// prepare vector
	avgCmp = (long*) calloc (totalNum, sizeof(long));

	for (int i = 0; i < totalNum; i++) {

		arrayLength = (i+1) * 100;

		// populate data for sorting; sort
		for (int j = 1; j <= rounds; j++) {

			// prepare data for sorting
			data = (int*) calloc (arrayLength, sizeof(int));
			seed = j;
			generator(seed, arrayLength, data);

			// sort and count
			if (strcmp(argv[1], "1") == 0) {
				totalCmp += sortFunction(data, 1, arrayLength, whetherReport); 
				// strcpy(fileName, "Insert.txt");
			}
			if (strcmp(argv[1], "2") == 0) {
				totalCmp += sortFunction(data, 2, arrayLength, whetherReport); 
				// strcpy(fileName, "Merge.txt");
			}
			if (strcmp(argv[1], "3") == 0) {
				totalCmp += sortFunction(data, 3, arrayLength, whetherReport); 
				// strcpy(fileName, "Quick.txt");
			}

			// free data
			free(data);
		}

		// save cmp data to vector
		avgCmp[i] = totalCmp / rounds;
	}


	// for (int i = 0; i < totalNum; i++) {
	// 	printf("%ld ", avgCmp[i]);
	// }
	// printf("\n");


	// write to a file
	if (strcmp(argv[1], "1") == 0) {
		strcpy(fileName, "Insert.txt");
	}
	if (strcmp(argv[1], "2") == 0) {
		strcpy(fileName, "Merge.txt");
	}
	if (strcmp(argv[1], "3") == 0) {
		strcpy(fileName, "Quick.txt");
	}

	ofstream theFile;
	// file name
	theFile.open(fileName);
	// write data
	for(int count = 0; count < totalNum; count++){
		theFile << avgCmp[count] << " " ;
	}
	theFile.close();

	// free vector
	free(avgCmp);

	return 0;
}