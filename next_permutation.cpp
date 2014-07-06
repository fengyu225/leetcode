#include "header.h"

void nextPermutation(vector<int>& num){
    int i=num.size()-1;
    while(i>0)
        if(num[i]>num[i-1]) break;
        else i--;
    if(i==0)
        std::sort(num.begin(), num.end());
    else{
        int j = num.size()-1;
        while(j>=i && num[j]<=num[i-1])
            j--;
        int temp = num[j];
        num[j] = num[i-1];
        num[i-1] = temp;
        std::sort(num.begin()+i,num.end());
    }
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
