#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//define method sig
void merge(int *data,int hi, int mid, int low, long * cmpNumber);
long mergeSort(int * data, int hi, int low);

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
	cmpNumber++;

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

// merge sort
long mergeSortOutput(int * data, int length, int whetherReport) {
    long cmpNumber = 0;
    mergeSort(data, length - 1, 0, &cmpNumber);
    
    //TODO debug current isssue w/ final output
    for(int i=0; i < length; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
    return cmpNumber;
}

long mergeSort(int * data, int hi, int low, long * cmpNumber){
    if (low < hi){
        int mid = (hi / 2) + (low / 2);
        mergeSort(data, mid, low);
        mergeSort(data, hi, mid+1);
        merge(data, hi, mid, low, cmpNumber);
    }
}

//merge
void merge(int *data,int hi, int mid, int low, long * cmpNumber){
    int next1 = mid - low + 1;
    int next2 = hi - mid;
    int * left, * right;
    
    //create left and right arrays
    left = new int[next1];
    right = new int[next2];
    
    //init values
    for(int i = 0; i < next1; i++)
        left[i] = data[low + i - 1];
    for(int i = 0; i < next2; i++)
        right[i] = data[mid + i];
    
    //set indicies
    int l,r;
    l = r = 0;
    
    for(int i =low; i < hi; i++){
        if(left[l] <= right[r]){
            data[i] = left[l++];
        }
        else{
            data[i] = right[r++];
        }
        *cmpNumber += 1;
    }
    
    free(left);
    free(right);
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
		mergeSortOutput(data, length, whetherReport);
	}

	if (mode == 3) {
		// quick sort
		quickSort(data, length, whetherReport);
	}
}