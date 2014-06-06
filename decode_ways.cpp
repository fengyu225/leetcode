#include<stdlib.h>
#include<stdio.h>
#include<string>

using std::string;

int numDecodings(string s){
    if(s.size() == 0) return 0;
    int arr[s.size()+1];
    arr[0] = 0;
    arr[1] = s[0] == '0'?0:1;
    for(int i=1; i<s.size(); i++){
        if(s[i] == '0'){
            arr[i+1]=arr[i];
            continue;
        }
        int b,a=(s[i-1] == '0' && arr[i] == 0)?1:arr[i];
        b = (i>0 && ((s[i-1] == '2' && s[i]>='0' && s[i]<='6') || s[i-1] == '1'))?arr[i-1]:0;
        arr[i+1] = a+b;
    }
    return arr[s.size()];
}

int main(){
    string s0("1226");
    printf("%d\n", numDecodings(s0));
    return 0;
}
