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

bool valid(vector<vector<bool> >& visited, int a, int b, int i, int j){
    if(a==i && b == j) return false;
    if(visited[i][j]) return false;
    if(a == i){
        for(int temp = min(b, j); temp <= max(b, j); temp++)
            if(temp != b && temp != j && !visited[a][temp]) return false;
        return true;
    } 
    if(b == j){
        for(int temp = min(a, i); temp <= max(a, i); temp++)
            if(temp != a && temp != i && !visited[temp][b]) return false;
        return true;
    }
    if(abs(a-i) != abs(b-j) || abs(a-i) == 1) return true;
    int x = i>a?1:-1;
    int y = j>b?1:-1;
    for(int curr_x=a+x, curr_y=b+y; curr_x<i; curr_x+=x, curr_y+=y){
        if(!visited[curr_x][curr_y]) return false;
    }
    return true;
}

void calc(int a, int b, vector<vector<bool> >& visited, int& cnt, int m, int n, int curr_len){
    if(curr_len<=n && curr_len>=m) cnt++;
    cout<<curr_len<<": "<<a<<" "<<b<<" "<<cnt<<endl;
    if(curr_len == n) return;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(valid(visited, a, b, i, j)){
                visited[i][j] = true;
                calc(i, j, visited, cnt, m, n, curr_len+1);
                visited[i][j] = false;
            }
        }
    }
}

int numberOfPatterns(int m, int n) {
    int cnt = 0;
    vector<vector<bool> > visited(3, vector<bool>(3, false));
    for(int i=0; i<3; i++){
        for(int j = 0; j<3; j++){
            visited[i][j] = true;
            calc(i, j, visited, cnt, m, n, 1);
            visited[i][j] = false;
        }
    }
    return cnt;
}

int main(){
    cout<<numberOfPatterns(1, 2)<<endl;
    return 0;
}
