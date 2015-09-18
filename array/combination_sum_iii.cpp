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

void search(int curr_sum, int last_n, int num, int n, int k, vector<int>& temp, vector<vector<int> >& res){
    if(num == k){
        if(curr_sum == n) res.push_back(temp);
        return;
    }
    if(curr_sum > n) return;
    for(int i=last_n+1; i<=9; i++){
        temp.push_back(i);
        search(curr_sum+i, i, num+1, n, k, temp, res);
        temp.pop_back();
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int> > res;
    vector<int> temp;
    if(k == 0 || n == 0) return res;
    for(int i=1; i<=9; i++){
        temp.push_back(i);
        search(i, i, 1, n, k, temp, res);
        temp.pop_back();
    }
    return res;
}

int main(){
    vector<vector<int> > res = combinationSum3(3,7);
    print_2d_vector<int>(res);
    return 0;
}