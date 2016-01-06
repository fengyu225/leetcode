/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case.
*/

#include "header.h"

FILE* ifp = fopen("file","r");

int read4(char *buf){
    int i = 0;
    for(; i<4; i++){
        if(fscanf(ifp, "%c", buf+i) != EOF) continue;
        else return i; 
    }
    return 4;
}

int read(char *buf, int n) {
    int res = 0;
    while(res<n){
        int temp = read4(buf);
        res += temp;
        buf += temp;
        if(temp<4) break;
    }
//    if(res <= n){
//        *(buf) = '\0';
//        return res;
//    }
//    else{
//        *(buf-(res-n)) = '\0';
//        return n;
//    }
    *(buf-max(res-n, 0)) = '\0';
    return min(res,n);
}

int main(){
    int n = 9;
    char buf[n];
    int res = read(buf, n);  
    cout<<buf<<endl;
    cout<<res<<endl;
    return 0;
}