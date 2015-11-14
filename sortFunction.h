#include <stdio.h>
#include <stdlib.h>
#include <string>

//insertion
int insertionSort(int * data, int length) {

}

// merge
int mergeSort(int * data, int length) {

}

// quick
int quickSort(int * data, int length) {

}

// sort wrapper
int sortFunction(int * data, int mode = 1, int length) {
	if (mode == 1) {
		// insertion sort
		insertionSort(data, length);
	} 
	if (mode == 2) {
		// merge sort
		mergeSort(data, length);
	}

	if (mode == 3) {
		// quick sort
		quickSort(data, length);
	}

	return 0;
}