#include "header.h"

bool isScramble(string s1, string s2){
    if(s1==s2) return true;
    if(s1.size() != s2.size()) return false;
    int len = s1.size();
    bool arr[len+1][len][len];
    memset(arr,0,sizeof(arr));
    for(int i=0; i<len; i++)
        for(int j=0; j<len; j++)
            arr[1][i][j] = s1[i]==s2[j]?true:false;
    for(int i=2; i<=len; i++){
        for(int j=0; j+i<=len; j++){
            for(int k=0; k+i<=len; k++){
                for(int p=1;p<i;p++){
                    arr[i][j][k] |= 
                        arr[p][j][k] && arr[i-p][j+p][k+p] ||
                        arr[p][j][k+i-p] && arr[i-p][j+p][k];
                }
            }
        }
    }
    return arr[len][0][0];
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
