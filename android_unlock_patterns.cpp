/*
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.

Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6 
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:
Given m = 1, n = 1, return 9.
*/

#include "header.h"

bool check(int i, int j, int a, int b, vector<vector<bool> >& visited){
    if(i == a && abs(b-j) == 2 && visited[i][(b+j)/2] == false) return false;
    if(b == j && abs(i-a) == 2 && visited[(i+a)/2][j] == false) return false;
    if(abs(i-a) == 2 && abs(j-b) == 2 && visited[(i+a)/2][(j+b)/2] == false) return false;
    return true;
}

int search(int i, int j, int m, int n, int curr_len, vector<vector<bool> >& visited){
    int res = 0;
    if(curr_len>=m && curr_len<=n) res++;
    if(curr_len == n) return res;
    for(int a = 0; a<3; a++){
        for(int b = 0; b<3; b++){
            if(a == i && b == j) continue;
            if(visited[a][b]) continue;
            if(check(i, j, a, b, visited)){
                visited[a][b] = true;
                res+=search(a, b, m, n, curr_len+1, visited);
                visited[a][b] = false;
            } 
        }
    }
    return res;
}

int numberOfPatterns(int m, int n) {
    int res = 0;
    vector<vector<bool> > visited(3, vector<bool>(3, false));
    for(int i=0; i<2; i++){
        for(int j = 0; j<2; j++){
            visited[i][j] = true;
            if(i == 0 && j == 0)
                res += 4*search(i, j, m, n, 1, visited);
            else if((i == 0 && j == 1) || (i == 1 && j == 0))
                res += 2*search(i, j, m, n, 1, visited);
            else 
                res += search(i, j, m, n, 1, visited);
            visited[i][j] = false;
        }
    }
    return res;
}

int main(){
    cout<<numberOfPatterns(1, 2)<<endl;
    return 0;
}
