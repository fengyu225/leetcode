#include "header.h"

bool isScramble(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    if(s1 == s2) return true;
    int sz = s1.size();
    bool arr[sz+1][sz][sz];
    for(int i=0; i<sz; i++)
        for(int j=0; j<sz; j++)
            arr[1][i][j] = s1[i]==s2[j];
    for(int i=2;i<=sz;i++){
        for(int j=0; j+i-1<sz; j++){
            for(int k=0;k+i-1<sz;k++){
                bool flag = false;
                for(int x = 1;x<i;x++){
                    if(
                            arr[x][j][k] && arr[i-x][j+x][k+x] || 
                            arr[x][j][k+i-x] && arr[i-x][j+x][k]
                      ){
                        flag =true;
                        break;
                    }
                }
                arr[i][j][k] = flag;
            }
        }
    }
    return arr[sz][0][0];
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
