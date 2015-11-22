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
  cout << ((passed) ? "test 1 passed\n" : "test 1 failed...\n");

  return 0;
}

bool assert(int i, int j){
  if(i != j){
    cout << i << " is NOT equal to: " << j << endl;
    return false;
  }
  return true;
}
