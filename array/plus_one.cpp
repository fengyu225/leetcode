/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include "header.h"

vector<int> plusOne(vector<int>& digits) {
    int carry = 1, sz = digits.size();
    vector<int> res(digits);
    int i=sz-1;
    for(;i>=0; i--){
        int temp = res[i]+carry;
        res[i] = temp%10;
        carry = temp/10;
        if(!carry) break;
    }
    if(i>=0) return res;
    if(carry) res.insert(res.begin(), carry);
    return res;
}

int main(){
    int arr[] = {9, 9, 9};
    vector<int> digits(arr, arr+sizeof(arr)/sizeof(arr[0]));
    vector<int> res = plusOne(digits);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}