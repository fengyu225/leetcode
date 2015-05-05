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
    for(int i=1; i<s.size(); i++){
        if(valid(s.substr(i-1,2))){
            int y = i==1?1:arr[i-1];
            int x = s[i] == '0'?0:arr[i];
            arr[i+1] = x+y;
            continue;
        }
        if(s[i-1] == '0'){
            if(s[i] == '0')
                arr[i+1]=0;
            else
                arr[i+1] = arr[i];
            continue;
        }
        int t = s[i]=='0'?0:arr[i];
        arr[i+1] = arr[i]==0?0:t;
    }
    return arr[s.size()];
}

int main(){
    string s0("01");
    printf("%d\n", numDecodings(s0));
    string s1("00");
    printf("%d\n", numDecodings(s1));
    string s2("10");
    printf("%d\n", numDecodings(s2));
    string s3("27");
    printf("%d\n", numDecodings(s3));
    return 0;
}
