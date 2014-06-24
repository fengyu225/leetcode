#include "header.h"

bool isScramble(string s1, string s2){
    if(s1==s2) return true;
    if(s2.size() == 0) return s1.size()==0;
    if(s1.size() != s2.size()) return false;
    bool res = false;
    string temp = s2;
    s2 = s1;
    s1 = temp;
    for(int i=0; i<s1.size(); i++){
        if(s1[i] != s2[0]) continue;
        res = isScramble(s1.substr(0,i),s2.substr(1,i)) && isScramble(s1.substr(i+1,s1.size()-i-1),s2.substr(i+1,s2.size()-i-1)) || isScramble(s1.substr(0,i),s2.substr(i+1,s2.size()-i-1)) && isScramble(s1.substr(i+1,s1.size()-i-1),s2.substr(1,i));
        if(res) return true;
    }
    return false;
}

int main(){
//    printf("%d\n", isScramble("great", "rgtae"));
//    printf("%d\n", isScramble("great", "great"));
//    printf("%d\n", isScramble("abc", "bca"));
//    printf("%d\n", isScramble("abc", "cab"));
//    printf("%d\n", isScramble("abcd", "bcad"));
    printf("%d\n", isScramble("abcd", "cabd"));
    return 0;
}
