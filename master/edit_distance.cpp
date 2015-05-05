#include "header.h"

int min(int a, int b){
    return a<b?a:b;
}

int minDistance(string word1, string word2) {
    int arr[word1.size()+1][word2.size()+1];
    for(int i=1; i<=word1.size(); i++)
        arr[i][0] = i;
    for(int i=1; i<=word2.size(); i++)
        arr[0][i] = i;
    arr[0][0] = 0;
    for(int i=1; i<=word1.size(); i++)
        for(int j=1;j<=word2.size();j++){
            arr[i][j] = min(arr[i][j-1], arr[i-1][j])+1;
            if(word1[i-1] != word2[j-1])
                arr[i][j] = min(arr[i][j], arr[i-1][j-1]+1);
            else
                arr[i][j] = min(arr[i][j], arr[i-1][j-1]);
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
