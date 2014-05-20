#include<stdio.h>


int* bsearch(int* arr, int l, int r, int n){
    if(l>r)
        return NULL;
    int m = (l+r)/2;
    if(arr[m] == n)
        return arr+m;
    if(arr[m]>n)
        return bsearch(arr, l, m-1, n);
    else
        return bsearch(arr, m+1, r, n);
}


int largest_less(int* arr, int l, int r, int n){
    if(l>r)
        return arr[r];
    int m = (l+r)/2;
    if(n<arr[m])
        return largest_less(arr,l,m-1,n);
    else
        return largest_less(arr,m+1,r,n);
}


int smallest_greater(int* arr, int l, int r, int n){
    printf("%d,%d\n", l, r);
    if(l>r)
        return arr[l];
    int m = (l+r)/2;
    if(n>arr[m])
        return smallest_greater(arr,m+1,r,n);
    else
        return smallest_greater(arr,l,m-1,n);
}

int main(){
    int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16};
    printf("%d\n", smallest_greater(arr, 0, sizeof(arr)/sizeof(arr[0])-1, -1));
    printf("%d\n", smallest_greater(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 1));
    printf("%d\n", smallest_greater(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 3));
    printf("%d\n", smallest_greater(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 5));
    printf("%d\n", smallest_greater(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 7));
    printf("%d\n", smallest_greater(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 9));
    printf("%d\n", smallest_greater(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 15));
    printf("%d\n", smallest_greater(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 17));
    return 0;
}
