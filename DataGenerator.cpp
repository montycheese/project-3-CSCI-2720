#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// set up seed
int seed = 0;
int * data;
long * avgCmp;
long totalCmp = 0;
string fileName;

// generate n random numbers, given a n
void generator(int seed, int n, int* array) {
	srand (seed);
	for (int i = 0; i < n; i++) {
		array[i] = rand() % n;
	}
}

//  main program
int main(int argc, char *argv[]) {

	// prepare vector
	avgCmp = (long*) calloc (i, sizeof(long));

	for (int i = 1000; i <= 100000; i = i + 1000) {

		// prepare data for sorting
		data = (int*) calloc (i, sizeof(int));

		// populate data for sorting; sort
		for (int j = 1; j <= 50; j++) {
			seed = j;
			generator(seed, i, data);

			if (strcmp(argv[1], "1") == 0) {
				totalCmp += sortFunction(data, 1); 
				fileName = "Insert";
			}

			if (strcmp(argv[1], "2") == 0) {
				totalCmp += sortFunction(data, 2); 
				fileName = "Merge";
			}

			if (strcmp(argv[1], "3") == 0) {
				totalCmp += sortFunction(data, 3); 
				fileName = "Quick";
			}
		}

		// free data
		free(data);

		// save cmp data to vector
		avgCmp[i/1000] = totalCmp / 50;
	}

	// write the vector to a txt file
	ofstream theFile;
	// file name
	fileName = fileName + ".txt";
	theFile.open(fileName);
	// write data
	for(int count = 0; count < 100; count++){
        theFile << avgCmp[count] << " " ;
    }
	theFile.close();

	// free vector
	free(avgCmp);

	return 0;
}