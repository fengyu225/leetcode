/*
 QuestionEditorial Solution  My Submissions
Total Accepted: 394
Total Submissions: 1434
Difficulty: Medium
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
*/

#include "header.h"

int getMoneyAmount(int n) {
    if(n == 1) return 0;
    vector<vector<int> > arr(n+1, vector<int>(n+1, 0));
    for(int len = 2; len<=n; len++){
        for(int i=1; i+len-1<=n; i++){
            // from i with length len
            int temp = INT_MAX;
            for(int j = i; j<=i+len-1; j++){
                if(j == i) temp = min(temp, j+arr[j+1][i+len-1]);
                else if(j == i+len-1) temp = min(temp, j+arr[i][j-1]);
                else temp = min(temp, j+max(
                                arr[i][j-1], arr[j+1][i+len-1]
                            ));
            }
            arr[i][i+len-1] = temp;
        }
    }
    return arr[1][n];
}

int main(){
    cout<<getMoneyAmount(10)<<endl;
    return 0;
}
