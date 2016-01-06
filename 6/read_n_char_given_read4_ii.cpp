/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.
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

}

int main(){
    for(int i=0; i<2; i++){
    int n = 5;
    char buf[n];
    int res = read(buf, n);  
    cout<<"buf: "<<buf<<endl;
    cout<<"temp_buf_size: "<<temp_buf_size<<endl;
    for(int k=0; k<temp_buf_size; k++) cout<<temp_buf[k]<<" ";
    cout<<endl;
    cout<<"res: "<<res<<endl;
    }
    return 0;
}