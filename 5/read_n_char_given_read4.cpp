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
    if(n == 0) return 0;
    int c_cnt = 0;
    while(1){
        int temp = read4(buf);
        if(n-c_cnt<temp){
            *(buf+n-c_cnt) = '\0';
            return n;
        }
        if(temp<4){
            *(buf+temp) = '\0';
            return c_cnt+temp;
        }
        buf += 4;
        c_cnt += 4;
    }
}

int main(){
    int n = INT_MAX;
    char buf[n];
    int res = read(buf, n);  
    cout<<buf<<endl;
    cout<<res<<endl;
    return 0;
}