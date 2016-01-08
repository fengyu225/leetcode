/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

#include "header.h"

class comp{
    public:
        bool operator() (int a, int b){
            string a_s = to_string(a);
            string b_s = to_string(b);
            return (a_s+b_s).compare(b_s+a_s)>0;
        }
};

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), comp());
    string res = "";
    for(int i:nums) res += to_string(i);
    return res;
}

int main(){
 //   int arr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int arr[] = {3, 30, 34, 5, 9};
    vector<int> nums(arr,arr+sizeof(arr)/sizeof(arr[0]));
    cout<<largestNumber(nums)<<endl;
    return 0;
}