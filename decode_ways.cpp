#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<stdbool.h>

using std::string;

bool valid(string s){
    return (s[0]=='1' && s[1]<='9' && s[1]>='0') || (s[0] == '2' && s[1]>=0 && s[1]<='6');
}

int numDecodings(string s){
    if(s.size() == 0) return 0;
    int arr[s.size()+1];
    arr[0] = 0;
    arr[1] = s[0] == '0'?0:1;
    if(s.size() == 1) return arr[1];
    arr[2] = 0;
    if((s[0] == 0 && s[1]!='0') || s[0]>'2' || s[0]=='2' && s[1]>'6') arr[2]+=1;
    if(valid(s.substr(s,2))) arr[2]+=1;
    for(int i=2; i<s.size(); i++){
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
