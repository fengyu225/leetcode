/*
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include "header.h"

int minDistance(string word1, string word2) {
    if(word1 == word2) return 0;
    int m=word1.size(), n=word2.size();
    int arr[m+1][n+1];
    arr[0][0] = 0;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0 && n == 0) continue;
            int a = i==0?j:arr[i-1][j]+1;
            int b = j==0?i:arr[i][j-1]+1;
            arr[i][j] = min(a,b);
            if(i == 0 || j==0) continue;
            if(word1[i-1]==word2[j-1])
                arr[i][j] = min(arr[i][j], arr[i-1][j-1]);
            else
                arr[i][j] = min(arr[i][j], arr[i-1][j-1]+1);
        }
    }
    return arr[m][n];
}

int main(){
    string word1("a");
    string word2("b");
    int res = minDistance(word1, word2);
    printf("%d\n", res);
    return 0;
}
