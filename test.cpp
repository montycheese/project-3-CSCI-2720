#include "sortFunction.h"
#include <iostream>
#define INSERTION 0
#define MERGE 1
#define QUICK 2

using namespace std;

bool assert(int i, int j);
bool test(int * array, int* sorted, int len, int type, int testNum);

int main(){
    int * array = new int[100];
    int * sorted = new int[100];
    int testNum = 1;
    int len;
  //test 1 -- fully reversed array
  for(int i=99, j=0; i >= 0; i--,j++){
    array[j] = i;
  }
  for(int i=0; i<100;i++){
      sorted[i] = i;
  }
    len = 100;
    test(array, sorted, len, INSERTION, 1);
    test(array, sorted, len, MERGE, 1);
    test(array, sorted, len, QUICK, 1);
 
    delete [] array;
    delete [] sorted;
    
    //test 2 -- random array size 100
    int array2[99] = {
        3351, 4017, 5053, 9227, 1900, 5166, 4859, 5063, 4446, 7050, 8089, 1814, 5765, -428, 6053, 7594, 9830, 3139, 1030, 9602, 1577, 3280, 477, 9568, 7403, -910, 5832, 7105, 5883, 5233, 5103, 7369, -997, 280, 9236, 3723, 2511, -126, 7639, 5163, 1227, 2260, 2578, 4432, -4, 3840, 3536, 5306, 4683, 6702, 8493, 1155, 8018, 2809, 6783, 6854, 9859, 9617, 3327, 9854, 4627, 5927, 4887, 4930, 5035, -340, 5460, 8899, 2582, 3501, 2680, 700, 4582, 421, 871, 713, 9493, 9917, 3401, 5638, -588, 116, 2076, 853, 1461, 1033, 3365, 9010, 8768, 6226, 7989, 1558, 8721, 5207, 5365, 932, 8263, 9325, 4907
    };
    int sorted2[99] = {
        -997, -910, -588, -428, -340, -126, -4, 116, 280, 421, 477, 700, 713, 853, 871, 932, 1030, 1033, 1155, 1227, 1461, 1558, 1577, 1814, 1900, 2076, 2260, 2511, 2578, 2582, 2680, 2809, 3139, 3280, 3327, 3351, 3365, 3401, 3501, 3536, 3723, 3840, 4017, 4432, 4446, 4582, 4627, 4683, 4859, 4887, 4907, 4930, 5035, 5053, 5063, 5103, 5163, 5166, 5207, 5233, 5306, 5365, 5460, 5638, 5765, 5832, 5883, 5927, 6053, 6226, 6702, 6783, 6854, 7050, 7105, 7369, 7403, 7594, 7639, 7989, 8018, 8089, 8263, 8493, 8721, 8768, 8899, 9010, 9227, 9236, 9325, 9493, 9568, 9602, 9617, 9830, 9854, 9859, 9917
    };
    len = 99;
    test(array2, sorted2, len, INSERTION, 2);
    test(array2, sorted2,len, MERGE, 2);
    test(array2, sorted2, len,QUICK, 2);
    
    //test 3 --  array size 1
    int array3[1] = {-1};
    int sorted3[1] = {-1};
    len = 1;
    
    test(array3, sorted3, len, INSERTION, 3);
    test(array3, sorted3, len, MERGE, 3);
    test(array3, sorted3, len, QUICK, 3);
    
    //test 4 -- already sorted array
    int * array4 = new int[1000];
    int * sorted4 = new int[1000];
    len = 1000;
    for(int i=999, j=0; i >= 0; i--,j++){
        array[j] = i;
    }
    for(int i=0; i<1000;i++){
        sorted[i] = i;
    }
    test(array4, sorted4, len, INSERTION, 3);
    test(array4, sorted4, len, MERGE, 3);
    test(array4, sorted4, len, QUICK, 3);

  return 0;
}

bool test(int * array, int * sorted, int len, int type, int testNum){
    bool passed = true;
    switch(type){
        case 0: insertionSort(array, len, 0);
            break;
        case 1: mergeSortOutput(array, len, 0);
            break;
        case 2: quickSortOutput(array, len, 0);
            break;
        default: cout << "error";
            break;
    }
    for(int i=0; i<len;i++){
        //printf("a: %d, sorted: %d\n", array[i], sorted[i]);
        if(!assert(array[i], sorted[i])){
            passed = false;
        }
    }
    if(passed){
        printf("Test %d passed on ", testNum);
    }
    else{
        printf("Test %d failed on ", testNum);
    }
    
    if(type == 0){
        printf("Insertion sort\n");
    }
    else if(type == 1){
        printf("Merge Sort\n");
    }
    else{
        printf("Quick sort\n");
    }
    return passed;
}

bool assert(int i, int j){
    //cout << i << " " << j<< endl;
  if(i != j){
    cout << i << " is NOT equal to: " << j << endl;
    return false;
  }
  return true;
}
