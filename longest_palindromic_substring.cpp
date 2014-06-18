#include "header.h"

string longestPalindrome(string s) {
    if(s.size() <=1) return s;
    bool arr[s.size()][s.size()];
    memset(arr,0,s.size()*s.size()*sizeof(bool));
    int begin = -1,max=0;
    for(int i=0; i<s.size(); i++) arr[i][i] = true;
    for(int i=0; i+1<s.size(); i++)
        if(s[i]==s[i+1]){
            arr[i][i+1] = true;
            max = 2;
            begin = i;
        }
    for(int k=3; k<=s.size(); k++){
        for(int i=0;i+k-1<s.size();i++){
            if(s[i] == s[i+k-1] && arr[i+1][i+k-2]){
                arr[i][i+k-1] = true;
                if(k>max){
                    begin = i;
                    max = k;
                }
            }
        }
    }
    return s.substr(begin,max);
}

bool is_palindromic(string& s, int i, int j){
    while(i<j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

string longestPalindrome(string s) {
    int max = 0;
    int begin = 0;
    for(int i=0; i<s.size(); i++){
        for(int k=0;i-k>=0 && i+k<s.size();k++){
            if(is_palindromic(s,i-k,i+k)){
                if(max<2*k+1){
                    begin = i-k;
                    max = 2*k+1;
                }
            }
        }
        for(int k=0;i-k>=0 && i+1+k<s.size();k++){
            if(is_palindromic(s,i-k,i+1+k)){
                if(max<2*k+2){
                    begin = i-k;
                    max = 2*k+2;
                }
            }
        }
    }
    return s.substr(begin,max);
}

int main(){
    string s0 = longestPalindrome("abacdfgdcaba");
    printf("%s\n", s0.c_str());
    return 0;
}
