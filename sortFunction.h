#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

//insertion
int insertionSort(int * data, int length, int whetherReport) {
	int key;
	int j;
	int cmpNumber = 0;

	for (int i = 1; i < length; i++) {
		key = data[i];
		// insertion
		j = i - 1;
		while (j >= 0 && data[j] > key) {
			data[j+1] = data[j];
			j = j - 1;
			cmpNumber++;
		}
		data[j+1] = key;
	}

	if (whetherReport == 1) {
		// report sorted results
		printf("Insertion sort: ");
		for (int i = 0; i < length; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		// report input size
		printf("Input size: %d\n", length);
		// report total comparison
		printf("Total # comparisons: %d\n", cmpNumber);
	} else {
		return cmpNumber;
	}
}

// merge
int mergeSort(int * data, int length, int whetherReport) {

}

// quick
int quickSort(int * data, int length, int whetherReport) {

}

// sort wrapper
int sortFunction(int * data, int mode, int length, int whetherReport) {
	if (mode == 1) {
		// insertion sort
		insertionSort(data, length, whetherReport);
	} 
	if (mode == 2) {
		// merge sort
		mergeSort(data, length, whetherReport);
	}

	if (mode == 3) {
		// quick sort
		quickSort(data, length, whetherReport);
	}
}