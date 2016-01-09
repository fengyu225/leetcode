/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

#include "header.h"

vector<vector<int> > combinationSum3(int k, int n){
    vector<vector<int> > res;
    if(k==0 || n==0) return res;
    return res;
}

int main(){
    vector<vector<int> > res = combinationSum3(3,9);
    for(int i=0; i<res.size(); i++)
        print_vector<int>(res[i]);
    return 0;
}