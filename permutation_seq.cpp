#include "header.h"

string getPermutation(int n, int k) {
    if(n==1) return "1";
    string result = "";
    int used[n];
    int from = 0,num=1;
    for(int i=n-1;i>=1;i--)
        num *= i;
    k-=1;
    for(int i=0;i<n;i++){
        int j=0,m=0;
        for(m=0;m<n;m++){
            if(used[m] == 1) continue;
            j++;
            if(j==k/num+1) break;
        }
        used[m]=1;
        result += m+1+'0';
        k = k-k/num*num;
        if(i==n-1) break;
        num = num/(n-1-i);
    }
    return result;
}

int main(){
    //string str0 = getPermutation(3,5);
    string str0 = getPermutation(5,1);
    printf("%s\n", str0.c_str());
    return 0;
}
