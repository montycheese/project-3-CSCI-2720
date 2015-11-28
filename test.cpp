#include "sortFunction.h"
#include <iostream>

using namespace std;

bool assert(int i, int j);


int main(){
  int * array = new int[100];
  bool passed = true;
  //test 1, fully reversed array
  for(int i=99, j=0; i >= 0; i--,j++){
    array[j] = i;
  }
  long cmpNumber =  mergeSortOutput(array, 100, 0);
  
  
  for(int i=0; i<100;i++){
    if(!assert(array[i], i)){
      passed = false;
    }
  }
  cout << ((passed) ? "test 1 passed on merge\n" : "test 1 failed on merge...\n");
    
    
    delete [] array;
    passed = true;
    
    //test 2 random array size 100
    int array2[99] = {
        3351, 4017, 5053, 9227, 1900, 5166, 4859, 5063, 4446, 7050, 8089, 1814, 5765, -428, 6053, 7594, 9830, 3139, 1030, 9602, 1577, 3280, 477, 9568, 7403, -910, 5832, 7105, 5883, 5233, 5103, 7369, -997, 280, 9236, 3723, 2511, -126, 7639, 5163, 1227, 2260, 2578, 4432, -4, 3840, 3536, 5306, 4683, 6702, 8493, 1155, 8018, 2809, 6783, 6854, 9859, 9617, 3327, 9854, 4627, 5927, 4887, 4930, 5035, -340, 5460, 8899, 2582, 3501, 2680, 700, 4582, 421, 871, 713, 9493, 9917, 3401, 5638, -588, 116, 2076, 853, 1461, 1033, 3365, 9010, 8768, 6226, 7989, 1558, 8721, 5207, 5365, 932, 8263, 9325, 4907
    };
    int sorted[99] = {
        -997, -910, -588, -428, -340, -126, -4, 116, 280, 421, 477, 700, 713, 853, 871, 932, 1030, 1033, 1155, 1227, 1461, 1558, 1577, 1814, 1900, 2076, 2260, 2511, 2578, 2582, 2680, 2809, 3139, 3280, 3327, 3351, 3365, 3401, 3501, 3536, 3723, 3840, 4017, 4432, 4446, 4582, 4627, 4683, 4859, 4887, 4907, 4930, 5035, 5053, 5063, 5103, 5163, 5166, 5207, 5233, 5306, 5365, 5460, 5638, 5765, 5832, 5883, 5927, 6053, 6226, 6702, 6783, 6854, 7050, 7105, 7369, 7403, 7594, 7639, 7989, 8018, 8089, 8263, 8493, 8721, 8768, 8899, 9010, 9227, 9236, 9325, 9493, 9568, 9602, 9617, 9830, 9854, 9859, 9917
    };
    
    cmpNumber = mergeSortOutput(array2, 99,0);
    
    for(int i=0; i<99;i++){
        if(!assert(array2[i], sorted[i])){
            passed = false;
        }
    }
    
    cout << ((passed) ? "test 2 passed on merge\n" : "test 2 failed on merge...\n");
    
    //delete [] array2;
    //delete [] sorted;

  return 0;
}

bool assert(int i, int j){
    //cout << i << " " << j<< endl;
  if(i != j){
    cout << i << " is NOT equal to: " << j << endl;
    return false;
  }
  return true;
}
