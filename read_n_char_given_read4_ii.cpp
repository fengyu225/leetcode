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

char temp_buf[4];
char* temp_buf_curr = temp_buf;
int temp_buf_size = 0;

int read(char *buf, int n) {
    if(n == 0) return 0;
    int cnt = 0;
    while(1){
        if(temp_buf_curr<temp_buf+temp_buf_size){
            *(buf++)=*(temp_buf_curr++);
            cnt++;
            if(cnt == n){
                *buf = '\0';
                return n;
            }
            continue;
        }
        int temp = read4(buf);
        if(n-cnt<temp){
            temp_buf_curr = temp_buf;
            temp_buf_size = temp-(n-cnt);
            for(char* x = buf+(n-cnt); x<buf+temp; *(temp_buf_curr++)=*(x++));
            temp_buf_curr = temp_buf;
            *(buf+(n-cnt)) = '\0';
            return n;
        }
        if(temp<4){
            temp_buf_curr = temp_buf;
            temp_buf_size = 0;
            *(buf+temp) = '\0';
            return cnt+temp;
        }
        buf += 4;
        cnt += 4;
    }
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