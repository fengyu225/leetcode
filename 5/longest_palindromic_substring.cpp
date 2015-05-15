#include "header.h"

//using dp
//string longestPalindrome(string s) {
//    if(s.length()<2) return s;
//    int sz = s.length();
//    int arr[1000][1000];
//    int res = 1, res_l = 0;
//    for(int i=0;i<1000;i++){arr[i][i]=1;}
//    for(int l=2;l<=sz;l++){
//        for(int i=0; i+l<=sz; i++){
//            int temp = l==2?0:arr[i+1][i+l-2];
//            if(s[i]==s[i+l-1] && (temp!=0||l==2)){
//                arr[i][i+l-1] = temp+2;
//                if(arr[i][i+l-1]>res){
//                    res = arr[i][i+l-1];
//                    res_l = i;
//                }
//            }
//            else{
//                arr[i][i+l-1] = 0;
//            }
//        }
//    }
//    return s.substr(res_l, res);
//}

string expand(string& s, int l, int r){
    int a=l,b=r;
    int sz = s.length();
    while(a>=0 && b<sz && s[a]==s[b]){
        a--;
        b++;
    }
    return s.substr(a+1,b-a-1);
}

string longestPalindrome(string s) {
    if(s.length()<2) return s;
    int sz = s.length();
    string res = s.substr(0,1);
    for(int i=0; i<sz-1; i++){
        string temp = expand(s,i,i);
        if(temp.length()>res.length()) res = temp;
        temp = expand(s,i,i+1);
        if(temp.length()>res.length()) res = temp;
    }
    return res;
}

int main(){
    string s0 = longestPalindrome("abacdfgdcaba");
    printf("%s\n", s0.c_str());
    return 0;
}
