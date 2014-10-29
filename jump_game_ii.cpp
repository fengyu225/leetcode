#include "header.h"

//dp
int jump(int A[], int n){
    if(n==1) return 0;
    if(n==0) return INT_MAX;
    int min_arr[n];
    min_arr[0] = 0;
    //min_arr is non-decreasing 
    for(int i=1; i<n; i++) min_arr[i] = INT_MAX;
    for(int i=1; i<n; i++){
        for(int j=0;j<i;j++){
            if(A[j]+j>=i){
                if(min_arr[j]+1<min_arr[i]){
                    min_arr[i] = min_arr[j]+1;
                    break;
                }
            }
        }
    }
    return min_arr[n-1];
}

//greedy
int jump(int A[], int n) {
    if(n==1) return 0;
    int start=0, end=0, max=0, count=0;
    while(end<n)
    {
        count++;
        for(int i=start; i<=end; ++i)
        {
            if(A[i]+i>=n-1)
                return count;
            if(A[i]+i>max)
                max=A[i]+i;
        }
        start=end+1;
        end=max;
    }
    return 0;
}

int main(){
    int A[] = {2, 3, 1, 1, 4};
    int res = jump(A,sizeof(A)/sizeof(A[0]));
    printf("%d\n", res);
    return 0;
}
