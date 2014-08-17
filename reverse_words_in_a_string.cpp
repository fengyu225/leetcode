#include "header.h"

void reverse(string& s, int i, int j){
    while(i<j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

void reverseWords(string &s) {
    if(s.size() < 2) return;
    reverse(s,0,s.size()-1);
    int start = 0,end=0;
    while(start<s.size() && s[start] == ' ') start++;
    end = start;
    while(end<=s.size()){
        if(end<s.size() && s[end]!=' '){
            end++;
            continue;
        }
        reverse(s,start,end-1);
        if(end==s.size()) break;
        start = end;
        while(start<s.size() && s[start]==' ') start++;
        end=start;
    }
}

int main(){
    string s("   the sky is blue ");
    reverseWords(s);
    cout<<s<<endl;
    return 0;
}
