#include <iostream>
#include <vector>
using namespace std;

// To execute C++, please define "int main()"


// Input: array of unique integers, and size of the array
// Output: second-largest number

int func(vector<int>& arr){
  int sz = arr.size();
  if(sz<2) return -1;
  int largest = -1, second_largest = -1;
  for(int i=0; i<sz; i++){
    if(largest == -1 || arr[i]>arr[largest]){
      second_largest = largest;
      largest = i;
    }
    else if(second_largest == -1 || arr[i]>arr[second_largest])
      second_largest = i;
  }
  return second_largest;
}

int main(){
  int arr0[] = {0, 1, 2, 3};
  vector<int> v_arr0(arr0, arr0+4);
  cout<<func(v_arr0)<<endl;
  return 0;
}