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
    if(word2 == "") return word1.size();
    int arr[word1.size()+1][word2.size()+1];
    for(int i=0; i<=word2.size(); i++) arr[0][i]=i; 
    for(int i=0; i<=word1.size(); i++) arr[i][0]=i;
    for(int i=1; i<=word1.size(); i++){
        for(int j=1; j<=word2.size(); j++){
            int x = INT_MAX;
            if(word1[i-1] == word2[j-1])
                x = arr[i-1][j-1];
            else
                x = arr[i-1][j-1]+1;
            arr[i][j] = std::min(arr[i-1][j], arr[i][j-1])+1;
            arr[i][j] = std::min(arr[i][j],x);
        }
    }
    return arr[word1.size()][word2.size()];
}

int main(){
    string word1("abcd");
    string word2("bedf");
    int res = minDistance(word1, word2);
    printf("%d\n", res);
    return 0;
}
