/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include "header.h"

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r=numbers.size()-1;
    vector<int> res;
    while(l<r){
        int x = numbers[l]+numbers[r];
        if(x == target){
            res.push_back(l+1);
            res.push_back(r+1);
            break;
        }
        else if(x<target) l++;
        else r--;
    }
    return res;
}

int main(){
    vector<int> numbers = {2, 7, 11, 15};
    vector<int> res = twoSum(numbers, 9);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}