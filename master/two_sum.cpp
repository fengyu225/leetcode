#include "header.h"

vector<int> twoSum(vector<int> &numbers, int target){
    unordered_map<int,int> m;
    vector<int> res;
    for(int i=0; i<numbers.size(); i++){
        if(m.find(target-numbers[i]) != m.end()){
            res.push_back(m[target-numbers[i]]+1);
            res.push_back(i+1);
            break;
        }
        if(m.find(numbers[i]) == m.end()){
            m[numbers[i]] = i;
        }
    }
    return res;
}

int main(){
//    int arr[] = {2, 7, 11, 15};
//    int target = 9;
    int arr[] = {3, 2, 4};
    int target = 6;
    vector<int> numbers(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> r = twoSum(numbers, target);
    for(int i=0; i<r.size(); i++)
        printf("%d ", r[i]);
    printf("\n");
    return 0;
}