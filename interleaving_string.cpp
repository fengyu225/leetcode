#include "header.h"

bool isInterleave(string s1, string s2, string s3) {
    int s1_sz = s1.size();
    int s2_sz = s2.size();
    int s3_sz = s3.size();
    if(s1_sz+s2_sz != s3_sz) return false;
    bool arr[s3_sz+1][s1_sz+1];
    arr[1][1] = s3[0]==s1[0];
    arr[1][0] = s3[0]==s2[0];
    for(int i=2; i<=s3_sz; i++){
        bool x = false;
        for(int j=0;j<=std::min(i,s1_sz);j++){
            if(i!=j && s3[i-1] == s2[i-j-1] && arr[i-1][j])
                x = true;
            else if(j>0 && s3[i-1]==s1[j-1] && arr[i-1][j-1])
                x = true;
            else
                x = false;
            arr[i][j] = x;
        }
    }
    return arr[s3_sz][s1_sz];
}

int main(){
//    string s1("aacaac");
//    string s2("aacaaeaac");
//    string s3("aacaaeaaeaacaac");
    string s1("c");
    string s2("");
    string s3("a");
    string s4("aadbbbaccc");
    printf("%s\n", isInterleave(s1,s2,s3)?"true":"false");
    printf("%s\n", isInterleave(s1,s2,s4)?"true":"false");
    return 0;
}
