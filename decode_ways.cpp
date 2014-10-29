#include "header.h"

bool is_valid(char a, char b){
    return a=='1' || (a=='2' && b<='6');
}

int numDecodings(string s){
    if(s.size()==0 || s.size()==1) return 1;
    int num[s.size()];
    memset(num,0,sizeof(num));
    num[0] = s[0]<='9' && s[0]>='1'?1:0;
    num[1] += s[1]<='9' && s[1]>='1'?num[0]:0;
    num[1] += is_valid(s[0],s[1])?1:0;
    for(int i=2; i<s.size(); i++){
        int count = 0;
        if(s[i]<='9' && s[i]>='1')
            count += num[i-1];
        if(is_valid(s[i-1],s[i]))
            count += num[i-2];
        num[i] = count;
    }
    return num[s.size()-1];
}

int main(){
//    string s0("01");
//    printf("%d\n", numDecodings(s0));
//    string s1("00");
//    printf("%d\n", numDecodings(s1));
//    string s2("10");
//    printf("%d\n", numDecodings(s2));
//    string s3("27");
//    printf("%d\n", numDecodings(s3));
    string s4("01");
    printf("%d\n", numDecodings(s4));
    return 0;
}
