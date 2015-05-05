/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

Input:          [1,3,2]
Expected:       [2,1,3]

*/

#include "header.h"

struct comp{
    public:
        bool operator () (int a, int b){
            return a<b;
        }
} cmp;

void swap(vector<int>& num, int i, int j){
    int x = num[i];
    num[i] = num[j];
    num[j] = x;
}

void nextPermutation(vector<int>& num){
    if(num.size()<2) return;
    int i = num.size()-1;
    while(i>0){
        if(num[i]>num[i-1]) break;
        i--;
    }
    if(i == 0){
        std::reverse(num.begin(), num.end());
        return ;
    }
    int j = num.size()-1;
    while(j>=i && num[j]<=num[i-1]) j--;
    swap(num,j,i-1);
    std::sort(num.begin()+i,num.end());
}

int main(){
    int arr[] = {1, 5, 1};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    nextPermutation(v);
    for(int i=0; i<v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
