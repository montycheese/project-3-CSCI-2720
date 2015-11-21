#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//define method sig
void merge(int *data, int * temp, int lo, int mid, int hi, long * cmpNumber);
void mergeSort(int * data, int * temp, int lo, int hi, long * cmpNumber);

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
    int * temp = new int[length];
    
    mergeSort(data, temp, 0, length - 1, &cmpNumber);
    
    if(whetherReport == 1){
        //report sorted array
        printf("Merge sort: ");
        for(int i=0; i < length; i++){
            printf("%d ", data[i]);
        }
        //len of array
        printf("Input size: %d\n", length);
        //num comparisons via merge sort
        printf("\Total # of comparisons: %ld\n", cmpNumber);
    }
    return cmpNumber;
}

void mergeSort(int * data, int * temp, int lo, int hi,long * cmpNumber){
    if (lo < hi){
        int mid = (hi +lo) / 2;
        //recursively call method on lower half of array
        //divide
        mergeSort(data, temp, lo, mid, cmpNumber);
        //recursively call method on upper half of array
        //divide
        mergeSort(data, temp, mid+1, hi, cmpNumber);
        //join the two partitions
        //conquer
        merge(data, temp, lo, mid+1, hi, cmpNumber);
    }
}

void merge(int * data, int * temp, int lo, int mid, int hi,long * cmpNumber){
    int i       = 0,
    leftEnd     = mid - 1,
    tmp         = lo,
    numElements = hi - lo + 1;
    
    //put lower elements in left half of temp array and higher
    //elements in right half of temp array
    while ((lo <= leftEnd) && (mid <= hi)){
        if(data[lo] <= data[mid]){
            temp[tmp] = data[lo];
            lo++;
        }
        else{
            temp[tmp] = data[mid];
            mid++;
        }
        *cmpNumber+=1;
        tmp++;
    }
    
    while (lo <= leftEnd){
        temp[tmp] = data[lo];
        lo++;
        tmp++;
        *cmpNumber+=1;
    }
    while (mid <= hi){
        temp[tmp] = data[mid];
        mid++;
        tmp++;
        *cmpNumber+=1;
    }
    //copy sorted values to original array.
    for(i=0;i <= numElements;i++){
        data[hi] = temp[hi];
        hi--;
    }
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