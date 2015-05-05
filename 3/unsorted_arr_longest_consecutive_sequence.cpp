#include "header.h"

using namespace std;

int longestConsecutive(vector<int>& num){
    if(num.size() < 2) return num.size();

}

int main(){
    int arr[] = {100, 4, 200, 1, 3, 2};
    vector<int> num(arr,arr+sizeof(arr)/sizeof(arr[0]));
    printf("%d\n", longestConsecutive(num));
    return 0;
}
