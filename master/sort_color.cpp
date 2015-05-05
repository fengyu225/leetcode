#include "header.h"

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void sortColors(int A[], int n) {
    int lt=0,eq=0,gt=n-1;
    while(eq<=gt){
        if(A[eq] == 1)
            eq++;
        else if(A[eq]<1)
            swap(A,eq++,lt++);
        else
            swap(A,eq,gt--);
    }
}

int main(){
    int A[] = {2, 0, 1, 1, 0, 2, 1};
    sortColors(A,sizeof(A)/sizeof(A[0]));
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
