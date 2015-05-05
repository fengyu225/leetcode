#include "header.h"

int min(int a, int b){
    return a>b?b:a;
}

bool isInterleave(string s1, string s2, string s3) {
    if(s3.size() != s1.size()+s2.size()) return false;
    bool temp[s3.size()+1][s1.size()+1];
    if(s1[0] == s3[0]) temp[1][1] = true;
    if(s2[0] == s3[0]) temp[1][0] = true;
    for(int i=2;i<=s3.size();i++){
        int is_inter = false;
        for(int j=0;j<=min(i,s1.size());j++){
            if(j>0 && s3[i-1] == s1[j-1] && temp[i-1][j-1]){
                temp[i][j] = true;
            }
            else if(i!=j && s3[i-1] == s2[i-j-1] && temp[i-1][j]){
                temp[i][j] = true;
            }
            else
                temp[i][j] = false; 
        }
    }
    return temp[s3.size()][s1.size()];
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
