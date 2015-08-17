/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

#include "header.h"

int calculateMinimumHP(vector<vector<int> >& dungeon) {
    int row = dungeon.size();
    if(row == 0) return 0;
    int col = dungeon[0].size();
    vector<vector<int> > mx(row, vector<int>(col, 0));
    //mx[i][j] is minimal health point knight can have before he enter (i,j)
    mx[row-1][col-1] = dungeon[row-1][col-1]>=0?1:-1*dungeon[row-1][col-1]+1;
    for(int i=row-1; i>=0; i--){
        for(int j=col-1; j>=0; j--){
            if(i == row-1 && j == col-1) continue;
            int temp = i==row-1?mx[i][j+1]:j==col-1?mx[i+1][j]:min(mx[i+1][j], mx[i][j+1]);
            if(dungeon[i][j] == 0) mx[i][j] = temp;
            else if(dungeon[i][j]>0) mx[i][j] = max(temp-dungeon[i][j], 1);
            else mx[i][j] = -1*dungeon[i][j]+temp;
        } 
    }
    return mx[0][0];
}

int main(){
    vector<vector<int> > dungeon = {
        {1, -3, 3},
        {0, -2, 0},
        {-3, -3, -3}
    };
    cout<<calculateMinimumHP(dungeon)<<endl;
    return 0;
}