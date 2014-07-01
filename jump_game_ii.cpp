#include "header.h"

int jump(int A[], int n){
    if(n==1) return 0;
    if(n==0) return INT_MAX;
    int min_arr[n];
    min_arr[0] = 0;
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
    for(int i=0; i<n; i++)
        printf("%d ", min_arr[i]);
    printf("\n");
    return min_arr[n-1];
}
//    int jump(int A[], int n) {  
//        int* dp;
//        if(n==0)  
//        {  
//            return INT_MAX;  
//        }  
//        dp = new int[n];  
//        dp[0] = 0;  
//        for(int i=1;i<n;i++)  
//        {  
//            dp[i] = INT_MAX;  
//        }  
//        for(int i=1;i<n;i++)  
//        {  
//            for(int j=0;j<i;j++)  
//            {  
//                if(j+A[j]>=i)  
//                {  
//                    int tmp = dp[j]+1;  
//                    if(tmp < dp[i])  
//                    {  
//                        dp[i] = tmp;  
//                        break;  
//                    }  
//                }  
//            }  
//        }  
//        for(int i=0; i<n; i++) 
//            printf("%d ", dp[i]);
//        printf("\n");
//        return dp[n-1];  
//    }  
//int jump(int A[], int n){
//    if(n==1) return 0;
//    int min_arr[n];
//    min_arr[n-1] = 0;
//    for(int i=n-2;i>=0;i--){
//        int m = n-i+1;
//        for(int j=1;j<=min(n-1-i,A[i]);j++)
//            m = min_arr[i+j]+1<m?min_arr[i+j]+1:m;
//        min_arr[i] = m;
//    }
//    return min_arr[0];
//}

int main(){
    int A[] = {2, 3, 1, 1, 4};
    int res = jump(A,sizeof(A)/sizeof(A[0]));
    printf("%d\n", res);
    return 0;
}
