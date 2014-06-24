#include "header.h"

bool isScramble(string s1, string s2){
    if(s1==s2) return true;
    if(s2.size() == 0) return s1.size()==0;
    if(s1.size() != s2.size()) return false;
    bool is_scramble[s1.size()][s1.size()][s2.size()];
    //is_scramble[i][j][k] is true means s1.substr(j,i+1) and s2.substr(k,i+1) is scramble
    for(int i=0;i<s1.size();i++){
        for(int j=0;j+i<s1.size();j++){
            for(int k=0;k+i<s2.size();k++){
                if(i==0 && s1[j] == s2[k]){
                    is_scramble[0][j][k] = true;
                    continue;
                }
                bool res = false;
                for(int m=0;m<i;m++){
                    if(
                            is_scramble[m][j][k] && is_scramble[i-1-m][j+m+1][k+m+1] ||
                            is_scramble[m][j][k+i-m] && is_scramble[i-1-m][j+m+1][k]
                      ){
                        res = true;
                        break;
                    }
                }
                is_scramble[i][j][k] = res;
            }
        }
    }
    return is_scramble[s1.size()-1][0][0];
}

int main(){
    printf("%d\n", isScramble("great", "rgtae"));
    printf("%d\n", isScramble("great", "great"));
    printf("%d\n", isScramble("abc", "bca"));
    printf("%d\n", isScramble("abc", "cab"));
    printf("%d\n", isScramble("abcd", "bcad"));
    printf("%d\n", isScramble("abcd", "cabd"));
    return 0;
}
