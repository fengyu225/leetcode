/*
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

#include "header.h"

vector<vector<int> > threeSum(vector<int>& num){
    vector<vector<int> > res;
    if(num.size() < 3) return res;
    std::sort(num.begin(), num.end());
    for(int i=0; i<num.size()-2; i++){
        if(i>0 && num[i] == num[i-1]) continue;
        int j = i+1;
        int k = num.size()-1;
        int target = -1*num[i];
        while(j<k){
            if(num[j]+num[k] == target){
                vector<int> vec;
                vec.push_back(num[i]);
                vec.push_back(num[j]);
                vec.push_back(num[k]);
                res.push_back(vec);
                j++;
                while(j<k && num[j] == num[j-1]) j++;
                k--;
                while(j<k && k>i && num[k] == num[k+1]) k--;
            }
            else if(num[j]+num[k]<target) j++;
            else k--;
        }
    }
    return res;
}

int main(){
//    int arr[] = {-1, 0, 1, 2, -1, -4};
    //int arr[] = {0, 0, 0, 0, 0};
    int arr[] = {-1, -1, -1, 0, 2};
    vector<int> num(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > r = threeSum(num);
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r[i].size(); j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
