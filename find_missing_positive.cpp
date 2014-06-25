#include "header.h"

int firstMissingPositive(int A[], int n) {
    return 0;
}

int main(){
    int arr0[] = {1, 2, 0}; //3
    int arr1[] = {3, 4, -1, 1}; //2 
    printf("%d\n", firstMissingPositive(arr0,sizeof(arr0)/sizeof(arr0[0])));
    printf("%d\n", firstMissingPositive(arr1,sizeof(arr1)/sizeof(arr1[0])));
    return 0;
}
