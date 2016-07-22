/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include "header.h"

vector<int> plusOne(vector<int>& digits){
    int carry = 1;
    int sz = digits.size();
    int* arr = new int[sz+1];
    int c = sz;
    for(int i=sz-1; i>=0; i--){
        int temp = digits[i]+carry;
        arr[c] = temp%10;
        carry = temp/10;
        c--;
    }
    if(carry){arr[c] = carry;c--;}
    return vector<int>(arr+c+1, arr+sz+1);
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