#include "header.h"

bool isInterleave(string s1, string s2, string s3) {
    if(s3.size() != s1.size()+s2.size()) return false;
    bool temp[s3.size()+1][s1.size()+1];
    if(s1[0] == s3[0]) temp[1][1] = true;
    if(s2[0] == s3[0]) temp[1][0] = true;
    for(int i=2;i<s3.size();i++){
        bool r = false;
        for(int j=0;j<=i;j++){

    }
    return false;
}

int main(){
    string s1("aabcc");
    string s2("dbbca");
    string s3("aadbbcbcac");
    string s4("aadbbbaccc");
    printf("%s\n", isInterleave(s1,s2,s3)?"true":"false");
    printf("%s\n", isInterleave(s1,s2,s4)?"true":"false");
    return 0;
}
