/*
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/

#include "header.h"

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {

}

int main(){
    //int arr[] = {0, 1, 3, 50, 75};
    int arr[] = {INT_MAX};
    //int arr[] = {-1};
    vector<int> v_arr(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<string> res = findMissingRanges(v_arr, 0, INT_MAX);
    //vector<string> res = findMissingRanges(v_arr, -2, -1);
    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}